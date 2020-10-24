

#include "FibonacciAnalizer.h"


FibonacciAnalizer::FibonacciAnalizer(std::string in, std::string out) {

  try {
    fileIn_ = std::ifstream(in);
    fileOut_ = std::ofstream(out);
    readFile();
    printV();
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
      if( (int)aux.size() > longMax_ )
        longMax_ = aux.size();
    }
    while( !fileIn_.eof());
    
  }
}

void FibonacciAnalizer::printV(){
  for (uint i = 0; i < vString_.size(); i++) {
    std::cout << vString_[i] << " ";
  }
  std::cout << "\n";

  makeSecuenceVector();
  
}


void FibonacciAnalizer::printS(){

  std::set<std::string>::iterator it = sString_.begin();
  while (it != sString_.end()) {
    std::cout << (*it) << std::endl;
    it++;
  }
  
  
  std::cout << "\n";
  
}

FibonacciAnalizer::~FibonacciAnalizer() {
  closeFiles();
}

void FibonacciAnalizer::closeFiles() {
  if(fileIn_.is_open()) {
    fileIn_.close();
    std::cout << "Cerrado FILEIN\n";
  }
  if(fileOut_.is_open()) {
    fileOut_.close();
    std::cout << "Cerrado FILEOUT\n";
  }
}

void FibonacciAnalizer::makeSecuenceSet() {
  int longGenerate = 0;
  std::string wo1 = vString_[0];
  std::string wo2 = vString_[1];
  //Insert to set first words
  sString_.insert(wo1);
  sString_.insert(wo2);
  std::string temp;
  //Only make until max size of read file;
  while (longGenerate <= longMax_) {
    temp = wo1 + wo2;
    sString_.insert(temp);
    wo1 = wo2;
    wo2 = temp;    
    longGenerate = temp.size();
  }

}

void FibonacciAnalizer::makeSecuenceVector() {
  int longGenerate = 0;
  std::string wo1 = vString_[0];
  std::string wo2 = vString_[1];
  //Insert to set first words
  vFibonacci_.push_back(wo1);
  vFibonacci_.push_back(wo2);
  std::string temp;
  //Only make until max size of read file;
  while (longGenerate <= longMax_) {
    temp = wo1 + wo2;
    vFibonacci_.push_back(temp);
    wo1 = wo2;
    wo2 = temp;    
    longGenerate = temp.size();
  }

  std::cout << "IMPRIMIENDO VECTOR FIBO" << std::endl;
  for (int i = 0; i < vFibonacci_.size(); i++) {
    std::cout << vFibonacci_[i] << " ";
  }
  

}

