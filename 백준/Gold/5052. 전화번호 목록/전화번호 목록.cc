#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<stack>
#include<cmath>
#include<cstdio>
#include<math.h>
#include<functional>
#include<map>
#include<set>
using namespace std;
//#5052_전화번호 목록
int t,n;
char arr[10001][11];
const int TrieNode = 10;
struct Trie {
	Trie* next[TrieNode];
	bool finish, nextChild;
	Trie() {
		fill(next, next + TrieNode, nullptr);
		finish = nextChild = false;
	}
	~Trie() {
		for (int i = 0; i < TrieNode; i++)if (next[i])delete next[i];
	}
	void insert(char* key) {
		if (*key == '\0')finish = true;
		else {
			int now = *key - '0';
			if (next[now] == NULL)next[now] = new Trie();
			nextChild = true;
			next[now]->insert(key + 1);
		}
	}
	bool find(char* key) {
		if (*key == '\0')return 0;
		if (finish)return 1;
		int now = *key - '0';
		return next[now]->find(key + 1);
	}
};
int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		Trie* root = new Trie();
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			root->insert(arr[i]);
		}
		bool tmp = false;
		for (int i = 0; i < n; i++) {
			if (root->find(arr[i]))tmp = true;
		}
		tmp ? cout << "NO\n" : cout << "YES\n";
		delete root;
	}
}