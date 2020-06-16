//
// Created by AnneSo on 16.06.2020.
//

#ifndef LABO12_GRAPHTAQUIN_H
#define LABO12_GRAPHTAQUIN_H

#include <cstdlib>
#include <list>
#include "Sommet.h"

using ListeSommets = std::list<Sommet*>;

class GraphTaquin {

public:

   GraphTaquin(std::size_t taille) : TAILLE(taille) {};

   ListeSommets adjacent(Sommet v) const;

   int V() const;

private:
   const std::size_t TAILLE;
   ListeSommets dejaAtteints;

};


#endif //LABO12_GRAPHTAQUIN_H
