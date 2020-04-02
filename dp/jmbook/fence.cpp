#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*
���� ���� �������� ���ڵ��� ����ġ�ٰ� ���� ���ڰ� ���δٸ�,
���� ������ ������ ���̸� ���Ѵ�. ���̴� �ִ� ���̷� ��� �����Ѵ�.

���� ���ڰ� ���δٸ� ���ڵ��� ����ģ��.

������ ���� �ִ� 20000���̱� ������ �־��� ��� 400000000
 4��... 4��
 
 ��������?

 <���̸� ���� �� ���簢���� �ִ� ũ�⸦ ����ϱ�>

���� ���� now, �������� ��next

now <= next : now�������� ����ؼ� �ʺ� �ø���. �׸��� next �������� ���Ӱ�
�ʺ� ���Ѵ�.

now > next : ��������� �ʺ� ���Ѵ�.(�������)

����, ����, ����,
 */
int maxRec = 0;
void calRectMaxSizeRecursive(int now, int size, vector<int>& h)
{
	int next;
	next = now + 1;

	//��������
	if (now > h.size() - 1)
	{
		maxRec = max(maxRec, size);
		return;
	}
	//����Լ� ȣ�� : ���̸� ����Ѵ�.
	if (h[now] > h[next])
	{
		//���翡�� �����.
		maxRec = max(maxRec, size + h[now]);
		//���� �ʺ�� �����ش�.
		calRectMaxSizeRecursive(now + 1, size + h[next], h);
	}
	
	if(h[now] <= h[next])
	{
		//���� �ʺ� �̾��.
		calRectMaxSizeRecursive(now + 1, size + h[now], h);
		//���Ӱ� �ʺ� ���Ѵ�.
		calRectMaxSizeRecursive(now + 1, 0, h);
	}
}

int main()
{
	int tc;
	int n;
	int value;
	vector<int> h;
	cin >> tc;
	while (tc--)
	{
		cin >> n;
		h = vector<int>();
		while (n--)
		{
			cin >> value;
			h.push_back(value);
		}
		maxRec = 0;
		calRectMaxSizeRecursive(0,0,h);
		cout << maxRec << endl;
	}
	return 0;
}