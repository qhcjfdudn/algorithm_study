/* https://programmers.co.kr/learn/courses/30/lessons/60062 */

/*
	������ �ܼ�ȭ �ϸ� ������ DFS �������� �� �� �ִ�.
	1. ��������� ������ �� ������, �̴� �� �������� �����̴� ������ �������ѵ� �����ϴ�.
	2. ������ �� ��, � �� ������ �����Ͽ� ����ϴ� ���� ���� ���� ������ ������ �� �ִ�.
    �׸����ϰ� DFS�� �����Ͽ� �ذ�!
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