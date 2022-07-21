N = 0
T = 0
K = 0
dictionary = {}
# 인덱스가 0부터 시작하니까, day1으로 시작하는 table과 헷갈릴 우려가 있다.

class number(object):
    def __init__(self,num):
        self.num = num


def my_input():
    global N, T, K
    global dictionary
# 딕셔너리에 하나의 key에 여러 value가 있을때 문제가 생김

    N , T , K = map(int, input().split())
    for i in range(N):
        c, d = map(int, input().split())
        dictionary[number(c)] = d

    return

def fill_table(T):
    global k, v
    global sorted_dict
    table = [0 for i in range(6)]
    l = len(k)
    
    end = 0
    flag = 0

    while len(k) != 0 and end != T:
        # 선택한 table의 자리가 빈자리일 경우
        if table[v[0]] == 0:
            table[v[0]] = k[0]
            del k[0]
            del v[0]
            end += 1
        # 선택한 table의 자리가 빈자리가 아닐 경우
        elif table[v[0]] != 0:
            # day를 바꾸면서 table의 빈자리를 찾는다. (다만 큰쪽부터 시작)
            for day in range(v[0], 0, -1):
                if table[day] == 0:
                    table[day] = k[0]
                    del k[0]
                    del v[0]
                    end += 1
                    flag = 1
            if flag == 0:
                del k[0]
                del v[0]
    return table


def solution():
    table = []
    global N, T, K, dictionary, sorted_dict
    global k, v

    # 데이터 전처리
    sorted_dict = sorted(dictionary.items(), key = lambda item: item[0].num, reverse = True)
    
    k = []
    v = []
    for d in sorted_dict: k.append(d[0].num)
    for d in sorted_dict: v.append(d[1])
    print(k, v)
    sorted_dict = dict(zip(k, v))
    for i in range(K):
        table.append(fill_table(T))  
    print(sum(table[0])+sum(table[1])) 
    return

my_input()
solution()