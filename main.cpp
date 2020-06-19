#include <iostream>
#include "Sommet.h"
#include "GraphTaquin.h"
#include <chrono>

using namespace std;

int main() {
   std::chrono::time_point<std::chrono::system_clock> start, end;
   while (true) {
      string etat;
      cout << "Entrez etat taquin: ";
      getline(std::cin, etat);
      try {
         start = std::chrono::system_clock::now();
         GraphTaquin graph(Sommet::fromString(etat));
         graph.evaluer();
         end = std::chrono::system_clock::now();
         int elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>
               (end-start).count();
         cout << elapsed_seconds << " ms" << endl;
      } catch (invalid_argument& e) {
         cout << "erreur: sequence invalide" << endl;
         cout << e.what() << endl;
      }
   }
   return 0;
}