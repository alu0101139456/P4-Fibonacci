/*
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Computabilidad y Algoritmia
*
* @author: Ángel Julián Bolaño Campos
* @e-mail:  alu0101139456@ull.edu.es
* @compilation: make
* @date: 27 octubre 2020
* @brief: Read input file and generate an output file indicating if the read words belong to the Fibonacci sequence  
*/

#include <iostream>
#include "FibonacciAnalizer.h"
#include <string>

void help();



int main(int argc, char *argv[]) {



  if ( argc == 2 ) {
    FibonacciAnalizer( argv[1],"output.txt" );
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
