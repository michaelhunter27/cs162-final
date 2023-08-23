#ifndef GAME_H
#define GAME_H

#include <fstream>
#include <iostream>

using namespace std;

class Game{
   private:
      char **tiles;
      int row;
      int col;
      int total_floors;
      int current_floor;
      
      //Actor **actors;
      //int num_actors;

   public:
      Game(int);
      void read_level(int);
      void print_level();
      void play_game(); //???
      void add_swan(int, int); //coordinates

};


#endif
