#include<iostream>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
//#16472_고냥이
int N, alph[26],ans,cnt;
set<char> s;
string str;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> str;
	int st = 0, en = 0;
	alph[str[0]-'a']++;
	s.insert(str[0]);
	cnt = 1;
	while (1) {
		ans = max(ans, cnt);
		if (st == str.length())break;
		if (en+1<str.length()&&s.size() < N || (s.size() == N && s.find(str[en + 1]) != s.end())) {
			alph[str[en + 1]-'a']++;
			s.insert(str[++en]);
			cnt++;
		}
		else{
			alph[str[st]-'a']--;
			if (alph[str[st] - 'a'] == 0)s.erase(str[st]);
			st++;
			cnt--;
		}
	}
	cout << ans;
}