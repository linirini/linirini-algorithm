# [Gold III] 양 구출 작전 - 16437 

[문제 링크](https://www.acmicpc.net/problem/16437) 

### 성능 요약

메모리: 90016 KB, 시간: 1500 ms

### 분류

그래프 이론, 그래프 탐색, 트리, 깊이 우선 탐색

### 아이디어

- 부모 노드 1을 기준으로 노드 연결
- dfs 탐색하며 늑대/양 여부에 따라 ans-=count/ans+=count
