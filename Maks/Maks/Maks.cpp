// Maks.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int max1 = 0;
int min1 = 32000;
struct stek {
	int value;
	stek *next, *head;
};

void add(int x, stek *&stack) {
	stek *temp = new stek;
	temp->value = x;
	temp->next = stack->head;
	stack->head = temp;
}

int k;
void show(stek *stack) {
	stek *temp = stack->head;
	while (temp != NULL) {
		cout<<temp->value<<" ";
		if (temp->value>max1) {
			k = 1;
			max1 = temp->value;
		}
		if (temp->value<min1) {
			min1 = temp->value;
			k = 0;
		}
		temp = temp->next;
	}
	cout<<endl;
	cout<<"Min: "<<min1<<endl;
	cout<<"Max: "<<max1<<endl;
}

void del(stek *stack) {
	stek *temp = stack->head;
	if (k == 1) {
		while (temp != NULL) {
			if (temp->value == min1) {
				stek *tmp = temp;
				stek *tmp_next = temp->next;
				while (tmp_next != NULL) {
					if (tmp_next->value == max1) {

						temp->next = tmp_next;
						break;
					}
					else {
						stek *dop = tmp_next;
						tmp_next = tmp_next->next;
						delete dop;
					}
				}
			}
			temp = temp->next;
		}
	}
}
int main() {
	stek *p = new stek;

	p->head = NULL;

	add(100, p);
	add(200, p);
	add(150, p);
	add(150, p); add(150, p); add(150, p); add(150, p); add(150, p); add(150, p); add(150, p); add(150, p);
	add(50, p);

	show(p);
	cout<<k<<endl;
	del(p);
	show(p);
	system("pause");
}
