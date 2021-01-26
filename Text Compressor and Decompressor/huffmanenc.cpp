
#include "heap.h"
#include "HuffmanNode.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <map>

using namespace std;





void fillhelper(HuffmanNode* node, map<char,string> &coder, string string){
  if(node->getLeft() == NULL && node->getLeft() == NULL){
    coder.emplace(node->getCharacter(),string);
    return;
  }
  fillhelper(node->getLeft(),coder,string + "0");
  fillhelper(node->getRight(),coder,string + "1");
}

map<char,string> fillcode(HuffmanNode* node){
  map<char,string> coder;
  fillhelper(node,coder,"");
  return coder;

}

// we want to use parameters
int main(int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // ifstream stands for "input file stream"
    ifstream file(argv[1]);
    // if the file wasn't found, output an error message and exit
    if (!file.is_open()) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }
    //read file and insert frequencies
    char g;
    vector<int> freqs(95);
    while(file.get(g)){
      if((int) g > 31 && (int) g < 127){
	int index = (int) g - 32;
	freqs[index] += 1;
      }
    }
    

    //fill heap
    heap heap;
    for(int i = 0; i < freqs.size(); i++){
      if(freqs[i] > 0){
	HuffmanNode* node = new HuffmanNode;
	char c = (char) i + 32;
	node->setCharacter(c);
	node->setFreq(freqs[i]);
	heap.insert(node);
      }
    }
    
    //empty heap and create tree;
    while(heap.size() > 1){
      HuffmanNode* node1 = heap.pop();
      HuffmanNode* node2 = heap.pop();
      HuffmanNode* combined = new HuffmanNode;
      combined->setLeft(node1);
      combined->setRight(node2);
      combined->setFreq(node1->getFreq() + node2->getFreq());
      heap.insert(combined);
    }
    HuffmanNode* root = heap.pop();
    map<char,string> coder = fillcode(root);
    for(auto const& element: coder){
      if(element.first == ' '){
	cout << "space " << coder[element.first] << endl;
	continue;
      }
      cout << element.first << " " << coder[element.first] << endl;
    }

      

    cout << "----------------------------------------" << endl;

    file.clear();
    file.seekg(0);

    string encoded = "";
    int bitsinfile = 0;
    int count = 0;
    while(file.get(g)){
      if((int) g > 31 && (int) g < 127){
	encoded += coder[g] + " ";
	count++;
	bitsinfile += coder[g].size();
      }
    }

    cout << encoded << endl;

    cout << "----------------------------------------" << endl;

    cout << "There are a total of " << count << " symbols that are encoded." << endl;
    cout << "There are " << coder.size() << " distinct symbols used." << endl;
    cout << "There were " << count * 8 << " bits in the original file." << endl;
    cout << "There were " << bitsinfile << " bits in the compressed file." << endl;
    double compression = (double) count * 8 / (double) bitsinfile;
    cout.precision(5);
    cout << "This gives a compression ratio of " << fixed << compression << "." << endl;
    double bitperchar = (double)bitsinfile / (double) count;
    cout << "The cost of the Huffman tree is " << fixed << bitperchar << " bits per character." << endl;

    delete root;
    
    
}
