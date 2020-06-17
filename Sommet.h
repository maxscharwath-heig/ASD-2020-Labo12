#ifndef LABO12_SOMMET_H
#define LABO12_SOMMET_H

#include <vector>
#include <list>
#include <ostream>
#include <string>

class Sommet {

   friend std::ostream& operator<<(std::ostream& os, const Sommet& s);

   friend bool operator==(const Sommet& rhs, const Sommet& lhs);

public:
   Sommet(const std::vector<int>& etat);

   std::list<Sommet> adjacent() const;

   std::string toString();

   std::size_t posZero() const;

   static Sommet fromString(const std::string &etat);
   static Sommet fromTaille(std::size_t taille);

   std::size_t getTaille() const;

private:
   std::vector<int> etat;
   std::size_t taille;

};

#endif //LABO12_SOMMET_H
