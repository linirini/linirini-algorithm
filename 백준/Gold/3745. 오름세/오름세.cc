#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#3745_오름세
int N,A[100001];
vector <int> LIS;
int main() {
	while(cin>>N){
		for (int i = 0; i < N; i++) cin >> A[i];
		LIS.clear();
		LIS.push_back(A[0]);
		for (int i = 1; i < N; i++) {
			if (LIS.back() < A[i])LIS.push_back(A[i]);
			else {
				auto it = lower_bound(LIS.begin(), LIS.end(), A[i]);
				*it = A[i];
			}
		}
		cout << LIS.size()<<'\n';
	}
}