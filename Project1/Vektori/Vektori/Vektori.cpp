#include<iostream>
#include<algorithm>
#include<vector>	

using namespace std;


/* Setanje i ispisivanje vektora*/
void set(vector<int>& A, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Unesite " << i + 1 << ". clan niza: "; cin >> A.at(i);
	}
}
void print(vector<int>A) {
	cout << A.front() << endl;
	
	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}
int main() {

	int n;
	cout << "Unesite broj clanova niza: "; cin >> n;
	vector<*int>v(n);
	set(v, n);
	print(v);


	system("pause");
	return 0;
}