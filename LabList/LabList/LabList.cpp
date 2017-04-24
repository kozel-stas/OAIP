// LabList.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int x = 0;

struct List {
	int a;
	List *HeadEnd, *HeadTop, *Next, *Previous;
};

void AddTop(int a, List *&Spisok);
void AddEnd(int a, List *&Spisok);
void ShowTop(List *Spisok);
void ShowEnd(List *Spisok);
void Task(List *Spisok);

int main()
{
	setlocale(LC_ALL, "rus");
	List *Spisok = new List;
	Spisok->HeadEnd = NULL;
	Spisok->HeadTop = NULL;
	bool sir = true;
	int num;
	int nym;
	while (sir == true)
	{
		cout << " 1-Добавление в начало \n 2-в конец \n 3-показать с начала \n 4-с конца \n 5-выполнение задания \n 6-выход \n ";
		cin >> num;
		switch (num)
		{
		case 1:
			cout << "Введите число:\n";
			cin >> nym;
			AddTop(nym, Spisok);
			break;
		case 2:
			cout << "Введите число:\n";
			cin >> nym;
			AddEnd(nym, Spisok);
			break;
		case 3:
			ShowTop(Spisok);
			cout << endl;
			break;
		case 4:
			ShowEnd(Spisok);
			cout << endl;
			break;
		case 5:
			Task(Spisok);
			break;
		case 6:
			sir = false;
			break;
		default:
			cout << "Попробуйте еще раз\n";
			break;
		}
	}
	system("pause");
    return 0;
}

void AddTop(int a, List *&Spisok)
{
	List *dop = new List;
	if (x == 0)
	{
		dop->a = a;
		dop->Previous = Spisok->HeadTop;
		dop->Next = NULL;
		Spisok->HeadTop = dop;
		Spisok->HeadEnd = dop;
	}
	else
	{
		dop->a = a;
		dop->Previous = Spisok->HeadTop;
		dop->Next = NULL;
		Spisok->HeadTop = dop;
		dop->Previous->Next = Spisok->HeadTop;
	}
	x++;
}

void ShowTop(List *Spisok)
{
	List *dop = new List;
	dop = Spisok->HeadTop;
	while (dop != NULL)
	{
		cout <<dop->a << " ";
		dop = dop->Previous;
	}
}

void ShowEnd(List *Spisok)
{
	List *dop = new List;
	dop = Spisok->HeadEnd;
	while (dop != NULL)
	{
		cout << dop->a << " ";
		dop = dop->Next;
	}
}


void AddEnd(int a, List *&Spisok)
{
	List *dop = new List;
	if (x == 0)
	{
		dop->a = a;
		dop->Next = Spisok->HeadEnd;
		dop->Previous = NULL;
		Spisok->HeadTop = dop;
		Spisok->HeadEnd = dop;
	}
	else
	{
		dop->a = a;
		dop->Next = Spisok->HeadEnd;
		dop->Previous = NULL;
		Spisok->HeadEnd = dop;
		dop->Next->Previous = dop;
	}
	x++;
}

void Task(List *Spisok)
{
	int max;
	List *dop = new List;
	dop = Spisok->HeadEnd;
	max = dop->a;
	while (dop != NULL)
	{
		if (max < dop->a)
			max = dop->a;
		dop = dop->Next;
	}
	dop = Spisok->HeadEnd;
	while (dop != NULL)
	{
		if (max == dop->a)
		{
			if (dop == Spisok->HeadTop)
			{
				Spisok->HeadTop = dop->Previous;
				dop->Previous->Next = NULL;
				delete dop;
				break;
			}
			else
			{
				if (dop == Spisok->HeadEnd)
				{
					Spisok->HeadEnd = dop->Next;
					dop->Next->Previous = NULL;
					delete dop;
					break;
				}
				else
				{
					dop->Previous->Next = dop->Next;
					dop->Next->Previous = dop->Previous;
					delete dop;
					break;
				}
			}
		}
		dop = dop->Next;
	}
}