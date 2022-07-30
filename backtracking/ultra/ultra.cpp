#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

using namespace std;

#define min(x,y) x<y ? x:y

int V, E, u, v, d;
int edge[27], val[27][27], node[27][27], visit[27];
int ans[27],  course[27];
int a_cnt, c_cnt, D, min_d = 21, goal_d = 42;

void	my_input(void){

	cin >> V >> E;
	while (E--) {
		cin >> u >> v >> d;
		u -= 'a'; v -= 'a';
		node[u][edge[u]] = v; node[v][edge[v]] = u;
		val[u][v] = d; val[v][u] = d;
		++edge[u]; ++edge[v];
	}
}

void FastBFS() {
    queue<int> Q;
    visit[0] = true;
    Q.push(0);
    while(!Q.empty()) {
        int cur = Q.front();Q.pop();
        for (int i = edge[cur]-1; i >= 0; i--) {
            int next = node[cur][i];
            if (!visit[next] && val[cur][next] > 0) {
                visit[next] = true;
                Q.push(next);
            }
        }
    }
}

void	record_visit(void){
	for (int i = 0; i < 26; i++) {
		for (int j = i+1; j < 26; j++) {
			if (val[i][j] != 0) {
			int tmp = val[i][j];
			val[i][j] = -1; val[j][i] = -1;
			FastBFS();
			val[i][j] = tmp; val[j][i] = tmp;

			int cnt = 0;
			for (int k = 25; k >= 0; k--) cnt += visit[k];
			
			if (cnt != V) {
			    printf("None\n"); exit(0);
			}

			memset(visit, 0, sizeof(visit));
	   }
        }
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

void DFS(int start) {
	visit[start] = 1;
	int i = edge[start];
	do {
		int next = node[start][i-1];
	if (next == 0) {
	    if (D + val[start][next] != 42) {
		--i; continue;
	    }
	    if (c_cnt >= a_cnt) Arrive();
	}
	if (!visit[next]) {
	    if (D + val[start][next] <= goal_d) {
		D += val[start][next];
		    course[c_cnt++] = next;
		    DFS(next);
		    D -= val[start][next];
		    course[--c_cnt] = 0;
	    }
	}
	--i;
	} while (i);
	visit[start] = 0;
}

int	main() {
	my_input();
	DFS(0);
	record_visit();
    }
