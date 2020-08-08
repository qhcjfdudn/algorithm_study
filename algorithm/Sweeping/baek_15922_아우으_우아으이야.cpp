/* https://www.acmicpc.net/problem/15922 */

/*
	라인스위핑으로 간단히 풀 수 있는 문제.
	스택을 사용하는 것도 가능하다.
*/

#include <iostream>
using namespace std;

long long N, sumLine, x, y;

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	x = y = -2e9;

	for (int i = 0, nx, ny; i < N; i++) {
		cin >> nx >> ny;
		if (y < nx) {
			sumLine += y - x;
			x = nx;
		}
		if (y < ny) y = ny;
	}

	cout << sumLine + y - x << '\n';
}