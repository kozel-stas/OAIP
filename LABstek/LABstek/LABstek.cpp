// LABstek.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Stek
{
	int a;
	Stek *Head, *Next;
};

void Add(int a, Stek *&List);
void Show(Stek *List);
void Delete (Stek *List);
void Remove (Stek *List);
void FindandDel(Stek *List);
void Sort1(Stek *List);
void Sort2(Stek *List);

int main()
{
	setlocale(LC_ALL,"rus");
	Stek *List = new Stek;
	List->Head = NULL;
	bool sir = true;
	int num, nym;
	while (sir == true)
	{
		cout << " 1-добавление элемента \n 2-показать стек \n 3-удаление стека \n 4-удаление верхнего элемента \n 5-задание \n 6-сортировка 1 \n 7-сортировка 2 \n 8-выход\n";
		cin >> num;
		switch (num)
		{
		case 1:
			cout << "Введите значение:";
			cin >> nym;
			Add(nym, List);
			break;
		case 2:
			Show(List);
			cout << endl;
			break;
		case 3:
			Remove(List);
			break;
		case 4:
			Delete(List);
			break;
		case 5:
			FindandDel(List);
			break;
		case 6:
			Sort1(List);
			break;
		case 7:
			Sort2(List);
			break;
		case 8:
			sir = false;
			break;
		default:
			cout << "Попробуйте еще раз \n";
			break;
		}
	}
    return 0;
}

void Add(int a, Stek *&List)
{
	Stek *dop = new Stek;
	dop->a = a;
	dop->Next = List->Head;
	List->Head = dop;
}

void Show(Stek *List)
{
	Stek *dop = new Stek;
	dop = List->Head;
	while (dop != NULL)
	{
		cout << dop->a << " ";
		dop=dop->Next;
	}
}

void Delete(Stek *List)
{
	Stek *dop = new Stek;
	dop = List->Head;
	List->Head = List->Head->Next;
	delete dop;
	
}

void Remove (Stek *List)
{
	while (List->Head != NULL)
	{
		Stek *dop = new Stek;
		dop = List->Head->Next;
		delete List->Head;
		List->Head = dop;
	}
}

void FindandDel(Stek *List)
{
	int max = List->Head->a;
	Stek *dop = new  Stek;
	Stek *List1 = new Stek;
	List1->Head = NULL;
	dop = List->Head;
	while (dop != NULL)
	{
		Add(dop->a, List1);
		if (dop->a > max)
			max = dop->a;
		dop = dop->Next;
	}
	dop = List1->Head;
	Remove(List);
	while (dop != NULL)
	{
		if (dop->a == max)
		{
			Add(dop->a, List);
			Delete(List);
		}
		else
		{
			Add(dop->a, List);
		}
		dop = dop->Next;
	}
	Remove(List1);
}

void Sort2(Stek *List)
{
	Stek *dop = new Stek;
	Stek *dop1 = new Stek;
	int arr;
	Add(10, List);
	dop = List->Head->Next;
	dop1 = List->Head->Next;
	while (dop1 != NULL)
	{
		dop = List->Head->Next;
		while (dop->Next != NULL)
		{
			if (dop->a > dop->Next->a)
			{
				arr = dop->a;
				dop->a = dop->Next->a;
				dop->Next->a = arr;
			}
			dop = dop->Next;
		}
		dop1 = dop1->Next;
	}
	Delete(List);
}

void Sort1(Stek *List)
{
	Stek *dop = new Stek;
	Stek *dop1 = new Stek;
	Stek *dop2 = new Stek;
	Stek *dop3 = new Stek;
	Stek *dop4 = new Stek;
	int h=0;
	dop = List->Head;
	while (dop != NULL)
	{
		dop = dop->Next;
		h++;
	}
	Add(10, List);
	dop = List->Head->Next;
	for (int i=0;i<h;i++)
	{

		dop2 = List->Head;
		dop = List->Head->Next;
		while (dop->Next != NULL)
		{
			if (dop->a > dop->Next->a)
			{
				dop3 = dop->Next->Next;
				dop4 = dop;
				dop = dop->Next;
				dop->Next = dop4;
				dop->Next->Next = dop3;
				dop2->Next = dop;
				dop2 = dop;
				dop = dop->Next;
			}
			else
			{
				dop2 = dop;
				dop = dop->Next;
			}
		}
	}
	Delete(List);
}