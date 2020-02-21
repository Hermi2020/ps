#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//12345/ 1�� ������ ���� ����
//21232425/ 2�� ������ ���� ����
//3311224455/ 3�� ������ ���� ���� 
/*
	1. ����� ������ ���� ��
	2. ���� Ƚ�� ���
	3. ���� ���� ���� ����� ��ȣ�� ���, ���� ���� 1���� ��� �������� ������ ����� ����Ѵ�.
*/
vector<int> solution(vector<int> answers)
{
	vector<int> answer;
	int maxElement;

	int a[5] = { 1,2,3,4,5 };
	int b[8] = { 2,1,2,3,2,4,2,5 };
	int c[10] = { 3,3,1,1,2,2,4,4,5,5 };

	vector<int> count(3);

	for (int i = 0; i < answers.size(); i++)
	{
		if (answers[i] == a[i % 5])
		{
			count[0]++;
		}
		if (answers[i] == b[i % 8])
		{
			count[1]++;
		}
		if (answers[i] == c[i % 10])
		{
			count[2]++;
		}
	}

	maxElement=*max_element(count.begin(), count.end());

	for (int i = 0; i < 3; i++)
	{
		if (count[i] == maxElement)
		{
			answer.push_back(i + 1);
		}
	}

	return answer;
}

int main()
{
	vector<int> answers = { 1,2,3,4,5 };
	vector<int> result;

	result = solution(answers);
	return 0;
}