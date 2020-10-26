# 2020-10-26
# Programmers 기둥과 보 설치
# Minju Kim
# simulation problem

def possible(answer):
    for x, y, a in answer:
        # 기둥 일 때
        if a == 0:
            if y == 0 or [x, y, 1] in answer or [x-1, y, 1] in answer or [x, y-1, 0] in answer:
                continue
            return False
        # 보 일 때 (양쪽 끝 부분이 두 쪽의 보와 연결 됨)
        elif a == 1:
            if [x, y-1, 0] in answer or [x+1, y-1, 0] in answer or ([x-1, y, 1] in answer and [x+1, y, 1] in answer):
                continue
            return False
    return True


def solution(n, build_frame):
    answer = []
    for x, y, a, b in build_frame:
        # 삭제하는 경우
        if b == 0:
            answer.remove([x, y, a])
            if not possible(answer):
                answer.append([x, y, a])
        if b == 1:
            answer.append([x, y, a])
            if not possible(answer):
                answer.remove([x, y, a])

    return sorted(answer)