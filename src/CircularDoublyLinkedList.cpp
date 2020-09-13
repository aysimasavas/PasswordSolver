
#include "CircularDoublyLinkedList.hpp"
#include "Node.hpp"

CircularDoublyLinkedList::CircularDoublyLinkedList() //kurucuda ilk degerler atanir
{
	head = NULL;
	size = 0;
}
Node *CircularDoublyLinkedList::FindPrevNode(int index) //indexe gore onceki dugum bulur
{
	Node *prev = head;
	int i = 1;
	for (Node *itr = head; i != index; itr = itr->next, i++)
	{
		prev = prev->next;
	}
	return prev;
}
void CircularDoublyLinkedList::insert(int index, int item)
{
	if (index == 0)
	{
		if (size == 0)

		{
			head = new Node(item, NULL, NULL);
			head->next = head->prev = head;
		}
		else
		{
			head = new Node(item, head, head->prev);
			head->next->prev = head;
			head->prev->next = head;
		}
	}
	else
	{
		Node *prv = FindPrevNode(index);
		prv->next = new Node(item, prv->next, prv);
		prv->next->next->prev = prv->next;
	}
	size++;
}

void CircularDoublyLinkedList::add(int item)
{
	insert(size, item);
}

void CircularDoublyLinkedList::addList(int item) //algoritmaya gore ekleme yapılır
{
	
	int mod=0;

	if (isEmpty())              //liste bos ise degeri ilk dugume ekler
	{
		insert(size, item);
		ebob1=0;               //ebob 0 olur.
	}

	else                      //liste bos degilse...
	{

		Node *lastNode = FindPrevNode(1);  //dugum olusturulur
		

		while (true)
		{
			ebob2= ebobHesapla(item, lastNode->data);  //ebob hesaplanir
			

			if(item==0||lastNode->data==0)    //eger item veya bir sonraki data 0 ise mod 0 olur
			{
				mod=0;
				
			}
			else           //degil ise mod hesaplanır
			{
				mod=bigNumber(item, lastNode->data)%smallNumber(item, lastNode->data);
			}
			
			//cout<<"item:"<<item<<endl<<"last node data"<<lastNode->data<<endl<< "ebob2"<<ebob2<<endl<<"ebob1"<<ebob1<<endl<<"index"<<indexOf(lastNode->data)<<endl<<"mod"<<mod<<endl<<"size"<<size<<endl<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        
			if (ebob2>=ebob1||indexOf(lastNode)==size-1)  //ebob bir önceki ebobdan buyukse veya gidecek baska dugum yoksa dugumde kal
			{

				if(ebob2>ebob1)  //son ebob degerini guncelle
				{
				ebob1=ebob2;
				}
								
				if (mod!=0)     //mod 0 a esit degilse
				{
					if(mod>indexOf(lastNode))   //mod son dugum konumundan buyukse liste basına yerlestir
					{
						insert(0,item);	
						break;
					}
					else
					{						
						insert((indexOf(lastNode)-mod+1),item);  //degilse mod degeri kadar sola git yerlestir
						
						break;
					}
					
				}
				else //mod 0 a esit ise
				{
					
					if (indexOf(lastNode) != size-1)
                        insert(indexOf(lastNode), item);
                    else
                        insert(indexOf(lastNode)+1, item);  //sag tarafa ekle
			
					break;
				}
	
			}
			else
			{

				lastNode=lastNode->next;

			}
		}
	}
}

int CircularDoublyLinkedList::count()
{
	return size;
}

bool CircularDoublyLinkedList::isEmpty()
{
	return size == 0;
}

int CircularDoublyLinkedList::first()
{
	return head->data;
}
int CircularDoublyLinkedList::last()
{
	return head->prev->data;
}

int CircularDoublyLinkedList::indexOf(int item)
{
	int index = 0;
	for (Node *itr = head; index < size; itr = itr->next)
	{
		if (itr->data == item)
			return index;
		index++;
	}
	return -1;
}
int CircularDoublyLinkedList::indexOf(Node *item)
{
	int index = 0;
	for (Node *itr = head; index < size; itr = itr->next)
	{
		if (itr == item)
			return index;
		index++;
	}
	return -1;
}

void CircularDoublyLinkedList::remove(int item)
{
	int index = indexOf(item);

	removeAt(index);
}

void CircularDoublyLinkedList::removeAt(int index)
{
	Node *del;
	if (index == 0)
	{
		del = head;
		if (size == 1)
		{
			head = head->next = head->prev = NULL;
		}
		else
		{
			head = head->next;
			head->prev = del->prev;
			del->prev->next = head;
		}
	}
	else
	{
		Node *prv = FindPrevNode(index);
		del = prv->next;
		prv->next = del->next;
		del->next->prev = prv;
	}
	size--;
	delete del;
}

int CircularDoublyLinkedList::ebobHesapla(int num1, int num2)
{
	int ebob;

	if(num1==0||num2==0)
	{
     return 0;
	}

	if (num1>num2)

		ebob = num1;

	else
	{
		ebob = num2;
	}

	for (ebob; ebob>0; ebob--)
	{
		if ((num1%ebob==0) && (num2%ebob==0))
		{
			
			break;
		}
	}
	return ebob;

}
int CircularDoublyLinkedList::bigNumber(int num1, int num2)
{

	if (num1>num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}


}
int CircularDoublyLinkedList::smallNumber(int num1, int num2)
{
	if (num1>num2)
	{
		return num2;
	}
	else
	{
		return num1;
	}

}

void CircularDoublyLinkedList::printascii()
{
	int index=0;
	int i = 0;
    cout<<"PASSWORD: ";
	for (Node *itr = FindPrevNode(index + 1); i < size; itr = itr->next, i++)

		cout<<(char)itr->data;
	cout << endl;
}

void CircularDoublyLinkedList::Clear()
{
	while (!isEmpty())
	{
		removeAt(0);
	}
}


CircularDoublyLinkedList::~CircularDoublyLinkedList()
{
	Clear();
	delete head;
}
