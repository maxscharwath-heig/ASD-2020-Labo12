//
// Created by AnneSo on 16.06.2020.
//

#include "Sommet.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>

using namespace std;

Sommet::Sommet(const vector<int> &etat) : etat(etat) {
   taille = sqrt(etat.size());
};

std::size_t Sommet::getTaille() const {
   return taille;
}

list<Sommet> Sommet::adjacent() const {
   list<Sommet> voisins;
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
   for (int i = 0; i < s.etat.size(); ++i) {
      os << s.etat.at(i) << ' ';
      if (i % s.taille == s.taille - 1) {
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

int Sommet::change() {
   for (size_t i = 0; i < etat.size(); ++i) {
      if (etat[i] == 0) {
         return i;
      }
   }
   return 0;
}

Sommet Sommet::fromString(const string& etat) {
   std::stringstream ss( etat );
   int number;
   std::vector<int> myNumbers;
   while ( ss >> number )
      myNumbers.push_back( number );
   return Sommet(myNumbers);
}

