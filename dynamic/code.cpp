#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stdbool.h>
using namespace std;

string  A;
string  B;

string     LCS[1001][1001] = {};

void    my_input(void){
    cin >> A;
    B = A;
    reverse(B.begin(), B.end());
    A = '$' + A;
    B = '$' + B;

    cout << A << ", " << B << endl;
    return;
}

string	my_compare(string a, string b){

	// 문자열 길이 비교 먼저한다.
	
	if 	(a.length() > b.length()) {return a;}
	else if (a.length() < b.length()) {return b;}
	else {
	// 사전상으로 빠른 문자열을 return 하도록 한다.
		if(a.compare(b) < 0) {return a;}
		else		     {return b;}
	}
}

bool	word_test(string a, int x, int y){

	queue<char> test;
	int flag = 0;
	// string a를 test 해보자
	for (int i = 0; i < a.length(); i++){
		test.push(a[i]);}
	
	for (int i = 0; i < x; i++){
		if (test.front() == A[i]) {test.pop();}
	}
	if (!test.empty()) {flag = 1;}
	
	test = queue<char> ();

	// string b를 test 해보자
	for (int i = 0; i < a.length(); i++){
		test.push(a[i]);}
	
	for (int i = 0; i < y; i++){
		if (test.front() == B[i]) {test.pop();}
	}
	if (!test.empty()) {flag = 1;}
	
	test = queue<char> ();

	if (flag == 1) {return false;}
	else {return true;}
}

void    my_sol(void){
	int i = 1;
	int j = 1;
	// index가 1부터 시작하는 이유는 i가 0일 때, i-1 인덱스를 접근하면 에러가 나기 때문이다.
	for (j = 1; j < B.length(); j++){
		for (int i = 1; i < A.length(); i++){
			if (A[i] == B[j]) {
				if (word_test(LCS[i - 1][j] + A[i], i, j) && word_test(LCS[i][j - 1] + A[i], i, j))
					{LCS[i][j] = my_compare(LCS[i - 1][j] + A[i], LCS[i][j - 1] + A[i]);}
				else if(word_test(LCS[i - 1][j] + A[i], i, j))
					{LCS[i][j] = LCS[i - 1][j] + A[i];}
				else if(word_test(LCS[i][j - 1] + A[i], i, j))
					{LCS[i][j] = LCS[i - 1][j] + A[i];}
				else    {LCS[i][j] = my_compare(LCS[i - 1][j] , LCS[i][j - 1]);}
				}
			else      	{LCS[i][j] = my_compare(LCS[i - 1][j] , LCS[i][j - 1]);}
			// cout << "LCS[" << i << "][" << j << "] = " << LCS[i][j] << endl;
			cout << LCS[i][j];
			for (int k = 0; k < 3 - LCS[i][j].length(); k++) { cout << " ";}
			}
			cout << endl;
    		}
	cout << LCS[i - 1][i - 1];
    return ;
}


int main(void){

    my_input();
    my_sol();
    return 0;
}

