#include <iostream>
#include "Sommet.h"
#include "GraphTaquin.h"

using namespace std;

int main() {
   GraphTaquin graph(3);

   cout << graph.V() << endl;

   Sommet s1({6, 4, 0, 3, 1, 2, 8, 5, 7});

/*   for(auto sommet : s1.adjacent()){
      cout << sommet << endl;
   }*/

   cout << graph.evaluer(s1) << endl;

   return 0;
}