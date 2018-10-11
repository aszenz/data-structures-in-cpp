#include <iostream>
struct node{
	int data;
	node* next;
};
class linkedList
{
public:
	linkedList():start{nullptr} {
	}
	int countNodes();
	void insertAt(const int&, const int&);
	void deleteAt(const int&);
	void printAll();
	int& operator[](const int&);
private:
	node* start;
	bool checkInsPosValid(const int&);
	bool checkDelPosValid(const int&);
	node* moveTo(const int&);
};
bool linkedList::checkInsPosValid(const int& ps)
{
	if(ps >= 0 && ps <= countNodes())
		return true;
	return false;
}
bool linkedList::checkDelPosValid(const int& ps)
{
	if(ps >= 0 && ps < countNodes())
		return true;
	return false;
}
// returns a pointer to the node at position ps-1
node* linkedList::moveTo(const int& ps)
{
	node* temp = start;
	for(int i = 1; i < ps; ++i)
	{
		temp = temp->next;
	}
	return temp;
}
int linkedList::countNodes()
{
	int c = 0;
	node* temp = start;
	while(temp != nullptr)
	{
		++c;
		temp = temp->next;
	}
	return c;
}
void linkedList::insertAt(const int& ps, const int& d)
{
	if(checkInsPosValid(ps))
	{
		node* newNode = new node;
		if(ps == 0)
		{		
			newNode->next = start;
			start = newNode;
			start->data = d;
		}
		else
		{
			node* p = moveTo(ps);
			newNode->next = p->next;
			p->next = newNode;
			newNode->data = d;
		}
	}
}
void linkedList::deleteAt(const int& ps)
{
	if(checkDelPosValid(ps))
	{
		if(start == nullptr)
		{
			return;
		}
		if(ps == 0)
		{
			node* temp = start;
			start = start->next;
			delete temp;
			return;
		}
		node* p = moveTo(ps);
		node* del = p->next;
		p->next = p->next->next;
		delete del;
	}
}
void linkedList::printAll()
{
	node* temp = start;
	std::cout << "\n";
	while(temp != nullptr)
	{
		std::cout << temp->data << ", ";
		temp = temp->next;
	}
	std::cout << "\n";
}
int& linkedList::operator[](const int& ps)
{
	if(checkDelPosValid(ps))
	{
		if(ps == 0)
		{
			return start->data;
		}
		node* p = moveTo(ps);
		return p->next->data;
	}
}
int main()
{
	linkedList list1;
	std::cout << "nodes: " << list1.countNodes() << "\n";
	int a = 0;
	list1.insertAt(a, 35);
	std::cout << "nodes: " << list1.countNodes() << "\n";
	list1.insertAt(1, 25);
	list1.insertAt(2, 10);
	std::cout << "nodes: " << list1.countNodes() << "\n";
	list1.insertAt(2, 110);
	std::cout << "nodes: " << list1.countNodes() << "\n";
	list1.insertAt(3,56);
	std::cout << "nodes: " << list1.countNodes() << "\n";
	list1.insertAt(0,67);
	std::cout << "nodes: " << list1.countNodes() << "\n";
	list1.printAll();
	list1.deleteAt(5);
	list1.deleteAt(0);
	list1.deleteAt(2);
	list1.printAll();
	std::cout << "\n" << list1[2] << "," << list1[0] << ","<< list1[2]; 
	return 0;
}