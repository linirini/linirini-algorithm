# [Gold V] 수 고르기 - 2230 

[문제 링크](https://www.acmicpc.net/problem/2230) 

### 성능 요약

메모리: 9832 KB, 시간: 16 ms

### 분류

정렬, 두 포인터

### 아이디어

- 정렬 후
- 투 포인터에 처음에서 시작하여
- 그 요소 차가 M보다 작을 경우 en++
- M보다 크거나 같을 경우 최소값 갱신 후 st++
- M보다 크거나 같은 가장 작은 경우를 찾는 것이므로 en 포인터가 끝에 도달할 때까지만 탐색하면 된다.
