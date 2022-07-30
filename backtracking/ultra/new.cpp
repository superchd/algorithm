#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

#define min(x,y) x<y ? x:y

int V, E, u, v, d;
int edge[27], val[27][27], node[27][27], visit[27];
int ans[27],  course[27];
int a_cnt, c_cnt = 0, D, min_d = 21, goal_d = 42;

void	my_input(void){
	cin >> V >> E;
	char a, b;
	while (E--) {
		cin >> a >> b >> d;
		u = int(a - 'a'); v = int(b - 'a');
		node[u][edge[u]] = v; node[v][edge[v]] = u;
		val[u][v] = d; val[v][u] = d;
		++edge[u]; ++edge[v];
	}
}

void Arrive() {
    if (a_cnt < c_cnt) {
        memmove(ans, course, sizeof(int)*c_cnt); a_cnt = c_cnt;
    }
    else {
        int i = 0;
        do {
            if (course[i] != ans[i]) {
            	if (course[i] < ans[i]) memmove(ans, course, sizeof(int)*c_cnt);
	            return;
			}
            ++i;
		} while (i < c_cnt);
    }
    return ;
}

void	DFS(int start){

	visit[start] = 1;
	int i = edge[start];
	do {
		int next = node[start][i-1];
	if (next == 0){
	    if (D + val[start][next] != 42) {
		--i; continue;
	    		}
	    //if (c_cnt >= a_cnt) Arrive();
		}
	if (c_cnt >= a_cnt) Arrive();
	if (!visit[next]) {
		D += val[start][next];
		course[c_cnt] = next;
	//	cout << course[c_cnt] << endl;
		c_cnt++;
	 	DFS(next);
		D -= val[start][next];
		course[--c_cnt] = 0;
		}
	--i;
	} while (i);
}

int	main() {
	my_input();
	memset(visit, 0, sizeof(visit));
	memset(course, 0, sizeof(course));
	DFS(0);
	/*
	for (int i = 0; i < sizeof(course) / sizeof(int); i++)    // 배열의 요소 개수만큼 반복
    	{
        	printf("%d\n", course[i]);    // 배열의 인덱스에 반복문의 변수 i를 지정
    	}
	*/
	for (int i = 0; i < a_cnt; i++) printf("%c ", ans[i]+97);
 }
