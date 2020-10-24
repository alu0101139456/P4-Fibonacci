// #ifdef FIBOANALIZER_H
// #define FIBOANALIZER_H

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <set>

class FibonacciAnalizer
{
 private:
  std::ifstream fileIn_;
  std::ofstream fileOut_;
  std::vector<std::string> vFibonacci_;
  std::vector<std::string> vString_;
  std::set<std::string> sString_;

  int longMax_ = -1;

 public:
  FibonacciAnalizer() {std::cout << "NO";};
  FibonacciAnalizer(std::string in, std::string out="output.txt");
  ~FibonacciAnalizer();

 private:
  void readFile();
  void printReadFile();
  void printS();
  void closeFiles();
  void makeSecuenceSet();
  void makeSecuenceVector();
  void exportToFile();
  void printTest();
  int findInVector(std::string &aux);
};




// #endif