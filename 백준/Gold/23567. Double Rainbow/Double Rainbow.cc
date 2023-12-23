#include<iostream>
#include<algorithm>
using namespace std;
//#23567_double rainbow
int n, k, P[10001], visited[10001], tmp[10001], Min = 1e9;
bool chk(){
    for (int i = 1; i <= k; i++) if(!visited[i] || !tmp[i]) return false;
    return true;
}
int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> P[i];
        visited[P[i]]++;
    }
    int st = 1, en = 1;
    visited[P[st]]--;
    tmp[P[st]]++;
    while(st <= n && en <= n){
        if(visited[P[en]]){
            int key = 1;
            for (int i = 1; i <= k; i++) if(tmp[i] == 0) key = 0;
            if(key){
                visited[P[st]]++;
                tmp[P[st]]--;
                st++;
                if(chk())Min = min(Min, en - st + 1);
            }
            else{
                en++;
                visited[P[en]]--;
                tmp[P[en]]++;
                if(chk()) Min = min(Min, en - st + 1);
            }
        }
        else{
            visited[P[st]]++;
            tmp[P[st]]--;
            st++;
            if(chk()) Min = min(Min, en - st + 1);
        }
    }
    if(Min != 1e9)cout << Min;
    else cout << 0;
}