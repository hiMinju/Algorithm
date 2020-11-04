# 2020-11-04
# Programmers 2020 KAKAO 신입 공채 1차
# Minju Kim
# 괄호 변환 using recursive

def check(u):
    stack = []
    for i in u:
        if i == '(':
            stack.append(i)
        else: # i가 )일 경우
            if len(stack) == 0 or stack.pop() == ')':
                return False
    return True

def dfs(s):
    result = ""
    if len(s) == 0:
        return s
    left, right = 0, 0
    for i in s:
        if i == '(':
            left += 1
        else:
            right += 1
        if left == right: #균형잡힌 괄호 문자열
            u = s[:left+right]
            v = s[left+right:]
            if check(u): # 올바른 괄호 문자열
                result += u
                result += dfs(v) 
            else:
                temp = '('
                temp += dfs(s[len(u):])
                temp += ')'
                for j in u[1:len(u)-1]:
                    if j == '(':
                        temp += ')'
                    else:
                        temp += '('
                result = temp
            break
    return result

def solution(p):
    if check(p):
        return p
    return dfs(p)