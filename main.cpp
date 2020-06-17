#include <iostream>
#include "Sommet.h"
#include "GraphTaquin.h"

using namespace std;

int main() {
   while (true) {
      string etat;
      cout << "Entrez etat taquin: ";
      getline(std::cin, etat);
      try {
         GraphTaquin graph(Sommet::fromString(etat));
         cout << graph.evaluer() << endl;
      } catch (invalid_argument e) {
         cout << "sequence invalide" << endl;
         cout << e.what() << endl;
      }
   }
   return 0;
}