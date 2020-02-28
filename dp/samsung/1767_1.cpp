#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dir[4][2]
{
	{-1,0},
	{0,1},
	{1,0},
	{0,-1},
};

int getMinLen(int yPos,int xPos, vector<vector<int>>& cells)
{
	int optimumDir= -1;
	int minLen=1234567;
	//4���� ������ ���鼭 �����ΰ� ����Ǿ��� ���� �ּұ��̸� ���Ѵ�. �����ΰ� ������� ������ ���� ������ -1�̴�.
	for (int dIdx = 0; dIdx < 4; dIdx++)
	{
		int len = 0;
		   
		int y=yPos+ dir[dIdx][0];
		int x=xPos+ dir[dIdx][1];

		while (x >= 0 && x < cells.size() && y >= 0 && y < cells.size() && !cells[y][x])
		{
			len++;
			y += dir[dIdx][0];
			x += dir[dIdx][1];
		}
		
		if (x < 0 || x == cells.size() || y < 0 || y == cells.size())//�����ο���Ǿ��� ��
		{
			if (minLen > len)
			{
				optimumDir = dIdx;
				minLen = len;
			}
		}
	}
	cells[yPos][xPos] = 3;//����ȭ���� �� ǥ��
	if (optimumDir == -1)
	{
		return 0;
	}
	else//���������� �������� ��� ���̸� �������ش�. �ھ�� �����ϱ� ���ؼ� �� 2�� �־��ش�.
	{
		yPos += dir[optimumDir][0];
		xPos += dir[optimumDir][1];

		while (xPos >= 0 && xPos < cells.size() && yPos >= 0 && yPos < cells.size())
		{
			cells[yPos][xPos] = 2;
			yPos += dir[optimumDir][0];
			xPos += dir[optimumDir][1];
		}
	}
	return minLen;
}

int getMaxConnectedLenRecursive(vector<vector<int>>& cells)
{	
	bool state = true;
	int xPos;
	int yPos;
	//��������
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
	
	if (state)
	{
		return 0;
	}
	//����
	return getMinLen(yPos, xPos, cells) + getMaxConnectedLenRecursive(cells);
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
		vector<vector<int>> MexinosCells(size,vs);
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cin >> MexinosCells[i][j];
			}
		}
		sum = getMaxConnectedLenRecursive(MexinosCells);
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << MexinosCells[i][j] << " ";
			}
			cout << endl;
		}
		cout << "#" << test_case << " " << sum << endl;
	}
	return 0;
}