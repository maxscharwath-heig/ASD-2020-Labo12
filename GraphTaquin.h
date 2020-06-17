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

   GraphTaquin(std::size_t taille, const Sommet& depart) : TAILLE(taille), depart
   (depart) {};

   int V() const;

   int evaluer();

private:
   const std::size_t TAILLE;
   std::map<std::string, Sommet> dejaAtteints;
   bool Marquer(Sommet& s, Sommet& parent);
   void chaine();

   Sommet depart;

   std::list<int> chemin;

   ListeSommets adjacent(const Sommet& v);

   const static Sommet sommetFinal;

};


#endif //LABO12_GRAPHTAQUIN_H
