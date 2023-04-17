#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
//#20291_파일 정리
int N;
map<string, int>ext;
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		int idx = str.length() - 1;
		string extension="";
		while (str[idx] != '.') {
			extension = str[idx] + extension;
			idx--;
		}
		if (ext.find(extension) != ext.end())ext[extension]++;
		else ext.insert({ extension,1 });
	}
	for (auto e : ext) {
		cout << e.first << ' ' << e.second << '\n';
	}
}