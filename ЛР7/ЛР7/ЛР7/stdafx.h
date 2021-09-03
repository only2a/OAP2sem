#pragma once
#include <iostream>;
#include <fstream>
#include <string>
#include <malloc.h>
using namespace std;

struct comp {
	int Data;
	comp* next;
};

struct Stack1 {			//�������� �������� �����
	int data;
			//��������� �� ������� �����
	Stack1* Next;		//��������� �� ��������� �������
};

struct Stack2 {			//�������� �������� �����
	int data;
			//��������� �� ������� �����
	Stack2* Next;		//��������� �� ��������� �������
};



struct Stask3 {
	char Data;
	Stask3* next;
};

struct Stask4 {
	int num;
	int size;
	Stask4* next;
};



void push(comp** top, int D);
void delete_key(comp** top, int N);
void find(comp* top, int N);
void print(comp* top);
bool extract(comp** top);
void toFile(comp* top);
void fromFile(comp** top);
void clear(comp** top);
void Add1(Stack1** s1, int D);				//�������� ������� � ���� 1
void Add2(Stack2** s2, int D);
void Add3(comp** top, int x);//�������� ������� � ���� 2
void Show1(Stack1* s1);					//������� ����
void Show2(Stack2* s2);					//������� ����
void Show( comp** top);
void Showw(comp* top);
void taskVar10(comp* top,int R,int T);
void task3_1(Stask3* top, int n);
void task3_2(Stask3* top, int n);
void task3();
void task4();
void fun(int** arr,int x);
int menu();
int menu2();
