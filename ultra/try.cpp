#include <iostream>
#include <cmath>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <queue>

using namespace std;


#define min(x,y) x<y ? x:y

int V, E, u, v, d;
int edge[27], val[27][27], node[27][27], visit[27];
int ans[27],  course[27];
int a_cnt, c_cnt = 0, D, min_d = 21, goal_d = 42;
int cur_max = 0;

struct box{
	char	partner;
	int	dist;
	bool	visited;
};


multimap<char, box> m;

stack<box> tower;

vector<stack<box>> answer;

map<char, bool> alpha;

vector<char> vertex;

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


bool check(box ex, int sum){

	if (sum + ex.dist > 42) {return false;}

	if(alpha.find(ex.partner) -> second == true){
	    return false;} 
	else {return true;} 
}

bool compare(stack<box> a, stack<box> b){

	if (a.size() >= b.size()) {return true;}
	else {return false;}

}

void	DFS(int start, int idx){	

	visit[start] = 1;

    do {
        int next = nodes[start][i - 1];
        if (next == 0){
            if (cur_max < D + val[start][next]) {
                D += val[start][next];
            
        }
        if (c_cnt >= a_cnt) Arrive();
        if (!visit[next]) {
            D += val[start][next];
            course[c_cnt] = next;
        //	cout << course[c_cnt] << endl;
            c_cnt++;
            DFS(next, idx + 1);
            D -= val[start][next];
            course[--c_cnt] = 0;
		}
	--i;
    } while(i);
}

void	choose_optimal(void){
	sort(answer.begin(), answer.end(), compare);
	// while (!answer[0].empty()) { cout << "char: " << answer[0].top().partner << ", " << answer[0].top().dist << endl; answer[0].pop(); }
}


