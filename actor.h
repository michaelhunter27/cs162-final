#ifndef ACTOR_H
#define ACTOR_H

#include "floor.h"

class Actor
{
   protected:
      int row;
      int col;
      char symbol;
      int r_move;
      int c_move;

   public:
      Actor();
      ~Actor();
     
      //GETTERS AND SETTERS
      void set_pos(int, int);
      int get_row();
      int get_col();
      char get_symbol();
      
      //MOVE CHECKING
      bool check_move_actors(Floor &, int, int, Actor **, int);
      virtual void move(Floor &, Actor **, int) = 0;
      virtual bool check_move(Floor &, int, int) = 0;

      //FUNCTIONS FOR PLAYER
      virtual char get_action() = 0;
      virtual int get_keys() = 0;
      virtual int get_apples() = 0;
      
      virtual void add_key() = 0;
      virtual void use_key() = 0;
      virtual void add_apple() = 0;
      virtual void use_apple() = 0;
      
      /* NOTE: compiler required all of the functions
      for Player class to be virtual to be able to
      access them from an Actor pointer */
};

#endif
