#include<iostream>
#include<algorithm>
using namespace std;
int N;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < 2*N-1; i++) {
		if (i == 0 || i == 2 * N - 2) {
			for (int j = 0; j < N; j++)cout << "*";
			for (int j = 0; j < 2 * (N - 1) - 1; j++)cout << " ";
			for (int j = 0; j < N; j++)cout << "*";
			cout << '\n';
		}
		else if(i<N){
			for (int j = 0; j < i; j++)cout << " ";
			cout << "*";
			for (int j = 0; j < N - 2; j++)cout << " ";
			cout << "*";
			for (int j = 0; j < 2 * (N - i - 1) - 1; j++) cout << " ";
			if(i!=N-1)cout << "*";
			for (int j = 0; j < N - 2; j++)cout << " ";
			cout << "*";
			cout << "\n";
		}
		else {
			for (int j = 0; j < 2 * (N - 1) - i; j++)cout << " ";
			cout << "*";
			for (int j = 0; j < N - 2; j++)cout << " ";
			cout << "*";
			for (int j = 0; j < 2 * (i + 1 - N) - 1; j++)cout << " ";
			if (i != N - 1)cout << "*";
			for (int j = 0; j < N - 2; j++)cout << " ";
			cout << "*";
			cout << "\n";
		}
	}
}