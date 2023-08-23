#ifndef SWAN_H
#define SWAN_H

#include "floor.h"
#include "actor.h"

class Swan: public Actor
{
   private:

   public:
      //CONSTRUCTOR
      Swan(int, int);
     
      //MOVE FUNCTIONS
      void move(Floor &, Actor **, int);
      bool check_move(Floor &, int, int);

      //VIRTUAL FUNCTIONS FOR PLAYER CLASS
      char get_action();
      int get_keys();
      int get_apples();
      void add_key();
      void use_key();
      void add_apple();
      void use_apple();

      /* NOTE: in order to be able to access
      those functions for the Player class from
      an Actor pointer, the functions had to be 
      virtual in the Actor class and defined in
      both derived classes*/
};

#endif
