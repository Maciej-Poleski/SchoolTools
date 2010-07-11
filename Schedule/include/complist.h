#ifndef TERMLIST_H
#define TERMLIST_H

#include <QtCore/QList>

/** Klasa poszerzająca funkcjonalność QList<T> */
template<class T>
class CompList : public QList<T>
{
public:
private:
public:
    /** Porównuje ze sobą obiekty pod kątem reprezentacji identycznych danych.
      * Wykorzystywane do kontroli spójności zapisu.
      *
      * Należy zoptymalizować tą metode
      * @param o Obiekt z którym zostanie porównany dany obiekt
      **/
    bool operator==(const CompList<T> &o) const;
private:
};

template<class T>
bool CompList<T>::operator==(const CompList<T>& o) const
{
    if(this->size()!=o.size())
        return false;
    for(int i=0;i<this->size();++i)
        if(!(this->operator[](i)==o.operator[](i)))
            return false;
    return true;
}

#endif // TERMLIST_H
