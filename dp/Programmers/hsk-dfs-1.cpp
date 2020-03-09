#include <iostream>
#include <vector>

using namespace std;

int numbers[5] = { 1,1,1,1,1 };
int counts = 0;

//+1 �̳� -1�� �ؼ� target number�� �����.
//�׻��ؾ��ϴ� ���� ����, �ڷ� numbers�� �̿��Ѵ�.
//������ʴ� ��� �ڷḦ �� ������� �� �����Ѵ�.
void getWaysRecursive(vector<int> numbers, int idx, int subject, int targetNumber)
{

	if (idx == numbers.size())
	{
		if (subject == targetNumber)
		{
			counts++;
		}
		return;
	}

	getWaysRecursive(numbers, idx + 1, subject + numbers[idx], targetNumber);

	getWaysRecursive(numbers, idx + 1, subject - numbers[idx], targetNumber);
}

int solution(vector<int> numbers, int target) {
	getWaysRecursive(numbers, 0, 0, 3);
	return counts;
}

int main() {
	vector<int> v(numbers, numbers + 5);
	std::cout << solution(v, 3) << endl;
}