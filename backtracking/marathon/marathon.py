import numpy as np

node = np.zeros(shape = (27, 27), dtype=np.int8)
val = np.zeros(shape = (27, 27), dtype=np.int8)
edge = np.zeros(shape = (27, ), dtype=np.int8)

def my_input():
    global node, val, edge

    N, M = map(int, input().split())

    # 데이터 처리
    for i in range(M):
        u, v, d = map(str, input().split())
        u = int(chr(u) - chr('a'))
        v = int(v)
        d = int(d)

        node[u][edge[u]] = v
        node[v][edge[v]] = u
        val[u][v] = d
        val[v][u] = d    

    pass


def solution( ):
    print('x')
    pass


my_input()
solution()