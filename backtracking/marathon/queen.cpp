
bool isPromising(int index){	// 유망함수
    if(non-promising)
        return false;
    if(promising)
        return true;
}
void backtracking(int index){
    if(index==n){		// 탈출 조건
        return;
    }
    if(isPromising()){
        visited[index] = true;	// 상태변화
        backtracking(index+1);	// 재귀호출
        visited[index] = false;	// 상태복구
    }
}

int main(void){



	backtracking(4);
	return 0;
}
