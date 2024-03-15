# [Silver II] 영재의 시험 - 19949 

[문제 링크](https://www.acmicpc.net/problem/19949) 

### 성능 요약

메모리: 2036 KB, 시간: 0 ms

### 분류

백트래킹, 브루트포스 알고리즘

### 아이디어

- 완전탐색 : 백트래킹
- dp[idx][ppre][pre][total] : idx번째에 전전 번호가 ppre였고, 전 번호가 pre 였을 때 최대 점수 total
