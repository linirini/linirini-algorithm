#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;
//#17413_단어 뒤집기 2
string S;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	getline(cin,S);
	int i = 0;
	while(i<S.length()) {
		if (S[i] == '<') {
			string str = "";
			while (S[i] != '>') {
				cout << S[i];
				i++;
			}
			cout << S[i];
			i++;
		}
		else if (S[i] == ' ') {
			cout << S[i];
			i++;
		}
		else {
			stack<char>s;
			while (i<S.length() && S[i] != ' ' && S[i] != '<') {
				s.push(S[i]);
				i++;
			}
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}
		}
	}
}