#include "actor.h"


Actor::Actor(){
}

Actor::~Actor(){
}

void Actor::set_pos(int r, int c){
   row = r;
   col = c;
}


int Actor::get_row(){
   return row;
}


int Actor::get_col(){
   return col;
}

char Actor::get_symbol(){
   return symbol;
}


//Checks if another actor is on a potential move space
bool Actor::check_move_actors(Floor &f, int r, int c, Actor **a, int n){
   for(int i = 0;  i < n; i++){
      if(row+r == a[i]->get_row() && col+c == a[i]->get_col())
	 return false;
   }
   return true;
}
