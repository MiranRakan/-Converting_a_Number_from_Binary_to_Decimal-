#include <bits/stdc++.h>
using namespace std;

// Converting a Number from Binary(base 2) to Decimal(base 10)

// linkedStack class

struct Node
{
	int info;
	Node* link; 
};


class linkedStack
{
private:
	Node* stackTop;
public:
	linkedStack(); //constructor 
	bool isEmpty();
	bool isFull();
	void push(const int &  );
	void pop();
	int top() const;
	void initializeStack();
	void copyStack(const linkedStack&);
	~linkedStack();

};

linkedStack::linkedStack() //constructor 
{
	stackTop = NULL;
}

 bool linkedStack::isEmpty() 
{
	return (stackTop==NULL); 
}//end isEmpty

 bool linkedStack::isFull() 
 {
	 return false;
 }//end isFull

void linkedStack::push(const int &newElement) 
{
	Node* newNode; //pointer to create the new node 
	newNode = new Node; //create the node 

	newNode->info = newElement; //stor newElement in the node 
	newNode->link = stackTop; //insert newNode before stackTop
	stackTop = newNode; //set stackTop to point to the top node


}//end push

 void linkedStack::pop() 
{
	 Node* temp;//pointer to deallocate memory 

	 if (stackTop != NULL) 
	 {
		 temp = stackTop; //set temp to point to the top node 
		 stackTop = stackTop->link; //advance stackTop to the next node
		 delete temp; //delete the top node
	 }
	 else
		 cout << "Cannot remove from an empty stack." << endl;
}//end pop

 int linkedStack ::top() const 
{
	 assert(stackTop != NULL); 

	return stackTop->info;
}//end top

void linkedStack::initializeStack() {
	Node* temp;//pointer to delete the node 

	while (stackTop != NULL) //while there are elements in the stack
	{
		temp = stackTop; //set temp to point to the current node 
		stackTop = stackTop->link; //advance stackTop to the next node 
		delete temp; //deallocate memory occupied by temp
	}
}//end initializeStack

void linkedStack::copyStack( const linkedStack&otherStack) 
{
	Node* newNode, * current, * last;
	if (stackTop != NULL)//if stack is nonempty, make it empty 
		initializeStack();

	if (otherStack.stackTop == NULL) // if other stack is empty
		stackTop == NULL;
	else // if other stack is nonempty 
	{
		current = otherStack.stackTop;

		//copy the stackTop element of the stack 
		stackTop = new Node;
		stackTop->info = current->info;
		stackTop->link = NULL;
		last = stackTop;
		current = current->link;

		while (current != NULL)
		{
			newNode = new Node;
			newNode->info = current->info;
			newNode->link = NULL;
			last->link = newNode;
			last = newNode;
			current = current->link;

		}
	}
}//end copyStack

linkedStack::~linkedStack() //destructor
{
	initializeStack();
}//end destructor
//end linkedStack class 


// number class

class number
{
private :
	long decimal; //number in decimal system
	linkedStack binary; //number in Binary system
public:
	number(); //constructor 
	void readNumber(); //reads the number in binary format as a string then converts it to ints and pushes them to the binary stack
	void toDecimal(); //converts the number from binary to decimal
	void print(); //prints the number in the 2 systems

};

number::number() //constructor 
{
	decimal = 0;
}//end constructor 

void number::readNumber()  
{
	cout << "Please enter the number in binary format (0s and 1s) : " << endl;
	string binary_number;
	cin >> binary_number;
	for (int i = 0; i < binary_number.size(); i++)
	{
		binary.push(binary_number[i] - 48);
	}
}//end readNumber 

void number::toDecimal() 
{
	//use multiplied by 2 algorithm
	linkedStack temp;
	temp.copyStack(binary);
	int sum = 0;
	int index = 0;
	while (!temp.isEmpty())
	{
		sum+=temp.top()* (pow(2, index++));
		temp.pop();
	}
	decimal = sum;

}//end toDecimal

void number::print()
{
	linkedStack temp;
	while (!binary.isEmpty())
	{
		temp.push(binary.top());
		binary.pop();
	}
	while (!temp.isEmpty())
	{
		cout << temp.top();
		temp.pop();
	}
	cout << " is equivelent to " << decimal << endl;
}//end print 

int main()
{
    number obj;
	obj.readNumber();
	obj.toDecimal();
	obj.print();
    return 0;
}