

#include "FibonacciAnalizer.h"


FibonacciAnalizer::FibonacciAnalizer(std::string in, std::string out) {

  try {
    fileIn_ = std::ifstream(in);
    fileOut_ = std::ofstream(out);
    readFile();
    // printReadFile();
    makeSecuenceVector();
    // printTest();
    exportToFile();
    
  }
  catch ( std::exception& e) {
    std::cout << "Failed to load file" << e.what() << std::endl;
  }
}

void FibonacciAnalizer::readFile() {
  std::string aux;
  try {
    if(fileIn_.is_open() && fileIn_) {
      while( !fileIn_.eof()) {
        fileIn_ >> aux;
        if( fileIn_.eof()) break;
        vString_.push_back(aux);
        if( (int)aux.size() > longMax_ )
          longMax_ = aux.size();
      }
    }
    else {
      std::cerr << "Nombre de fichero erroneo. " << std::endl;
    }
       
  }
  catch ( std::exception& e) {
    std::cout << "Failed to read file" << e.what() << std::endl;
  }  
}

void FibonacciAnalizer::printReadFile(){
  for (uint i = 0; i < vString_.size(); i++) {
    std::cout << vString_[i] << " ";
  }
  std::cout << "\n";
  
}


FibonacciAnalizer::~FibonacciAnalizer() {
  closeFiles();
}

void FibonacciAnalizer::closeFiles() {
  if(fileIn_.is_open()) {
    fileIn_.close();

  }
  if(fileOut_.is_open()) {
    fileOut_.close();
 
  }
}

// void FibonacciAnalizer::makeSecuenceSet() {
//   int longGenerate = 0;
//   std::string wo1 = vString_[0];
//   std::string wo2 = vString_[1];
//   //Insert to set first words
//   sString_.insert(wo1);
//   sString_.insert(wo2);
//   std::string temp;
//   //Only make until max size of read file;
//   while (longGenerate <= longMax_) {
//     temp = wo1 + wo2;
//     sString_.insert(temp);
//     wo1 = wo2;
//     wo2 = temp;    
//     longGenerate = temp.size();
//   }

// }

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

  
}

int FibonacciAnalizer::findInVector(std::string &aux) {
  for (int i = 0; i < (int)vFibonacci_.size(); i++) {
    if(vFibonacci_[i] == aux) {
      return i+1;
    }
  }
  return -1;  
}

void FibonacciAnalizer::exportToFile() {
  try {
    int site=0;
    for (int i = 0; i < (int)vString_.size(); i++) {
      site = findInVector(vString_[i]);
      if( site != -1) {
          fileOut_ << vString_[i] << " is the word number " << site << "\n";
        }
        else {
          fileOut_ << vString_[i] << " in position " << i + 1 << " is not a Fibonacci word\n";
        }
      }
  }
  catch ( std::exception& e) {
    std::cout << "Failed to save in file" << e.what() << std::endl;
  }
}

void FibonacciAnalizer::printTest() {
  int site=0;
  for (int i = 0; i < (int)vString_.size(); i++) {
    site = findInVector(vString_[i]);
    if( site != -1) {
      std::cout << vString_[i] << " is the word number " << site << std::endl;
    }
    else {
      std::cout << vString_[i] << " in position " << i + 1 << " is not a Fibonacci word" << std::endl;
    }
  }
}