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

   GraphTaquin(std::size_t taille) : TAILLE(taille) {};

   int V() const;

   int evaluer(Sommet& depart);

private:
   const std::size_t TAILLE;
   std::map<std::string,bool> dejaAtteints;

   std::list<int> chemin;

   ListeSommets adjacent(const Sommet& v);

   bool Marquer(Sommet& s);

   void chaine();

};


#endif //LABO12_GRAPHTAQUIN_H
