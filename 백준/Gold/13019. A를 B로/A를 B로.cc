#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//#13019_A를 B로
string A, B;
int cnt,visA[26],visB[26];
void move(int pos) {
	string tmp = "";
	for (int i = 0; i < B.length(); i++)
		if(i!=pos)tmp = tmp + A[i];
	A = A[pos] + tmp;
}
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> A >> B;
	if (A == B) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < A.length(); i++) {
		visA[A[i] - 'A']++;
		visB[B[i] - 'A']++;
	}
	for (int i = 0; i < 26; i++) {
		if (visA[i] != visB[i]) {
			cout << -1;
			return 0;
		}
	}
	int j = B.length()-1;
	for (int i = A.length() - 1; i >= 0;i--) {
		if (A[i] != B[j]) {
			cnt++;
		}
		else {
			j--;
		}
			
	}
	cout << cnt;
}