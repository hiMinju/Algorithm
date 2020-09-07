#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;
stack<int> bascket;
int answer = 0;

void recheck(int n) {
    if (bascket.top() == n) {
        bascket.pop();
        answer += 2;
        recheck(n);
    }
}

void check(int n) {
    if (bascket.empty()) {
        bascket.push(n);
    }
    else if (bascket.top() != n) {
        bascket.push(n);
    }
    else {
        recheck(n);
    }
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int n = board.size();
    for (int i = 0; i < moves.size(); i++) {
        for (int j = 0; j < n; j++) {
            if (board[j][moves[i] - 1] != 0) {
                check(board[j][moves[i] - 1]);

                board[j][moves[i] - 1] = 0;
                break;
            }
        }
    }
    return answer;
}

int main() {
    vector<vector<int>> board = { {0,0,0,0,0}, {0,0,1,0,3}, {0,2,5,0,1}, {4,2,4,4,2}, {3,5,1,3,1} };
    vector<int> moves = { 1,5,3,5,1,2,1,4 };

    solution(board, moves);
    cout << answer;

    return 0;
}