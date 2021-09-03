#include "stdafx.h"

string A = "A.txt";
char str[100];
int numOfnumber;
int z = 0, m=0;
int* arr=new int[0];
int* arr2=new int[0];
int* arr3=new int[0];

void push(comp** top, int D)
{
	comp* q = new comp();
	q->Data = D;
	if (top == NULL)
	{
		*top = q;
	}
	else
	{
		q->next = *top;
		*top = q;
	}
}

void delete_key(comp** top, int N)
{
	comp* q = *top;
	comp* prev = NULL;
	while (q != NULL)
	{
		if (q->Data == N)
		{
			if (q == *top)
			{

				*top = q->next;
				free(q);
				q->Data = NULL;
				q->next = NULL;
			}
			else
			{
				prev->next = q->next;
				free(q);
				q->Data = NULL;
				q->next = NULL;
			}
		}
		prev = q;
		q = q->next;
	}
}

void find(comp* top, int N)
{
	comp* q = top;
	comp* prev = NULL;
	cout << "���������� �� ���������: " << N << endl;
	while (q != NULL)
	{
		if (q->Data == N) cout << q->Data << endl;
		prev = q;
		q = q->next;
	}
}

void print(comp* top)
{
	comp* q = top;
	while (q)
	{
		cout << q->Data << " --> ";
		q = q->next;
	}
	cout << "NULL" << endl;
}

bool extract(comp** top)
{
	comp* q = *top;
	if (q != NULL)
	{
		*top = q->next;
		free(q);
	}
	else return 0;

	return 1;
}

void toFile(comp* top)
{
	numOfnumber = 0;
	ofstream fAout(A);
	if (fAout.is_open())
	{
		if (top == NULL)
		{
			fAout << "������ ����" << endl;
		}
		else
		{
			while (top != NULL)
			{
				fAout << top->Data << endl;
				numOfnumber++;
				top = top->next;
			}
		}
	}
	else
	{
		cout << " ���������� ������� ����!" << endl;
	}
	fAout.close();
}

void fromFile(comp** top)
{
	int* arr = new int[numOfnumber], n;
	ifstream fAin(A);
	if (fAin.is_open())
	{
		clear(top);
		for (int i = 0; i < numOfnumber; i++)
		{
			fAin.getline(str, sizeof(str));
			arr[i] = atoi(str);
		}
		for (int i = numOfnumber - 1; i >= 0; i--)
		{
			push(top, arr[i]);
		}
	}
	else
	{
		cout << " ���������� ������� ����!" << endl;
	}
	fAin.close();
	delete[] arr;
}


void taskVar10(comp* top, int R, int T)
{
	comp* q = top;
	comp* prev = NULL;
	cout << "���������e �� ��������� � ��������� ��: " << R<<" �� "<< T << endl;
	while (q != NULL)
	{
		if (q->Data >R && q->Data<T) cout << q->Data << endl;
		prev = q;
		q = q->next;
	}
}

void task3_1(Stask3* top, int n)
{
	Stask3* q = top;
	for (int i = 0; i < n; i++)
	{
		if (i >= n / 2) cout << q->Data;
		q = q->next;
	}
}

void task3_2(Stask3* top, int n)
{
	Stask3* q = top;
	for (int i = 0; i < n / 2; i++)
	{
		cout << q->Data;
		q = q->next;
	}
}

void task3()
{
	cout << "���� �������� a ���������� ���� �� ������� ���������� ��������. �������� � ���������� �������� b, ��������� �� �����-��� ������ �������� �������� a, ���������� � �������� �������, ����� ������� ���� ������� ������ �������� ������-�� a, ����� ���������� � �������� ������� (��������, ��� � = ������� b ������ ���� ����� �������)" << endl;
	Stask3* top = NULL;
	int n;
	cout << "������� ���-�� ��������(������): ";
	cin >> n;
	char* arr = new char[n];
	cout << "������� �����: ";
	cin >> arr;

	for (int i = 0; i < n; i++)
	{
		Stask3* q = new Stask3();
		q->Data = arr[i];
		if (top == NULL)
		{
			top = q;
		}
		else
		{
			q->next = top;
			top = q;
		}
	}
	task3_1(top, n);
	task3_2(top, n);
}

void task4()
{
	cout << "������� ���� � ������������� �������������� �����. ��������� ��� ������� �����, ��������� �� �����. ������������ �� ������ ���������� �����. ������� ����� � ����� ��������� ����� �������� ������ �����" << endl;
	Stask4* top = NULL;
	const int sizeArr = 7;
	string arr[sizeArr] = { "123456", "123", "1234567890123" , "12345678" , "123" , "1234" , "1234567" };

	ifstream fAin(A);
	ofstream fAout(A);

	if (fAout.is_open())
	{
		for (int i = 0; i < sizeArr; i++)
		{
			cout << i + 1 << ") " << arr[i] << endl;
			fAout << arr[i] << "\n";
		}
	}
	fAout.close();

	if (fAin.is_open())
	{
		for (int i = 0; i < sizeArr; i++)
		{
			fAin.getline(str, sizeof(str));
			Stask4* q = new Stask4();
			q->num = i;
			q->size = strlen(str);
			if (top == NULL)
			{
				top = q;
			}
			else
			{
				q->next = top;
				top = q;
			}
		}
	}
	else
	{
		cout << " ���������� ������� ����!" << endl;
	}
	fAin.close();

	Stask4* q = top;
	int min, size;
	min = q->num;
	size = q->size;
	while (q != NULL)
	{
		if (q->size < size)
		{
			min = q->num;
			size = q->size;
		}
		q = q->next;
	}

	cout << "����� ������ = " << min + 1 << " � � ������ = " << size << endl;
}

