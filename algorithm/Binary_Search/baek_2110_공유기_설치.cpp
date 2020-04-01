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