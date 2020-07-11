/* https://www.acmicpc.net/problem/1516 */

/*
	��������, DP ������ ������ �ذ� ������ ����. ������ �ǹ��� ���� ���� ���� ����� �ϴ� �͵� ��
	���� �����ɸ��� ���� ���ϸ� ������ �ذ��� �� �ִ�.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, cache[500], createTime[500];
vector<int> prerequisite[500];

int DP(int idx) {
	if (prerequisite[idx].empty()) return createTime[idx];

	int& ret = cache[idx];
	if (ret) return ret;

	for (auto it : prerequisite[idx])
		ret = max(ret, DP(it));

	return ret += createTime[idx];
}

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	for (int i = 0, a; i < N; i++) {
		cin >> createTime[i];
		while (1) {
			cin >> a;
			if (a == -1) break;
			prerequisite[i].push_back(a - 1);
		}
	}

	for (int i = 0; i < N; i++)
		cout << DP(i) << '\n';
}