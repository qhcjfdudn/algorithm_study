/* https://www.acmicpc.net/problem/3653 */

/*
	배열을 탐색하여 개수를 하나씩 세면 간단히 시간초과다.
	비디오를 꺼내고 맨 위에 놓는다면, 꺼낸 비디오를 제외한 나머지의 위치관계는 동일해진다.
	세그먼트 트리를 이용하자. 빼낸 비디오를 다시 얹는 것은, 가장 높은 위치에 있는 비디오보다
	더 높은 곳에 새로운 비디오가 추가되는 것과 같다. 세그먼트 트리의 인덱스를 하나씩 늘려가며
	계산을 하면 답을 구할 수 있다. 또 이는 연속된 구간의 합을 구하는 것과 같아서, 펜윅트리를
	이용할 수 있다.
*/

#include <iostream>
#include <cstring>
using namespace std;

int C, N, M;
int fenwick[200001], no2pos[100001];

void update(int pos, int delta) {
	while (pos <= 200000) {
		fenwick[pos] += delta;
		pos += pos & (-pos);
	}
}

int pSum(int pos) {
	int ret = 0;
	while (pos > 0) {
		ret += fenwick[pos];
		pos &= pos - 1;
	}
	return ret;
}

void init() {
	memset(fenwick, 0, sizeof(fenwick));
	for (int i = 1; i <= N; i++) {
		no2pos[i] = N + 1 - i;
		update(no2pos[i], 1);
	}
}

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);
	cin >> C;
	while (C--) {
		cin >> N >> M;
		init();
		for (int i = 1, a; i <= M; i++) {
			cin >> a;
			cout << N - pSum(no2pos[a]) << " ";

			update(no2pos[a], -1);
			no2pos[a] = N + i;
			update(no2pos[a], 1);
		}
		cout << '\n';
	}
}