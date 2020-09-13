

#include <iostream>
#include "CircularDoublyLinkedList.hpp"
#include "Node.hpp"
#include <string>
#include <fstream>
using namespace std;



int stringToInt(string st)   //string degeri integera ceviren komut blokları
{
	try
	{
		return stoi(st);
	}
	catch (std::invalid_argument const &e)
	{
		return 0;
	}
	catch (std::out_of_range const &e)
	{
		return 0;
	}

}

int main()
{
	
	CircularDoublyLinkedList *list;

	ifstream fileread;                    //dosyadan okuma islemleri yapılır
	fileread.open("Sayilar.txt", ios::in); //sayilar.txt dosyası tanımlanır
	string okunan;                         //dosyadan okuyacagımız satır
	okunan = "";

	if(fileread.is_open())
	{

	while (getline(fileread, okunan))
	{
		list=new CircularDoublyLinkedList();  //her satır icin bir circular doubly linked list olsuturulur

		string str = okunan+" ";         //okudugumuz dosyadan bosluk bosluk alacagimiz icin split mekanizması
		string delimiter = " ";
		int pos = 0;
		string token;
		while ((pos = str.find(delimiter)) != string::npos)
		{
			token = str.substr(0, pos);
			list->addList(stringToInt(token));  //satirdaki her sayiyi algoritmaya gore listeye ekler
			str.erase(0, pos + delimiter.length());
			if (str==" ")
			{
				break;
			}
		}

		list->printascii();
		delete list;

	}


	}

	else
	{
		cout<<"DOSYA BULUNAMADI...LUTFEN KONTROL EDIN...."<<endl;
	}
	

	
	fileread.close();
}
