#include<iostream>

/* Sink Zeros in Binary Tree
Given a binary tree containing many zero nodes, sink nodes having zero value to the bottom of the sub-tree rooted at that node.
In other words, the output binary tree should not contain any node having zero value that is parent of node having non-zero value.*/
using namespace std;

struct node {
	node* left;
	int key;
	node* right;
};
class Queue {
public:
	Queue() :
		front{ -1 }, rear{ -1 }, size{ 100 }, Q{ nullptr }{
		Q = new node * [100];
	}
	~Queue() {
		delete[]Q; Q = nullptr;
	}

	void enqueue(node * x) {
		if (rear == size - 1) {
			cout << "Queue is full! " << endl;
		}
		else {
			rear++;
			Q[rear] = x;
		}
	}

	node * dequeue() {
		node* x = nullptr;
		if (front == size - 1) {
			cout << "Queue is empty! " << endl;
		}
		else {
			front++;
			x = Q[front];
		}
		return x;
	}

	int isEmpty() {
		return front == rear;
	}

private:
	int front, rear, size;
	node** Q;
};
class Tree {
public:
	node* root;
	Queue q;

	Tree() :
		root{ nullptr }, q{}{}
	~Tree() {
		oslobodi_memoriju(root);
	}

	void oslobodi_memoriju(node* x);
	void create();
	void sink(node* x) {
		if (x) {
			if (x->left && x->left->key > 0) {
				swap(x->key, x->left->key);
				sink(x->left);
			}
			else if (x->right && x->right->key > 0) {
				swap(x->key, x->right->key);
					sink(x->right);
			}
		}
	
	}


	void sink_nodes(node* x) {
		if (x) {
			sink_nodes(x->left);
			sink_nodes(x->right);
			if (x->key == 0) { sink(x); }
			
		}
	}
	void print_inorder(node* x) {
		if (x) {
			print_inorder(x->left);
			cout << x->key << " ";
			print_inorder(x->right);
		}
	}
};
void Tree::oslobodi_memoriju(node* x) {
	if (x != nullptr) {
		oslobodi_memoriju(x->left);
		oslobodi_memoriju(x->right);
		free(x);
	}
}
void Tree::create() {
	node* p, * t;
	int x;
	root = new node;
	cout << "Unesite root vrijednost: "; cin >> root->key;
	root->left = root->right = nullptr;
	q.enqueue(root);
	while (!q.isEmpty()) {
		p = q.dequeue();
		cout << "Unesite vrijednost lijevog djeteta od " << p->key << ": ";
		cin >> x;
		if (x != -1) {
			t = new node;
			t->key = x;
			t->left = t->right = nullptr;
			p->left = t;
			q.enqueue(t);
		}
		cout << "Unesite vrijednost desnog djeteta od " << p->key << ": ";
		cin >> x;
		if (x != -1) {
			t = new node;
			t->key = x;
			t->left = t->right = nullptr;
			p->right = t;
			q.enqueue(t);
		}
	}
}

int main() {

	Tree t;
	t.create();
	cout << "Before sinking: "; t.print_inorder(t.root); cout << endl;
	t.sink_nodes(t.root);
	cout << "After sinking: "; t.print_inorder(t.root); cout << endl;

	system("pause");
	return 0;
}
