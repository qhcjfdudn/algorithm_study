/* https://programmers.co.kr/learn/courses/30/lessons/62048?language=cpp */

/*
	�׸��� ���� ������ ��, ������ ����� ���� �� �ݺ� �� �� ������ �� �� �ִ�.
	������ ����� �ݺ��Ǵ� ���� W�� H�� 1���� ū ������� ���� ���� ���̴�.
	�̴� ����� ���� ��ŭ �����ϰ�, �ϳ��� ����� �����ϴ� ���� ������ �̸� �����ϴ�
	���� + ���� - 1������ �� �� �ִ�. �̸� ���� ���� ������ �� �ִ�.
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