void fun(int*& arr,int x)
{
	int* temp = new int[_msize(arr) / 4 + 1];
	for (size_t i = 0; i < _msize(arr)/4; i++)
	{
		temp[i] = arr[i];
	}
	temp[_msize(arr) / 4] = x;
	delete[]arr;
	arr = temp;
}

void clear(comp** top)
{
	while (extract(top));
}

void Add1(Stack1** s1, int D) {	//���������� ��������� � ���� 1
	Stack1* a = new Stack1();
	
	
     
	fun(arr, D);
	a->data = D;
	if (s1 == NULL)
	{
		*s1 = a;
	}
	else
	{
		a->Next = *s1;
		*s1 = a;
	}
	
}

void Add2(Stack2** s2, int D) {	//���������� ��������� � ���� 2
	Stack2* u = new Stack2();
	
	fun(arr2, D);
	u->data = D;
	if (s2 == NULL)
	{
		*s2 = u;
	}
	else
	{
		u->Next = *s2;
		*s2 = u;
	}
	
}

void Add3(comp** top, int x)
{
	comp* u = new comp();
	u->Data = x;
	if (top == NULL)
	{
		*top = u;
	}
	else
	{
		u->next = *top;
		*top = u;
	}
}

void Show1(Stack1* s1) {	//����� ����� 1 �� �����
	Stack1* a = s1;
	while (a)
	{
		cout << a->data << " --> ";
		a = a->Next;
	}
	cout << "NULL" << endl;
}

void Show2(Stack2* s2) {	//����� ����� 2 �� �����
	Stack2* u = s2;
	while (u)
	{
		cout << u->data << " --> ";
		u = u->Next;
	}
	cout << "NULL" << endl;
}



void Showw(comp* top) {	//����� ����� 2 �� �����
	for (size_t i = 0; i < _msize(arr3)/4; i++)
	{
		Add3(&top, arr3[i]);
	}
	comp* u = top;
	while (u)
	{
		cout << u->Data << " --> ";
		u = u->next;
	}
	cout << "NULL" << endl;
}
void Show( comp** top) {	//���������� ��������� ����� Stack
	comp* q = new comp();
	int z = 0;
	
	for (int i = 0; i < _msize(arr)/4; i++)
	{
		for (int k = 0; k < _msize(arr2)/4; k++) {
			if (arr[i] == arr2[k]) break;
			if (k == _msize(arr2) / 4 - 1) fun(arr3, arr[i]) ;
			
		}

	}
	for (int i = 0; i < _msize(arr2) / 4; i++)
	{
		for (int k = 0; k < _msize(arr) / 4; k++) {
			if (arr2[i] == arr[k]) break;
			if (k == _msize(arr) / 4 - 1) fun(arr3, arr2[i]);

		}

	}


}


int menu()
{
	int n;
	cout << endl;
	cout << " 1. ���������� �����" << endl;
	cout << " 2. �������� �����" << endl;
	cout << " 3. ����� �����" << endl;
	cout << " 4. ����� ����� � ���������� ����" << endl;
	cout << " 5. ���������� �����" << endl;
	cout << " 6. ������ ����� � ����" << endl;
	cout << " 7. ���������� ����� �� �����" << endl;
	cout << " 8. ������� �����" << endl;
	cout << " 9. �������(9 �������)" << endl;
	cout << " 10. �������(10 �������)" << endl;
	cout << " 11. �������������� 1" << endl;
	cout << " 12. �������������� 2" << endl;
	cout << " 0. �����" << endl;
	cout << "(������� �����) ";
	cin >> n;
	cout << endl;
	return n;
}

int menu2()
{
	int n;
	cout << "\n\n����������� �������, ������� ��������� ���� Stack,\n ������� � ���� �� ������ ���� ��������, ������� ������ � ���� �� ������ Stack1 � Stack2,\n �� �� ������ � ������. �������� �������:" << endl;
	cout << "1 - ���������� � Stack1" << endl;
	cout << "2 - ���������� � Stack2" << endl;
	cout << "3 - ����� Stack1" << endl;
	cout << "4 - ����� Stack2" << endl;
	cout << "5 - �������� Stack" << endl;
	cout << "6 - ����� Stack" << endl;
	cout << "7 - �����" << endl;
	cin >> n;
	cout << endl;
	return n;
}

































