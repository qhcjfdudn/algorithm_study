/* https://www.acmicpc.net/problem/12738 */

/*
	LIS를 O(NlgN)의 시간복잡도에 해결해야 하는 가장 기본적인 문제.
	그리디 적인 생각으로 이진 탐색을 통해 해결할 수 있다.
	증가하는 부분수열을 만들면서,
	부분 수열 내에서 임의의 수의 위치가 결정되었을 때, 부분 수열의 동일한 인덱스를 갖는 다른 수 중
	가장 작은 값을 부분 수열의 값으로 취한다. 이렇게 하면 LIS가 되는 이 수보다 큰 다른 수를 부분 수열에
	포함하면서 LIS의 특성을 유지해나갈 수 있다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, sz;

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	vector<int> ret;

	for (int i = 0, num; i < N; i++) {
		cin >> num;
		int index = lower_bound(ret.begin(), ret.end(), num) - ret.begin();
		if (sz == index) ret.push_back(num), sz++;
		else ret[index] = num;
	}

	cout << sz << '\n';
}