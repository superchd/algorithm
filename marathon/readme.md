
# 마라톤 풀이법

### 그래프 문제 해결 방법
* 처음의 풀이는 그래프를 만들지 않고 풀었는데, 그래프를 만들지 않으니 marathon.cpp 처럼 쓸데 없이 자료구조를 많이 만들어서 한계에 봉착했다. 
* **그래프는 그래프를 그려야 한다**


```c++

int V, E, u, v, d;
int edge[27], val[27][27], node[27][27], visit[27];
int ans[27],  course[27];
int a_cnt, c_cnt = 0, D, min_d = 21, goal_d = 42;
int cur_max = 0;

```
* 다음과 같이 그래프 관련 자료를 셋팅하고 시작하자 

```c++

int	main(void){
	my_input();
	DFS(0, 0);
	choose_optimal();
}
```

* 입력을 받고 입력 받은 값들을 기준으로 바로 DFS를 시작하자 

### DFS 내부

* 도착한 vertex가 'a'이면 동작그만 -> 도착했다는 말 -> if로 vertex 'a'인지 체크하기
  * 도착햇다면, 이때까지의 경로를 기록해놓아야지
* vertex가 'a'가 아닌 다른 vertex 라면, 과거에 방문했었는지 check
  * 과거에 방문하지 않았다면, 재귀로 더 깊숙한 depth로 들어가자 

### 어려운것 ::
#### 'a'에 도착했읖 때, 경로를 기록할때, visited 행렬을 어떻게 처리할지 고민이 됨 // 이 visited 행렬 처리 때문에 자꾸 애를 먹고 있다. 


### 그래프 문제를 풀때는 전역변수를 잘 설정하는것이 중요

> * edge : 각 vertex별 연결된 node가 몇개인지를 알려줌
> node[u][edge[u]] : 굳이 열을 edge[u]로 설정한 이유는 dfs를 돌면서 연결된 vertex를 빠르게 찾기위한 일이다. edge를 이용해 연결된 node가 



