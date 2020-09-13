
#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;

class Node   //Dugum sinifi
{   public:

	int data;  //int datasi
	Node *next;  //sonraki dugum
	Node *prev;  //onceki dugum
	
	Node(int,Node*,Node*);  //parametreli kurucu
    Node();  //bos kurucu
    
};


#endif