# backspace 풀이법

### DFS
* DFS를 통해 나올 수 있는 모든 경우의 단어와 목표 string을 비교해서, 일치하면 "YES" , 불일치하면 "NO"  

<img width="436" alt="스크린샷 2022-06-24 오후 9 55 38" src="https://user-images.githubusercontent.com/63406434/175540492-a26a87dc-f13e-49f5-bfcf-47bba91282a4.png">

### 발생한 문제들

* backspace , space가 입력을 들어오면 space를 dfs로 못찾더라 왜 이런 문제가 생긴지는 모르겠다. 
* 반복문에서 기준인 i와 j를 바꾸자, 그냥 string b를 기준으로 string b의 한 문자라도 놓치면, return 하면 되잖아
* depth: 0, a: backspace, b: space, b[j] = s, a[i] = s, current + a[i]: s, abs(p_idx - i): 4 일때, 문제가 생긴다... 즉 p_idx - i % 2 == 1 인 조건을 dfs 도입 조건문에 넣게되면은 s가 처음인 문자들을 받지 못하게 된다. 


