# [Gold V] 두 용액 - 2470 

[문제 링크](https://www.acmicpc.net/problem/2470) 

### 성능 요약

메모리: 2808 KB, 시간: 16 ms

### 분류

이분 탐색, 정렬, 두 포인터

### 아이디어

- 정렬한 배열에 대해 두 포인터를 양끝에서 조이면서 합의 절대값이 0에 가장 가까운 값을 찾는다.
- st<en일 동안
- 합이 0보다 작다면 : st++
- 합이 0보다 크다면 : en--
- 합이 0이라면 루프 탈출
