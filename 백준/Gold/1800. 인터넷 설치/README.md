# [Gold I] 인터넷 설치 - 1800 

[문제 링크](https://www.acmicpc.net/problem/1800) 

### 성능 요약

메모리: 2688 KB, 시간: 4 ms

### 분류

이분 탐색, 데이크스트라, 그래프 이론, 매개 변수 탐색, 최단 경로

### 아이디어

- 이진 탐색으로 낼 수 있는 최소 비용 탐색
  - dist[N] > K == cost값 이하의 값으로 경로 구성할 수 없다 -> 오른쪽 탐색
  - dist[N] <= K -> 왼쪽 탐색
- 검증 by 다익스트라
  - 이진 탐색으로 넘겨진 비용(cost)에 대해 간선 비용이 cost 보다 크면 해당 노드의 비용을 1 로 설정
  - dist[node] = cost 보다 비싼 간선의 총 개수가 담긴다.
