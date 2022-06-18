#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct p
{
	int x;
	int y;
};
int		n;
vector<p>	c;
vector<int>	ans;

void	my_input(void){

	cin >> n;
	int a, b;
	p ex;
	for (int i = 0; i < n; i++){
		cin >> a >> b;
		ex.x = a; ex.y = b;
		c.push_back(ex);
	}
}

int	flag(p a, p b, p c){

	int decision = b.x * a.y + c.x * b.y + a.x * c.y - a.x * b.y - b.x * c.y - c.x * a.y;
	return decision;
}


void	my_sol(){

	for(int i = 0; i < n - 2; i++){
		if (flag(c[i], c[i + 1], c[i + 2]) > 0) {ans.push_back(i + 2);}
	}

	if (flag(c[n - 2], c[n - 1], c[0]) > 0) {ans.push_back(n);}
	if (flag(c[n - 1], c[0], c[1]) > 0) {ans.push_back(1);}
	
	sort(ans.begin(), ans.end());
	for (int i =0 ; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
	
	return;
}

int	main(void){

	my_input();
	my_sol();
}
