# [Silver IV] 대피소 - 28215 

[문제 링크](https://www.acmicpc.net/problem/28215) 

### 성능 요약

메모리: 3788 KB, 시간: 20 ms

### 분류

브루트포스 알고리즘, 구현, 수학, 시뮬레이션

### 아이디어

- N개 중 대피소가 될 수 있는 K개 조합 저장 : vector<vector<int>>index
- 임의의 조합에 대해 N개 집들의 대피소까지의 최소 길이 중 최대(Max) 구하기
- 모든 조합에 대해 Max의 최소 갱신 : ans = min(ans,Max)
