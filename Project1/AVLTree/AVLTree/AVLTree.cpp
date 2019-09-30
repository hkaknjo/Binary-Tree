#include <iostream>
#include <algorithm>
#include <math.h>


using namespace std;



class Node {
public:
	Node* rchild;
	Node* lchild;
	int key;
	int height;

};

class Tree {
public:
	Node* root = NULL;
	Tree() :
		root{ NULL }{}
	~Tree() {
		oslobodi_memoriju(root);
	}
	

	void oslobodi_memoriju(Node* root) {
		if (root) {
			oslobodi_memoriju(root->lchild);
			oslobodi_memoriju(root->rchild);
			free(root);
		}
	}

	int count_height(Node* x) {
		int hl, hr;
		hl = x && x->lchild ? x->lchild->height : 0;
		hr = x && x->rchild ? x->rchild->height : 0;
		
		return hl > hr ? hl + 1: hr +1 ;
	}

	int balance_factor(Node* x) {
		int hl, hr;
		hl = x && x->lchild ? x->lchild->height : 0;
		hr = x && x->rchild ? x->rchild->height : 0;

		return hl - hr;
	}
	Node* LLrotation(Node* x) {
		Node* t = x->lchild;
		x->lchild = t->rchild;
		t->rchild = x;
		root = t;
		return t;
	}

	Node* Balance(Node* x) {
		if (balance_factor(x) == 2 && balance_factor(x->lchild) == 1) {
			return LLrotation(x);
		}
		
		return x;
	}
	void print_inorder(Node* x) {
		if (x) {
			print_inorder(x->lchild);
			cout << x->key << " ";
			print_inorder(x->rchild);
		}
	}

	Node* RInsert(Node* p, int key) {
		if (p == nullptr) {
			p = new Node;
			p->key = key;
			p->height = 1;
			p->rchild = p->lchild = NULL;
			return p;
		}
		if (key == p->key) {
			return p;
		}
		else if (key < p->key) {
			p->lchild = RInsert(p->lchild, key);
		}
		else if(key>p->key){
			p->rchild = RInsert(p->rchild, key);
		}

		p->height = count_height(p);
		Balance(p);

		
		
	}
};
int main() {
	Tree t;
	int key;
	cout << "Unesite root vrijednost: "; cin >> key;
	t.root = t.RInsert(t.root, key);
	while (key != -1) {
		cout << "Unesite vrijednost vrha: "; cin >> key;
		if (key == -1)break;
		t.RInsert(t.root, key);
	}
	cout << "Inorder: "; t.print_inorder(t.root); cout << endl;


	return 0;
}