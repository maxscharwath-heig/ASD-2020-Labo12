#include <iostream>
#include "Sommet.h"
#include "GraphTaquin.h"

using namespace std;

int main() {
   GraphTaquin graph(3, {{2, 6, 7, 1, 3, 4, 8, 5, 0}});
   
   cout << graph.V() << endl;


/*   for(auto sommet : s1.adjacent()){
      cout << sommet << endl;
   }*/

   cout << graph.evaluer() << endl;

   return 0;
}