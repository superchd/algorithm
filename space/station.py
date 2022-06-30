import math

points = []
lines = []

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

class line:

    start = point(0, 0, 0)
    end = point(0, 0, 0)

    def __init__(self, start, end):
        self.start = start
        self.end = end

def my_length(a, b):
    length = math.sqrt(math.pow(a.x - b.x, 2) + math.pow(a.y - b.y, 2) + math.pow(a.z - b.z, 2))
    return length

def mid(L):
    x1 = L[0].x * 0.5 + L[1].x * 0.5
    y1 = L[0].y * 0.5 + L[1].y * 0.5
    z1 = L[0].z * 0.5 + L[1].z * 0.5
    return point(x1, y1, z1)

def my_input():

    global points
    global lines

    for i in range(4):
        x, y, z = map(int, input().split())
        points.append(point(x, y, z))

    for i in range(0, 3, 2):
        lines.append(line(points[i], points[i + 1]))
    return

def direction(L1, L2, flag):
    if flag == "L1":
        len_1 = my_length(mid(L1))
        if my_length(mid(L1), mid(L2)) < 
        
    elif flag == "L2":
        pass
       

def my_sol(L1, L2, depth, flag):
    
    # end condition
    if depth == 500:
        print(my_length(mid(L1), mid(L2)))
        return my_length(mid(L1), mid(L2))

    # flag = 1이면, 직선 L1에 있는 점q를 옮긴다. 
    if flag == "L1":
        if direction(L1, L2, flag) == "Left"     : my_sol(L1, L2, depth + 1, "L1")
        elif direction(L1, L2, flag) == "Right" : my_sol(L1, L2, depth, "L2")
    
    # flag = -1 이면, 직선 L2에 있는 점q를 옮긴다.
    else :
        if direction(L1, L2, flag) == "Left"     : my_sol(L1, L2, depth + 1, "L2")
        elif direction(L1, L2, flag) == "Right" : my_sol(L1, L2, depth, "L1")

if  __name__=="__main__":
    my_input()
    L1, L2 = lines[0], lines[1]
    my_sol(L1, L2, 0, "L1")