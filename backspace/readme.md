# backspace 풀이법

### DFS
* DFS를 통해 나올 수 있는 모든 경우의 단어와 목표 string을 비교해서, 일치하면 "YES" , 불일치하면 "NO"  
* **그래프는 그래프를 그려야 한다**




```c++

int V, E, u, v, d;
int edge[27], val[27][27], node[27][27], visit[27];
int ans[27],  course[27];
int a_cnt, c_cnt = 0, D, min_d = 21, goal_d = 42;
int cur_max = 0;

```
* 다음과 같이 그래프 관련 자료를 셋팅하고 시작하자 



* 입력을 받고 입력 받은 값들을 기준으로 바로 DFS를 시작하자 

### DFS 내부

* 도착한 vertex가 'a'이면 동작그만 -> 도착했다는 말 -> if로 vertex 'a'인지 체크하기
  * 도착햇다면, 이때까지의 경로를 기록해놓아야지
* vertex가 'a'가 아닌 다른 vertex 라면, 과거에 방문했었는지 check
  * 과거에 방문하지 않았다면, 재귀로 더 깊숙한 depth로 들어가자 

### 어려운것 ::
#### 'a'에 도착했읖 때, 경로를 기록할때, visited 행렬을 어떻게 처리할지 고민이 됨 // 이 visited 행렬 처리 때문에 자꾸 애를 먹고 있다. 



