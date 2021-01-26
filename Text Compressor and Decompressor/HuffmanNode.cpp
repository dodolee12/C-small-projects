

#include "HuffmanNode.h"
#include <string>

using namespace std;

HuffmanNode::HuffmanNode(){
  left = NULL;
  right = NULL;
}

HuffmanNode::~HuffmanNode(){
  //implement later
  delete left;
  delete right;
  left = NULL;
  right = NULL;
  
}

void HuffmanNode::setCharacter(char c){
  character = c;
}

char HuffmanNode::getCharacter(){
  return character;
}

void HuffmanNode::setFreq(int f){
  freq = f;
}

int HuffmanNode::getFreq(){
  return freq;
}

HuffmanNode* HuffmanNode::getLeft(){
  return left;
}

void HuffmanNode::setLeft(HuffmanNode* left){
  this->left = left;
}

HuffmanNode* HuffmanNode::getRight(){
  return right;
}

void HuffmanNode::setRight(HuffmanNode* right){
  this->right = right;
}



  
    
