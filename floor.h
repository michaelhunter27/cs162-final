#ifndef FLOOR_H
#define FLOOR_H

class Floor
{
   private:
      int r;
      int c;
   public:
      char **tiles;
      
      //CONSTRUCTOR AND DESTRUCTOR
      Floor(int, int);
      ~Floor();

      //ACCESSORS
      int row();
      int col();
};


#endif
