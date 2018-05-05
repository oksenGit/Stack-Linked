#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
};

struct Stack{
	Node *head;
	Node *iter;
};

void MAKENULL(Stack &stack) {
	stack.head = NULL;
	stack.iter = NULL;
}

bool isEmpty(Stack s) {
	return s.head == NULL;
}

void push(Stack &s, int data) {
	if (isEmpty(s)) {
		s.head = new Node;
		s.iter = s.head;
	}
	else {
		s.iter->next = new Node;
		s.iter = s.iter->next;
	}
	s.iter->next = NULL;
	s.iter->data = data;
}

int pop(Stack &s) {
	if (isEmpty(s)) return -1;
	Node *temp = s.head;
	Node *prev = NULL;
	while (temp->next != NULL) {
		prev = temp;
		temp = temp->next;
	}
	if (prev == NULL) 
		MAKENULL(s);
	else {
		s.iter = prev;
		s.iter->next = NULL;
	}
	return temp->data;
}

void printStack(Stack s) {
	Node *temp = s.head;
	int count = -1;
	cout << endl;
	while (temp != NULL) {
		count++;
		cout << count << ": " << temp->data<<endl;
		temp = temp->next;
	}
	cout << endl;
}

int getSize(Stack s) {
	Node *temp = s.head;
	int count = 0;
	while (temp != NULL) {
		count++;
		temp = temp->next;
	}
	return count;
}

int getTop(Stack s) {
	return s.iter->data;
}


void main() {
	Stack stack;
	MAKENULL(stack);
	cout << "Hello!\n-------\n\n";
	cout << "Enter number of the Requierd Action or any other key to exit:-\n";
	while (1) {
		char CMD;
		cout << "\n1-Push\n";
		cout << "2-Pop\n";
		cout << "3-Print Stack\n";
		cout << "4-top Element\n";
		cout << "5-Number of elements in stack\n";

		cout << "Action: ";
		cin >> CMD;

		switch (CMD) {
		case '1':
			int pnum;
			cout << "Enter number to push: ";
			cin >> pnum;
			push(stack, pnum);
	
			break;
		case '2':
			if (!isEmpty(stack))
				cout << pop(stack) << " is poped.\n";
			else cout << "Error: Stack is empty!\n";
			break;
		case '3':
			printStack(stack);
			break;
		case '4':
			if (!isEmpty(stack)) {
				cout << "Top Element of stack: " << getTop(stack) << endl;
			}
			else cout << "Error: Stack is empty.\n";
			break;
		case '5':
			cout << "Number of Elements of stack: " << getSize(stack) << endl;
			break;
		default:
			goto OUT;
		}
	}
OUT:;
}
