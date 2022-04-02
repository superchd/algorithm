#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <stdbool.h>
using namespace std;

string  A;
string  B;

int     LCS[1001][1001] = {};

stack<int> xt;
stack<int> yt;

void    my_input(void){
    cin >> A;
    B = A;
    reverse(B.begin(), B.end());
    A = '0' + A;
    B = '0' + B;
    return;
}

void    my_sol(void){
    for (int i = 1; i < A.length(); i++){
        for (int j = 1; j < B.length(); j++){
           	 if (A[i] == B[j]){
                	LCS[i][j] = LCS[i - 1][j - 1] + 1;
	    		}
            	else {LCS[i][j] = max(LCS[i - 1][j] , LCS[i][j - 1]);}
        }
    }
    return ;
}

void	my_output(void){
	
	int i = A.length() - 1;
	int j = B.length() - 1;
	vector<char> X;
	vector<char> Y;
	bool check = true;
	

	while (LCS[i][j] != 0)
	{
		if (LCS[i][j] == LCS[i-1][j])
			i--;
		else if (LCS[i][j] == LCS[i][j-1])
			j--;
		else if (LCS[i][j] - 1 == LCS[i - 1][j - 1])
		{
			xt.push(i);
			i--;
			j--;
		}
	}
	while(!xt.empty())
	{
		X.push_back(A[xt.top()]);
		xt.pop();}
// one side 
	i = A.length() - 1;
	j = B.length() - 1;
	while (LCS[i][j] != 0)
	{
		if (LCS[i][j] == LCS[i][j-1])
			j--;
		else if (LCS[i][j] == LCS[i-1][j])
			i--;
		else if (LCS[i][j] - 1 == LCS[i - 1][j - 1])
		{
			yt.push(i);
			i--;
			j--;
		}
	}
	while(!yt.empty())
	{
		Y.push_back(A[yt.top()]);
		yt.pop();}
	for (int k = 0; k < A.length() - 1; k++){
		if(X[k] > Y[k]) { check = false;}
	}
	if (check) {
		for(int k = 0; k < X.size(); k++) { cout << X[k];}}
	else { for(int k = 0; k < Y.size(); k++) { cout << Y[k];}}
	return;
}

void 	print(void){

	for (int i = 0; i < A.length(); i++) {
		cout << B[i] << " " ;
	}
	cout << endl;
    for (int i = 0; i < A.length(); i++)    // 2차원 배열의 세로 크기만큼 반복
    {
        for (int j = 0; j < B.length(); j++)    // 2차원 배열의 가로 크기만큼 반복
        {
            printf("%d ", LCS[i][j]); // 2차원 배열의 인덱스에 반복문의 변수 i, j를 지정
        }
	cout << A[i];
        printf("\n");                // 가로 요소를 출력한 뒤 다음 줄로 넘어감
    }
}

int main(void){

    my_input();
    my_sol();
    my_output();
    //print();
    return 0;
}

