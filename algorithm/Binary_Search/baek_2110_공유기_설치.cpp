/* https://www.acmicpc.net/problem/2110 */

/*
	공유기가 설치될 수 있는 간격을 임의로 정하고, 간격 내에서 공유기를 설치했을 때
	C개를 충족하지 못할 경우, 현재 설정한 간격보다 더 큰 간격 중에서는 답이 있을 수 없다.
	이와 같은 방법으로 간격이 될 수 있는 범위를 이진탐색으로 찾을 수 있다.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int H[200000], N, C;

void bin() {
	int L = 1, R = 1000000000;
	while (L <= R) {
		int mid = (L + R) / 2, cnt = 1, temp = H[0];
		for (int i = 1; i < N; i++) {
			if (temp + mid <= H[i]) {
				cnt++;
				temp = H[i];
			}
		}
		if (cnt >= C) L = mid + 1;
		else R = mid - 1;
	}
	cout << R;
}

int main() {
	cin >> N >> C;
	for (int i = 0; i < N; i++) cin >> H[i];
	sort(H, H + N);

	bin();
}