#include <iostream>
#include <cstdlib>

#include "player.h"
#include "floor.h"
#include "actor.h"

using namespace std;


//CONSTRUCTOR
Player::Player(){
   symbol = 'P';
   keys = 0;
   apples = 0;
   action = '0';
}


//Gets a move from the user and moves the player
//if possible
void Player::move(Floor &f, Actor **a, int n){
   action = get_move();
   r_move = c_move = 0;
   if(action == 'w'){
      r_move = -1;
      c_move = 0;
   }
   if(action == 'a'){
      r_move = 0;
      c_move = -1;
   }
   if(action == 's'){
      r_move = 1;
      c_move = 0;
   }
   if(action == 'd'){
      r_move = 0;
      c_move = 1;
   }
   if(check_move(f, r_move, c_move) == false || check_move_actors(f, r_move, c_move, a, n) == false)
      r_move = c_move = 0;
   row += r_move;
   col += c_move;
}


//checks if there is a wall or door
//at the potential move space
bool Player::check_move(Floor &f, int r, int c){
   if(f.tiles[row+r][col+c_move] == '#')
      return false;
   else if(f.tiles[row+r][col+c] == 'D' && keys  == 0)
      return false;
   return 1;
}


//Gets a valid move from the user
char Player::get_move(){
   char c;
   string input;
   bool cont = true;
   do{
      getline(cin, input);
      if(input.length() > 0)
      c = input.at(0);
      if(input.length() != 1)
	 cout << "try again." << endl;
      else if(c != 'w' && c != 'a' && c != 's' && c != 'd' 
	    && c != 'e' && c != 'u' && c != 'q')
	 cout << "try again." << endl;
      else
	 cont = false;
   }while(cont);
   return c;
}


/* GETTERS AND SETTERS */
char Player::get_action(){
   return action;
}

int Player::get_keys(){
   return keys;
}

int Player::get_apples(){
   return apples;
}

void Player::add_key(){
   keys++;
}

void Player::use_key(){
   keys--;
}

void Player::add_apple(){
   apples++;
}

void Player::use_apple(){
   apples--;
}



