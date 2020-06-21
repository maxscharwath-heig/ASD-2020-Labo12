#include "GraphTaquin.h"
#include <queue>
#include <iostream>

using namespace std;

GraphTaquin::GraphTaquin(const Sommet& depart) : depart(depart) {
   taille = depart.getTaille();
   final = Sommet::fromTaille(taille);
}

void GraphTaquin::evaluer() {
   queue<Sommet> Q{};
   Q.push(depart);
   marquer(depart, depart);

   while (!Q.empty()) {
      Sommet v = Q.front();
      Q.pop();

      if (v == final) {
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
   if (dejaAtteints.count(s.getId()) > 0) return true;
   dejaAtteints[s.getId()] = parent;
   return false;
}

void GraphTaquin::chaine() {
   Sommet w = final;
   string chaine;
   if (dejaAtteints.count(w.getId()) <= 0) return;
   while (!(dejaAtteints.find(w.getId())->second == w)) {
      chaine.insert(0, to_string(w.posZero()) + " ");
      w = dejaAtteints.find(w.getId())->second;
   }
   cout << chaine << endl;
}
