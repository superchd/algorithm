import copy

edge = [0 for i in range(100)]
node = [[0 for i in range(100)] for j in range(100)]
val = [[0 for i in range(100)] for j in range(100)]
visit = [0 for i in range(100)]

paths = []
cost_set = []

def dfs(start, path, cost, depth, n):
    global edge
    global node
    global val
    global paths
    global cost_set
    
    if len(path) == n:
        ans_path = copy.deepcopy(path)
        paths.append(ans_path)
        cost_set.append(cost)
        path = []
        cost = 0
        return
    
    visit[start] = 1
    end = edge[start]
    for i in range(end, -1, -1):
        # 다음 vertex 찾기
        next = node[start][i]
        # 다음 Vertex를 선택후, 방문, 경로, 비용 설정
        if visit[next] == 1 or val[start][next] == 0:
            continue
        visit[next] = 1
        path.append(next)
        cost += val[start][next]
        dfs(next, path, cost, depth + 1, n)
        # 방문, 경로, 비용 초기화
        visit[next] = 0
        path.pop()
        cost -= val[start][next]
        
    return

def solution(n, costs):
    answer = 0
    # 그래프 문제 풀기 위한 자료 셋팅
    global edge
    global node
    global val
    global paths
    global cost_set
    
    # 그래프 그리기
    for c in costs:
        node[c[0]][edge[c[0]]] = c[1]
        node[c[1]][edge[c[1]]] = c[0]
        val[c[0]][c[1]] = c[2]
        val[c[1]][c[0]] = c[2]
        edge[c[0]] += 1
        edge[c[1]] += 1
        
    path = []
    
    for i in range(n):
        visit[i] = 1
        path.append(i)
        dfs(i, path, 0, 0, n)
        visit[i] = 0
        path.pop()
  
    print(paths)
    print(cost_set)
    return cost_set
    

n = 4
costs = [[0,1,1],[0,2,2],[1,2,5],[1,3,1],[2,3,8]]
solution(n, costs)