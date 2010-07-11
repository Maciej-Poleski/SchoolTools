#ifndef DELETABLE_H
#define DELETABLE_H

/** Reprezentuje klasy których obiekty są usuwalne */
class Deletable
{
public:
protected:
    bool exist;             ///< Czy obiekt istnieje
private:
public:
    /** Decyduje o tym, czy powstający obiekt istnieje. */
    Deletable(bool exist=false) : exist(exist) {}
    
    /** Porównuje ze sobą obiekty pod kątem identyczności.
      * Wykorzystywane do kontroli spójności zapisu.
      * @param o Obiekt z którym zostanie porównany dany obiekt
      **/
    bool operator==(const Deletable &o) const
    {
        return exist==o.exist;
    }

protected:
    /** Sprawdza czy obiekt istnieje.
      * @return true - jeżeli istnieje.
      */
    bool alive() const
    {
        return exist;
    }
    
    /** Ustawia status obiektu.
      * @param e Nowy status obiektu.
      * @return Stary status obiektu.
      */
    bool setExistance(bool e)
    {
        bool old=exist;
        exist=e;
        return old;
    }
private:

};

#endif // DELETABLE_H
