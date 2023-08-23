#ifndef GAME_H
#define GAME_H

#include "actor.h"
#include "floor.h"


class Game{
   private:
      Floor *f;
      int total_floors;
      int current_floor;
      int e_row;
      int e_col;
      int invisible;
      int exit_status;
      bool cont;

      Actor **actors;
      int num_actors;

   public:
      Game(int);
      ~Game();
      
      void read_level(int);
      
      void play_game();
      void play_level(int);
      
      void print_level();

      void send_player_back();
      void actions();

      void add_swan(int, int);
      void remove_swans();

};

#endif
