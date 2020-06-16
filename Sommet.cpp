//
// Created by AnneSo on 16.06.2020.
//

#include "Sommet.h"
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

list<Sommet> Sommet::adjacent() const {
   list<Sommet> voisins;
   int taille = sqrt(etat.size());
   int posZero = distance(etat.begin(), find(etat.begin(), etat.end(), 0));
   int x = posZero % taille;
   int y = posZero / taille;
   if (x + 1 < taille) {
      vector<int> tmp = etat;
      swap(tmp.at(posZero), tmp.at((x + 1) + y * taille));
      voisins.emplace_back(tmp);
   }
   if (x - 1 >= 0) {
      vector<int> tmp = etat;
      swap(tmp.at(posZero), tmp.at((x - 1) + y * taille));
      voisins.emplace_back(tmp);
   }
   if (y + 1 < taille) {
      vector<int> tmp = etat;
      swap(tmp.at(posZero), tmp.at(x + (y + 1) * taille));
      voisins.emplace_back(tmp);
   }
   if (y - 1 >= 0) {
      vector<int> tmp = etat;
      swap(tmp.at(posZero), tmp.at(x + (y - 1) * taille));
      voisins.emplace_back(tmp);
   }
   return voisins;
}

std::ostream& operator<<(ostream& os, const Sommet& s) {
   int taille = sqrt(s.etat.size());
   for (int i = 0; i < s.etat.size(); ++i) {
      os << s.etat.at(i) << ' ';
      if (i % taille == taille - 1) {
         os << endl;
      }
   }
   return os;
}

bool operator==(const Sommet& rhs, const Sommet& lhs) {
   return rhs.etat == lhs.etat;
}

string Sommet::toString() {
   string s;
   for (auto el:etat) {
      s += to_string(el);
      s += ' ';
   }
   return s;
}

int Sommet::change(const Sommet& s) {
   for (size_t i = 0; i < etat.size(); ++i) {
      if (etat[i] != s.etat[i]) {
         return s.etat[i] ? s.etat[i] : etat[i];
      }
   }
   return 0;
}
