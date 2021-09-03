#include "stdafx.h"

void var9()
{
    bool work = true;
    Number* begin = NULL, * end;
    Number* begin1 = NULL, * end1;
    Number* begin2 = NULL, * end2;
    int p, choice = 0;

    cout << "\n������� ������ ������� = ";
    cin >> maxSize;

    while (work)
    {
        cout << "\n1. ���� �����\n2. ����� �������\n3. �������� ��������\n4. ������ �������\n5. �������\n0. ���������\n(������� �����) " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "������� �����: ";
            cin >> p;
            create(&begin, &end, p, curSize);
            break;
        case 2:
            view(begin);
            break;
        case 3:
            cout << "������� �����: ";
            cin >> p;
            Delete(&begin, &end, p);
            break;
        case 4:
            cout << "������ ������� = " << amount(begin) << endl;
            break;
        case 5:
            cout << "����������� �������, ������� �� ����� ������� ������ ��� �����: Queue1 �� ������ ��������� � Queue2 �� ��������� ��������� �������" << endl;
            task(&begin, &end, &begin1, &end1, &begin2, &end2);
            break;
        case 0:
            work = false;
            break;
        default:
            break;
        }
    }
}

void create(Number** begin, Number** end, int p, int& size) //������������ ��������� �������
{
    if (size != maxSize)
    {
        Number* t = new Number;
        t->next = NULL;
        if (*begin == NULL)
        {
            *begin = *end = t;
            t->info = p;
        }
        else
        {
            t->info = p;
            (*end)->next = t;
            *end = t;
        }
        size++;
    }
    else
    {
        cout << "������� ���������!" << endl;
    }
}

void view(Number* begin) //����� ��������� ������� 
{
    Number* t = begin;
    if (t == NULL)
    {
        cout << "������� �����\n";
    }
    else
    {
        while (t != NULL)
        {
            cout << t->info << " --> ";
            t = t->next;
        }
        cout << "NULL";
    }
}

void Delete(Number** begin, Number** end, int p) //�������� �� ������������ �������� 
{
    Number** prev = begin, ** cur = &(*begin)->next;
    if (prev == NULL)
    {
        cout << "������� �����\n";
    }
    else
    {
        if ((*prev)->info == p)
        {
            *begin = (*prev)->next;
            curSize--;
        }
        else
        {
            while (cur != NULL)
            {
                if ((*cur)->info == p)
                {
                    (*prev)->next = (*cur)->next;
                    if ((*prev)->next == NULL) *end = *prev;
                    curSize--;
                    break;
                }
                prev = cur;
                cur = &(*cur)->next;
            }
        }
    }
}

int amount(Number* begin)
{
    int x = 0;
    Number* t = begin;
    if (t == NULL)
    {
        return 0;
    }
    else
    {
        while (t != NULL)
        {
            t = t->next;
            x++;
        }
    }
    return x;
}

void task(Number** begin, Number** end, Number** begin1, Number** end1, Number** begin2, Number** end2)
{
    Number* t = *begin;
    *begin1 = NULL;
    *begin2 = NULL;
    if (t == NULL)
    {
        cout << "������� �����\n";
    }
    else
    {
        while (t != NULL)
        {
            if (t->info % 2 == 0) create(begin1, end1, t->info, curSize1);
            else create(begin2, end2, t->info, curSize22);
            t = t->next;
        }
    }
    cout << "������ �������: ";
    view(*begin1);
    cout << "\n" << "������ �������: ";
    view(*begin2);
}

void dop1()
{
    int n;
    bool work = true;
    while (work)
    {
        cout << "\n1. ������ �������\n2. ������ �������\n3. ������ �������\n4. ����� �������\n0. �����" << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            dop1_1();
            break;
        case 2:
            dop1_2();
            break;
        case 3:
            dop1_3();
            break;
        case 4:
            dop1_5();
            break;
        case 0:
            work = false;
            break;
        default:
            break;
        }
    }
}

