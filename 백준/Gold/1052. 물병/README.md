# [Gold V] 물병 - 1052 

[문제 링크](https://www.acmicpc.net/problem/1052) 

### 성능 요약

메모리: 14236 KB, 시간: 116 ms

### 분류

수학, 그리디 알고리즘, 비트마스킹

### 아이디어

- 같은 양의 물을 두 개씩 합친다: 1L -> 2L -> 4L -> 8L (이진수)
- bitCount(N) -> 물이 차 있는 물병의 개수
  - ex. bitCount(3) -> 11 -> 2L 물병 1개, 1L 물병 1개
- 물병 추가는 1L 하나씩이므로, bitCount(N)이 K보다 클 동안 (N+1)하여 원하는 bitCount 까지 연산
