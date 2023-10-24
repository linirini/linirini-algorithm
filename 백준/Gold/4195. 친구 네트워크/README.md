# [Gold II] 친구 네트워크 - 4195 

[문제 링크](https://www.acmicpc.net/problem/4195) 

### 성능 요약

메모리: 19300 KB, 시간: 244 ms

### 분류

자료 구조, 분리 집합, 해시를 사용한 집합과 맵

### 아이디어

- 입력 받은 id들에 인덱스 부여 : map 저장
- map.find(key)의 idx로 분리 집합 만들기
- visited 배열에 루트 인덱스에 연결된 친구 개수 저장 : visited[x]+=visited[y];
