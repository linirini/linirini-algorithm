#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//#2290_LCD Test
int pattern[10][7]{
	{1,1,1,0,1,1,1},
	{0,0,1,0,0,1,0},
	{1,0,1,1,1,0,1},
	{1,0,1,1,0,1,1},
	{0,1,1,1,0,1,0},
	{1,1,0,1,0,1,1},
	{1,1,0,1,1,1,1},
	{1,0,1,0,0,1,0},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1}
};
int s;
string n;
void print(int num, int idx) {
	if (idx % 3==0) {
		cout << " ";
		if (pattern[num][idx] == 1) {
			for (int i = 0; i < s; i++)
				cout << '-';
		}
		else {
			for (int i = 0; i < s; i++) 
				cout << " ";
		}
		cout << "  ";
	}
	else {
		if (pattern[num][idx] == 1)cout << '|';
		else cout << " ";
		if (idx % 3 == 1) {
			for (int i = 0; i < s; i++)
				cout << " ";
		}
		else cout << " ";
	}
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> s >> n;
	for (int i = 0; i < n.size(); i++)print(n[i]-'0', 0);
	cout << '\n';
	for (int k = 0; k < s; k++) {
		for (int i = 0; i < n.size(); i++)
			for (int j = 1; j <= 2; j++)
				print(n[i] - '0', j);
		cout << '\n';
	}
	for (int i = 0; i < n.size(); i++)print(n[i] - '0', 3);
	cout << '\n';
	for (int k = 0; k < s; k++) {
		for (int i = 0; i < n.size(); i++)
			for (int j = 4; j <= 5; j++)
				print(n[i] - '0', j);
		cout << '\n';
	}
	for (int i = 0; i < n.size(); i++)print(n[i] - '0', 6);
	cout << '\n';
}