#include<iostream>
#include<algorithm>
using namespace std;
int N,cnt;
int main(){
    cin>>N;
    while(1){
        if(N%5==0){
            cnt+=N/5;
            break;
        }
        N-=3;
        cnt++;
        if(N<=0)break;
    }
    if(N<0)cout<<-1<<'\n';
    else cout<<cnt<<'\n';
}