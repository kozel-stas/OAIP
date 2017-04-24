// Lab11Duble.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "fstream"
#include "iomanip"
#include "cstdlib"
using namespace std;

struct Train
{
	string Date;
	string Place;
	string Time;
	string NumberofPlace;
};
struct Train1
{
	string Date;
	string Place;
	string Time;
	string NumberofPlace;
};

int jife = 0;
int li1, li2, li3;
string Date1, Place1, Time1;
string str;
int height;
int NumberofPlace1;
bool sir = true, syr = true;
int hu = 0, hi = 0;;
char test1[1], test2[1];
int lil, lyl;
int NumberofTrain = 0;
Train *lol = new Train[NumberofTrain];
Train1 *lol1;
int num, nym;
int shet = 0;
ofstream file;
ifstream files;

void Sort();
void Qsort(int left, int right);

int main()
{
	setlocale(LC_ALL, "rus");

	while (sir == true)
	{
		cout << " 1-Режим добавления поездов \n 2-Заказ билетов\n 3-Выход \n ";
		cin >> num;
		switch (num)
		{
		case 1:
			shet = 0;
			syr = true;
			while (syr == true)
			{
				cout << " 1-Запись в файл\n 2-Добавление поезда \n 3-Список поездов\n 4-Cчитать с файла \n 5-Выход \n 6-Сортировка \n";
				cin >> nym;
				switch (nym)
				{
				case 1:
					file.open("lolushka.txt", ios_base::trunc);
					for (int i = 0; i <hu; i++)
					{
						file << " " << lol[i].Place << ";" << lol[i].Time << ";" << lol[i].Date << ";" << lol[i].NumberofPlace << ";";
					}
					file.close();
					break;
				case 2:
					lol1 = new Train1[hu];
					for (int i = 0; i < hu; i++)
					{
						lol1[i].Date = lol[i].Date;
						lol1[i].Time = lol[i].Time;
						lol1[i].Place = lol[i].Place;
						lol1[i].NumberofPlace = lol[i].NumberofPlace;
					}
					lol = new Train[hu + 1];
					for (int i = 0; i < hu; i++)
					{
						lol[i].Date = lol1[i].Date;
						lol[i].Time = lol1[i].Time;
						lol[i].Place = lol1[i].Place;
						lol[i].NumberofPlace = lol1[i].NumberofPlace;
					}
					delete[]lol1;
					cout << "Введите место прибытия: \n";
					cin >> lol[hu].Place;
					cout << "Введите время (формат 24 часовой вида 23.15) отправления: \n";
					cin >> lol[hu].Time;
					cout << "Введите дату (вида 10.12.2017) отправления: \n";
					cin >> lol[hu].Date;
					cout << "Введите число свободных мест: \n";
					cin >> lol[hu].NumberofPlace;
					hu++;
					break;
				case 3:
					cout << setw(15) << "Место прибытия" << setw(10) << "Время" << setw(15) << "Дата" << setw(15) << "Свободных мест" << endl;
					for (int i = 0; i < hu; i++)
					{
						cout << setw(15) << lol[i].Place << setw(10) << lol[i].Time << setw(15) << lol[i].Date << setw(15) << lol[i].NumberofPlace << endl;;
					}
					break;
				case 4:
					hu = 0;
					hi = -1;
					shet = 0;
					files.open("lolushka.txt", ios::in | ios::binary);
					getline(files, str);
					files.close();
					height = str.length();
					for (int i = 0; i < height; i++)
					{
						if (str[i] == ' ')
							hu++;
					}
					NumberofTrain = hu;
					lol = new Train[hu];
					for (int i = 0; i < height; i++)
					{
						if (str[i] == ' ')
						{
							hi++;
							shet = 0;
							li1 = i;
						}
						if (str[i] == ';')
						{
							if (shet != 0)
							{
								li3 = li2;
							}
							li2 = i;
							if (shet == 0)
							{
								lol[hi].Place = str.substr(li1 + 1, li2 - li1 - 1);
								shet++;
							}
							else
							{
								if (shet == 1)
								{
									lol[hi].Time = str.substr(li3 + 1, li2 - li3 - 1);
									shet++;
								}
								else
								{
									if (shet == 2)
									{
										lol[hi].Date = str.substr(li3 + 1, li2 - li3 - 1);
										shet++;
									}
									else
									{
										if (shet == 3)
										{
											lol[hi].NumberofPlace = str.substr(li3 + 1, li2 - li3 - 1);
											shet++;
										}
									}
								}
							}
						}
					}
					Sort();
					break;
				case 5:
					syr = false;
					break;
				case 6:
					hu--;
					Qsort(0,hu);
					hu++;
					break;
				}
			}
			break;
		case 2:
			syr = true;
			while (syr == true)
			{
				cout << " 1-Бронь мест \n 2-Выход\n";
				cin >> num;
				switch (num)
				{
				case 1:
					cout << "Место назначения\n";
					cin >> Place1;
					cout << "Введите дату отправления\n";
					cin >> Date1;
					cout << "До скольки часов(вид 23.15)\n";
					cin >> Time1;
					cout << "Количество мест\n";
					cin >> NumberofPlace1;
					jife = 0;
					for (int i = 0; i < NumberofTrain; i++)
					{
						if (Place1 == lol[i].Place)
						{
							if (Date1 == lol[i].Date)
							{
								nym = 0;
								num = 0;
								lil = 0;
								lyl = 0;
								test1[0] = Time1[0];
								test2[0] = Time1[1];
								nym = atoi(test1) * 10 + atoi(test2);
								test1[0] = lol[i].Time[0];
								test2[0] = lol[i].Time[1];
								num = atoi(test1) * 10 + atoi(test2);
								test1[0] = Time1[3];
								test2[0] = Time1[4];
								lyl = atoi(test1) * 10 + atoi(test2);
								test1[0] = lol[i].Time[3];
								test2[0] = lol[i].Time[4];
								lil = atoi(test1) * 10 + atoi(test2);
								if ((nym == num && lyl >= lil) || (num < nym))
								{
									if (NumberofPlace1 < atoi(lol[i].NumberofPlace.c_str()))
									{
										if (jife == 0)
										{
											cout << "Забронировано " << NumberofPlace1 << " мест до " << lol[i].Place << " на " << lol[i].Date << " " << lol[i].Time << endl;
											NumberofPlace1 = atoi(lol[i].NumberofPlace.c_str()) - NumberofPlace1;
											lol[i].NumberofPlace = to_string(NumberofPlace1);
											jife++;
										}
									}
								}
							}
						}
					}
					if (jife == 0)
					{
						cout << "Забронировать места не удалось \n";
					}
					Sort();
					break;
				case 2:
					syr = false;
					break;
				}
			}
			break;
		case 3:
			sir = false;
			break;
		}
	}
	return 0;
}

void Sort()
{
	for (int i = 1; i<hu; i++)
		for (int j = i; j>0 && atoi(lol[j - 1].NumberofPlace.c_str()) >= atoi(lol[j].NumberofPlace.c_str()); j--)
			swap(lol[j - 1], lol[j]);
}

void Qsort(int left, int right)
{
	int i = left, j = right;
	int tmp;
	int pivot = atoi(lol[(left + right) / 2].NumberofPlace.c_str());
	while (i <= j) {
		while (atoi(lol[i].NumberofPlace.c_str()) < pivot)
			i++;
		while (atoi(lol[j].NumberofPlace.c_str()) > pivot)
			j--;
		if (i <= j) {
			swap(lol[i], lol[j]);
			i++;
			j--;
		}
	};
	if (left < j)
		Qsort(left, j);
	if (i < right)
		Qsort(i, right);

}