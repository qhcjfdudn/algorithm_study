/* https://www.acmicpc.net/problem/1806 */

/*
	어떤 부분 수열의 합이 S인 구간이 있다고 하자. 각 원소는 자연수이다.
	이 부분 수열에서 왼쪽 또는 오른쪽에 어떤 수를 빼어주면 그 때의 부분 수열의 합은 S보다 작다.
	또 왼쪽 또는 오른쪽에 어떤 수를 더해주면 그 수는 S보다 크게 된다.
	즉 전체 부분 수열을 왼쪽에서부터 오른쪽으로 그 합을 유지해가며 계산하다 합이 S보다 커지면
	왼쪽에서부터 제외해주면서 부분 수열을 결정해나가면 답을 구할 수 있다.
*/

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int N, S, ans = 100000;

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);
	deque<int> DQ;

	cin >> N >> S;

	for (int i = 0, num, pSum = 0; i < N; i++) {
		cin >> num;
		pSum += num;
		DQ.push_back(num);
		while (pSum >= S) {
			ans = min(ans, (int)DQ.size());
			pSum -= DQ.front(); DQ.pop_front();
		}
	}
	if (ans == 100000) ans = 0;

	cout << ans << '\n';
}