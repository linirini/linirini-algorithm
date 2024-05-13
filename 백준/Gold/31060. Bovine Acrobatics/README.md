# [Gold II] Bovine Acrobatics - 31060 

[문제 링크](https://www.acmicpc.net/problem/31060) 

### 성능 요약

메모리: 9860 KB, 시간: 72 ms

### 분류

자료 구조, 그리디 알고리즘, 우선순위 큐

### 제출 일자

2024년 5월 13일 15:34:13

### 문제 설명

<p>Farmer John has decided to make his cows do some acrobatics! First, FJ weighs his cows and finds that they have $N$ ($1\le N\le 2\cdot 10^5$) distinct weights. In particular, for each $i\in [1,N]$, $a_i$ of his cows have a weight of $w_i$ ($1\le a_i\le 10^9, 1\le w_i\le 10^9$).</p>

<p>His most popular stunt involves the cows forming <em>balanced towers</em>. A <em>tower</em> is a sequence of cows where each cow is stacked on top of the next. A tower is <em>balanced</em> if every cow with a cow directly above it has weight at least $K$ ($1\le K\le 10^9$) greater than the weight of the cow directly above it. Any cow can be part of at most one balanced tower.</p>

<p>If FJ wants to create at most $M$ ($1 \le M \le 10^9$) balanced towers of cows, at most how many cows can be part of some tower?</p>

### 입력 

 <p>The first line contains three space-separated integers, $N$, $M$, and $K$.</p>

<p>The next $N$ lines contain two space-separated integers, $w_{i}$ and $a_i$. It is guaranteed that all $w_i$ are distinct.</p>

### 출력 

 <p>Output the maximum number of cows in balanced towers if FJ helps the cows form towers optimally.</p>

