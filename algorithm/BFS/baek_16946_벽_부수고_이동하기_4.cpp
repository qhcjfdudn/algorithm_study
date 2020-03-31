/* https://www.acmicpc.net/problem/16946 */

/*
	단순한 척 하는 다소 복잡한 BFS
	전체 맵을 n^2으로 순회하면서, 1을 만날 때마다 인접한 0을 BFS로 탐색해 나간다면
	n^2(맵 탐색에 걸리는 시간) * n^2(맵을 BFS 탐색하며 걸리는 시간) = O(N^4)가 된다
	이를 해결하기 위해서 memoization을 해보자. 1을 만났을 때, 인접한 0은 한 번 BFS로 탐색하면
	다음에 또 BFS로 탐색할 때 결과값이 같기 때문에 memoization이 가능하다.

	1. 맵을 탐색하며, 0을 만날 때마다 인접한 모든 0의 개수를 세어 cache배열에 저장한다.
	2. 이후에 전체 맵을 탐색하면서 현재 board[][]의 값이 1일 때, 인접한 0인 위치의 cache[인덱스] 값을 더한다.
		- 아래와 같이 인접하지만, 이미 세어준 적이 있는 값을 다시 계산하는 경우가 생길 수 있다.
		  10
		  00
		  visitedCache를 두어 두 번 세는 것을 방지하자.
*/

#include <iostream>
#include <queue>
#include <string>
using namespace std;

const int dy[4] = { 0, -1, 0, 1 };
const int dx[4] = { -1, 0, 1, 0 };

struct Node {
	int y, x;
	Node(int _y, int _x) : y(_y), x(_x) {}
};

int N, M, cntSection, cache[500000];
char board[1001][1001];
int numberedMap[1000][1000];
bool visited[1000][1000], visitedCache[500000];

void numberringSection(int y, int x) {
	queue<Node> Q;
	visited[y][x] = true;
	numberedMap[y][x] = cntSection;
	cache[cntSection]++;
	Q.push({ y, x });

	while (!Q.empty()) {
		Node cur = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			if (ny < 0 || ny == N || nx < 0 || nx == M || visited[ny][nx] || board[ny][nx] == '1') continue;
			visited[ny][nx] = true;
			numberedMap[ny][nx] = cntSection;
			cache[cntSection]++;
			Q.push({ ny, nx });
		}
	}
}

void precalc() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == '0' && !visited[i][j]) {
				cntSection++;
				numberringSection(i, j);
			}
		}
	}
}

string solve() {
	string ret = "";
	queue<int> checkQ;
	for (int i = 0; i < N; i++) {
		for (int j = 0, v; j < M; j++) {
			v = 0;
			if (board[i][j] == '1') {
				v = 1;
				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny < 0 || ny == N || nx < 0 || nx == M || board[ny][nx] == '1') continue;
					if (!visitedCache[numberedMap[ny][nx]]) {
						v += cache[numberedMap[ny][nx]];
						visitedCache[numberedMap[ny][nx]] = true;
						checkQ.push(numberedMap[ny][nx]);
					}
				}
				while (!checkQ.empty()) {
					visitedCache[checkQ.front()] = false;
					checkQ.pop();
				}
			}
			ret += (v % 10) + 48;
		}
		ret += '\n';
	}
	return ret;
}

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> board[i];

	precalc();

	cout << solve();
}