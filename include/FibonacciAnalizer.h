// #ifdef FIBOANALIZER_H
// #define FIBOANALIZER_H

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

class FibonacciAnalizer
{
 private:
  std::ifstream fileIn_;
  std::ofstream fileOut_;

  std::vector<std::string> vString_;


 public:
  FibonacciAnalizer() {std::cout << "NO";};
  FibonacciAnalizer(std::string in, std::string out="output.txt");
  ~FibonacciAnalizer() {}

 private:
  void readFile();
  void print();

};




// #endif