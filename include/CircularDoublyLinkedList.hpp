
#ifndef CircularDoublyLinkedList_HPP
#define CircularDoublyLinkedList_HPP
#include "Node.hpp"

class CircularDoublyLinkedList
{
    private:

    Node *head;     //ilk dugum
    int size;       //liste boyutu
    Node *FindPrevNode(int);  //onceki konumu vbulan fonksyon
    int ebob1;
	int ebob2;
    

    public:

    CircularDoublyLinkedList();  
  
    int count();     //liste buyuklugunu veren fonksyon
    bool isEmpty();   //liste bos mu kontrolu yapar
    void add(int);   //listeye ekleme yapar
    void addList(int);   //listeye algoritmaya göre ekler
    void insert(int,int);  //verilen konum bilgisine göre ekleme yapar
    int first();          //ilk dugumu dondurur 
    int last();           //son dugumu dondurur
    int indexOf(int);      //verilen degerin indexi döner
    int indexOf(Node*);    //verilen dugumun indexi döner
    int bigNumber(int,int);  //buyuk sayiyi döndürür
    int smallNumber(int,int);  //kucuk sayiyi döndürür
    void remove(int);         //verilen degeri siler
    void removeAt(int);       //verilen konumdaki dugumu siler
    void printascii();        //sifreyi ekrana bastırır
    int ebobHesapla(int,int); //ebob hesaplar
    void Clear();             //temizleme fonksyonu
    

    ~CircularDoublyLinkedList();  //yıkıcı fonksyon



};




#endif