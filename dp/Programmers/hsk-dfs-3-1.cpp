/*

target�� words ���� �־�� ��.
begin���� �ܾ� �� ���� �ٲ㼭 target�� �Ǿ�� ��.

��� ��츦 �� Ž���ϴ� dfs�� ��������



*/

#include <string>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

int countToMakeTarget = 0;
int mincnt = 987654321;

void calculateCountToMakeTargetRecursive(string subject, string target, int cnt, vector<string>& words, vector<int>& isVisited)
{
	//1���� ���̰� �ȳ��� ��찡 ���� �� ���� ->�����ع���
	//Ÿ�ٰ� ������Ʈ�� ���ٸ� ī������ �� ����
	//��� �ܾ���� �湮�ߴٸ� ����

	if (subject == target)
	{
		if (cnt < mincnt)
		{
			mincnt = cnt;
		}
	}

	for (int i = 0; i < words.size(); i++)
	{
		int dif = 0;

		if (isVisited[i])
			continue;

		for (int j = 0; j < words[i].size(); j++)
		{
			if (words[i][j] != subject[j])
			{
				dif++;
			}
		}

		if (dif > 1)
			continue;

		if (dif == 1)
		{
			//dfs
			isVisited[i] = 1;
			calculateCountToMakeTargetRecursive(words[i], target, cnt+1, words, isVisited);
			isVisited[i] = 0;
		}
	}
}

int solution(string begin, string target, vector<string> words)
{
	//Ÿ���� words ���� �־�� ��.
	
	for (int i = 0; i < words.size(); i++)
	{
		if (words[i] == target)
		{
			//dfs
			vector<int> isVisited(words.size(), 0);
			calculateCountToMakeTargetRecursive(begin, target, 0, words, isVisited);
			//������ ����
			return mincnt;
		}
	}
	return 0;
}

int main()
{

}