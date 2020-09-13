
#include "Node.hpp"

Node::Node(int data,Node* next,Node* prev)
{
    this->data=data;
    this->next=next;
    this->prev=prev;
}
Node::Node()
{
    this->data=0;
    this->next=NULL;
    this->prev=NULL;
}