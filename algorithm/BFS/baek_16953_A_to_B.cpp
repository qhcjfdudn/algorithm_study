/* https://www.acmicpc.net/problem/16953 */

/*
	���� �Ἥ �ߺ��� �����ϸ� ������ �� ���� �ɸ��� ����.
	��������� ���� ���ؼ� �ټ� �ߺ� Ž���� ����ص� ���� �װ� �� �����ٴ� ����
	������ �� �ִ�.
*/

#include <iostream>
#include <queue>
using namespace std;
typedef pair<long long, int> pli;

long long A, B;

int solve() {
	queue < pli > Q;
	Q.push({ A, 0 });

	while (!Q.empty()) {
		pli cur = Q.front(); Q.pop();
		long long nextNum[2] = { cur.first * 2, cur.first * 10 + 1 };

		for (int i = 0; i < 2; i++) {
			if (nextNum[i] <= B) {
				if (nextNum[i] == B) return cur.second + 2;
				Q.push({ nextNum[i], cur.second + 1 });
			}
		}
	}
	return -1;
}

int main() {
	cin >> A >> B;

	cout << solve() << '\n';
}