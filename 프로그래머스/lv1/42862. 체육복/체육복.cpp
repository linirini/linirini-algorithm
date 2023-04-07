#include<algorithm>
#include <string>
#include <vector>
#include<cmath>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int>visited_reserve,visited_lost;
    visited_reserve.resize(n+2,0);
    visited_lost.resize(n+2,0);
    answer=n-lost.size();
    sort(reserve.begin(),reserve.end());
    sort(lost.begin(),lost.end());
    for(int i=0;i<reserve.size();i++)visited_reserve[reserve[i]]=1;
    for(int i=0;i<lost.size();i++)visited_lost[lost[i]]=1;
    for(int i=1;i<n+1;i++){
        if(visited_reserve[i]&&visited_lost[i]){
            answer++;
            visited_reserve[i]=0;
            visited_lost[i]=0;
        }
    }
    for(int i=0;i<lost.size();i++){
        if(visited_lost[lost[i]]){
            if(visited_reserve[lost[i]-1]){
                answer++;
                visited_reserve[lost[i]-1]=0;
            }else if(visited_reserve[lost[i]+1]){
                answer++;
                visited_reserve[lost[i]+1]=0;
            }
        }
    }
    return answer;
}