#include <iostream>
#include "Sommet.h"
#include "GraphTaquin.h"
#include <chrono>

using namespace std;

int main() {

/*   Sommet s1 = {{10, 5, 2, 7, 13, 1, 3, 11, 15, 12, 0, 4, 8, 9, 6, 14}};

   return 0;*/

   std::chrono::time_point<std::chrono::system_clock> start, end;

   while (true) {
      string etat;
      cout << "Entrez etat taquin: ";
      getline(std::cin, etat);
      try {
         start = std::chrono::system_clock::now();
         GraphTaquin graph(Sommet::fromString(etat));
         cout << graph.evaluer() << endl;
         end = std::chrono::system_clock::now();
         int elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>
               (end-start).count();
         cout << elapsed_seconds << " ms" << endl;
      } catch (invalid_argument& e) {
         cout << "sequence invalide" << endl;
         cout << e.what() << endl;
      }
   }
   return 0;
}