#include<iostream>
#include<algorithm>
using namespace std;
int T,a,b;
int main(){
    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>a>>b;
        cout<<a+b<<'\n';
    }
}