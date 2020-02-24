/*n���� ���� �� m���� ���� ��� ������ ã�� �˰���*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//n:��ü ������ ��
//picked : ���ݱ��� �� ���ҵ��� ��ȣ
//toPick : �� �� ������ ��
//�� ��, ������ toPick ���� ���Ҹ� ���� ��� ����� ����Ѵ�.
void printPicked(vector<int>& v)
{
	for (int element : v)
	{
		cout << element << " ";
	}
	cout << endl;
}
void pick(int n, vector<int>& picked, int toPick)
{
	//���� ��� : �� �� ���Ұ� ���� �� �� ���ҵ��� ����Ѵ�.
	if (toPick == 0)
	{
		printPicked(picked);
		return;
	}
	//�� �� �ִ� ���� ���� ��ȣ�� ����Ѵ�.
	int smallest = picked.empty() ? 0 : picked.back() + 1;
	//�� �ܰ迡�� ���� �ϳ��� ����.
	for (int next = smallest; next < n; ++next)
	{
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		picked.pop_back();
	}
}
int main()
{
	vector<int> testCase;
	pick(5, testCase, 3);
	
	//abc�� �������� �����س���
	vector<char> testCase2 = { 'a','b','c' };
	//next_permutation(testCase2.begin(), testCase2.end());
	cout << "The 3! possible permutations with 3 elements:\n";
	do {
		std::cout << testCase2[0] << ' ' << testCase2[1] << ' ' << testCase2[2] << '\n';
	} while (next_permutation(testCase2, testCase2.begin() + 3));
	return 0;
}