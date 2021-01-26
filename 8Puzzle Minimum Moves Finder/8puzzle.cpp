//Edward Lee edl6zpg 11/16/2020 8puzzle.cpp

#include "8puzzle.h"

#include <iostream>
#include <vector>
#include <list>
#include <cmath>

/**
 *@author Edward Lee
 */
using namespace std;

/**
 *@brief constructor with double array
 */
puzzle::puzzle(int input[3][3]){
  state = new int *[3];
  for(int i = 0; i<3; i++){
    state[i] = new int [3];
  }
  for(int i = 0; i <3; i++){
    for(int j = 0; j < 3; j++){
      state[i][j] = input[i][j];
    }
  }
  edges = new vector<puzzle*>;
  depth = 0;
  
}

/**
 *@brief constructor with pointer to double array
 */
puzzle::puzzle(int** input){
  state = new int *[3];
  for(int i = 0; i<3; i++){
    state[i] = new int [3];
  }
  for(int i = 0; i <3; i++){
    for(int j = 0; j < 3; j++){
      state[i][j] = input[i][j];
    }
  }
  edges = new vector<puzzle*>;
  depth = 0;
}

/**
 *@brief destructor
 */
puzzle::~puzzle(){
  // delete edges;
  // delete state;
}

/**
 *@brief calculate next possible state
 */
void puzzle::calculateEdges(){
  int blankx,blanky;

  for(int i = 0; i <3; i++){
    for (int j = 0; j < 3; j ++){
      if(state[i][j] == 0){
	blankx = i;
	blanky = j;
      }
    }
  }

  if(blankx != 2){
    //swap with right
    edges->push_back(new puzzle(swap(blankx,blanky,blankx+1,blanky)));
  }
  if(blankx != 0){
    //swap left
    edges->push_back(new puzzle(swap(blankx,blanky,blankx-1,blanky)));

  }
  if(blanky != 0){
    //swap up
    edges->push_back(new puzzle(swap(blankx,blanky,blankx,blanky-1)));

  }
  if(blanky != 2){
    // swap down
    edges->push_back(new puzzle(swap(blankx,blanky,blankx,blanky+1)));

  }
}

/**
 *@brief swap 2 values in state
 */
int** puzzle::swap(int x1, int y1, int x2, int y2){
  int** ret = copyState();
  int temp = ret[x1][y1];
  ret[x1][y1] = ret[x2][y2];
  ret[x2][y2] = temp;
  return ret;
}

int** puzzle::copyState(){
  int** ret;
  ret = new int *[3];
  for(int i = 0; i<3; i++){
    ret[i] = new int [3];
  }
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      ret[i][j] = state[i][j];
      //cout << state[i][j] << " ";
    }
  }
  return ret;
}

/**
 *@brief print the state in array
 */
void puzzle::printState(){
  for(int i = 0; i <3; i++){
    for (int j = 0; j < 3; j ++){
      cout << state[i][j] << " ";
    }
    cout << endl;
  }
}

/**
 *@brief check state if sorted
 */
bool puzzle::sorted(){
  int copy1[9];
  for(int i = 0; i <3; i++){
    for (int j = 0; j < 3; j ++){
      copy1[3*i + j] = state[i][j];
    }
  }

  for(int i = 0; i < 8; i ++){
    if(copy1[i] != i + 1){
      return false;
    }
  }
  return true;

  /*
  int blankx,blanky;

  for(int i = 0; i <3; i++){
    for (int j = 0; j < 3; j ++){
      if(state[i][j] == 0){
	blankx = i;
	blanky = j;
      }
    }
  }
  int ** copy = copyState();
  int copy1[9];
  for(int i = 0; i <3; i++){
    for (int j = 0; j < 3; j ++){
      copy1[3*i + j] = copy[i][j];
    }
  }
 

  int remove = blankx*3 + blanky;
  for(int i = remove; i< 8; i++){
    copy1[i] = copy1[i+1];
  }

 
  for(int i = 0; i < 7; i++){
    if(copy1[i] > copy1[i+1]){
      return false;
    }
  }
  
  return true;
  */
  
}

/**
 *@brief check if solvabel
 */
bool puzzle::solvable(){
int blankx,blanky;

  for(int i = 0; i <3; i++){
    for (int j = 0; j < 3; j ++){
      if(state[i][j] == 0){
	blankx = i;
	blanky = j;
      }
    }
  }
  int ** copy = copyState();
  int copy1[9];
  for(int i = 0; i <3; i++){
    for (int j = 0; j < 3; j ++){
      copy1[3*i + j] = copy[i][j];
    }
  }

  int remove = blankx*3 + blanky;
  for(int i = remove; i< 8; i++){
    copy1[i] = copy1[i+1];
  }
  int inversions = 0;
  for(int i = 1; i <= 8; i++){
    for(int j = 0; j < 8; j++){
      if(copy1[j] == i && i-1 == j){
	break;
      }
      else if(copy1[j] == i){
	inversions++;
	copy1[j] = copy1[i-1];
	copy1[i-1] = i;
	
      }
    }
  }
  if(inversions % 2 == 0){
    return true;
  }
  return false;
  
}
/**
 *@brief create hashcode
 */
int puzzle::hashcode(){
  int ret = 0;
  for(int i = 0;i < 3; i ++){
    for(int j = 0; j <3 ;j ++){
      int inc = 3*i + j;
      ret += state[i][j] * pow(9,inc);
    }
  }
  return ret;
}

