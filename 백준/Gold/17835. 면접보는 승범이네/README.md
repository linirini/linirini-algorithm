# [Gold II] 면접보는 승범이네 - 17835 

[문제 링크](https://www.acmicpc.net/problem/17835) 

### 성능 요약

메모리: 22156 KB, 시간: 276 ms

### 분류

데이크스트라, 그래프 이론, 최단 경로

### 아이디어

- 역간선으로 저장 후 면접 장소를 출발지점을 생각해서 최단 경로를 차즌ㄴ다 : 다익스트라
- 시간 초과 : 면접 장소도 100000개일 수 있으므로 모든 면접 장소에 대해 각각 탐색을 진행하면 TLE
  - 해결 : 각 지점을 따로 탐색하는 것이 아닌, 모든 면접 장소를 한번에 큐에 넣은 뒤 탐색한다.
    -> 어떤 장소든 항상 가장 가까운 면접 장소를 기준으로 거리가 갱신된다. 따라서, 한 번의 다익스트라 사용만으로도 탐색 가능하다.
- 그 외 주의 사항 : 간선 비용 최대 범위가 100,000이므로 long long의 최대값으로 초기화 해야한다.
