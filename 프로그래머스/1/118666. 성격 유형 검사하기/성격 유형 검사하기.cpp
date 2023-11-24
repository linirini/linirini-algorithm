#include <string>
#include <vector>
#include<map>

using namespace std;
int alph[26];
string solution(vector<string> survey, vector<int> choices) {
    
    for(int i=0;i<choices.size();i++){
        if(choices[i]<4){
            alph[survey[i][0]-'A']+=(4-choices[i]);
        }else if(choices[i]>4){
            alph[survey[i][1]-'A']+=(choices[i]-4);
        }
    }
    string answer = "";
    alph['R'-'A']>=alph['T'-'A']?answer+='R':answer+='T';
    alph['C'-'A']>=alph['F'-'A']?answer+='C':answer+='F';
    alph['J'-'A']>=alph['M'-'A']?answer+='J':answer+='M';
    alph['A'-'A']>=alph['N'-'A']?answer+='A':answer+='N';
    return answer;
}