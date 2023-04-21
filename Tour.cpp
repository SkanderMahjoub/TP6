
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#pragma pop()
#include "Tour.hpp"

bool Modele::Tour::mouvementValide(int colFrom, int rankFrom, int colTo, int rankTo) {
    if (colTo < 1 || colTo  > board()->columns()) return false;
    if (rankTo < 1 || rankTo > board()->ranks())   return false;
    if(colFrom == colTo || rankFrom == rankTo) return true;
    return false;
}