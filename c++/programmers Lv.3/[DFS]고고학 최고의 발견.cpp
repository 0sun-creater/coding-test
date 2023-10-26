#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;  // std 네임스페이스 사용

const int INF = INT_MAX;  // 무한대 값 정의
const vector<pair<int, int>> DIR = {{0, 0}, {0, -1}, {0, 1}, {1, 0}, {-1, 0}};  // 이동 방향 정의

// 시계방향으로 회전하는 함수
void rotate(vector<vector<int>>& clockHands, int x, int y, int i) {
    for (const auto& d : DIR) {
        int dx = d.first, dy = d.second;
        int n = clockHands.size();
        if (0 <= x + dx && x + dx < n && 0 <= y + dy && y + dy < n) {
            // 시계방향으로 회전하며 값 갱신
            clockHands[x + dx][y + dy] = (clockHands[x + dx][y + dy] + i) % 4;
        }
    }
}

// 반시계방향으로 회전하는 함수
void counterRotate(vector<vector<int>>& clockHands, int x, int y, int i) {
    for (const auto& d : DIR) {
        int dx = d.first, dy = d.second;
        int n = clockHands.size();
        if (0 <= x + dx && x + dx < n && 0 <= y + dy && y + dy < n) {
            // 반시계방향으로 회전하며 값 갱신
            clockHands[x + dx][y + dy] = (clockHands[x + dx][y + dy] - i + 4) % 4;
        }
    }
}

// 모든 시계가 12시 방향(0)인지 확인하는 함수
bool finalCheck(const vector<vector<int>>& clockHands) {
    for (const auto& row : clockHands) {
        for (int cell : row) {
            if (cell != 0) {
                return false;  // 12시 방향이 아닌 시계가 존재하면 false 반환
            }
        }
    }
    return true;  // 모든 시계가 12시 방향이면 true 반환
}

// DFS를 이용해 최소 이동 횟수를 찾는 함수
int search(vector<vector<int>>& clockHands, int x, int y, int move) {
    int n = clockHands.size();
    if (x == n) {
        // 모든 시계를 확인하고 최소 이동 횟수 업데이트
        if (finalCheck(clockHands)) {
            return move;
        }
        return INF;  // 불가능한 경우
    }



    int result = INF;

    for (int i = 0; i < 4; ++i) {
        // 회전 후 탐색
        rotate(clockHands, x, y, i);
        if (x - 1 >= 0 && clockHands[x - 1][y] != 0) {
            counterRotate(clockHands, x, y, i);
            continue;
        }
        int nx = (y + 1 == n) ? x + 1 : x;
        int ny = (y + 1) % n;
        result = min(result, search(clockHands, nx, ny, move + i));
        counterRotate(clockHands, x, y, i);
    }

    return result;
}

// 최종 결과를 반환하는 함수
int solution(vector<vector<int>> clockHands) {
    int minimum = INF;
    int result = search(clockHands, 0, 0, 0);
    return (result != INF) ? result : -1;  // 결과 반환
}