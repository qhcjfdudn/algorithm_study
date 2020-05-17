/* https://www.acmicpc.net/problem/1480 */

/*
	�賶 �迭�� �ϳ��� ���� ������ ä���.
	�� �� ������ ä��� ������ ������ ����, ������ �ϳ��� �����ϹǷ� ��Ʈ����ũ�� �̿��Ͽ�
	�޸𸮸� ����ȭ�� �� �ִ�. �̸� Ȱ���� DP�� �����Ѵ�.
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, C, weight[13], cache[1 << 13][10][21];

int DP(int bit, int numBack, int curWei) {
	if (numBack == M || bit == (1 << N) - 1) return 0;

	int &ret = cache[bit][numBack][curWei];
	if (ret != -1) return ret;

	for (int i = 0; i < N; i++) {
		if ((1 << i) & bit) continue;
		if (curWei + weight[i] <= C)
			ret = max(ret, DP(bit | (1 << i), numBack, curWei + weight[i]) + 1);
	}
	ret = max(ret, DP(bit, numBack + 1, 0));

	return ret;
}

int main() {
	cin >> N >> M >> C;
	for (int i = 0; i < N; i++) cin >> weight[i];
	memset(cache, -1, sizeof(cache));

	cout << DP(0, 0, 0) << '\n';
}