#include<iostream>
#include<vector>

using namespace std;

//��ǻ���� ���� n��,
//��� ��带 �� �湮�� ������ dfs�� �Ѵ�.
//
void dfs(vector<int> isVisited, int idx, vector<vector<int>> computers)
{
	isVisited[idx] = 1;

	for (int i = 0; i < computers.size(); i++)
	{
		if (computers[idx][i] == 1 && !isVisited[i])
		{
			dfs(isVisited, i, computers);
		}
	}
}
int solution(int n, vector<vector<int>> computers)
{
	int answer = 0;
	int count = 0;
	vector<int> isVisited(n, 0);

	for (int i = 0; i < n; i++)
	{
		if (isVisited[i] != 0)
		{
			answer++;
			dfs(isVisited, i, computers);
		}
	}
	return answer;
}