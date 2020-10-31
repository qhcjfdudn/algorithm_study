/* https://www.acmicpc.net/problem/14891 */

/*
	입력에서 bit를 사용하도록 유도하니.. bit로 풀자!
	사실 배열로 받고, 시작 인덱스만 움직여주는 게 제일 간단함.
*/

#include <stdio.h>

int gears[6], K, visited[6];

void init() {
	char bits[9];

	for (int i = 1; i <= 4; ++i) {
		scanf("%s", bits);
		for (int j = 0; j < 8; ++j) {
			gears[i] <<= 1;
			gears[i] |= (bits[j] == '1');
		}
	}
	scanf("%d", &K);
}
void rotate(int n, int d) {
	visited[n] = 1;

	if (visited[n - 1] == 0 && (!!(gears[n - 1] & (1 << 5))) ^ (!!(gears[n] & (1 << 1))))
		rotate(n - 1, d * -1);

	if (visited[n + 1] == 0 && (!!(gears[n] & (1 << 5))) ^ (!!(gears[n + 1] & (1 << 1))))
		rotate(n + 1, d * -1);

	if (d == 1) {
		gears[n] |= ((gears[n] & 1) << 8);
		gears[n] >>= 1;
	}
	else {
		gears[n] = (gears[n] << 1) | (gears[n] >> 7);
		gears[n] &= ~(1 << 8);
	}
}
int solve() {
	int ret = 0, num, dir;
	visited[0] = visited[5] = 1;

	while (K--) {
		scanf("%d %d", &num, &dir);
		for (int i = 1; i <= 4; ++i)
			visited[i] = 0;

		rotate(num, dir);
	}

	for (int i = 1; i <= 4; ++i)
		ret += (!!(gears[i] & (1 << 7))) << (i - 1);

	return ret;
}

int main() {
	init();

	printf("%d", solve());
}