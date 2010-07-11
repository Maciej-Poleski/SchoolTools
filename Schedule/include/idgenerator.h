#ifndef IDGENERATOR_H
#define IDGENERATOR_H

#include <QtCore/QtGlobal>
#include <QtCore/QDataStream>

/** Generator identyfikatorów określonego typu **/
class IDGenerator
{
    /** Każdy generator identyfikatorów jest zaprzyjaźniony ze swoim stwórcą **/
    friend class GeneratorIDGenerator;

    /** Zapisuje dany generator identyfikatorów do danego strumienia.
      * @param stream Strumień do którego będzie zapisany generator identyfikatorów.
      * @param generator Generator identyfikatorów który zostanie zapisany.
      * @return Ten sam strumień.
      **/
    friend QDataStream& operator<<(QDataStream& stream, const IDGenerator& generator);

    /** Odczytuje dany generator identyfikatorów z danego strumienia.
      * @param stream Strumień z którego będzie odczytany generator identyfikatorów.
      * @param generator Generator identyfikatorów który zostanie zainicjalizowany odczytanymi danymi.
      * @return Ten sam strumień.
      **/
    friend QDataStream& operator>>(QDataStream& stream, IDGenerator& generator);

public:
    /** Obiekt reprezentuje dany identyfikator określonego typu **/
    class ID
    {
        /** Identyfikator jest zaprzyjaźniony ze swoim stwórcą **/
        friend class IDGenerator;

        /** Zapisuje dany identyfikator do danego strumienia.
          * @param stream Strumień do którego będzie zapisany identyfikator.
          * @param id Identyfikator który zostanie zapisany.
          * @return Ten sam strumień.
          **/
        friend QDataStream& operator<<(QDataStream& stream, const ID& id);

        /** Odczytuje dany identyfikator z danego strumienia.
          * @param stream Strumień z którego będzie odczytany identyfikator.
          * @param id Identyfikator który zostanie zainicjalizowany odczytanymi danymi.
          * @return Ten sam strumień.
          **/
        friend QDataStream& operator>>(QDataStream& stream, ID& id);

    public:
    private:
        quint64 id;                        ///< Reprezentowany ID
        quint64 type;                      ///< Typ tego identyfikatora
    public:
        /** Konstruktor domyślny **/
        ID() : id(0),type(0) {}

        /** Przypisuje wartość identyfikatora do pustego identyfikatora. **/
        ID& operator=(const ID& o) throw(char*);

        /** Porównuje ze sobą obiekty pod kątem identyczności.
          * Wykorzystywane do kontroli spójności zapisu.
          * @param o Obiekt z którym zostanie porównany dany obiekt
          **/
        bool operator==(const ID &o) const
        {
            return id==o.id && type==o.type;
        }

    private:
        /** Inicjalizuje identyfikator **/
        ID(quint64 id,quint64 type) : id(id), type(type) {}
    };
private:
    quint64 type;                          ///< Typ identyfikatorów generowanych przez dany generator.
    quint64 freeID;                        ///< Pierwszy wolny ID

public:
    /** Przeładowany operator przypisania dla upewnienia się, że żaden generator nie zostanie zniszczony **/
    IDGenerator& operator=(const IDGenerator&o) throw(char*);

    /** Porównuje ze sobą obiekty pod kątem identyczności.
      * Wykorzystywane do kontroli spójności zapisu.
      * @param o Obiekt z którym zostanie porównany dany obiekt
      **/
    bool operator==(const IDGenerator &o) const
    {
        return type==o.type && freeID==o.freeID;
    }

    /** Generuje następny identyfikator **/
    ID nextID()
    {
        return ID(freeID++,type);
    }

    /** Generuje niezainicjalizowany identyfikator **/
    ID voidID()
    {
        return ID(0,type);
    }

    /** Inicjalizuje dany generator identyfikatorów. Inicjalizowany identyfikator MUSI być niezainicjalizowany! **/
    void initialize() throw(char*);

private:
    /** Inicjalizuje dany generator.
      *
      * @param T Typ identyfikatorów generowanych przez ten generator.
      **/
    IDGenerator(quint64 T) : type(T), freeID(1LL) {}
};

/** Zapisuje dany identyfikator do danego strumienia.
  * @param stream Strumień do którego będzie zapisany identyfikator.
  * @param id Identyfikator który zostanie zapisany.
  * @return Ten sam strumień.
  **/
QDataStream& operator<<(QDataStream& stream, const IDGenerator::ID& id);

/** Odczytuje dany identyfikator z danego strumienia.
  * @param stream Strumień z którego będzie odczytany identyfikator.
  * @param id Identyfikator który zostanie zainicjalizowany odczytanymi danymi.
  * @return Ten sam strumień.
  **/
QDataStream& operator>>(QDataStream& stream, IDGenerator::ID& id);

/** Zapisuje dany generator identyfikatorów do danego strumienia.
  * @param stream Strumień do którego będzie zapisany generator identyfikatorów.
  * @param generator Generator identyfikatorów który zostanie zapisany.
  * @return Ten sam strumień.
  **/
QDataStream& operator<<(QDataStream& stream, const IDGenerator& generator);

/** Odczytuje dany generator identyfikatorów z danego strumienia.
  * @param stream Strumień z którego będzie odczytany generator identyfikatorów.
  * @param generator Generator identyfikatorów który zostanie zainicjalizowany odczytanymi danymi.
  * @return Ten sam strumień.
  **/
QDataStream& operator>>(QDataStream& stream, IDGenerator& generator);

#endif
