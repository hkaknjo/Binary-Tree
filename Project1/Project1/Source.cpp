#include <iostream>
#include <stdio.h>

using namespace std; 

class Node {
public:
	Node* lchild;
	int data;
	Node* rchild;
	 
};

class Queue {
private: 
	int size;
	int front;
	int rear;
	Node **Q;
public: 
	Queue() {
		front = rear = -1;
		size = 10;
		Q = new  Node*[size];
	}
	Queue(int size) {
		this->size = size;
		front = rear = -1;
		Q = new  Node*[this->size];

	}
	void enqueue(Node* x);
	Node* dequeue();
	void Display();
	int isEmpty() {
		return rear == front;
	}
};
Node* Queue::dequeue() {
	Node* x = NULL;
	if (rear == front) {
		cout << "Stack is empty "  ;
	}
	else {
		x = Q[front + 1];
		front++;
	}
	return x;

}
void Queue::enqueue(Node* x) {
	if (rear == size-1) {
		cout << "Queue is empty ";

	}
	else {

		rear++;
		Q[rear] = x;

	}
}


class Tree {
public:
	Node* root = NULL;
	Tree() {
		root = NULL;

	}
	void CreateTree();
	void Preorder(Node* x);


};

void Tree::CreateTree() {
	Node* p, * t = NULL;
	int x;
	Queue q(100);
	cout << "Unesite root vrijednost: ";
	cin >> x;
	root = new Node;
	root->data = x;
	root->lchild = root->rchild = NULL;
	q.enqueue(root);
	while (!q.isEmpty()) {
		p = q.dequeue();
		cout << "Unesite lijevo dijete od " << p->data;
		cin >> x;
		if (x != -1) {
			t = new Node;
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->lchild = t;
			q.enqueue(t);
		}
		cout << "Unesite desno dijete od " << p->data;
		cin >> x;
		if (x != -1) {
			t = new Node;
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->rchild = t;
			q.enqueue(t);
		}
	}


}

void Tree::Preorder(Node* x) {
	if (x) {
		cout << x->data;
		Preorder(x->lchild);
		Preorder(x->rchild);
	}
	}
	


int main() {
	Tree t;
	t.CreateTree();
	t.Preorder(t.root);

}