//
// Created by AnneSo on 16.06.2020.
//

#include "Sommet.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

Sommet::Sommet(const vector<int>& etat) : etat(etat) {
   taille = sqrt(etat.size());

   if (
         etat.empty() ||
         taille * taille != etat.size() ||
         find(etat.begin(), etat.end(), 0) == etat.end()
         ) {
      throw invalid_argument("etat invalide");
   }
};

std::size_t Sommet::getTaille() const {
   return taille;
}

list<Sommet> Sommet::adjacent() const {
   list<Sommet> voisins;
   size_t pos = posZero();
   int x = pos % taille;
   int y = pos / taille;
   if (x + 1 < taille) {
      vector<int> tmp = etat;
      swap(tmp.at(pos), tmp.at((x + 1) + y * taille));
      voisins.emplace_back(tmp);
   }
   if (x - 1 >= 0) {
      vector<int> tmp = etat;
      swap(tmp.at(pos), tmp.at((x - 1) + y * taille));
      voisins.emplace_back(tmp);
   }
   if (y + 1 < taille) {
      vector<int> tmp = etat;
      swap(tmp.at(pos), tmp.at(x + (y + 1) * taille));
      voisins.emplace_back(tmp);
   }
   if (y - 1 >= 0) {
      vector<int> tmp = etat;
      swap(tmp.at(pos), tmp.at(x + (y - 1) * taille));
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

size_t Sommet::posZero() const{
   return distance(etat.begin(), find(etat.begin(), etat.end(), 0));
}

Sommet Sommet::fromString(const string& etat) {
   stringstream ss(etat);
   int number;
   vector<int> tab;
   while (ss >> number) {
      tab.push_back(number);
   }
   return Sommet(tab);
}

Sommet Sommet::fromTaille(std::size_t taille) {
   vector<int> tab;
   for (std::size_t i = 0; i < taille*taille; ++i)
      tab.push_back(i);
   return Sommet(tab);
}

