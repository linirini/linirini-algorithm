#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#2550_전구
vector <int> V, ans;
int N, swit[10001], num[10001], bulb[10001], dp[10001];
int main(){
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> swit[i];
		num[swit[i]] = i;
	}
	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;
		bulb[i] = num[n];
	}
	for (int i = 1; i <= N; i++){
		int cnt = lower_bound(V.begin(), V.end(), bulb[i]) - V.begin();
		if (cnt == V.size()) V.push_back(bulb[i]);
		else V[cnt] = bulb[i];
		dp[i] = cnt;
	}
	int Max = 0;
	for (int i = 1; i <= N; i++) {
		Max = max(dp[i], Max);
	}
	for (int i = N; i>0; i--)
		if (dp[i] == Max) ans.push_back(swit[bulb[i]]), Max--;
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int n : ans) cout<<n<<' ';
}
