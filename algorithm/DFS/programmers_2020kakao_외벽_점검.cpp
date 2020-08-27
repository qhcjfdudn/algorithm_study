/* https://programmers.co.kr/learn/courses/30/lessons/60062 */

/*
	문제를 단순화 하면 간단한 DFS 문제임을 알 수 있다.
	1. 양방향으로 움직일 수 있지만, 이는 한 방향으로 움직이는 것으로 고정시켜도 무방하다.
	2. 구간을 잴 때, 어떤 한 점에서 시작하여 계산하는 것이 가장 넓은 범위를 포함할 수 있다.
    그리디하게 DFS를 적용하여 해결!
*/

#include <string>
#include <vector>
using namespace std;

int ret = 999, wSize, dSize, N;
bool visited[8];

void dfs(int ddx, int dth, int init, int s, int cur, vector<int>& weak, vector<int>& dist) {
    if (dth == dSize) return;
    if (dth + 1 >= ret) return;
    if (init + wSize == cur) ret = dth + 1;
    else {
        int d = weak[cur % wSize] - weak[s % wSize];
        if (d < 0) d += N;

        if (dist[ddx] >= d) dfs(ddx, dth, init, s, cur + 1, weak, dist);
        else {
            for (int i = 1; i < dSize; i++) {
                if (visited[i]) continue;
                visited[i] = true;
                dfs(i, dth + 1, init, cur, cur, weak, dist);
                visited[i] = false;
            }
        }
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    N = n, wSize = weak.size(), dSize = dist.size();
    swap(dist[0], dist[dSize - 1]);

    for (int i = 0; i < wSize; i++)
        dfs(0, 0, i, i, i, weak, dist);

    return ret == 999 ? -1 : ret;
}