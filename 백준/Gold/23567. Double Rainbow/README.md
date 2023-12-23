# [Gold V] Double Rainbow - 23567 

[문제 링크](https://www.acmicpc.net/problem/23567) 

### 성능 요약

메모리: 2136 KB, 시간: 68 ms

### 분류

두 포인터

### 아이디어

- P-P' == visited
- P' == tmp
- visited[P[en]]==0 -> 0이 아닐때까지 st++
- visited[P[en]]!=0 -> en++
- 모든 구간의 움직임에서 최소 구간 길이를 갱신한다.
- 이때 visited배열과 tmp배열 모두에 대해서 모든 색깔이 존재하는지 체크한다.
- 반례 : double 무지개는 충족하지만 최소 구간 길이가 아닌 경우
  - double 무지개 조건을 충족하는 구간에 대해 최소 구간 길이가 될 때까지 st++
