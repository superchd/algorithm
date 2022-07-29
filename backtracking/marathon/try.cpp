#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

#define min(x,y) x<y ? x:y

int V, E, d;
int edge[27], val[27][27], node[27][27], visit[27];
int ans[27],  course[27];
int a_cnt, c_cnt, D, min_d = 21, goal_d = 42;

vector<stack<int> > answer;

void	my_input(void){

	cin >> V >> E;
	char u, v;
	for (int i = 0; i < E; i++){
		cin >> u >> v >> d;
		node[u - 'a'][edge[u - 'a']] = v - 'a';
		node[v - 'a'][edge[v - 'a']] = u - 'a';
		val[u - 'a'][v - 'a'] = d;
		val[v - 'a'][u - 'a'] = d;
		++edge[u - 'a']; ++edge[v - 'a'];
	}
	return;
}

void	DFS(int start, stack<int> s, int sum, int depth){
	// 종료조건 
	stack<char> path;	
	if (sum == 42) {
		answer.push_back(s);
		while(!s.empty()) {
			path.push(s.top() + 'a');
			s.pop();
    		}
		while(!path.empty()) {
			cout << path.top() << " ";
			path.pop();
    		}
		cout << ", " << sum << endl;;
		return;}
	// 한바퀴 다돌았음
	visit[start] = 1;
	int i = edge[start];
	do{
		int next = node[start][i - 1];
		if (next == 0) {
			if (D + val[start][next] != 42) {
            			--i; continue;
            		}
		}
		if (!visit[next]){
			if (D + val[start][next] <= goal_d){
				s.push(next);
				visit[next] = 1;
				sum = sum + val[start][next];
				DFS(next , s, sum, depth + 1);
				sum -= val[start][next];
				visit[next] = 0;
				s.pop();
			}
		}
		i--;
	} while(i);
}

int 	main(void){
	my_input();
	stack<int> s; s.push(0);
	DFS(0, s, 0, 0);
	return 0;
}
