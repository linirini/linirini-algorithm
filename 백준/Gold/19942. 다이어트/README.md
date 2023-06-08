# [Gold V] 다이어트 - 19942 

[문제 링크](https://www.acmicpc.net/problem/19942) 

### 성능 요약

메모리: 2028 KB, 시간: 0 ms

### 분류

백트래킹, 브루트포스 알고리즘

### 아이디어

- 백트래킹으로 조합 만들어보면서 최소 영양치를 모두 충족한 경우에 한해 최소값 갱신(vector<vector<int>> clear), 최소값이 같다면 vector<int> push
- 틀린 이유 :
	- string으로 인덱스 값 입력 받아 사전순 정렬 시도 : 두 자리 숫자에 대한 구분 할 수 없음
	- 해결 : vector<int>에 인덱스 값 넣어 vector<vector<int>>에 저장후 정렬
