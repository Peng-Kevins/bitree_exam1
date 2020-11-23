//生成随机数据序列，并创建二叉排序树
//设计函数， 统计二叉树的高度
//设计函数，统计二叉树的叶子结点
//设计中序遍历函数，遍历该二叉排序树，输出便利序列，验证创建的二叉排序树是否正确

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct bitree      //定义二叉树节点存储结构
{
	int data;
	struct bitree* lchild;
	struct bitree* rchild;
}Bitree;

typedef struct			  //定义二叉树树根
{
	Bitree* root;
}Tree;

void createtree(Tree* tree, int x);				   //创建二叉树
void treehigh(bitree* p, int& high);			  //统计二叉树高度
void countleaf(bitree* root, int& count);		 //统计二叉树叶子节点
void visit(Bitree* root);					    //输出节点
void inOrder(Bitree* root);					   //中序遍历函数

int main()
{
	int DataCount, MaxData;
	int a[20];
	Tree tree;
	tree.root = NULL;
	int  height, num = 0;
	srand((int)time(0));
	cout << "\aPlease input the DataCount(10~20) & MaxData(50~100) :\n__ __\b\b\b\b\b";
	cin >> DataCount >> MaxData;				 //输入数据大小和最大值
	for (int i = 0; i < DataCount; i++)
	{
		a[i] = rand() % (MaxData + 1) + 1;       //生成DataCount个在0和MaxData之间的随机数
	}
	for (int i = 0; i < DataCount; i++)
	{
		if (i == 0)
		{
			cout << "所生成的数据为：" << endl;
		}
		cout << a[i] << endl;
		if (i == DataCount - 1)
		{
			cout << endl;
		}
	}
	for (int j = 0; j < DataCount; j++)
	{
		createtree(&tree, a[j]);				//创建二叉树
	}
	treehigh(tree.root, height);				//求树高
	cout << "二叉树的高度是：" << height << endl;
	countleaf(tree.root, num);					//求叶子数
	cout << "二叉树的叶子节点数是：" << num << endl;		
	cout << "中序遍历结果：" << endl;
	inOrder(tree.root);
	return 0;
}

void createtree(Tree* tree, int x)		//创建二叉树
{
	Bitree* bitree = new Bitree;        //分配内存
	bitree->data = x;					//传入数据
	bitree->lchild = NULL;
	bitree->rchild = NULL;
	if (tree->root == NULL)
	{
		tree->root = bitree;
	}
	else 
	{
		Bitree* temp = tree->root;   //临时变量存储节点
		while (temp != NULL)
		{
			if (x < temp->data)     //传入数据小于节点数据
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
			else                    //传入数据大于节点数据
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

void treehigh(bitree* p, int& high)    //统计二叉树高度，p指向根节点
{
	if (p == 0)
	{
		high = 0;
		return;
	}
	else 
	{
		int lhigh, rhigh;
		treehigh(p->lchild, lhigh);  //求左子树高度
		treehigh(p->rchild, rhigh);  //求右子树高度
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

void countleaf(bitree* root, int& count)	//统计二叉树叶子节点
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

void visit(Bitree* root)     //输出节点
{
	cout << root->data << endl;
}

void inOrder(Bitree* root)			//中序遍历函数
{
	if (root != NULL)
	{
		inOrder(root->lchild);
		visit(root);
		inOrder(root->rchild);
	}
}