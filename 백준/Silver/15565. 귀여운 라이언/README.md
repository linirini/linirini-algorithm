# [Silver I] 귀여운 라이언 - 15565 

[문제 링크](https://www.acmicpc.net/problem/15565) 

### 성능 요약

메모리: 5220 KB, 시간: 64 ms

### 분류

슬라이딩 윈도우, 두 포인터

### 아이디어

- 라이언 인형 존재하는 경우에만 인덱스 저장 : vector<int> dolls
- K개 라이언 인형 : 구간 K만큼에 대해 슬라이딩 윈도우로 최소 갱신
- 라이언 인형 총 개수가 K보다 작은 경우 예외 처리
