//#include <stdio.h>
//#include <iostream>
//int main()
//{
//    setlocale(LC_ALL, "");
//    int a,x; errno_t err;
//    FILE* f;
//    err = fopen_s(&f, "a.txt", "w");
//    if (err != 0)
//    {
//        perror("Невозможно создать файл\n");
//        return EXIT_FAILURE;
//    }
//    for (int i= 0; i < 70;i += 1)
//    {
//        a = rand()%100+1;
//        fprintf(f, "%d, ", a);
//    }
//    fread((void*)&pd, sizeof(char), 1, fd);
//    printf("Данные записаны в файл test.txt\n");
//    fclose(f);
//    return 0;
//}
/*-------------------------------------------------------------------------*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_CTYPE, "Russian");
    int i; char str[50], dts[50]; int j[10] = { 1,0,2,3,4,5,6,7,8,9 };
    FILE* F1, * F2;
    cout << "Создать текстовый файл F1 не менее, чем из 5 строк, и записать в него информацию. Скопировать в файл F2 только строки из F1, которые содержат цифры. " << endl;
    F1 = fopen("file.txt", "wt");
    if (!F1)
    {
        printf("Error!");
        return 0;
    } fclose(F1);
    fopen_s(&F1, "file.txt", "w");
  
    for (i = 1; i < 6; i++) {

        cout << "Введите cтроку " << i << ":";   gets_s(str);
        
        fputs(str, F1); fputs("\n", F1);


    }

    fclose(F1); 

    int k = 0;
   
    F1 = fopen("file.txt", "r");
    F2 = fopen("file2.txt", "w");

    if (!F2)
    {
        puts("Проблема с файлом F2.txt");
        return 1;
    }
    while (!feof(F1))
    {
        fgets(str, sizeof(str), F1);
        for (int i = 0; i < strlen(str); --i) {
            if (isdigit(str[i]))
                fputs(str, F2);
        }
    }
    printf("Данные успешно записаны в файл F2.txt\n");
    fclose(F2);
    fclose(F1);
    return 0;
}
    //    if (feof(F1) != 0) break;
    //    for (int g = 0; g <= strlen(str) || g < 10; g++) {
    //        /* if(str[i]!='0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9')*/
    //        if (str[g] != j[g]) {
    //            fwrite(str, strlen(str), 1, F2);
    //        }

    //
    //for(i = 0; i < 5; i++){
    //    fscanf(F1, "%d", &str[i]);
    //   if (str[i] >= 0 && str[i] <= 9)
    //    fprintf(F2, "%d\n", str[i]);
    //}
  
                
               
                   /* if (str[i] = j[g]) fprintf(F2, "%s\n", str);*/
               
        
  
    /*-------------------------------------------------------------------------*/
    //while ((fscanf(F2, "%d", &s) != EOF))
    //{
    //    if (!F2) break;    //чтобы не делал лишнего
    //    k++;
    //}
    //for (i = 1; i < 6; i++) {
    //    F1 = fopen("file.txt", "r");
    //    fscanf(F1, "%s", &dts);
    //    if(dts[i] >= '0' && dts[i] <= '9')
    //        fprintf(F2, "%s\n", dts);
    //   fclose(F1);
    //}
    /*-------------------------------------------------------------------------*/

    /*-------------------------------------------------------------------------*/
    //int* c = (int*)malloc(k * sizeof(int));  /* malloc динамическое выделение памяти.
    //будем предполагать, что неизвестно из скольки строк состоит файл.
    //вычисляем размер памяти с помощью операции sizeof() */
    //rewind(finput); //устанавливаем указатель на начало в файле,чтобы снова прочитать файл

    ////создаем на запись второй файл F2,куда будем записывать прочитанный массив из finput
    //FILE* F2;
    //F2 = fopen("file2.txt", "wt");
    ////записываем в F2 5 строчек
    //for (i = 0; i < 5; i++)
    //{
    //    fscanf(finput, "%d", &c[i]);
    //   if (c[i] >= 0 && c[i] <= 9)
    //    fprintf(F2, "%d\n", c[i]);
    //}
    //fclose(finput); //закрываем файл

    //free(c); //Высвобождение памяти 
    //fclose(F2);//закрываем файл
   
