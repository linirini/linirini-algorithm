#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>
using namespace std;
//#18311_왕복
long long N, K,n,dis[200001],sum,in[1000001];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> in[i];
	dis[0] = in[0];
	for(int i=1;i<N;i++)dis[i] = dis[i-1] + in[i];
	for (int i = N - 1; i >= 0; i--) dis[2 * N - 1 - i] = dis[2*N - i - 2] + in[i];
	for (int i = 0; i < 2 * N; i++) {
		if (dis[i] == K) {
			i < N ? cout << i + 2 : cout << 2 * N - (i + 1);
			break;
		}
		else if (dis[i] > K) {
			i < N ? cout << i + 1 : cout << 2 * N - i;
			break;
		}
	}
}
