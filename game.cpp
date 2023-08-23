#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

#include "game.h"
#include "func.h"
#include "swan.h"
#include "player.h"

using namespace std;


//CONSTRUCTOR
Game::Game(int n){
   total_floors = n;
   current_floor = 1;
   actors = new Actor*[1];
   actors[0] = new Player;
   num_actors = 1;
   exit_status = 0;
}


//DESTRUCTOR
Game::~Game(){
   for(int i = 0; i < num_actors; i++)
      delete actors[i];
   delete [] actors;
}


//Reads a level from a file "level_#"
//NOTE: no .txt at end of file name
void Game::read_level(int level_num){
   int a, b, e = 0, l = 0, x = 0;
   char c;
   string input;
   string filename = "floor_";

   filename += int_to_string(level_num);
   //filename += ".txt";
   ifstream readfile(filename.c_str());

   readfile >> input;
   a = atoi(input.c_str());
   readfile >> input;
   b = atoi(input.c_str());
   readfile.get(c); //Consumes newline character

   f = new Floor(a, b);

   for(int i = 0; i < f->row(); i++){
      getline(readfile, input);
      if(input.length() != f->col() || (readfile.eof() && i < f->row() - 1)){
	 cout << "Invalid file (wrong number of characters)" << endl;
	 exit(1);
      }

      for(int j = 0; j < f->col(); j++){
	 c = input.at(j);
	 if(c == ' ' || c == '#' || c == 'L' || c == 'X' 
	       || c == 'A' || c == 'K' || c == 'D')
	    f->tiles[i][j] = c;
	 else if(c == 'E'){
	    e++;
	    actors[0]->set_pos(i, j);
	    e_row = i;
	    e_col = j;
	    f->tiles[i][j] = 'E';
	 }
	 else if(c == 'S'){
	    f->tiles[i][j] = ' ';
	    add_swan(i, j);
	 }
	 else{
	    cout << "Invalid file (invalid character)" << endl;
	    exit(1);
	 }
	 if(c == 'L')
	    l++;
	 if(c == 'X')
	    x++;
	 if(l > 1 || e > 1 || x > 1){
	    cout << "Invalid file (entrance/exit issue)" << endl;
	    exit(1);
	 }
      }
   }
   if(e == 0){
      cout << "Invaid file (no entrance)" << endl;
   }

   if( (l == 1 && level_num == total_floors) || (x == 1 && level_num != total_floors) ){
      cout << "Invalid file (wrong ladder/exit for level #)" << endl;
      exit(1);
   }

   readfile >> input;
   if(!readfile.eof()){
      cout << "Invalid file (too many lines)" << endl;
      exit(1);
   }
}


//Prints the level to the screen
void Game::print_level(){
   bool o;
   system("clear");
   for(int i = 0; i < f->row(); i++){
      for(int j = 0; j < f->col(); j++){
	 o = false;
	 for(int n = 0; n < num_actors; n++){
	    if( actors[n]->get_row() == i && actors[n]->get_col() == j){
	       cout << actors[n]->get_symbol();
	       o = true;
	       break;
	    }
	 }
	 if(!o)
	    cout << f->tiles[i][j];
      }
      cout << endl;
   }
}


//Plays a full set of levels
void Game::play_game(){
   for(int i = 1; i <= total_floors; i++){
      exit_status = 0;

      play_level(i);

      if(exit_status == 2)
	 break;
      else if(exit_status == 3){
	 cout << endl << endl;
	 cout << "YOU WIN!!!!!!";
	 cout << endl << endl << endl;
      }
   }
}



//Plays a single level #n
void Game::play_level(int n){
   int a, b;
   int step = 0;

   read_level(n);

   print_level();

   invisible = 0;
   cont = true;

   while(cont){
      cout << "Steps: " << step << endl;
      cout << "Keys: " << actors[0]->get_keys() << endl;
      cout << "Apples: " << actors[0]->get_apples() << endl;

      /* ADDS A SWAN */
      if(step % 30 == 29){
	 do{
	    a = rand() % f->row();
	    b = rand() % f->col();
	 }while(f->tiles[a][b] != ' ');

	 add_swan(a, b);
      }

      /* MOVES ACTORS */
      for(int i = num_actors-1; i >= 0; i--){
	 actors[i]->move(*f, actors, num_actors);
      }

      /* SWAN-PLAYER INTERACTION */
      send_player_back();

      /* OTHER PLAYER ACTIONS */
      actions();

      print_level();

      if(invisible > 0){
	 cout << "Invisible for " << invisible << " more steps." << endl;
	 invisible--;
      }
      step++;
   }
   /* CLEAN UP */
   remove_swans();
   delete f;
}


//Checks if a swan is by the player
//if so, sends player back to entrance
void Game::send_player_back(){
   for(int i = 1; i < num_actors; i++){
      if( invisible == 0 &&
	    actors[0]->get_row() >= actors[i]->get_row()-1 &&
	    actors[0]->get_row() <= actors[i]->get_row()+1 &&
	    actors[0]->get_col() >= actors[i]->get_col()-1 &&
	    actors[0]->get_col() <= actors[i]->get_col()+1 ){
	 actors[0]->set_pos(e_row, e_col);
	 break;
      }
   }
}


//handles player actions other than moving
//picking up apples and keys, going up a ladder
//quitting, eating an apple, unlocking a door
void Game::actions(){
   if(actors[0]->get_action() == 'e' && actors[0]->get_apples() > 0){
      invisible = 15;
      actors[0]->use_apple();
   }

   if(actors[0]->get_action() == 'u')
      if(f->tiles[actors[0]->get_row()][actors[0]->get_col()] == 'L'){
	 exit_status = 1;
	 cont = false;
      }

   if(actors[0]->get_action() == 'q'){
      exit_status = 2;
      cont = false;
   }

   if(f->tiles[actors[0]->get_row()][actors[0]->get_col()] == 'K'){
      if(actors[0]->get_keys() < 3){
	 actors[0]->add_key();
	 f->tiles[actors[0]->get_row()][actors[0]->get_col()] = ' ';
      }
   }

   if(f->tiles[actors[0]->get_row()][actors[0]->get_col()] == 'D'){
      actors[0]->use_key();
      f->tiles[actors[0]->get_row()][actors[0]->get_col()] = ' ';
   }

   if(f->tiles[actors[0]->get_row()][actors[0]->get_col()] == 'A'){
      if(actors[0]->get_apples() < 2){
	 actors[0]->add_apple();
	 f->tiles[actors[0]->get_row()][actors[0]->get_col()] = ' ';
      }
   }

   if(f->tiles[actors[0]->get_row()][actors[0]->get_col()] == 'X'){
      exit_status = 3;
      cont = false;
   }
}


//Adds a swan to the dynamic array actors
void Game::add_swan(int r, int c){
   Actor **temp = new Actor*[num_actors + 1];
   for(int i = 0; i < num_actors; i++)
      temp[i] = actors[i];
   if(num_actors > 0)
      delete [] actors;
   actors = temp;
   actors[num_actors] = new Swan(r, c);
   num_actors++;
}


//Removes all swans from actors
//deletes and allocates a new player
void Game::remove_swans(){
   Actor **temp = new Actor*[1];
   for(int i = num_actors - 1; i >= 0; i--){
      delete actors[i];
   }
   temp[0] = new Player;
   delete [] actors;
   actors = temp;
   num_actors = 1;
}
