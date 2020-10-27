/**
    *@file FibonacciAnalizer.h
    *@version 1.0
    *@date 26/10/2020
    *@author Ángel Julián Bolaño Campos
    *@title Palabras de Fibonacci
*/

#pragma once

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

class FibonacciAnalizer
{
 private:
  std::ifstream fileIn_;
  std::ofstream fileOut_;
  std::vector<std::string> vFibonacci_;
  std::vector<std::string> vString_;
  int longMax_ = -1;

 public:
/**
    *@brief Default builder.
*/
  FibonacciAnalizer() {};
/**
    *@brief Principal builder. M
    *@param in Name of file in.
    *@param out Name of file out - "output.txt" as default
*/
  FibonacciAnalizer(std::string in, std::string out="output.txt");
/**
  *@brief Destructo by default.
*/
  ~FibonacciAnalizer();

 private:
/**
    * @brief Open the file and if everything is correct, put the content in a vector
*/
  void readFile();
/**
    * @brief Print what was read on the screen
*/
  void printReadFile();
/**
    * @brief Verify that the files are closed
*/
  void closeFiles();

/**
    * @brief Use the first two characters read to generate the sequence and put it in a vector
*/
  void makeSecuenceVector();
  
/**
    * @brief Export to file 
*/ 

/**
    * @brief Export to file putting if it belongs to the sequence
*/
  void exportToFile();

/**
    * @brief Print on screen putting if it belongs to the sequence
*/
  void printTest();

/**
   * @brief Search the vector for a certain word
   * 
   * @param aux The word to find
   * @return int The position in vector
*/
  int findInVector(std::string &aux);
};




