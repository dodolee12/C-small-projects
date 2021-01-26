
#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
#include <string>
#include "HuffmanNode.h"

using namespace std;

class heap {
 public:
  heap();
  ~heap();
  void insert(HuffmanNode* node);
  HuffmanNode* pop();
  int size();


 private:
  vector<HuffmanNode*> *minheap;
  
};

#endif
