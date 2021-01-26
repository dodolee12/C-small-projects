
#include "heap.h"

using namespace std;

heap::heap(){
  minheap = new vector<HuffmanNode*>;
}

heap::~heap(){
  for(HuffmanNode* a : *minheap){
    delete a;
  }
  delete minheap;
}

void heap::insert(HuffmanNode* node){
  minheap->push_back(node);

  int pos = minheap->size();
  while(pos != 1 && ((*minheap)[pos - 1]->getFreq()) < ((*minheap)[pos/2 - 1]->getFreq())){
    HuffmanNode* temp = (*minheap)[pos - 1];
    (*minheap)[pos - 1] = (*minheap)[pos/2 - 1];
    (*minheap)[pos/2 - 1] = temp;
    pos /= 2;
  }
  


}

HuffmanNode* heap::pop(){
  HuffmanNode* ret = (*minheap)[0];
  (*minheap)[0] = (*minheap)[minheap->size()-1];
  minheap->pop_back();
  int pos = 1;
  while(pos <= (minheap->size()/2) && (((*minheap)[pos -1] -> getFreq()) > ((*minheap)[2*pos -1] -> getFreq()) ||( ((*minheap)[pos - 1] ->getFreq()) > ((*minheap)[2*pos] -> getFreq())))){
    if(((*minheap)[2*pos - 1] -> getFreq()) < ((*minheap)[2*pos] -> getFreq())){
      HuffmanNode* temp = (*minheap)[pos - 1];
      (*minheap)[pos - 1] = (*minheap)[2*pos - 1];
      (*minheap)[2*pos - 1] = temp;
      pos = 2*pos;
    }
    else{
      HuffmanNode* temp = (*minheap)[pos - 1];
      (*minheap)[pos - 1] = (*minheap)[2*pos];
      (*minheap)[2*pos] = temp;
       pos = 2*pos + 1;
    }
  }
  return ret;
}

int heap::size(){
  return minheap->size();
}

