#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
//#28215_대피소
int N, K,visited[51],ans=1e9,dist[51][51];
pair<int, int>house[51];
vector<vector<int>>index;
int dis(pair<int, int>a, pair<int, int>b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
void go(int idx,int cnt) {
	if (cnt == K) {
		vector<int>v;
		for (int i = 0; i < N; i++) if (visited[i])v.push_back(i);
		index.push_back(v);
		return;
	}
	else {
		for (int i = idx; i < N; i++) {
			if (visited[i])continue;
			visited[i] = 1;
			go(i, cnt + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) 
		cin >> house[i].first >> house[i].second;
	go(0, 0);
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
			dist[i][j]=dis(house[i], house[j]);
	for (int k = 0; k < index.size(); k++) {
		int Max = 0;
		for(int i= 0 ; i < N ; i++){
			int Min = 1e9;
			int vis[51];
			fill(vis, vis+N, 0);
			for (int j = 0; j < index[k].size(); j++)visited[index[k][j]] = 1;
			for (int j = 0; j < index[k].size(); j++)
				if (!vis[index[k][j]]) Min = min(Min, dist[i][index[k][j]]);
			if(Min!=1e9)Max = max(Min, Max);
		}
		ans = min(ans, Max);
	}
	cout << ans;
}