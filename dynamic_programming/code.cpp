#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string  A;
string  B;

int     LCS[1001][1001];

void    my_input(void){
    cin >> A;
    B = A;
    reverse(B.begin(), B.end());
    return;
}
/*
void    lcs_setting(void){
    string temp;
    string rev_temp;
    temp = A;
    rev_temp = B;

    A.resize(A.length() + 1);
    B.resize(B.length() + 1);

    for(int i = 1; i < A.length(); i++){
        A[i] = temp[i - 1];
        B[i] = rev_temp[i - 1];
    }

    return ;
}
*/
void    my_sol(void){
    for (int i = 1; i < A.length(); i++){
        for (int j = 1; j < B.length(); j++){
            if (A[i - 1] == B[j - 1]){
                LCS[i][j] = LCS[i - 1][j - 1] + 1;}
            else {LCS[i][j] = max(LCS[i - 1][j] , LCS[i][j - 1]);}
        }
    }
    cout << LCS[A.length()][B.length()];
    return ;
}


int main(void){

    my_input();
   //lcs_setting();
    my_sol();
    return 0;

}
