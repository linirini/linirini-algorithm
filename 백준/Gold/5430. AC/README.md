# [Gold V] AC - 5430 

[문제 링크](https://www.acmicpc.net/problem/5430) 

### 성능 요약

메모리: 82512 KB, 시간: 924 ms

### 분류

덱, 파싱, 구현, 문자열, 자료 구조

### 아이디어

- 'R'일 경우, poll의 위치를 바꾸기 위해 포인터 값을 저장한다 : pointer = 1-pointer
- 'D'일 경우, deque가 비어있지 않다면(비어있다면 flag = -1) pointer 위치에 따라 poll out 작업을 수행한다
- 결과 출력 : 출력 형식이 arr.toString() 형식과 다르므로, 주의
