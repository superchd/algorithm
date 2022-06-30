import math

points = []

class point:

    x = 0
    y = 0
    z = 0

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def printInfo(self) :
        print(f'x={self.x} | y={self.y} | z={self.z}')

def my_length(a, b):
    length = math.sqrt(math.pow(a.x - b.x, 2) + math.pow(a.y - b.y, 2) + math.pow(a.z - b.z, 2))
    return length

def mid(a, b):
    x1 = a.x * 0.5 + b.x * 0.5
    y1 = a.y * (1 - 0.5) + b.y * 0.5
    z1 = a.z * (1 - 0.5) + b.z * 0.5
    return point(x1, y1, z1)

def my_input():

    global points

    for i in range(4):
        x, y, z = map(int, input().split())
        points.append(point(x, y, z))
    return

def direction(p, q, r, s, flag):
    if flag == "L1":
        # L1에 있는점을 왼쪽으로 이동했을때 거리 len_1
        len_1 = my_length(mid(p, mid(p, q)), mid(r, s))
        # L1에 있는점을 오른쪽으로 이동했을때 거리 len_2
        len_2 = my_length(mid(mid(p, q), q), mid(r, s))
        if len_1 > len_2      : return "Right"
        elif len_1 < len_2    : return "Left"
        else                  : return "change"
    elif flag == "L2":
        # L2에 있는점을 왼쪽으로 이동했을때 거리 len_1
        len_1 = my_length(mid(p, q), mid(r, mid(r,s)))
        # L2에 있는점을 오른쪽으로 이동했을때 거리 len_2
        len_2 = my_length(mid(p, q), mid(mid(r, s), s))
        if len_1 > len_2      : return "Right"
        elif len_1 < len_2    : return "Left"
        else                  : return "change"

def my_sol(p, q, r, s, prev_l, flag):

    ep = 0.0001
    # end condition
    next = []
    next.append(my_length(mid((p, q), q), mid(r, s)))
    next.append(my_length(mid(p, mid(p, q)), mid(r, s)))
    next.append(my_length(mid(p, q), mid(r, mid(r, s))))
    next.append(my_length(mid(p, q), mid(mid(r, s), s)))

    if  abs(min(next) - prev_l) < 0.05:
        print(my_length(mid(p,q), mid(r,s)))
        return my_length(mid(p,q), mid(r,s))

    # flag = 1이면, 직선 L1에 있는 점p를 오른쪽으로 옮길지 왼쪽으로 옮길지 정함
    if flag == "L1":
    #    오른쪽으로 가야한다
        if direction(p, q, r, s, flag)    == "Right" : my_sol(mid(p, q), q, r, s, my_length(mid((p, q), q), mid(r, s)), "L1")
    #    왼쪽으로 가야한다
        elif direction(p, q, r, s, flag)  == "Left"  : my_sol(p, mid(p, q), r, s, my_length(mid(p, mid(p, q)), mid(r, s)), "L1")
        elif direction(p, q, r, s, flag)  == "change" : my_sol(p, q, r, s, my_length(mid(p, q), mid(r, s)), "L2")
    # flag = -1 이면, 직선 L2에 있는 점q를 오른쪽으로 옮길지 왼쪽으로 옮길지 정함 
    else : 
    #    오른쪽으로 가야한다
        if direction(p, q, r, s, flag)    == "Right"    : my_sol(p, q, r, mid(r,s), my_length(mid(p, q), mid(r, mid(r, s))), "L2")
    #    왼쪽으로 가야한다
        elif direction(p, q, r, s, flag)  == "Left"   : my_sol(p, q, mid(r, s), s, my_length(mid(p, q), mid(mid(r, s), s)), "L2")
        elif direction(p, q, r, s, flag)  == "change" : my_sol(p, q, r, s, my_length(mid(p, q), mid(r, s)), "L2")
    # flag = -1 이면, 직선 L2에 있는 점q를 오른쪽으로 옮길지 왼쪽으로 옮길지 정함 

if  __name__=="__main__":
    my_input()
    # setting
    a, b, c, d = points[0], points[1], points[2], points[3]
    my_sol(a, b, c, d, my_length(mid(a, b), mid(c, d)), "L1") 