void dop1_1()
{
    int i = 1, choice = 1, z; head = NULL;  tail = NULL;
    while (choice != 0)
    {
        cout << "1. �������� �������" << endl;
        cout << "2. �������� ������� � ������" << endl;
        cout << "3. ������� ������� � ������" << endl;
        cout << "4. ������� ��������" << endl;
        cout << "5. �������� �������" << endl;
        cout << "0. �����" << endl;
        cout << "�������� ��������  ";  cin >> choice;
        switch (choice)
        {
        case 1: cout << "������� �������:  "; cin >> z;
            insertToQueue(z); printQueue();  break;
        case 2: getFromHead(); break;
        case 3: deletFirst();  break;
        case 4: printQueue();  break;
        case 5: clrQueue();    break;
        }
    }
}

void dop1_2()
{
    int i = 1, choice = 1, z; head = NULL;  tail = NULL;
    while (choice != 0)
    {
        cout << "1. �������� �������" << endl;
        cout << "2. �������� ������� � ������" << endl;
        cout << "3. ������� ������� � ������" << endl;
        cout << "4. ������� ��������" << endl;
        cout << "5. �������� �������" << endl;
        cout << "0. �����" << endl;
        cout << "�������� ��������  ";  cin >> choice;
        switch (choice)
        {
        case 1: cout << "������� �������:  "; cin >> z;
            insertToQueue2(z); printQueue();  break;
        case 2: getFromHead(); break;
        case 3: deletFirst();  break;
        case 4: printQueue();  break;
        case 5: clrQueue();    break;
        }
    }
}

void dop1_3()
{
    int i = 1, choice = 1, z; head = NULL;  tail = NULL;
    while (choice != 0)
    {
        cout << "1. �������� �������" << endl;
        cout << "2. �������� ������� � �����" << endl;
        cout << "3. ������� ������� � �����" << endl;
        cout << "4. ������� ��������" << endl;
        cout << "5. �������� �������" << endl;
        cout << "0. �����" << endl;
        cout << "�������� ��������  ";  cin >> choice;
        switch (choice)
        {
        case 1: cout << "������� �������:  "; cin >> z;
            insertToQueue(z); printQueue();  break;
        case 2: getFromEnd(); break;
        case 3: deletLast();  break;
        case 4: printQueue();  break;
        case 5: clrQueue();    break;
        }
    }
}

void dop1_5()
{
    int i = 1, choice = 1, z; head = NULL;  tail = NULL;
    while (choice != 0)
    {
        cout << "1. �������� �������" << endl;
        cout << "2. �������� ������� � �����" << endl;
        cout << "3. ������� ������� � �����" << endl;
        cout << "4. ������� ��������" << endl;
        cout << "5. �������� �������" << endl;
        cout << "0. �����" << endl;
        cout << "�������� ��������  ";  cin >> choice;
        switch (choice)
        {
        case 1: cout << "������� �������:  "; cin >> z;
            insertToQueue2(z); printQueue();  break;
        case 2: getFromEnd(); break;
        case 3: deletLast();  break;
        case 4: printQueue();  break;
        case 5: clrQueue();    break;
        }
    }
}

bool isNull(void)    //�������� �� �������
{
    return (head == NULL);
}

void deletFirst()   //���������� �������� �� ������
{
    if (isNull())
        cout << "������� �����" << endl;
    else
    {
        Item* p = head;
        head = head->next;
        delete p;
    }
}

void getFromHead()  //��������� �������� �� ������
{
    if (isNull())
        cout << "������� �����" << endl;
    else
        cout << "������ = " << head->data << endl;
}

void deletLast()   //���������� �������� �� ������
{
    if (isNull())
        cout << "������� �����" << endl;
    else
    {
        Item* h = head, * t = tail;
        while (true)
        {
            if (h->next == t)
            {
                delete tail;
                tail = h;
                tail->next = NULL;
                break;
            }
            h = h->next;
        }
    }
}

void getFromEnd()  //��������� �������� �� ������
{
    if (isNull())
        cout << "������� �����" << endl;
    else
        cout << "������ = " << tail->data << endl;
}

