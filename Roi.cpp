/*Ce fichier  contient les fonctions necessaires pour creer la piece roi
    et les fonctions qui lui permettent de se deplacer dans l'echiquier.
                    Waridi Bennouna Mohamed   2030286
                        Rezzouk Kawtar 2000057                   */

#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#pragma pop()
#include "Roi.hpp"


 bool Modele::Roi::mouvementValide(int colFrom, int rankFrom, int colTo, int rankTo) {
     if (colTo < 1 || colTo  > board()->columns()) return false;
     if (rankTo < 1 || rankTo > board()->ranks())   return false;
     if ((abs(colFrom - colTo) == 1 || abs(colFrom - colTo) == 0) && (abs(rankFrom - rankTo) == 1 || abs(rankFrom - rankTo) == 0)) {
             return true;
         }
     return false;
 }
 