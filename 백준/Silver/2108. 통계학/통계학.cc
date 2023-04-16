#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>
using namespace std;
//#2108_통계학
double N,sum,mean,mid,cnt,fre,range,visited[80001];
vector<double>num;
set<int>freq;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		num.push_back(n);
		visited[n + 4000]++;
		sum += n;
	}
	mean = sum / N;
	sort(num.begin(), num.end());
	mid = num[num.size() / 2];
	for (int i = 0; i <= 8000; i++) {
		if (visited[i] > cnt) {
			cnt = visited[i];
			freq.clear();
			freq.insert(i - 4000);
		}
		else if (visited[i] == cnt) {
			freq.insert(i - 4000);
		}
	}
	if (freq.size() > 1) {
		int idx = 0;
		for (auto iter : freq) {
			if (idx == 1) {
				fre = iter;
				break;
			}
			idx++;
		}
	}
	else fre = *freq.begin();
	range = num[N - 1] - num[0];
	mean = round(mean);
	if (mean == -0)mean = 0;
	cout << mean << '\n' << mid << '\n' << fre << '\n' << range;
}