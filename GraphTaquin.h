//
// Created by AnneSo on 16.06.2020.
//

#ifndef LABO12_GRAPHTAQUIN_H
#define LABO12_GRAPHTAQUIN_H

#include <cstdlib>
#include <list>
#include "Sommet.h"
#include <map>
#include <string>

using ListeSommets = std::list<Sommet>;
using ListePtrSommet = std::list<Sommet*>;

class GraphTaquin {

public:

   GraphTaquin(const Sommet& depart);

   int V() const;

   int evaluer();

private:
   std::size_t taille;
   std::map<std::size_t, Sommet> dejaAtteints;
   bool Marquer(Sommet& s, Sommet& parent);
   void chaine();

   Sommet depart;

   ListeSommets adjacent(const Sommet& v);

   Sommet sommetFinal;
};


#endif //LABO12_GRAPHTAQUIN_H
