/* https://www.acmicpc.net/problem/14226 */

/*
	클립보드에 저장한 개수, 현재 화면에 보이는 개수를 통해 BFS 구현 가능.
*/

#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int copy, cnt_emo, cnt;
	Node(int _c = 0, int _e = 0, int _cnt = 0) : copy(_c), cnt_emo(_e), cnt(_cnt) {}
};

int S;
bool visited[2001][2001];

void init() {
	cin >> S;
}

int solve() {
	queue<Node> Q;
	Q.push({ 0, 1, 0 });
	visited[0][1] = true;

	while (!Q.empty()) {
		Node cur = Q.front(); Q.pop();

		if (!visited[cur.cnt_emo][cur.cnt_emo]) {
			Q.push({ cur.cnt_emo, cur.cnt_emo, cur.cnt + 1 });
			visited[cur.cnt_emo][cur.cnt_emo] = true;
		}
		if (cur.cnt_emo < S && !visited[cur.copy][cur.cnt_emo + cur.copy]) {
			int next = cur.cnt_emo + cur.copy;
			if (next == S) return cur.cnt + 1;
			Q.push({ cur.copy, next, cur.cnt + 1 });
			visited[cur.copy][next] = true;
		}
		if (cur.cnt_emo > 1 && !visited[cur.copy][cur.cnt_emo - 1]) {
			int next = cur.cnt_emo - 1;
			if (next == S) return cur.cnt + 1;
			Q.push({ cur.copy, next, cur.cnt + 1 });
			visited[cur.copy][next] = true;
		}
	}
	return -1;
}

int main() {
	init();

	cout << solve() << '\n';
}