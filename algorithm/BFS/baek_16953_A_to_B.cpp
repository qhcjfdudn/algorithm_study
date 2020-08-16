/* https://www.acmicpc.net/problem/16953 */

/*
	맵을 써서 중복을 제거하면 오히려 더 오래 걸리는 문제.
	만들어지는 값을 통해서 다소 중복 탐색을 허용해도 차라리 그게 더 빠르다는 것을
	이해할 수 있다.
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