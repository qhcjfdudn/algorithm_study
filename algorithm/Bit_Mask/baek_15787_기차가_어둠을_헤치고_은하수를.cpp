/* https://www.acmicpc.net/problem/15787 */

/*
	3번 명령을 처리하며 오버플로우가 되는 부분을 고려했다면 펄펙트!
*/

#include <iostream>
using namespace std;

int N, M, trains[100001], ret;
bool visited[1 << 20];

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M;
	for (int turn = 0, op, i, x; turn < M; turn++) {
		cin >> op >> i;
		switch (op) {
		case 1: cin >> x; trains[i] |= (1 << (x - 1)); break;
		case 2: cin >> x; trains[i] &= ~(1 << (x - 1)); break;
		case 3: trains[i] <<= 1; trains[i] &= ~(1 << 20); break;
		case 4: trains[i] >>= 1; break;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (visited[trains[i]]) continue;
		visited[trains[i]] = true;
		ret++;
	}

	cout << ret << '\n';
}