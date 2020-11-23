//��������������У�����������������
//��ƺ����� ͳ�ƶ������ĸ߶�
//��ƺ�����ͳ�ƶ�������Ҷ�ӽ��
//���������������������ö���������������������У���֤�����Ķ����������Ƿ���ȷ

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct bitree      //����������ڵ�洢�ṹ
{
	int data;
	struct bitree* lchild;
	struct bitree* rchild;
}Bitree;

typedef struct			  //�������������
{
	Bitree* root;
}Tree;

void createtree(Tree* tree, int x);				   //����������
void treehigh(bitree* p, int& high);			  //ͳ�ƶ������߶�
void countleaf(bitree* root, int& count);		 //ͳ�ƶ�����Ҷ�ӽڵ�
void visit(Bitree* root);					    //����ڵ�
void inOrder(Bitree* root);					   //�����������

int main()
{
	int DataCount, MaxData;
	int a[20];
	Tree tree;
	tree.root = NULL;
	int  height, num = 0;
	srand((int)time(0));
	cout << "\aPlease input the DataCount(10~20) & MaxData(50~100) :\n__ __\b\b\b\b\b";
	cin >> DataCount >> MaxData;				 //�������ݴ�С�����ֵ
	for (int i = 0; i < DataCount; i++)
	{
		a[i] = rand() % (MaxData + 1) + 1;       //����DataCount����0��MaxData֮��������
	}
	for (int i = 0; i < DataCount; i++)
	{
		if (i == 0)
		{
			cout << "�����ɵ�����Ϊ��" << endl;
		}
		cout << a[i] << endl;
		if (i == DataCount - 1)
		{
			cout << endl;
		}
	}
	for (int j = 0; j < DataCount; j++)
	{
		createtree(&tree, a[j]);				//����������
	}
	treehigh(tree.root, height);				//������
	cout << "�������ĸ߶��ǣ�" << height << endl;
	countleaf(tree.root, num);					//��Ҷ����
	cout << "��������Ҷ�ӽڵ����ǣ�" << num << endl;		
	cout << "������������" << endl;
	inOrder(tree.root);
	return 0;
}

void createtree(Tree* tree, int x)		//����������
{
	Bitree* bitree = new Bitree;        //�����ڴ�
	bitree->data = x;					//��������
	bitree->lchild = NULL;
	bitree->rchild = NULL;
	if (tree->root == NULL)
	{
		tree->root = bitree;
	}
	else 
	{
		Bitree* temp = tree->root;   //��ʱ�����洢�ڵ�
		while (temp != NULL)
		{
			if (x < temp->data)     //��������С�ڽڵ�����
			{
				if (temp->lchild == NULL)
				{
					temp->lchild = bitree;
					return;
				}
				else 
				{
					temp = temp->lchild;
				}
			}
			else                    //�������ݴ��ڽڵ�����
			{
				if (temp->rchild == NULL)
				{
					temp->rchild = bitree;
					return;
				}
				else 
				{
					temp = temp->rchild;
				}
			}
		}
	}
	return;
}

void treehigh(bitree* p, int& high)    //ͳ�ƶ������߶ȣ�pָ����ڵ�
{
	if (p == 0)
	{
		high = 0;
		return;
	}
	else 
	{
		int lhigh, rhigh;
		treehigh(p->lchild, lhigh);  //���������߶�
		treehigh(p->rchild, rhigh);  //���������߶�
		if (lhigh >= rhigh) 
		{
			high = lhigh + 1;
		}
		else 
		{
			high = rhigh + 1;
		}
	}
}

void countleaf(bitree* root, int& count)	//ͳ�ƶ�����Ҷ�ӽڵ�
{
	if (root == 0) 
	{
		return;
	}
	else if (root->lchild == NULL && root->rchild == NULL)
	{
		count++;
		return;
	}
	else 
	{
		countleaf(root->lchild, count);
		countleaf(root->rchild, count);
	}
}

void visit(Bitree* root)     //����ڵ�
{
	cout << root->data << endl;
}

void inOrder(Bitree* root)			//�����������
{
	if (root != NULL)
	{
		inOrder(root->lchild);
		visit(root);
		inOrder(root->rchild);
	}
}