# [Gold IV] List of Unique Numbers - 13144 

[문제 링크](https://www.acmicpc.net/problem/13144) 

### 성능 요약

메모리: 3584 KB, 시간: 12 ms

### 분류

두 포인터

### 아이디어

- st, en 포인터를 처음에서 시작하여
- en 포인터에 해당하는 요소가 존재하지 않을 동안 방문 표시 하면서 en++
- 중복되는 값이 등장하기 전까지의 연속된 순열의 경우의 수 == st에서 시작하여 만들 수 있는 순열의 경우의 수 == en - st
- 방문 표시 제거하며 st를 이동한다. 
