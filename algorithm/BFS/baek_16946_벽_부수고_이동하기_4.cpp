/* https://www.acmicpc.net/problem/16946 */

/*
	�ܼ��� ô �ϴ� �ټ� ������ BFS
	��ü ���� n^2���� ��ȸ�ϸ鼭, 1�� ���� ������ ������ 0�� BFS�� Ž���� �����ٸ�
	n^2(�� Ž���� �ɸ��� �ð�) * n^2(���� BFS Ž���ϸ� �ɸ��� �ð�) = O(N^4)�� �ȴ�
	�̸� �ذ��ϱ� ���ؼ� memoization�� �غ���. 1�� ������ ��, ������ 0�� �� �� BFS�� Ž���ϸ�
	������ �� BFS�� Ž���� �� ������� ���� ������ memoization�� �����ϴ�.

	1. ���� Ž���ϸ�, 0�� ���� ������ ������ ��� 0�� ������ ���� cache�迭�� �����Ѵ�.
	2. ���Ŀ� ��ü ���� Ž���ϸ鼭 ���� board[][]�� ���� 1�� ��, ������ 0�� ��ġ�� cache[�ε���] ���� ���Ѵ�.
		- �Ʒ��� ���� ����������, �̹� ������ ���� �ִ� ���� �ٽ� ����ϴ� ��찡 ���� �� �ִ�.
		  10
		  00
		  visitedCache�� �ξ� �� �� ���� ���� ��������.
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