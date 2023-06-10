#include <iostream>
#include <algorithm>
#include<string>
using namespace std;
//#2138_전구와 스위치
int N;
string from, tmp, to;
void switch_on(int i){
    if (i != 0)
        from[i - 1] = from[i - 1] == '0' ? '1' : '0';
    from[i] = from[i] == '0' ? '1' : '0';
    if (i != N - 1)
        from[i + 1] = from[i + 1] == '0' ? '1' : '0';
}
int go(int n){
    int cnt = n;
    for (int i = 1; i < N; i++){
        if (from[i - 1] != to[i - 1]){
            switch_on(i);
            cnt++;
        }
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> N>>from >> to;
    tmp = from;
    int res1 = go(0);
    if (from != to)res1 = -1;
    from = tmp;
    switch_on(0);
    int res2 = go(1);
    if (from != to)res2 = -1;
    if (res1 == -1)cout<< res2;
    else if (res2 == -1)cout<< res1;
    else cout<<min(res1, res2);
}