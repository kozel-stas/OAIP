// LabTree.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Hlo
{
	int x;
	Hlo *Left, *Right;
};

void Add(int x, Hlo *&Tree);
void Show(Hlo *Tree);
int Find(int x,Hlo *Tree);
void Remove(Hlo *Tree);
void Delete(int x, Hlo *Tree);
void Del(int x, Hlo *Tree,Hlo *lol);

int main()
{ 
	setlocale(LC_ALL, "rus");
	Hlo *Tree = NULL;
	Add(15, Tree);
	Add(6, Tree);
	Add(8, Tree);
	Add(18, Tree);
	Add(16, Tree);
	Show(Tree);
	system("pause");
	return 0;
}

void Add(int x, Hlo *&Tree)
{
	if (Tree == NULL)
	{
		Tree = new Hlo;
		Tree->x = x;
		Tree->Left = NULL;
		Tree->Right = NULL;
	}
	if (Tree->x > x)
	{
		if (Tree->Left != NULL) Add(x, Tree->Left);
		else
		{
			Tree->Left = new Hlo;
			Tree->Left->x = x;
			Tree->Left->Left = NULL;
			Tree->Left->Right = NULL;
		}
	}
	if (Tree->x < x)
	{
		if (Tree->Right != NULL) Add(x, Tree->Right);
		else
		{
			Tree->Right = new Hlo;
			Tree->Right->x = x;
			Tree->Right->Left = NULL;
			Tree->Right->Right = NULL;
		}
	}
}

void Show(Hlo *Tree)
{
	if (Tree != NULL)
	{
		Show(Tree->Left);
		Show(Tree->Right);
		cout << Tree->x << " ";
    }
}

int Find(int x,Hlo *Tree)
{
	int y=NULL;
	if (Tree != NULL)
	{
		Find(x,Tree->Left);
		Find(x,Tree->Right);
		if (x == Tree->x)
			y = Tree->x;
	}
		return y;
}

void Del(int x, Hlo *Tree, Hlo *lol)
{
	if (Tree != NULL)
	{
		if (Tree->x != x)
		{
			Add(Tree->x, lol);
		}
		Del(x, Tree->Left, lol);
		Del(x, Tree->Right, lol);
	}
}

void Remove(Hlo *Tree)
{
	if (Tree != NULL) 
	{
		Remove(Tree->Left); 
		Remove(Tree->Right); 
		delete Tree; 
		Tree = NULL;
	}
}

void Delete(int x, Hlo *Tree)
{
	Hlo *lol = NULL;
	int y;
	y = Find(x, Tree);
	//if (y != NULL)
	//{
		Del(x, Tree, lol);
		Tree = lol;
	//}
	//else
	//	cout << "Такого элемента нет" << endl;
	
}