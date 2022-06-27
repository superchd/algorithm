## timebomb -> 토너먼트 실행시간을 어떻게 줄일까??


### 1	2	3	4	5	6	7	8
### 2		    4		   6		   8

###		4			8
###			8

### 8과 싸운애들끼리 중에 최강자를 뽑으면 됨 

###
*	최강자 결정 나면, 최강자에 flag = 1 대입
*	다시 이제 토너먼트 돌린다 
*	토너먼트 돌리면서 flag = 1인 애와 만난 친구들을 벡터에넣는다
*	벡터에 넣은 친구들끼리 토너먼트 돌린다. 
* 생긴문제 :: Box[i], Box[j]라고 따로 박스의 인덱스를 넣어주면, 그 박스의 무게를 알려주는 함수가 있다... 이 함수 때문에 방향성을 틀었음 .... 내 코드에서 토너먼트 최종결과물은 flag 인데, 2번째 테케를 돌렸을때, 자꾸 flag =2 가 나오니까? 오 뭐지? 했었는데, 그게 아니라 box[2] = 10이 잖아, 즉 박스의 순서를 잘 알려주고 있었음.... 
*   최강자를 구한다음, 이 최강자와 겨룬 아이들을 찾으려고 한번더 tour를 돌리는 순간 이제 횟수초과가 됨.... 

### 내가 싸운 문제:
* 8과 싸운 애들끼리를 구하는거 자체가 시간이 또 N번걸리네. 왜냐하면, 최강자구하는데 N번 횟수 걸리고, 또 싸운애들 구하는데 N번걸리니까 총 2N번, 즉 이 문제의 횟수제한인 N + log N + 3에 제한걸린다.
``` c++

int box_comp(int i , int  j){
    called = called + 1;
    if (called > Limit){
        out = fopen("test.out", "w");
        fprintf(out, "Function call limit over");
        free(Box);
        exit(-1);
    }
    
    if (i <= 0 || i > N || j <= 0 || j > N) {
        printf("index out of range : box_comp(%d, %d)\n",i,j);
        return 0;
    }
    printf("check box %d %d\n",Box[i], Box[j]);
    if (Box[i] < Box[j])
        return -1;
    else if (Box[i] > Box[j])
        return 1;
    return 0;
}
```
