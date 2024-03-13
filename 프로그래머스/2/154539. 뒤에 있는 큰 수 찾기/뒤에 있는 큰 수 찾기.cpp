#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;
stack<pair<int,int>>st;
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    answer.resize(numbers.size());
    for(int i=0;i<numbers.size();i++){
        while(!st.empty()&&st.top().first<numbers[i]){
            answer[st.top().second] = numbers[i];
            st.pop();
        }
        st.push({numbers[i],i});
    }
    while(!st.empty()){
        answer[st.top().second] = -1;
        st.pop();
    }
    return answer;
}