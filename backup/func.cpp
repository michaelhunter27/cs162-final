#include "func.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;


string int_to_string(int n){
   int m;
   string s;
   for(int i = 0; i <= (int) log10((double) n); i++){
      m = n % 10;
      s += (char)((char) m + '0');
      n -= m;
      n/=10;
   }
   return s;
}




//Description: Gets an integer between two integers, a < b
//Output: an integer between the two integer arguments
int get_int(int a, int b){
   string input;
   while (1) {
      getline(cin, input);
      if ( check_int(input)==1 && atoi(input.c_str())>=a && atoi(input.c_str())<=b )
	 return atoi(input.c_str());
      else
	 cout << "try again: ";
   }
}

//Description: Checks if a string is an integer
//Output: 1 if the string is an integer, 0 otherwise
bool check_int(string test){
   int i;
   if (test.size()==0)
      return 0;
   for (i = 0; i < test.size(); i++){
      if ( (test[i] < '0' || test[i] > '9') ){
	 //if ( i != 0 || ( i==0 && test[i] != '-' ) ) //allows negative numbers
	 return 0;
      }
   }
   return 1;
}
