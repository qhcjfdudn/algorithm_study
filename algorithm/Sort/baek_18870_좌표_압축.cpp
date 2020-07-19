/* https://www.acmicpc.net/problem/18870 */

/*
	������ ���� ������ �� �ִ� ������ ��ǥ ���� ����.
	������ �ε����� ���ؼ� ������ �Ǵ� ���� �ε����� �� ���� ã�� �� �ִ�.
*/

#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, pair<int, int>> piii;

int N, ans[1000000];
piii V[1000000];

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> V[i].first;
		V[i].second.first = i;
	}

	sort(V, V + N);

	int num = V[0].first;
	V[0].second.second = 0;
	for (int i = 1; i < N; i++) V[i].second.second = V[i - 1].second.second + (V[i].first != V[i - 1].first);

	for (int i = 0; i < N; i++) ans[V[i].second.first] = V[i].second.second;

	for (int i = 0; i < N; i++) cout << ans[i] << " ";
}