# [Gold V] 골목 대장 호석 - 기능성 - 20168 

[문제 링크](https://www.acmicpc.net/problem/20168) 

### 성능 요약

메모리: 2020 KB, 시간: 4 ms

### 분류

백트래킹, 브루트포스 알고리즘, 데이크스트라, 그래프 이론

### 아이디어

- 백트래킹으로 현재 노드 인덱스, 현재까지의 총 비용, 현재까지의 경로 중 최대 비용을 인자로 넘겨주며 경로 탐색
- 현재 노드 == 도착 노드이면서 사용 가능한 비용보다 현재까지의 총 비용이 작거나 같을 경우 경로 속 최대 비용의 최소를 갱신
