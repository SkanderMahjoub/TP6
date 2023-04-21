/*Ce fichier  contient les fonctions necessaires pour creer la piece fou 
    et les fonctions qui lui permettent de se deplacer dans l'echiquier.
                    Waridi Bennouna Mohamed   2030286
                        Rezzouk Kawtar 2000057                   */

#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#pragma pop()
#include "Fou.hpp"
using namespace std;

bool Modele::Fou::mouvementValide(int colFrom, int rankFrom, int colTo, int rankTo) {
    if (colTo < 1 || colTo  > board()->columns()) return false;
    if (rankTo < 1 || rankTo > board()->ranks())   return false;
    if (abs(colTo - colFrom) == abs(rankFrom - rankFrom)) return true;
    return false;
}
