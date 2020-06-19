#include "GraphTaquin.h"
#include <queue>
#include <iostream>

using namespace std;

int fact(int n) {
   return n == 0 or n == 1 ? 1 : n * fact(n - 1);
}

void GraphTaquin::evaluer() {
   queue<Sommet> Q{};
   Q.push(depart);
   marquer(depart, depart);

   while (!Q.empty()) {
      Sommet v = Q.front();
      Q.pop();
      //action sur v
      if (v == sommetFinal) {
         chaine();
         return;
      }

      for (auto w : v.adjacent()) {
         if (!marquer(w, v)) {
            Q.push(w);
         }
      }
   }
   cout << "Aucune reponse possible" << endl;
}

bool GraphTaquin::marquer(Sommet& s, Sommet& parent) {
   if (dejaAtteints.count(s.getId()) > 0) {
      return true;
   }
   dejaAtteints.insert(pair<std::size_t, Sommet>(s.getId(), parent));
   return false;
}

void GraphTaquin::chaine() {
   Sommet w = sommetFinal;
   string chaine;
   if (dejaAtteints.count(w.getId()) <= 0) return;
   while (!(dejaAtteints.find(w.getId())->second == w)) {
      chaine.insert(0, to_string(w.posZero()) + " ");
      w = dejaAtteints.find(w.getId())->second;
   }
   cout << chaine << endl;
}

GraphTaquin::GraphTaquin(const Sommet& depart): depart(depart) {
   taille = depart.getTaille();
   sommetFinal = Sommet::fromTaille(taille);
}
