/*Ce fichier  contient les fonctions necessaires pour creer la piece tour
    et les fonctions qui lui permettent de se deplacer dans l'echiquier.
                    Waridi Bennouna Mohamed   2030286
                        Rezzouk Kawtar 2000057                   */

#pragma once
#include "Jeu.hpp"

namespace Modele {
    class Tour : public Modele::Piece {
    public:
        bool mouvementValide(int colFrom, int rankFrom, int colTo, int rankTo) override;
    };
}