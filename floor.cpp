#include "floor.h"

//CONSTRUCTOR
//sets row and column dimensions
Floor::Floor(int a, int b){
   r = a;
   c = b;
   tiles = new char*[a];
   for(int i = 0; i < a; i++)
      tiles[i] = new char[b];
}


//DESTRUCTOR
//deletes the dynamic array
Floor::~Floor(){
   for(int i = 0; i < r; i++)
      delete [] tiles[i];
   delete [] tiles;
}


int Floor::row(){
   return r;
}


int Floor::col(){
   return c;
}
