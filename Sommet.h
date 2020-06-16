//
// Created by AnneSo on 16.06.2020.
//

#ifndef LABO12_SOMMET_H
#define LABO12_SOMMET_H
#include <list>

class Sommet {

   std::list<int> etat;

public:
   Sommet(std::list<int> etat) : etat(etat) {};

   std::list<Sommet> adjacent();

};


#endif //LABO12_SOMMET_H
