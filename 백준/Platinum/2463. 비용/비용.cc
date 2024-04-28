#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//#2463_비용
const int MAX = 100000 + 1;
int N, M;
int parent[100001];
vector<pair<pair<int, int>, int>> edge;
long long setSize[100001],total,ans;
int find(int num){
	if (num == parent[num]) return num;
	return parent[num] = find(parent[num]);
}
void merge(int num1, int num2){
	parent[num2] = num1;
	setSize[num1] += setSize[num2];
	setSize[num2] = 1;
}
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
	return a.second > b.second;
}
int main(void){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
		setSize[i] = 1;
	}
	for (int i = 0; i < M; i++) {
		int num1, num2, cost;
		cin >> num1 >> num2 >> cost;
		edge.push_back({{num1, num2}, cost });
		total += cost;
	}
	sort(edge.begin(), edge.end(), cmp);
	for (int i = 0; i < edge.size(); i++) {
		int p1 = find(edge[i].first.first);
		int p2 = find(edge[i].first.second);
		int cost = edge[i].second;
		if (p1 != p2) {
			ans += (((setSize[p1] * setSize[p2]) % 1000000000) * total) % 1000000000;
			ans %= 1000000000;
			merge(p1, p2);
		}
		total -= cost;
	}
	cout << ans << "\n";
}