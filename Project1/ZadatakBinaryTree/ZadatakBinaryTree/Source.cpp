#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;


/* 
	Potrebno je provjeriti da li je BInary Tree ili je Binary Search tree 
*/
vector<int> g1;
struct node {
	node* left;
	int key;
	node* right;
};
class Queue {
private:
	int front, rear, size;
	node** Q;
public:
	Queue() :
		front{ -1 }, rear{ -1 }, size{ 100 }, Q{ nullptr }{
		Q = new node * [size];
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
	void oslobodi_memoriju(node* x) {
		if (x) {
			oslobodi_memoriju(x->left);
			oslobodi_memoriju(x->right);
			free(x);
		}
	}

	void create() {
		node* t, * p;
		int x;
		root = new node;
		cout << "Unesite root vrijednost: "; cin >> root->key;
		root->left = root->right = nullptr;
		q.enqueue(root);
		while (!q.isEmpty()) {
			p = q.dequeue();
			cout << "Unesite vrijednost lijevog dijeteta od " << p->key << ": ";
			cin >> x;
			if (x != -1) {
				t = new node;
				t->key = x;
				t->left = t->right = nullptr;
				p->left = t;
				q.enqueue(t);
			}
			cout << "Unesite vrijednost desnog dijeteta od " << p->key << ": ";
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

	int count_height(node* x) {
		static int br = 0;
		static int br2 = 0;
		if (x) {
			count_height(x->left);
			count_height(x->right);
			if (x->left)br++;
			if (x->right)br2++;
			if (br > br2)return br;
			else return br2;
		}
	}

	void is_bst(node* x) {
		
		
		
		if (x) {
			is_bst(x->left);
			g1.push_back(x->key);
			is_bst(x->right);
		}
		
	}
};

int main() {

	Tree t;
	t.create();
	t.is_bst(t.root);
	

	if (is_sorted(begin(g1), end(g1))) {
		cout << "Jeste" << endl;
	}
	else {
		cout << "Nije";
	}
	
	system("pause");
	return 0;
}