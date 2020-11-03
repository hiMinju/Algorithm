# 2020-11-03
# Minju Kim
# Programmers 2020 KAKAO BLIND RECRUITMENT
# 외벽 점검

from itertools import permutations

def solution(n, weak, dist):
    # 길이를 2배로 늘려 원형의 모양을 일자로 만듦
    length = len(weak)
    for i in range(length):
        weak.append(weak[i]+n)
    answer = len(dist) + 1 # 투입할 친구 수의 최솟값을 찾아야 하므로 len(dist)+1로 초기화
    # 모든 좌표를 시작점으로 설정
    for start in range(length):
        # 모든 친구를 나열하는 경우의 수
        for friends in list(permutations(dist, len(dist))):
            count = 1 # 투입할 친구 수 
            # 해당 친구가 점검할 수 있는 마지막 위치 -> 잘 모르겠다
            position = weak[start] + friends[count - 1] # count 1부터 시작 마지막 친구
            # 시작점부터 모든 weak 확인
            for index in range(start, start+length):
                if position < weak[index]: # 점검할 수 있는 위치가 아닌 경우
                    count += 1 # 친구 더 투입
                    if count > len(dist):
                        break
                    position = weak[index] + friends[count - 1] # 마지막 위치 업데이트
            answer = min(answer, count)
    if answer > len(dist):
        return -1
    return answer