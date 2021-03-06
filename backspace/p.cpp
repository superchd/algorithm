#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <stdbool.h>
#include <array>
#include <cmath>
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

	if(b.length() == 0) {
		answer.push_back(current);
		return ;}
	// end condition
//	
	for (int j = 0; j < b.length(); j++){
		for (int i = p_idx; i < a.length(); i++){
//				cout << "depth: " << depth << ", a: " << a << ", b: " << b << ", b[j] = " << b[j] << ", a[i] = " << a[i] <<", current + a[i]: " << current + a[i] << ", abs(p_idx - i): " <<  abs(p_idx - i) << endl; 
			if (b[j] == a[i]) {
				if (depth != 0 && abs(i - p_idx) % 2) {
					dfs(depth + 1, a, b.substr(j + 1), current + a[i], i);}
				else if (depth == 0) {
					dfs(depth + 1, a, b.substr(j + 1), current + a[i], i);}
			}
		}
	}
	return;	
}

void	my_sol(){

	for (int i = 0; i < k; i++){
		dfs(0, words[i].first, words[i].second, "", 0);
		for (auto s: answer){
			cout << s << ", " ;
			if (s == words[i].second) {flag = 1; break;}
		}
		if (flag == 1) { cout << "YES" << endl;}
		else {cout << "NO" << endl;}
		flag = 0;
		answer.clear();
	}
}
//
int	main(void) {
	my_input();
	my_sol();
}	
