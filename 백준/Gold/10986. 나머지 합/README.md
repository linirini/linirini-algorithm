# [Gold III] 나머지 합 - 10986 

[문제 링크](https://www.acmicpc.net/problem/10986) 

### 성능 요약

메모리: 9840 KB, 시간: 124 ms

### 분류

수학, 누적 합

### 아이디어
- (sum[j]-sum[i]) % M = 0
- sum[j]%M = sum[i]%M
- modNum[sum[i]%M]++ -> 나머지가 같은 것들끼리 구간합을 구하면 나누어떨어진다
- 따라서, modNum[x]C2 (조합)의 결과값들의 합이 구하고자 하는 나누어 떨어지는 구간의 개수
