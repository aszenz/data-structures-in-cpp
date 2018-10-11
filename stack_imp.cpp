#include <iostream>
#include <string>
using namespace std;
#include "../CustomFunctions/cliMenu.cpp"
int getInput();
#define max 10
template<class T>

class stack{
private:
	T stck_arr[max];
	int top;
public:
	stack():top(-1){}

	void push(T itm)
	{
		if(top < max)
		{
			stck_arr[++top] = itm;
		}
		else
		{
			// overflow error code goes here.
		}
	}
	T pop()
	{	if(top >= 0)
		{
			return stck_arr[top--];
		}
		else
		{
			// underflow error code goes here
		}
	}
	int getTop(){return top;}
	void displayStck()
	{
		for(int i = 0; i <= top; ++i){cout << stck_arr[i] << ", ";}
		cout << "\n";
	}
};

int main()
{
	stack<int> obj;
	string ms = "Enter option";
	string opt[] = {"Push Stack", "Pop Stack", "View Stack", "Show Top", "Exit", "end"};
	bool run = true;
	while(run)
	{
		createMenu(ms, opt);
		int i = getInput();
		switch(i)
		{
		case 1:
			{
				int j;
				cout << "Enter no to push\n";
				cin >> j ;
				obj.push(j);
				cout << j << " has been pushed onto the stack\n";
				break;
			}
		case 2:
			cout << obj.pop() << " has been popped from the stack\n";
			break;
		case 3:
			cout << "The stack contents are: \n";
			obj.displayStck();
			break;
		case 4:
			cout << "The top of the stack is: " << obj.getTop() << "\n";
			break;
		case 5:
			run = false;
			break;	
		default:
			cout << "Wrong input";
		}
	}
}


int getInput()
{
	int i = -1;
	cin >> i;
	return i;
}
