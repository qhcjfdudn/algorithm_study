/* https://www.acmicpc.net/problem/2042 */

/*
	���� ������ ����� �Ͼ��, ������ ���� ���Ѵ�. ���׸�Ʈ Ʈ���� ����ϱ� ������ ����.
*/


#include <iostream>

using namespace std;

long long tree[1000001] = {}, N, M, K;
int a, b, c;

long long sum(int index) {
	long long Sum = 0;
	while (index >= 1) {
		Sum += tree[index];
		index -= (index & -index);
	}
	return Sum;
}

long long getSection(int start, int end) {
	return sum(end) - sum(start - 1);
}

void update(int index, int value) {
	long long before = getSection(index, index);
	while (index <= N) {
		tree[index] += value;
		tree[index] -= before;
		index += (index & -index);
	}
}

void make(int index, int value) {

	while (index <= N) {
		tree[index] += value;
		index += (index & -index);
	}
}

int main() {
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		cin >> a;
		make(i + 1, a);
	}

	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;

		if (a == 1) update(b, c);
		else cout << getSection(b, c) << endl;
	}
}