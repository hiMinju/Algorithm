# 2020-11-06
# Minju Kim
# Programmers 2019 KAKAO BLIND RECRUITMENT
# 실패율 using sort library

def solution(N, stages):
    length = len(stages)
    arr = []
    result = {}
    print(arr)
    for i in range(1, N+1):
        count = stages.count(i)
        if length == 0:
            result[i] = 0
        else:
            result[i] = count / length
        length -= count
    result = sorted(result.items(), reverse=True, key=lambda t : t[1])
    print(result)
    answer = [i[0] for i in result]
    return answer