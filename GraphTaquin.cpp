#include "GraphTaquin.h"

using namespace std;

list<Sommet> GraphTaquin::adjacent(Sommet v) const {

   return list<Sommet>();
}

int fact(int n){
   return n == 0 or n == 1 ? 1 : n*fact(n-1);
}

int GraphTaquin::V() const {
   return fact(TAILLE*TAILLE);
}


