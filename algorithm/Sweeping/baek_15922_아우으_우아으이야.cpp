/* https://www.acmicpc.net/problem/15922 */

/*
	���ν��������� ������ Ǯ �� �ִ� ����.
	������ ����ϴ� �͵� �����ϴ�.
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