#ifndef MARK_H
#define MARK_H

#include <QtCore/QtGlobal>

#include "initializable.h"
#include "idgenerator.h"

/** Klasa przechowująca informacje o pojedyńczym skutku wydarzenia.
  *
  * Jeżeli ocena jest klasyczna - wymagana jest transformacja formatu klasycznego na ocenę cząstkową przy użyciu metody podanej przez użytkownika.
  *
  * Jeżeli ocena jest nowoczesna - wymagana jest transformacja formatu nowoczesnego na ocenę cząstkową przy użyciu skali ocen podanej przez użytkownika.
  * W przypadku podania oceny cząstkowej nowoczesnej bezpośrednio KONIECZNA jest transformacja wstecz!!! [TODO]
  */
class Mark : private Initializable
{
    /** Zapisuje informacje o danej ocenie do danego strumienia.
      * @param stream Strumień do którego będą zapisywane dane.
      * @param mark Ocena która będzie zapisana.
      * @throw QString Jeżeli zapisywana ocena nie zostało zainicjalizowane
      * @return Ten sam strumień.
      **/
    friend QDataStream & operator<< (QDataStream& stream, const Mark& mark) throw(QString);

    /** Odczytuje informacje o danej ocenie z danego strumienia.
      * @param stream Strumień z którego będą odczytywane dane.
      * @param mark Ocena która zostanie zainicjalizowane wczytanymi danymi.
      * @throw QString Jeżeli ocena została wcześniej zainicjalizowane.
      * @return Ten sam strumień.
      **/
    friend QDataStream & operator>> (QDataStream& stream, Mark& mark) throw(QString);
public:
    /** Reprezentuje skutek wydarzenia w znanym formacie */
    union Format
    {
        struct
        {
            quint8 classic; ///< Licznik
            qint8  sign;    ///< Znak: 1, 0 lub -1
        };
        double  modern;     ///< Dodatnia liczba wymierna
    };
private:
    quint8          top;        ///< Licznik
    qint8           sign;       ///< Mianownik lub znak: 1, 0 lub -1. W przeciwnym przypadku mianownik
    IDGenerator::ID termID;     ///< Identyfikator terminu

public:
    /** Konstruktor. Inicjalizuje obiekt.
      * @param termID Identyfikator terminu który sopwodował powstanie danego obiektu
      * @param top Licznik ułamka
      * @param sign Mianownik lub znak ułamka
      */
    Mark(IDGenerator::ID termID,quint8 top,qint8 sign) : termID(termID), top(top), sign(sign),Initializable(true) {}

    /** Umożliwia tworzenie niezainicjalizowanych obiektów */
    Mark() : Initializable(false) {}

    /** Inicjalizuje obiekt.
      * @param termID Identyfikator terminu który sopwodował powstanie danego obiektu
      * @param top Licznik ułamka
      * @param sign Mianownik lub znak ułamka
      * @throw QString Jeżeli dany obiekt już został zainicjalizowany
      */
    void initialize(IDGenerator::ID termID,quint8 top,qint8 sign) throw(QString)
    {
        makeInitialized();
        this->termID=termID;
        this->top=top;
        this->sign=sign;
    }

    /** Porównuje ze sobą obiekty pod kątem identyczności.
      * Wykorzystywane do kontroli spójności zapisu.
      * @param o Obiekt z którym zostanie porównany dany obiekt
      **/
    bool operator==(const Mark &o) const
    {
        return Initializable(*this)==Initializable(o) && top==o.top && sign==o.sign && termID==o.termID;
    }

    /** Czy skutek jest klasyczny.
      * @throw QString Jeżeli dany obiekt jest niezainicjalizowany.
      */
    bool isClassic() const throw(QString)
    {
        checkInitialized();
        return sign==0 || sign==-1 || sign==1;
    }

    /** Zwraca dany rezultat wydarzenia.
      * @throw QString Jeżeli dany obiekt jest niezainicjalizowany.
      */
    Format getMark() const throw(QString)
    {
        checkInitialized();
        Format result;
        if (isClassic())
            result.classic=top,result.sign=sign,result.modern=-1;   // modern<0 ==> isClassic()=true
        else
            result.modern=static_cast<double>(top)/sign;
        return result;
    }

private:

};

/** Zapisuje informacje o danej ocenie do danego strumienia.
  * @param stream Strumień do którego będą zapisywane dane.
  * @param mark Ocena która będzie zapisana.
  * @throw QString Jeżeli zapisywana ocena nie zostało zainicjalizowane
  * @return Ten sam strumień.
  **/
QDataStream & operator<< (QDataStream& stream, const Mark& mark) throw(QString);

/** Odczytuje informacje o danej ocenie z danego strumienia.
  * @param stream Strumień z którego będą odczytywane dane.
  * @param mark Ocena która zostanie zainicjalizowane wczytanymi danymi.
  * @throw QString Jeżeli ocena została wcześniej zainicjalizowane.
  * @return Ten sam strumień.
  **/
QDataStream & operator>> (QDataStream& stream, Mark& mark) throw(QString);

#endif // MARK_H
