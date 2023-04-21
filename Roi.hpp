/*Ce fichier  contient les fonctions necessaires pour creer la piece roi
    et les fonctions qui lui permettent de se deplacer dans l'echiquier.
                    Waridi Bennouna Mohamed   2030286
                        Rezzouk Kawtar 2000057                   */

#pragma once

namespace Modele {
    class Roi : public Modele::Piece {
    public:
        bool mouvementValide(int colFrom, int rankFrom, int colTo, int rankTo) override;
        
    };
}