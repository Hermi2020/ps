#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> result;
typedef struct connectInfo {
	int powerCount;
	int len;
}ConnectInfo;
int dir[4][2]
{
	{-1,0},
	{0,1},
	{1,0},
	{0,-1},
};

ConnectInfo set(int dIdx, int yPos, int xPos, vector<vector<int>>& cells)
{
	ConnectInfo result;
	bool bFlagConnected = false;
	int len = 0;
	int y = yPos;
	int x = xPos;

	cells[y][x] = 3;//�湮ǥ��

	//�����ο� ������ ���
	if (dIdx == 0 && yPos == 0)
	{
		result.powerCount = 1;
		result.len = 0;
		return result;
	}
	else if (dIdx == 1 && xPos == cells.size() - 1)
	{
		result.powerCount = 1;
		result.len = 0;
		return result;
	}
	else if (dIdx == 2 && yPos == cells.size() - 1)
	{
		result.powerCount = 1;
		result.len = 0;
		return result;
	}
	else if (dIdx == 3 && xPos == 0)
	{
		result.powerCount = 1;
		result.len = 0;
		return result;
	}
	else if (dIdx == 4)
	{
		result.powerCount = 0;
		result.len = 0;
		return result;
	}

	//Ư�� ������ �����α��� ������ �� �� �ִ°�?
	y = yPos + dir[dIdx][0];
	x = xPos + dir[dIdx][1];

	while (y >= 0 && y < cells.size() && x >= 0 && x < cells.size())
	{
		if (cells[y][x] == 1 || cells[y][x] == 2 || cells[y][x] == 3 || cells[y][x] == -1) //��ֹ��� ������ ���
		{
			break;
		}
		if (y == 0 || y == cells.size() - 1 || x == 0 || x == cells.size() - 1) //������ ������ �������� ���
		{
			bFlagConnected = true;
		}
		y += dir[dIdx][0];
		x += dir[dIdx][1];
	}

	if (!bFlagConnected)
	{
		result.powerCount = 0;
		result.len = 0;
		return result;
	}
	else
	{
		y = yPos + dir[dIdx][0];
		x = xPos + dir[dIdx][1];

		while (y >= 0 && y < cells.size() && x >= 0 && x < cells.size() && !cells[y][x])
		{
			cells[y][x] = 2;//����ǥ��
			y += dir[dIdx][0];
			x += dir[dIdx][1];
			len++;
		}
		result.powerCount = 1;
		result.len = len;
		return result;
	}
}

void unset(int dIdx, int yPos, int xPos, vector<vector<int>> cells, vector<vector<int>> restore)
{
	cells = restore;
}

ConnectInfo getMaxConnectedLenRecursive(vector<vector<int>>& cells, int power, int len)
{
	ConnectInfo info = { 0,0 };
	vector<vector<int>> restoreV = cells;
	bool state = true;
	int xPos;
	int yPos;

	//�湮����
	for (int i = 0; i < cells.size(); i++)
	{
		for (int j = 0; j < cells.size(); j++)
		{
			if (cells[i][j] == 1)
			{
				state = false;
				yPos = i;
				xPos = j;
				break;
			}
		}
		if (!state)
		{
			break;
		}
	}

	//��� ��带 �湮�ߴٸ� ����
	if (state)
	{
		ConnectInfo result;
		result.powerCount = power;
		result.len = len;

		return result;
	}

	int powerMax = -1;
	int lenMin = 1000;

	for (int dIdx = 0; dIdx < 5; dIdx++)
	{
		//����
		ConnectInfo afterSetInfo = set(dIdx, yPos, xPos, cells);

		//������ ������ ���������� Ž���ϰ�, ���Ѵ�.
		info = getMaxConnectedLenRecursive(cells, power + afterSetInfo.powerCount, len + afterSetInfo.len);
		if (info.powerCount > powerMax && info.len < lenMin)
		{
			powerMax = info.powerCount;
			lenMin = info.len;
		}
		//����
		unset(dIdx, yPos, xPos, cells, restoreV);
	}
	info.powerCount = powerMax;
	info.len = lenMin;
	return info;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	int size;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> size;
		int sum = 0;
		vector<int> vs(size, 0);
		vector<vector<int>> MexinosCells(size, vs);
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cin >> MexinosCells[i][j];
			}
		}
		ConnectInfo ret = getMaxConnectedLenRecursive(MexinosCells, 0, 0);

		cout << "#" << test_case << " "<<ret.powerCount << " " << ret.len << endl;

	}
	return 0;
}