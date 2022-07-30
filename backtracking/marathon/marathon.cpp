#include <iostream>
#include <cmath>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <queue>

using namespace std;

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

void	my_input(){

	int ver, edge;
	pair<char, box> ex;
	pair<char, box> rev;

	cin >> ver >> edge;
	pair<char, bool> pair_1;
	pair<char, bool> pair_2;

	for (int i = 0; i < edge; i++){
		char	fir, sec;
		int	val;
		cin >> fir >> sec >> val;

		ex.first	   = fir;
		ex.second.partner  = sec;
		ex.second.dist     = val;

		rev.first	   = sec;
		rev.second.partner = fir;
		rev.second.dist    = val;
		m.insert(ex);
		m.insert(rev);
		pair_1.first = fir; pair_1.second = false;
		pair_2.first = sec; pair_2.second = false;
		
		alpha.insert(pair_1); alpha.insert(pair_2);
	}
	/*
	for(auto iter = m.begin(); iter != m.end(); iter++){
        cout << "[" << iter->first << ", " << iter->second.partner << ", " << iter->second.dist << "] ";
    }
    */
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

void	make_stack(char st, int idx, int sum){	
	
	box ex;
	vector<box> next;

	if (alpha.find('a') -> second) {
		if (sum == 42){
			answer.push_back(tower);
			for(auto it = alpha.begin(); it != alpha.end(); it++){
				it -> second = false;
			}

			while(!tower.empty() ) {cout << tower.top().partner << ", " << tower.top().dist << endl; tower.pop();} // 초기화
			cout << "=================================================" << endl;
		}
	}
			alpha.find(st) -> second =  false;

	else {
		int N = 0;
		// setting 
		for (auto it = m.lower_bound(st); it != m.upper_bound(st); it++)
			{ex.partner = it->second.partner; ex.dist = it->second.dist;
			 next.push_back(ex);
			 N++;}

		for(int i = 0; i < N; i++) {
        		tower.push(next[i]); // 해당 위치에 퀸을 배치
			vertex.push_back(next[i].partner);
        		if(check(next[i], sum)) // 유효하다면 next의 i번째box를 그대로 스택에 넣고, 아니면 next의 다른 box를 스택에 넣는다.
			{	
				alpha.find(next[i].partner) -> second = true;
				make_stack(next[i].partner, idx + 1, sum + next[i].dist);
			//	alpha.find(next[i].partner) -> second = false;
			//	if (!tower.empty() ) {tower.pop();}
			}
        	}
	     }
	return;
}

void	choose_optimal(void){

	sort(answer.begin(), answer.end(), compare);
	// while (!answer[0].empty()) { cout << "char: " << answer[0].top().partner << ", " << answer[0].top().dist << endl; answer[0].pop(); }

}

int	main(void){

	my_input();
	make_stack('a', 0, 0);
	choose_optimal();
}
