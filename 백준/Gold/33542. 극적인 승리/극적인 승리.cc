#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;
int A, B, N;
vector<pair<int, int>> L,R;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    cin >> A >> B >> N;
    for (int i = 0; i < N; ++i) {
        int l, r;
        cin >> l >> r;
        L.push_back({l, i + 1});
        R.push_back({r, i + 1});
    }
    if (B > A) {
        cout << "-1 -1";
        return 0;
    }
    sort(L.begin(), L.end());
    ll minTotal = 1e18;
    int answerX = -1, answerY = -1;
    for (int i = 0; i < N; ++i) {
        int rScore = R[i].first;
        int rIdx = R[i].second;
        int need = A - B - rScore + 1;
        auto it = lower_bound(L.begin(), L.end(), make_pair(need, -1));
        while (it != L.end()) {
            int lScore = it->first;
            int lIdx = it->second;
            if (lIdx != rIdx) {
                ll total = lScore + rScore;
                if (B + total > A) {
                    if (total < minTotal ||
                        (total == minTotal && (lIdx < answerX || (lIdx == answerX && rIdx < answerY)))) {
                        minTotal = total;
                        answerX = lIdx;
                        answerY = rIdx;
                    }
                }
                break;
            }
            ++it;
        }
    }
    for (int i = 0; i < N; ++i) {
        int lScore = L[i].first;
        int lIdx = L[i].second;
        if (B + lScore > A) {
            if (lScore < minTotal ||
                (lScore == minTotal && (answerX == -1 || lIdx < answerX || (lIdx == answerX && answerY > -1)))) {
                minTotal = lScore;
                answerX = lIdx;
                answerY = -1;
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        int rScore = R[i].first;
        int rIdx = R[i].second;
        if (B + rScore > A) {
            if (rScore < minTotal ||
                (rScore == minTotal && answerX == -1 && (answerY == -1 || rIdx < answerY))) {
                minTotal = rScore;
                answerX = -1;
                answerY = rIdx;
            }
        }
    }

    if (answerX == -1 && answerY == -1) cout << "No";
    else cout << answerX << " " << answerY;
}