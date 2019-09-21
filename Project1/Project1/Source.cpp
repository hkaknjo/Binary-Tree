#include<iostream>

using namespace std;

void set(int* A, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Input " << i + 1 << ". element of an array: "; cin >> A[i];
	}
}
void print(int* A, int n) {
	cout << "Array elements are: ";
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
}
int getMax(int* A, int n) {
	int max = A[0];
	for (int i = 0; i < n; i++) {
		if (A[i] > max) {
			max = A[i];
		}
	}
	return max;
}

struct node {
	int key;
	node* next;
};

void radix_sort(int* A, int n) {
	int max = getMax(A, n);

	for (int i = 1; max / i > 0; i *= 10) {
		//Making 10 bins and setting them to NULL
		node** bin = new node * [10];
		node** head = new node * [10];
		node** tail = new node * [10];
		for (int j = 0; j < 10; j++) {
			bin[j] = nullptr;
			head[j] = nullptr;
			tail[j] = nullptr;
		}
		//Inserting elements based on their modulo
		for (int j = 0; j < n; j++) {
			node* t = new node;
			t->key = A[j];
			t->next = nullptr;
			if (head[(A[j] / i) % 10] == nullptr) {
				bin[(A[j] / i) % 10] = t;
				head[(A[j] / i) % 10] = bin[(A[j] / i) % 10];
				tail[(A[j] / i) % 10] = bin[(A[j] / i) % 10];
			}
			else {
				tail[(A[j] / i) % 10]->next = t;
				tail[(A[j] / i) % 10] = t;
			}
		}

		int k = 0;
		for (int j = 0; j < 10; j++) {
			while (bin[j] != nullptr) {
				A[k] = bin[j]->key;
				k++;
				bin[j] = bin[j]->next;
			}
			delete[]bin[j]; bin[j] = nullptr;

		}
		delete[]bin; bin = nullptr;
		delete[]head; head = nullptr;
		delete[]tail; tail = nullptr;

	}
}

int main() {


	int n;
	cout << "Input array size: "; cin >> n;
	int* A = new int[n];
	set(A, n);
	radix_sort(A, n);
	print(A, n);

	delete[]A; A = nullptr;
	system("pause");
	return 0;
}