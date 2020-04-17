/* https://programmers.co.kr/learn/courses/30/lessons/62048?language=cpp */

/*
	그림을 통해 보았을 때, 동일한 모양이 여러 개 반복 될 수 있음을 알 수 있다.
	동일한 모양이 반복되는 경우는 W와 H가 1보다 큰 공약수를 갖고 있을 때이다.
	이는 공약수 개수 만큼 존재하고, 하나의 모양을 형성하는 것의 개수는 이를 구성하는
	가로 + 세로 - 1개임을 알 수 있다. 이를 통해 답을 도출할 수 있다.
*/

using namespace std;

long long gcd(long long a, long long b) {
	return a % b ? gcd(b, a % b) : b;
}

long long solution(int w, int h)
{
	long long M = gcd(w, h);
	long long nw = w / M, nh = h / M;

	return (long long)w * (long long)h - (nw + nh - 1) * M;
}