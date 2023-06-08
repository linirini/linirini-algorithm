#include <iostream>
#include<algorithm>
using namespace std;
//#25633_도미노 넘어뜨리기
int n, a[1001], dp[1001], ans,sum,cnt;
int main(void){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)  cin >> a[i];
    for (int i = 0; i < n; i++) {
        sum = a[i];
        cnt = 1;
        for (int j = i+1; j < n; j++) {
            if (sum >= a[j]) {
                sum+=a[j];
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}