#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <stdbool.h>
#include <array>
using namespace std;

int		n, m,k;

struct word{
	string first;
	string second;	
};
int		flag = 0;
vector<word> 	words;
vector<string>	answer;

void	my_input(void){

	word 	example;
	string 		word_1;
	string 		word_2;

	cin  >> k;

	for (int i = 0; i < k; i++){
		cin >> word_1;
		cin >> word_2;
		example.first	= word_1;
		example.second 	= word_2;
		words.push_back(example);}
	return;
}


void	dfs(int depth, string a, string b, string current, int p_idx){

	if(p_idx == a.length() - 1 || b.length() == 0) {
		answer.push_back(current);
		return ;}
	// end condition
	
	for (int i = 0; i < a.length(); i++){
		for (int j = 0; j < b.length(); j++){
//			cout << "a: " << a.substr(i) << ", b: " << b << endl;
			if (a[i] == b[j]) {
			//	cout << "depth: " << depth << ", current: " << current << ", a[i]: " << a[i] << ", b : " << b << endl;
				dfs(depth + 1, a, b.substr(j + 1), current + a[i], i);}	
		}
	}
	return;	
}

void	my_sol(){

	for (int i = 0; i < k; i++){
		dfs(0, words[i].first, words[i].second, "", 0);
		for (auto s: answer){
			cout << s << ", " ;
			//if (s == words[i].second) {flag = 1; break;}
		}
		cout << endl;
		//if (flag == 1) {cout << "YES" << endl;}
		//else	       {cout << "NO" << endl;}
		flag = 0;
		answer.clear();
	}
}

int	main(void) {
	my_input();
	my_sol();
}	
