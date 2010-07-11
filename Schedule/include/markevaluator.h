#ifndef MARKEVALUATOR_H
#define MARKEVALUATOR_H

#include "complist.h"

/** Klasa reprezentuje system przeliczania punktów i ocen pośrednich w oceny cząstkowe nie uwzględniając wag.
  *
  * Możliwości:
  * - Dummy (do nothing)
  * - modern -> classic
  * - classic -> partial-mark (ocena cząstkowa)
  * - modern -> partial-mark
  *
  * W przyszłości również operacje wstecz.
  *
  * Tablica do wyszukiwania binarnego, sposób wypełniania:
  * Od najniższych indeksów wypełniamy progiem na daną ocenę aż do osiągnięcia dokładnie tego indeksu, który odpowiada danej ocenie.
  * Sposób wyszukiwania:
  * qUpperBound - trzeci argument to ocena w formacie modern. Od wyniku odejmujemy jeden.
  * Teraz posiadamy oczekiwaną odległość od początku tablicy gotową do dalszych tranformacji.
  * O(lg(maksymalna potencjalna liczba różnych ocen klasycznych))
  */
class MarkEvaluator
{
public:
private:
    bool                dummy;              ///< Jeżeli ustawione - należy potraktować modern-mark bezpośrednio
    CompList<double>    modernToClassic;    ///< Tablica do wyszukiwania binarnego podczas transformacji modern-mark -> classic
    
public:
private:

};

#endif // MARKEVALUATOR_H
