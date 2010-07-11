#ifndef INITIALIZABLE_H
#define INITIALIZABLE_H

#include <QtCore/QString>

/** Określa klasy inicjalizowalne */
class Initializable
{
public:
protected:
private:
    bool initialized;           ///< Czy zostało zainicjalizowane
public:
    /** Decyduje o tym, czy powstający obiekt jest zainicjalizowany. */
    Initializable(bool initialized=false) : initialized(initialized) {}

    /** Porównuje ze sobą obiekty pod kątem identyczności.
      * Wykorzystywane do kontroli spójności zapisu.
      * @param o Obiekt z którym zostanie porównany dany obiekt
      **/
    bool operator==(const Initializable &o) const
    {
        return initialized==o.initialized;
    }

protected:
    /** Sprawdza czy obiekt został zainicjalizowany. */
    bool isInitialized() const
    {
        return initialized;
    }

    /** Ustawia niezainicjalizowany obiekt w stan zainicjalizowany.
      * @throw QString Jeżeli dany obiekt już został zainicjalizowany
      */
    void makeInitialized() throw(QString)
    {
        if (initialized)
            throw "Ten obiekt jest zainicjalizowany!";
        initialized=true;
    }

    /** Pozwala na dalsze wykonywanie kodu jeżeli dany obiekt jest zainicjalizowany
      * @throw QString Jeżeli dany obiekt jest niezainicjalizowany.
      */
    void checkInitialized() const throw(QString)
    {
        if (!initialized)
            throw "Ten obiekt jest niezainicjalizowany!";
    }
private:
};

#endif // INITIALIZABLE_H