void insertToQueue(int x)  //���������� �������� � ������� 
{
    Item* p = new Item;      //����� ��������� 
    p->data = x;
    p->next = NULL;
    Item* v = new Item;      //��������� ��� ������ �����
    Item* p1 = new Item;
    Item* p2 = new Item;
    int i = 0;               //������
    if (isNull())
        head = tail = p;
    else
    {
        p2 = head; p1 = head;
        while (p1 != NULL)  //���� ������� �� ����������
        {
            if (i == 1)
            {
                if (x <= p1->data)  //����� ������, ��� � �������
                {
                    v->data = x;
                    v->next = p1;
                    p2->next = v;
                    return;
                }
                p2 = p2->next;      // ��������� �����
            }
            else
            {
                if (x <= p1->data)
                {
                    v->data = x;
                    v->next = p1;
                    head = v;
                    return;
                }
            }
            p1 = p1->next;
            i = 1;
        }
        if (p1 == NULL)
        {
            tail->next = p;
            tail = p;
        }
    }
}

void insertToQueue2(int x)  //���������� �������� � ������� 
{
    Item* p = new Item;      //����� ��������� 
    p->data = x;
    p->next = NULL;
    Item* v = new Item;      //��������� ��� ������ �����
    Item* p1 = new Item;
    Item* p2 = new Item;
    int i = 0;               //������
    if (isNull())
        head = tail = p;
    else
    {
        p2 = head; p1 = head;
        while (p1 != NULL)  //���� ������� �� ����������
        {
            if (i == 1)
            {
                if (x >= p1->data)  //����� ������, ��� � �������
                {
                    v->data = x;
                    v->next = p1;
                    p2->next = v;
                    return;
                }
                p2 = p2->next;      // ��������� �����
            }
            else
            {
                if (x >= p1->data)
                {
                    v->data = x;
                    v->next = p1;
                    head = v;
                    return;
                }
            }
            p1 = p1->next;
            i = 1;
        }
        if (p1 == NULL)
        {
            tail->next = p;
            tail = p;
        }
    }
}

void printQueue()             //����� �������
{
    Item* p = new Item;
    if (isNull())
        cout << "������� �����" << endl;
    else
    {
        cout << "������� = ";
        p = head;
        while (!isNull())
        {
            if (p != NULL)
            {
                cout << p->data << " "; cout << "->";
                p = p->next;
            }
            else
            {
                cout << "NULL" << endl;
                return;
            }
        }
    }
}

void clrQueue()           //������� �������
{
    while (!isNull()) deletFirst();
}

void dop2()
{
    bool work = true;
    Number2* begin = NULL, * end;
    int choice = 0;
    float p;

    cout << "\n������� ������ ������� = ";
    cin >> maxSize2;

    while (work)
    {
        cout << "\n1. ���� �����\n2. ����� �������\n3. �������� ��������\n4. ������� ����������� �����\n0. ���������\n(������� �����) " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "������� �����: ";
            cin >> p;
            create2(&begin, &end, p);
            break;
        case 2:
            view2(begin);
            break;
        case 3:
            cout << "������� �����: ";
            cin >> p;
            Delete2(&begin, &end, p);
            break;
        case 4:
            task2(&begin, &end);
            break;
        case 0:
            work = false;
            break;
        default:
            break;
        }
    }
}

void create2(Number2** begin, Number2** end, float p) //������������ ��������� �������
{
    if (curSize2 != maxSize2)
    {
        Number2* t = new Number2;
        t->next = NULL;
        if (*begin == NULL)
        {
            *begin = *end = t;
            t->info = p;
        }
        else
        {
            t->info = p;
            (*end)->next = t;
            *end = t;
        }
        curSize2++;
    }
    else
    {
        cout << "������� ���������!" << endl;
    }
}

void view2(Number2* begin) //����� ��������� ������� 
{
    Number2* t = begin;
    if (t == NULL)
    {
        cout << "������� �����\n";
    }
    else
    {
        while (t != NULL)
        {
            cout << t->info << " --> ";
            t = t->next;
        }
        cout << "NULL";
    }
}

