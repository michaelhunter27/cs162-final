#include <iostream>
#include <cstdlib>

#include "swan.h"
#include "actor.h"

using namespace std;


//CONSTRUCTOR
//sets position
Swan::Swan(int r, int c){
   row = r;
   col = c;
   symbol = 'S';
}

//Moves swan randomly to valid location
void Swan::move(Floor &f, Actor **a, int n){
   int i;
   i = rand() % 4;
   switch(i){
      case 0:
	 r_move = 0;
	 c_move = 1;
	 break;
      case 1:
	 r_move = 0;
	 c_move = -1;
	 break;
      case 2:
	 r_move = 1;
	 c_move = 0;
	 break;
      case 3:
	 r_move = -1;
	 c_move = 0;
	 break;
   }
   if(check_move(f, r_move, c_move) == false || check_move_actors(f, r_move, c_move, a, n) == false)
      r_move = c_move = 0;
   
   row += r_move;
   col += c_move;
}


//Checks if there is a wall or door
//at the potential move loaction
bool Swan::check_move(Floor &f, int r, int c){
   char ch = f.tiles[row+r][col+c];
   if(ch != '#' && ch != 'E' && ch != 'D' && ch != 'L' && ch != 'X'){
      return true;
   }
   else
      return false;
}

//USELESS VIRTUAL FUNCTIONS
//(SEE HEADER FILE)
char Swan::get_action(){}
int Swan::get_keys(){}
int Swan::get_apples(){}

void Swan::add_key(){}
void Swan::use_key(){}
void Swan::add_apple(){}
void Swan::use_apple(){}



