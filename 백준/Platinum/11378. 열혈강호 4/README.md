# [Platinum III] 열혈강호 4 - 11378 

[문제 링크](https://www.acmicpc.net/problem/11378) 

### 성능 요약

메모리: 37840 KB, 시간: 1284 ms

### 분류

이분 매칭, 최대 유량

### 아이디어

- i번이 무조건 1개 이상 일 수행 가능 : i번과 Source 사이의 유량 : 1
- 총합 벌점 만큼의 일이 추가로 가능 : Source와 PENALTY 사이의 유량 & Penalty와 i 사이의 유량 : K
- i번과 가능한 일 사이에 간선 : 유량 == 1
- sink와 벌점 사이 유량 == 1
