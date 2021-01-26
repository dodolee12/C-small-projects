//Edward Lee edl6zpg 11/16/2020 puzzlesolver.cpp


#include <iostream>
#include <vector>
#include <string>
#include "8puzzle.h"
#include <list>

using namespace std;


//Assuming input is valid
int main(){

  cout << "Enter puzzle" << endl;
  int int1,int2,int3;
  int initialState[3][3];
  for(int i =0; i<3; i++){
    cin >> int1 >> int2 >> int3;
    initialState[i][0] = int1;
    initialState[i][1] = int2;
    initialState[i][2] = int3;
  }

  puzzle initialPuzzle(initialState);
  //find index of blank space
  cout << "Solving puzzle" << endl;
  
  if(!initialPuzzle.solvable()){
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  
  /*
  initialPuzzle.calculateEdges();
  for(puzzle* a: *initialPuzzle.edges){
    a->printState();
  }
  */
  // cout << initialPuzzle.sorted() << endl;
   
  // cout << initialPuzzle.solve() << endl;
 vector<int> hashtable(500009);
  // cout << "table created" << endl;
  
  if(initialPuzzle.sorted()){
    cout << "0" << endl;
    return 0;
  }
  int code = initialPuzzle.hashcode();
  int tableindex = code % 500009;
  hashtable[tableindex] = code;
  list<puzzle*> check;
  check.push_back(&initialPuzzle);
  while(check.size() != 0){
    // cout << check.size() << endl;
    // cout << "before pop" << endl;
    puzzle *toCheck = check.front();
    //cout << toCheck << endl;
    check.pop_front();
    // cout << "after pop" << endl;
    toCheck->calculateEdges();
    // cout << "1" << endl;
    //    toCheck->printState();
    //  cout << " -- " << endl;
    for(puzzle* a: *(toCheck->edges)){
      code = a->hashcode();
      tableindex = code % 500009;
      //  a->printState();
      // cout << code << endl;
      //cout << "2" << endl;
      bool checked = false;
      while(hashtable[tableindex] != 0){
	if(hashtable[tableindex] == code){
	  checked = true;
	  break;
	}
	//   cout << code << endl;

	tableindex += 7;
	tableindex %= 500009;
	
      }
      if(checked){
	continue;
      }
      hashtable[tableindex] = code;
      a->depth = toCheck->depth + 1;
      if(a->sorted()){
	//	a->printState();
	cout << a->depth << endl;
	return 0;
      }
      check.push_back(a);
      //  a->printState();
      // cout << code << endl;
         
	}
    //  cout << " ---------" << endl;
    // cout << check.size() << endl;
    
  }
 
  return 0;
}
