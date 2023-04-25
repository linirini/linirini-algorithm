#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
//#1283_단축키 지정
int N;
vector<string>str[31],ans;
char visited[26];
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++) {
		string s;
		getline(cin, s);
		string tmp = "";
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == ' ') {
				str[i].push_back(tmp);
				tmp = "";
				continue;
			}
			tmp = tmp + s[j];
		}
		str[i].push_back(tmp);
	}
	for (int i = 0; i < N; i++) {
		int flag = 0;
		char origin = '0';
		for (int j = 0; j < str[i].size(); j++) {
			int tmp = str[i][j][0] - 'A';
			if (tmp > 25)tmp -= 32;
			if (!visited[tmp]) {
				visited[tmp] = 1;
				origin = str[i][j][0];
				str[i][j][0] = '0';
				flag = 1;
				break;
			}
		}
		if (!flag) {
			for (int j = 0; j < str[i].size(); j++) {
				if (flag)break;
				for (int k = 1; k < str[i][j].length(); k++) {
					int tmp = str[i][j][k] - 'A';
					if (tmp > 25)tmp -= 32;
					if (!visited[tmp]) {
						visited[tmp] = 1;
						flag = 1;
						origin = str[i][j][k];
						str[i][j][k] = '0';
						break;
					}
				}
			}
		}
		string tmp="";
		for (int j = 0; j < str[i].size(); j++) {
			for (int k = 0; k < str[i][j].length(); k++) {
				if (str[i][j][k] == '0') tmp = tmp + '[' + origin + ']';
				else tmp = tmp + str[i][j][k];
			}
			if(j!=str[i].size()-1)tmp = tmp + ' ';
		}
		ans.push_back(tmp);
	}
	for (int i = 0; i < ans.size(); i++)cout << ans[i] << '\n';
}