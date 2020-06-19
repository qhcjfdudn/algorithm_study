/* https://www.acmicpc.net/problem/19236 */

/*
    문제의 의도대로 순서대로 따라가며 구현해가면 어렵지 않은 문제.
    다만 소스코드를 보다 가독성 높고, 효율적으로 짜기 위한 고민을 해야할 것.
    코드를 깔끔하게 짜기 위해 고민하기 좋은 문제!
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
const int dy[8] = { 1, 0, -1, -1, -1, 0, 1, 1 };

struct Node {
    int num, d;
    Node(int _n = -1, int _d = -1) : num(_n), d(_d) {}
};

int teenagerShark(Node sb[][4], int sf[], int sharkPos, int sharkDir) {
    int ret = 0;
    Node tempBoard[4][4];
    int tempFish[17];

    for (int i = 0; i < 16; i++) {
        tempBoard[i / 4][i % 4] = sb[i / 4][i % 4];
        tempFish[i + 1] = sf[i + 1];
    }

    for (int i = 1; i <= 16; i++) {
        if (tempFish[i] == -1) continue;
        int cx = tempFish[i] / 4, cy = tempFish[i] % 4;
        if (tempBoard[cx][cy].num == -1) continue;
        for (int j = 0; j < 8; j++) {
            int nx = cx + dx[tempBoard[cx][cy].d % 8];
            int ny = cy + dy[tempBoard[cx][cy].d % 8];
            if (nx < 0 || nx == 4 || ny < 0 || ny == 4 || tempBoard[nx][ny].num == -1)
                tempBoard[cx][cy].d++;
            else {
                Node temp = tempBoard[cx][cy];
                tempFish[i] = nx * 4 + ny;
                tempFish[tempBoard[nx][ny].num] = cx * 4 + cy;
                tempBoard[cx][cy] = tempBoard[nx][ny];
                tempBoard[nx][ny] = temp;
                break;
            }
        }
    }

    int sx = sharkPos / 4, sy = sharkPos % 4;
    sx += dx[sharkDir % 8];
    sy += dy[sharkDir % 8];
    while (sx >= 0 && sx < 4 && sy >= 0 && sy < 4) {
        if (tempBoard[sx][sy].num != 0) {
            int v = tempBoard[sx][sy].num;
            tempFish[v] = -1;
            tempBoard[sx][sy].num = -1;
            tempBoard[sharkPos / 4][sharkPos % 4].num = 0;
            ret = max(ret, teenagerShark(tempBoard, tempFish, sx * 4 + sy, tempBoard[sx][sy].d) + v);
            tempBoard[sharkPos / 4][sharkPos % 4].num = -1;
            tempBoard[sx][sy].num = v;
            tempFish[v] = sx * 4 + sy;
        }
        sx += dx[sharkDir % 8];
        sy += dy[sharkDir % 8];
    }
    return ret;
}

int main() {
    Node board[4][4];
    int fish[17];

    for (int i = 0, a, b; i < 16; i++) {
        cin >> a >> b;
        board[i / 4][i % 4] = { a, b };
        fish[a] = i;
    }

    int ans = board[0][0].num;
    fish[board[0][0].num] = -1;
    board[0][0].num = -1;

    cout << ans + teenagerShark(board, fish, 0, board[0][0].d) << '\n';
}