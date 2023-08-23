#include <iostream>
#include <fstream>
#include <string>


#include "game.h"


using namespace std;


int main(){

   Game g(1);

   g.read_level(1);
   g.print_level();

   return 1;
}
