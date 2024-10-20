# [Gold V] 문자열 게임 2 - 20437 

[문제 링크](https://www.acmicpc.net/problem/20437) 

### 성능 요약

메모리: 2156 KB, 시간: 4 ms

### 분류

슬라이딩 윈도우, 문자열

### 아이디어

- 무조건 K개 이상 포함하는 문자에 대해서만 탐색하면 된다.
- 따라서, 문자에 대해 위치 정보를 기억: alph[문자].push_back(위치)
- K개 이상 가진 문자에 대해서만 구간 길이의 최소, 최대를 구한다.
  - Min = min(Min, alph[i][j + K - 1] - alph[i][j] + 1);
  - Max = max(Max, alph[i][j + K - 1] - alph[i][j] + 1);
