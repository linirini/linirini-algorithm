# [Platinum V] 연돌이와 고잠녀 - 11563 

[문제 링크](https://www.acmicpc.net/problem/11563) 

### 성능 요약

메모리: 2100 KB, 시간: 120 ms

### 분류

브루트포스 알고리즘, 기하학

### 아이디어

- 각 점들 사이의 거리
- 한 점에서 다른 선분에 대해 내린 수선의 길이
  - 조건 : 삼각형 밑변 양쪽 점에 끼인 각 = 예각 : 내적의 결과 >=0
  - 방법 : 외적 결과를 이요해서 삼각형의 넓이를 구해 높이를 알아낸다.
