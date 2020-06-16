#include "GraphTaquin.h"
#include <queue>
#include <iostream>

using namespace std;

int fact(int n){
   return n == 0 or n == 1 ? 1 : n*fact(n-1);
}

int GraphTaquin::V() const {
   return fact(TAILLE*TAILLE);
}

ListeSommets GraphTaquin::adjacent(const Sommet &v) {
   return v.adjacent();
}

int GraphTaquin::evaluer(Sommet &depart) {
   Sommet sommetFinal({0,1,2,3,4,5,6,7,8});

   //parcours
   int i = 0;
   queue<Sommet> Q{};
   Q.push(depart);
   Marquer(depart);

   while(!Q.empty()){
      //cout << Q.size() << ' ';
      Sommet v = Q.front();
      Q.pop();
      //cout << Q.size() << ' ';
      //action sur v
      //if(v == sommetFinal) return i;

      //cout << endl << v;

      for(auto w : v.adjacent()){
         if(!Marquer(w)){
            Q.push(w);
            ++i;
         }
      }
      //cout << Q.size() << endl;
   }

   return i;
}


bool GraphTaquin::Marquer(Sommet &s) {
   if(dejaAtteints.count(s.toString()) > 0){
      return true;
   }
   dejaAtteints[s.toString()] = true;
   return false;
}

void GraphTaquin::chaine() {

}