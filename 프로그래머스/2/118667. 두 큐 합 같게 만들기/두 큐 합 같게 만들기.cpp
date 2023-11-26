#include <string>
#include <vector>
using namespace std;
vector<int>v;
int solution(vector<int> queue1, vector<int> queue2) {
    long long sum1 =0,sum2=0;
    for(int i=0;i<queue1.size();i++){
        v.push_back(queue1[i]);
        sum1+=queue1[i];
    }
    for(int i=0;i<queue2.size();i++){
        v.push_back(queue2[i]);
        sum2+=queue2[i];
    }
    int answer = 0;
    int st1 = 0, en1 = queue1.size()-1,st2=queue1.size(),en2=v.size()-1;
    while (answer <= v.size()*2) {
        if (sum1 < sum2) {
            sum1 += v[(++en1) % v.size()];
            sum2 -= v[(st2++) % v.size()];
        } 
        else if (sum1 > sum2) {
            sum1 -= v[(st1++) % v.size()];
            sum2 += v[(++en2) % v.size()];
        } 
        else return answer;
        answer++;
    }
    return -1;
}