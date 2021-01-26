//Edward Lee edl6zpg 11/7/2020 HuffmanNode.h

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <string>

class HuffmanNode{
 public:
  HuffmanNode();
  ~HuffmanNode();
  int getFreq();
  void setFreq(int f);
  char getCharacter();
  void setCharacter(char c);
  HuffmanNode* getLeft();
  void setLeft(HuffmanNode* left);
  HuffmanNode* getRight();
  void setRight(HuffmanNode* right);



 private:
  int freq;
  char character;
  HuffmanNode* left;
  HuffmanNode* right;
};

#endif
