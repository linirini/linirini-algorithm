#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//#18868_멀티버스 I
int M, N, cnt;
int main() {
    cin >> M >> N;
    vector<vector<int>> universe(M, vector<int>(N));
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            cin >> universe[i][j];
    for (int i = 0; i < M; ++i) {
        vector<int> planet = universe[i];
        sort(planet.begin(), planet.end());
        vector<int> idx(N);
        for (int j = 0; j < N; ++j)
            idx[j] = find(planet.begin(), planet.end(), universe[i][j]) - planet.begin() + 1;
        universe[i] = idx;
    }
    for (int i = 0; i < M - 1; ++i)
        for (int j = i + 1; j < M; ++j)
            if (universe[i] == universe[j]) cnt++;
    cout << cnt << '\n';
}