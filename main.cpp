#include <iostream>
#include "Sommet.h"
#include "GraphTaquin.h"

using namespace std;

int main() {
   while (true) {
      string etat;
      cout << "Entrez etat taquin: ";
      getline(std::cin, etat);
      GraphTaquin graph(Sommet::fromString(etat));
      cout << graph.evaluer() << endl;
   }
   return 0;
}