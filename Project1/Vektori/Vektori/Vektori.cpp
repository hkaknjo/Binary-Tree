#include<iostream>
#include<algorithm>
#include<vector>	

using namespace std;




int main() {
	int n;
	cout << "Unesite koliko zelite redova da ima matrica: ";
	cin >> n;
	vector<vector<int>> row(n);
	int kolona;
	for (int i = 0; i < n; i++) {
		
		
		cout << "Unesite koliko svaki od redova ima kolona: ";
		cin >> kolona;
		row[i] = vector<int> (kolona);
	
		for (int j = 0; j < kolona; j++) {
			cout << "Unesite [" << i << "][" << j << "] clan: ";
			cin >> row[i][j];
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < row[i].size(); j++) {
			cout << row[i][j] << "  ";

		}
		cout << endl;

	}
	 



	system("pause");
	return 0;
}