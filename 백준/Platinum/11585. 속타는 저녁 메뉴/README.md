# [Platinum V] 속타는 저녁 메뉴 - 11585 

[문제 링크](https://www.acmicpc.net/problem/11585) 

### 성능 요약

메모리: 11848 KB, 시간: 56 ms

### 분류

KMP, 문자열

### 아이디어

- 원형 계산 : string 2번 이어 붙이기
- 반례 : T == N 일 때 cnt 할 때 문제 발생 가능
  - A,A -> 1/1 (O), 2/1 (X)
- 반례 처리 위해서 2번 이어  붙인 string의 마지막 글지 빼고 KMP 연산 진행
