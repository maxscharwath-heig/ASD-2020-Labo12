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

class GraphTaquin {

public:

   explicit GraphTaquin(const Sommet& depart);

   void evaluer();

private:
   std::size_t taille;
   std::map<std::size_t, Sommet> dejaAtteints;
   bool marquer(Sommet& s, Sommet& parent);
   void chaine();

   Sommet depart;
   Sommet sommetFinal;
};


#endif //LABO12_GRAPHTAQUIN_H
