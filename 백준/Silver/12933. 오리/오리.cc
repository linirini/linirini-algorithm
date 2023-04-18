#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
//#12933_오리
int cnt;
string str;
vector<string>duck;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		int flag=0;
		if (str[i] == 'q') {
			for (int j = 0; j < duck.size(); j++) {
				if (duck[j][duck[j].size() - 1] == 'k') {
					flag = 1;
					duck[j] = duck[j] + 'q';
					break;
				}
			}
			if (!flag)duck.push_back("q");
			flag = 1;
		}
		else if (str[i] == 'u') {
			for (int j = 0; j < duck.size(); j++) {
				if (duck[j][duck[j].size() - 1] == 'q') {
					duck[j] = duck[j] + 'u';
					flag = 1;
					break;
				}
			}
		}
		else if (str[i] == 'a') {
			for (int j = 0; j < duck.size(); j++) {
				if (duck[j][duck[j].size() - 1] == 'u') {
					duck[j] = duck[j] + 'a';
					flag = 1;
					break;
				}
			}
		}
		else if (str[i] == 'c') {
			for (int j = 0; j < duck.size(); j++) {
				if (duck[j][duck[j].size() - 1] == 'a') {
					duck[j] = duck[j] + 'c';
					flag = 1;
					break;
				}
			}
		}
		else if (str[i] == 'k') {
			for (int j = 0; j < duck.size(); j++) {
				if (duck[j][duck[j].size() - 1] == 'c') {
					duck[j] = duck[j] + 'k';
					flag = 1;
					break;
				}
			}
		}
		if (!flag) {
			cout << -1;
			return 0;
		}
	}
	for (int i = 0; i < duck.size(); i++)if (duck[i][duck[i].size() - 1] != 'k') {
		cout << -1;
		return 0;
	}
	cout << duck.size();
}