# [Gold V] 바이러스 복제 - 9241 

[문제 링크](https://www.acmicpc.net/problem/9241) 

### 성능 요약

메모리: 18728 KB, 시간: 164 ms

### 분류

그리디 알고리즘, 구현, 문자열

### 아이디어

- 두번째 테스트 케이스에서 알 수 있는 점: **제거는 카운트하지 않는다**
- before와 after의 동일한 접두어 인덱스 찾기: st
- before와 after의 동일한 접미어 인덱스 찾기: en
  - min(before, after) - en -> 동일하지 않은 부분의 끝 인덱스
  - 해당 값이 st보다 크다면 B - en- st가 답
  - 그렇지 않을 때는 before길이가 더 길 땐 0, B의 길이가 더 길 땐 after 길이- before 길이
