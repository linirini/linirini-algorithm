# [Gold V] 카드 놀이 - 24432 

[문제 링크](https://www.acmicpc.net/problem/24432) 

### 성능 요약

메모리: 5224 KB, 시간: 240 ms

### 분류

이분 탐색, 브루트포스 알고리즘, 정렬, 두 포인터

### 아이디어

- alice와 bob의 카드 뽑는 조합 모두 저장 후 정렬
- Max = max((bob의 최대 크기 - alice의 최대 크기)의 절대값, (alice의 최대 크기- bob의 최대 크기)의 절대값)
- Min = 최대한 bob과 alice의 값 차이가 작을 때 : bob과 alice의 값이 최대한 유사할 때
	- bob 또는 alice 기준으로 모든 값에 대해 이분탐색으로 가장 차이가 작은 값 찾아 최소 차이 갱신
