#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

#define min(x,y) x<y ? x:y

int V, E, d;
int edge[27], val[27][27], node[27][27], visit[27];
int ans[27],  course[27];
int a_cnt, c_cnt, D, min_d = 21, goal_d = 42;

void	my_input(void){

	int N, M;
	cin >> N >> M;
	char u, v;
	while (M){

		cin >> u >> v >> d;
		node[u - 'a'][edge[u - 'a']] = v - 'a';
		node[v - 'a'][edge[v - 'a']] = u - 'a';
		val[u - 'a'][v - 'a'] = d;
		val[v - 'a'][u - 'a'] = d;
		++edge[u - 'a'] ; ++edge[v - 'a'];
		M--;
	}
	return;
}
void	print_path(vector<int> path){
	
	char con = 'a';

	for (auto p : path){
		cout << char(con + p) << " ";}
	cout << endl;	
}
void	DFS(int start, int sum, vector<int> path){

	if (sum == 42 && start == 0) {
		print_path(path);
		path.clear();
		for (auto v : visit) { v = 0;}
		return;
	}

	int i = edge[start];
	visit[start] = 1;
	do {
		int next = node[start][i - 1];
		if (next == 0) {
			i--; continue;}
		
		if (!visit[next]){
			visit[next] = 1;
			sum += val[start][next];
			path.push_back(next);
			DFS(next, sum, path);
			visit[next] = 0;
			sum -= val[start][next];
			path.pop_back();
		}
		i--;
	} while(i);
}
int	main(void){
	my_input();
	vector<int> path; path.push_back(0);
	DFS(0, 0, path);
	return 0;
}
