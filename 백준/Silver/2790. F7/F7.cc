#include<iostream>
#include<algorithm>
using namespace std;
//#2790_F7
int N,arr[300001],score = 0;
bool cmp(int a, int b) { return a > b;}
int main() {
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N, cmp);
    score = arr[0] + 1;
    int result = 1;
    for (int i = 1; i < N; i++) {
        if (arr[i] + N >= score) result++;
        score = max(score, arr[i] + i + 1);
    }
    cout << result;
}
