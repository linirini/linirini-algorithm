#include<iostream>
#include<algorithm>
#include<string>
#include<stdlib.h>
using namespace std;
char SL, SR;
int t;
string str;
pair<int, int>pos_left,pos_right;
pair<pair<int, int>, char> arr[26] = { {{1, 2},'L'}, {{5, 3},'R'}, {{3, 3},'L'}, {{3, 2},'L'}, {{3, 1},'L'}, {{4, 2},'L'}, {{5, 2},'L'},
	{{6, 2},'R'}, {{8, 1},'R'}, {{7, 2},'R'}, {{8, 2},'R'}, {{9, 2},'R'}, {{7, 3},'R'}, {{6, 3},'R'}, {{9, 1},'R'}, {{10, 1},'R'},
	{{1, 1},'L'}, {{4, 1},'L'}, {{2, 2},'L'}, {{5, 1},'L'}, {{7, 1},'R'}, {{4, 3},'L'}, {{2, 1},'L'}, {{2, 3},'L'}, {{6, 1},'R'},
	{{1, 3},'L'} };
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> SL >> SR >> str;
	pos_left = arr[SL - 'a'].first;
	pos_right = arr[SR - 'a'].first;
	for (int i = 0; i < str.length(); i++) {
		if (arr[str[i] - 'a'].second == 'L') {
			t += abs(arr[str[i] - 'a'].first.first - pos_left.first) + abs(arr[str[i] - 'a'].first.second - pos_left.second);
			pos_left = arr[str[i] - 'a'].first;
			t++;
		}
		if (arr[str[i] - 'a'].second == 'R') {
			t += abs(arr[str[i] - 'a'].first.first - pos_right.first) + abs(arr[str[i] - 'a'].first.second - pos_right.second);
			pos_right = arr[str[i] - 'a'].first;
			t++;
		}
	}
	cout << t;
}