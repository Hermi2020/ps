//�θ� ��带 ã�� �Լ�
int getParent(int parent[], int x)
{
	if (parent[x] == x)
	{
		return x;
	}
	return parent[x] = getParent(parent, parent[x]);
}

//�� �θ� ��带 ��ġ�� �Լ�
int unionParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b)
	{
		parent[b] = a;
	}
	else
	{
		parent[a] = b;
	}
}
//���� �θ� �������� Ȯ��              
int findParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) 
	{
		return 1;
	}
	else
	{
		return 0;
	}
}