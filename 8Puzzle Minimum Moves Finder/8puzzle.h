
#ifndef PUZZLE_H
#define PUZZLE_H

#include <vector>

using namespace std;

class puzzle{
 public:
  puzzle(int input[3][3]);
  puzzle(int** input);
  ~puzzle();
  int** state;
  vector<puzzle*>* edges;
  void calculateEdges();
  int** swap(int x1, int y1, int x2, int y2);
  int** copyState();
  void printState();
  bool sorted();
  bool solvable();
  int depth;
  int hashcode();
};



#endif
