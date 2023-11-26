# [level 2] 두 큐 합 같게 만들기 - 118667 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/118667) 

### 성능 요약

메모리: 11 MB, 시간: 4.25 ms

### 구분

코딩테스트 연습 > 2022 KAKAO TECH INTERNSHIP

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 아이디어

- 처음에는 queue1 + queue2 + queue1 을 넣은 벡터에 대해 투포인터 탐색 시도
  - 조건 및 반례 처리 까다로움
- 각 큐의 합을 비교하면서
  - sum1>sum2 : q1 pop (st1++), q2 push (++en2)
  - sum2<sum1 : q2 pop (st2++), q1 push (++en1)
  - sum2==sum1 : return answer
  - 순환 : 나머지 연산
- 예제 1 실패 : 종료 조건 잘못 설정 : answer<=(q1+q1)*2
