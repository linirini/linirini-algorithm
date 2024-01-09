# [Silver I] 배열 돌리기 1 - 16926 

[문제 링크](https://www.acmicpc.net/problem/16926) 

### 성능 요약

메모리: 2376 KB, 시간: 120 ms

### 분류

구현

### 아이디어

- min(N,M)/2만큼의 사각형을 돌려야 한다.
- cnt번 만큼, 열 최대값 = M-cnt-1, 행 최대값 = N-cnt-1 
   - 위쪽 변은 오른쪽 -> 왼쪽 : cnt부터 MaxM까지
   - 오른쪽 변은 아래 -> 위 : cnt부터 MaxN까지
   - 아래쪽 변은 왼 -> 오 : MaxM부터 cnt까지
   - 왼쪽 변은 위 -> 아래 : MaxN부터 cnt까지
