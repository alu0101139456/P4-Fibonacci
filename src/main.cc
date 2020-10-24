#include <iostream>
#include "FibonacciAnalizer.h"
#include <string>

void help();



int main(int argc, char *argv[]) {



  if ( argc == 2 ) {
    FibonacciAnalizer( argv[1],"" );
  }
  else if ( argc == 3) {
    FibonacciAnalizer( argv[1], argv[2]);
  }
  else {
    help();
  }
    
}



void help() {
  system("clear");
  std::cout << "\nHELP";
  std::cout << "\nDESCRIPTION     \n";
  std::cout << "fibonacci_words [FILE INPUT] [FILE_OUTPUT]     \n";
  std::cout << "fibonacci_words [FILE INPUT] \n";
  std::cout << "Default: output.txt";

  std::cout << "\n";
}
