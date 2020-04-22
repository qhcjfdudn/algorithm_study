/* https://www.acmicpc.net/problem/14427 */

/*
	구간에 대한 질의가 들어왔을 때 이를 빠르게 구하기 위해서는 부분합 배열과 같이 구간에 대해 미리 연산 결과를
	구해놓고 값을 리턴하는 방법을 들 수 있다. 이 경우에 어떤 요소의 값이 변경되는 경우, 이를 포함하는 미리
	구해놓았던 연산 결과 또한 수정을 해야 하기 때문에, 이 과정의 시간복잡도를 줄여야 한다.
	세그먼트 트리가 이에 대한 답이다.
	부분합 배열의 경우에 최악의 경우 부분합 배열 전체의 값을 새로 계산해야할 수 있기 때문에, 시간복잡도는 선형 시간이다.
	세그먼트 트리의 경우, 어떤 노드가 값이 바뀌면 이를 포함하는 구간의 노드들의 값만을 변경하면 되기 때문에,
	시간복잡도는 로그 시간이 된다.
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	int v, idx;
	Node(int _v = 1e9 + 1, int _idx = 0) : v(_v), idx(_idx) {}
	bool operator < (const Node &rhs) const {
		if (v == rhs.v) return idx < rhs.idx;
		return v < rhs.v;
	}
};

int N, M, A[100001];
Node seg[1 << 18];

Node update(int cur_idx, int idx, int left, int right) {
	if (cur_idx < left || cur_idx > right) return seg[idx];
	if (left == right)
		return seg[idx] = Node(A[cur_idx], cur_idx);

	int mid = (left + right) / 2;
	return seg[idx] = min(update(cur_idx, idx * 2, left, mid),
		update(cur_idx, idx * 2 + 1, mid + 1, right));
}

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		update(i, 1, 1, N);
	}

	cin >> M;
	for (int i = 0, q, a, b; i < M; i++) {
		cin >> q;
		if (q == 1) {
			cin >> a >> b;
			A[a] = b;
			update(a, 1, 1, N);
		}
		else cout << seg[1].idx << '\n';
	}
}