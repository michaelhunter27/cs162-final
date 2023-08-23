#ifndef PLAYER_H
#define PLAYER_H

#include "floor.h"
#include "actor.h"

class Player: public Actor
{
   private:
      int keys;
      int apples;
      char action;
   public:
      //CONSTRUCTOR
      Player();

      //MOVE FUNCTIONS
      void move(Floor &, Actor **, int);
      bool check_move(Floor &, int, int);
      char get_move();
      
      //GETTERS
      char get_action();
      int get_keys();
      int get_apples();
      
      //SETTERS
      void add_key();
      void use_key();
      void add_apple();
      void use_apple();
};

#endif
