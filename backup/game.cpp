#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

#include "game.h"
#include "func.h"

using namespace std;


Game::Game(int n){
   row = col = 0;
   total_floors = n;
   current_floor = 1;
   //num_actors = 0;

}


void Game::read_level(int level_num){
   char c;
   string input;
   string filename = "floor_";

   filename += int_to_string(level_num);
   filename += ".txt";
   ifstream readfile(filename.c_str());

   readfile >> input;
   row = atoi(input.c_str());
   readfile >> input;
   col = atoi(input.c_str());
   readfile.get(c); //Consumes newline character

   tiles = new char*[row];
   for(int i = 0; i < row; i++)
      tiles[i] = new char[col];


   for(int i = 0; i < row; i++){
      getline(readfile, input);
      if(input.length() != col || (readfile.eof() && i < row - 1)){
	 cout << "Invalid file 1" << endl;
	 exit(1);
      }

      for(int j = 0; j < col; j++){
	 c = input.at(j);
	 if(c == ' ' || c == '#' || c == 'E' || c == 'X' 
	       || c == 'L' || c == 'A' || c == 'K' || c == 'D')
	    tiles[i][j] = c;
	 else if(c == 'S'){
	    //add swan
	 }
	 else{
	    cout << "Invalid file 2" << endl;
	    exit(1);
	 }
      }
   }
   readfile >> input;
   if(!readfile.eof()){
      cout << "Invalid file 3" << endl;
      exit(1);
   }
}


void Game::print_level(){
   for(int i = 0; i < row; i++){
      for(int j = 0; j < col; j++){
         /*
	 for(int n = 0; n < num_actors; n++){
	    if( actors[n]->row == i && actors[n]->col == j)
	       cout << actors[n]->symbol;
	 }
	 */
	 cout << tiles[i][j];
      }
      cout << endl;
   }
}
