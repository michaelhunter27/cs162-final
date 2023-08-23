/************************************************
 * Name: Michael Hunter
 * Class: CS 162
 * Program: Final Project
 * Date: March 12, 2016
 * Description: Maze game.  Player moves through
 *    a maze to a ladder, eventually to an exit.
 *    Includes deadly swans, doors, keys,
 *    apples, etc.  Requires commandline
 *    argument of number of levels to play.
 *    Files "floor_1", "floor_2", etc. must be
 *    included in same directory.
 ***********************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "game.h"

using namespace std;


int main(int argc, char *argv[]){
   srand(time(NULL));

   if(argc != 2)
      return -1;

   int num = atoi(argv[1]);

   Game g(num);

   g.play_game();

   return 0;
}