void Delete2(Number2** begin, Number2** end, float p) //�������� �� ������������ �������� 
{
    Number2** prev = begin, ** cur = &(*begin)->next;
    if (prev == NULL)
    {
        cout << "������� �����\n";
    }
    else
    {
        if ((*prev)->info == p)
        {
            *begin = (*prev)->next;
            curSize2--;
        }
        else
        {
            while (cur != NULL)
            {
                if ((*cur)->info == p)
                {
                    (*prev)->next = (*cur)->next;
                    if ((*prev)->next == NULL) *end = *prev;
                    curSize2--;
                    break;
                }
                prev = cur;
                cur = &(*cur)->next;
            }
        }
    }
}

void task2(Number2** begin, Number2** end)
{
    cout << "��������� ����������� ����� ��������� � ������� ���, ����� � �� ������ ��� ���������� ���������� �������" << endl;
    Number2** h = begin, ** t = end, * newH = NULL, * newT = NULL;
    float n;
    int count = 0;
    if (h == NULL)
    {
        cout << "������� �����\n";
    }
    else
    {
        n = (*h)->info;
        while (h != NULL)
        {
            count++;
            if ((*h)->info > n) n = (*h)->info;
            if ((*h)->next == NULL) h = NULL;
            else h = &(*h)->next;
        }

        bool work = false;
        curSize2 = 0;
        h = begin;
        if ((*h)->info == n) return;
        while (h != NULL)
        {
            if ((*h)->info == n || work)
            {
                work = true;
                count--;
                create2(&newH, &newT, (*h)->info);
            }
            if ((*h)->next == NULL) h = NULL;
            else h = &(*h)->next;
        }

        h = begin;
        for (int i = 0; i < count; i++)
        {
            create2(&newH, &newT, (*h)->info);
            h = &(*h)->next;
        }
        *begin = newH;
        *end = newT;
    }
}

void createCH(CHAR** begin, CHAR** end, char p) //������������ ��������� �������
{
    CHAR* t = new CHAR;
    t->next = NULL;
    if (*begin == NULL)
    {
        *begin = *end = t;
        t->info = p;
    }
    else
    {
        t->info = p;
        (*end)->next = t;
        *end = t;
    }
}

void task3()
{
    cout << "���������� ���������� ����� f, ����������� �� ������, ���������� � ��������� ���� g, �������� ��� ���� � ����� ������ ������ ��� �������� � ��� ����� (� ����������� ��������� ��������� �������, ��� ����� ����, ��� � ����� ��������� ��-��� ������). ������������ �������" << endl;
    char str[200];
    string A = "A.txt", B = "B.txt";
    ifstream fAin(A), fBin(B);
    ofstream fAout(A), fBout(B);
    string arr[] = { "ab12cd3e4fghi56jk", "12a34bc567de8", "123abc456" };
    CHAR* begin = NULL, * end = NULL;

    cout << size(arr) << endl;
    if (fAout.is_open())
    {
        for (int i = 0; i < size(arr); i++)
        {
            fAout << arr[i] << "\n";
        }
    }
    else
    {
        cout << " ���������� ������� ����!" << endl;
    }
    fAout.close();
    CHAR* t = begin;
    if (fAin.is_open() && fBout.is_open())
    {
        while (!fAin.eof())
        {
            begin = NULL;
            end = NULL;
            fAin.getline(str, sizeof(str));
            if (fAin.eof() != 0) break;
            for (int i = 0; i < strlen(str); i++)
            {
                createCH(&begin, &end, str[i]);
            }

            t = begin;
            while (t != NULL)
            {
                if (t->info < '0' || t->info > '9') fBout << t->info;
                t = t->next;
            }

            t = begin;
            while (t != NULL)
            {
                if (t->info >= '0' && t->info <= '9') fBout << t->info;
                t = t->next;
            }
            fBout << "\n";
        }
    }
    else
    {
        cout << " ���������� ������� ����!" << endl;
    }
    fAin.close();
    fBout.close();
}