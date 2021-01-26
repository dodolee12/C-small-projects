//Edward Lee edl6zpg 11/7/2020 heap.h

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
