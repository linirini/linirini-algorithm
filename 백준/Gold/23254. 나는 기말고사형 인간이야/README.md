# [Gold V] 나는 기말고사형 인간이야 - 23254 

[문제 링크](https://www.acmicpc.net/problem/23254) 

### 성능 요약

메모리: 6784 KB, 시간: 76 ms

### 분류

자료 구조, 그리디 알고리즘, 우선순위 큐

### 아이디어

- 시간 당 점수가 큰 것부터 채우는 것이 이득 -> 우선순위 큐
- 만약, 시간 당 점수를 채웠을 때 100점 이하라면, 시간 당 점수를 재갱신하여 큐에 다시 삽입
  - ex) 시간당 3점, 기본 점수 50 -> 50 + 3*16 = 98이므로 시간당 2점으로 바꿔서 큐에 다시 삽입
