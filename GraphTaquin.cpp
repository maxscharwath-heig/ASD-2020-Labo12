#include "GraphTaquin.h"
#include <queue>
#include <iostream>

using namespace std;

int fact(int n) {
   return n == 0 or n == 1 ? 1 : n * fact(n - 1);
}

int GraphTaquin::V() const {
   return fact(taille * taille);
}

ListeSommets GraphTaquin::adjacent(const Sommet& v) {
   return v.adjacent();
}

int GraphTaquin::evaluer() {
   //parcours
   int i = 0;
   queue<Sommet> Q{};
   Q.push(depart);
   Marquer(depart, depart);

   while (!Q.empty()) {
      Sommet v = Q.front();
      Q.pop();
      //action sur v
      if (v == sommetFinal) {
         chaine();
         return i;
      }

      for (auto w : v.adjacent()) {
         if (!Marquer(w, v)) {
            Q.push(w);
            ++i;
         }
      }
   }

   return i;
}

bool GraphTaquin::Marquer(Sommet& s, Sommet& parent) {
   if (dejaAtteints.count(s.toString()) > 0) {
      return true;
   }
   dejaAtteints.insert(pair<string, Sommet>(s.toString(), parent));
   return false;
}

void GraphTaquin::chaine() {
   Sommet w = sommetFinal;
   string chaine;
   if (dejaAtteints.count(w.toString()) <= 0) return;
   while (!(dejaAtteints.find(w.toString())->second == w)) {
      chaine.insert(0, to_string(w.change()) + " ");
      w = dejaAtteints.find(w.toString())->second;
   }
   cout << chaine << endl;
}

GraphTaquin::GraphTaquin(const Sommet& depart) : depart(depart), sommetFinal(depart) {
   taille = depart.getTaille();
   sommetFinal = Sommet::fromTaille(taille);
}
