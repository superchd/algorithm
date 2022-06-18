#include <iostream>
#define n 10
#define r 3
using namespace std;
int cArr[r] = { 0, };


void combination(int depth, int next){
    if(depth == r){
	for (int i = 0; i < sizeof(cArr) / sizeof(int); i++)    // 배열의 요소 개수만큼 반복
    {
        printf("%d", cArr[i]);    // 배열의 인덱스에 반복문의 변수 i를 지정
    }
	cout << endl;

        return;
    }

    for(int i = next; i <= n; i++){
        cArr[depth] = i;
        combination(depth + 1, i + 1);
    }
}

int main(void){
    cout << "조합 (순서x, 중복x)" << endl;
    combination(0, 1);

    return 0;
}
