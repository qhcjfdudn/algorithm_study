/* https://www.acmicpc.net/problem/2011 */

/*
	주어진 코드를 여러가지 문자로 해석할 수 있는 이유는 어떤 두 자리의 숫자는 각각의 문자로 보거나,
	하나의 문자로 볼 수 있기 때문이다.
	ex) 17은 각각 1과 7의 AG로 보거나, Q 하나로 볼 수 있다.
	
	그럼 1714는 어떨까?
	앞에서부터 하나씩 보면, AGAD이지만, 17을 AG로 보든 Q로 보든, 그 뒤는 14가 된다. 이를 통해
	DP가 적용 가능함을 알 수 있다.
*/

#include <iostream>
#include <cstring>
using namespace std;

int N, cache[5000];
char code[5002];

int DP(int index) {
	if (index == N) return 1;
	if (code[index] == '0') return 0;

	int &ret = cache[index];
	if (ret != -1) return ret;

	ret = DP(index + 1);
	if (index + 1 != N && (code[index] == '1' || (code[index] == '2' && code[index + 1] < '7'))) {
		ret += DP(index + 2);
		ret %= 1000000;
	}
	return ret;
}

int main() {
	memset(cache, -1, sizeof(cache));

	cin >> code;
	N = strlen(code);

	cout << DP(0) << '\n';
}