

#include "FibonacciAnalizer.h"


FibonacciAnalizer::FibonacciAnalizer(std::string in, std::string out) {

  try {
    fileIn_ = std::ifstream(in);
    fileOut_ = std::ofstream(out);
    readFile();
    print();
  }
  catch ( std::exception& e) {
    std::cout << "Failed to load file" << e.what() << std::endl;
  }
}

void FibonacciAnalizer::readFile() {
  std::string aux;
  if(fileIn_.is_open()) {
    do {
      fileIn_  >> aux;
      
      vString_.push_back(aux);
    }
    while( !fileIn_.eof());
    fileIn_.close();
  }
}

void FibonacciAnalizer::print(){
  for (uint i = 0; i < vString_.size(); i++) {
    std::cout << vString_[i] << " ";
  }
  std::cout << "\n";
  
}