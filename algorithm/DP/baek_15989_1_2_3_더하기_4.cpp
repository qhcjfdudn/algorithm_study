/* https://www.acmicpc.net/problem/15989 */

/*
	���ϴ� ������ ������ ������ �Ѵ�. ��������� ������ ������ �����ϴ� ������ �ذ��غ���.
	���� ���� �� ������ ������ �ݺ��ǵ��� ��Ÿ���� �� ��쿣 memoization�� ����� �� �ֱ� ������
	DP�� ����� Ǯ�̸� ��������.
*/

#include <iostream>
#include <cstring>
using namespace std;

int T, N, cache[10001][4];

// ����� Ǯ��
int DP(int v, int e) {
	// 1. base case
	if (v == 0) return 1;
	if (v < 0) return 0;

	// 2. �ݺ� ����. memoization
	int &ret = cache[v][e];
	if (ret != -1) return ret;

	// 3. �����ϱ�
	ret = 0;
	for (int i = 1; i <= e; i++)
		ret += DP(v - i, i);

	// 4. ����
	return ret;
}

int main() {
	memset(cache, -1, sizeof(cache));

	cin >> T;

	while (T--) {
		cin >> N;
		cout << DP(N, 3) << '\n';
	}
}