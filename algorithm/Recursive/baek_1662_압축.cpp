/* https://www.acmicpc.net/problem/1662 */

/*
	���ڿ��� �Ź� ���� ���� �ʿ� ���� ������ �����ϴ� ��� �Լ��� �����Ѵ�.
*/

#include <cstdio>

struct retVal {
	int cnt, offset;
	retVal(int _c, int _o) : cnt(_c), offset(_o) {}
};

char str[51];
int len;

retVal rec(int cursor) {
	int ret = 0;

	while (cursor != len) {
		if (str[cursor] == '(') {
			retVal next = rec(cursor + 1);
			ret += next.cnt * (str[cursor - 1] - '0') - 1;
			cursor = next.offset + 1;
		}
		else if (str[cursor] == ')') {
			return { ret, cursor };
		}
		else { cursor++; ret++; }
	}
	return { ret, cursor };
}

int main() {
	scanf("%s", str);
	while (str[len]) len++;

	printf("%d\n", rec(0).cnt);

	return 0;
}