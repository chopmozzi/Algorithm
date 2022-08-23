from collections import deque # bfs 함수 사용 시 시간 절약

def bfs(places): # bfs 함수 사용
    start = []
    
    for i in range(5): # 시작점이 되는 P 좌표 구하기  //i 세로, j 가로
        for j in range(5): # 응시자가 앉아있는 자리 P가 시작점
            if places[i][j] == 'P':
                start.append([i, j]) # 입력값에 있는 모든 P, start 배열에 입력
    
    for s in start: # start 배열 반복 -> 모든 P 거리두기 확인
        queue = deque([s])  # 큐에 초기값
        visited = [[0]*5 for i in range(5)]   # 방문 처리 리스트 //[0]*5 리스트 반복 [0,0,0,0,0]
        distance = [[0]*5 for i in range(5)]  # 경로 길이 리스트 ->> 배열 초기화
        visited[s[0]][s[1]] = 1 # 시작 노드 1로 초기화 -> 이미 방문한 노드 (시작점)
        
        while queue:
            y, x = queue.popleft() # 세로, 가로 순서대로, queue에 시작점 삽입
        
            dx = [-1, 1, 0, 0]  # 좌우
            dy = [0, 0, -1, 1]  # 상하

            for i in range(4): # 노드 이동
                nx = x + dx[i]
                ny = y + dy[i]
# P, O, X 각각 마주칠 때 방법
                if 0<=nx<5 and 0<=ny<5 and visited[ny][nx] == 0: # //방문하지 않은 노드만 확인
                    
                    if places[ny][nx] == 'O': # 빈 자리 만났을 때
                        queue.append([ny, nx]) # 시작점 재설정
                        visited[ny][nx] = 1 # 방문한 칸이므로 1, 재방문 방지
                        distance[ny][nx] = distance[y][x] + 1 # 방문 길이 1 증가
                    
                    if places[ny][nx] == 'P' and distance[y][x] <= 1: # 응시자끼리 붙어있을 때
                        return 0
                # 파티션(X) 만나면 위의 if 2개 조건 만족 X, 다음 start 배열 반복 시작
    return 1


def solution(places): # solution 함수 선언 및 출력값 관련
    answer = []
    
    for i in places:
        answer.append(bfs(i)) #answer 배열에 거리두기 확인값 입력 (0,1)
    
    return answer # 출력