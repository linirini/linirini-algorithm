# [Gold II] 닭싸움 팀 정하기 - 1765 

[문제 링크](https://www.acmicpc.net/problem/1765) 

### 성능 요약

메모리: 2188 KB, 시간: 4 ms

### 분류

자료 구조, 분리 집합, 그래프 이론, 그래프 탐색

### 아이디어

- 친구라면 Union
- 원수라면 저장해둔 간선 정보 바탕으로 dfs 탐색
  - 원수의 원수는 친구다 : 자신으로부터 2만큼 떨어진 인접 노드에 대해서 Union
