# [Gold I] 망가진 계산기 - 1443 

[문제 링크](https://www.acmicpc.net/problem/1443) 

### 성능 요약

메모리: 2208 KB, 시간: 12 ms

### 분류

백트래킹, 브루트포스 알고리즘

### 아이디어

- 백트래킹 함수 정의 : 곱할 수, 현재 수, 연산 횟수를 인자로 전달
- 종료 조건 : P회 연산 완료 or 곱하는 값이 2보다 작아짐
- 만약 곱할수를 현재 수에 곱했을 때 D 자리수를 넘는다면 곱할 수 -1 로 다시 재귀호출
- 그렇지 않을 경우에는 곱할 수 -1 재귀와 현재수에 곱할 수를 곱하고 연산 횟수 +1 한 재귀 호출

