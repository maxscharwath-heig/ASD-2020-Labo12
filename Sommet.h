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

   int change(const Sommet& s);

private:
   std::vector<int> etat;

};


#endif //LABO12_SOMMET_H
