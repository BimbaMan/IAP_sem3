#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int writeFile11(char* filename, int n)
{
    FILE* pFile;
    if ((pFile = fopen(filename, "w+t")) == NULL) {
        perror("Не удалось открыть файл %s", filename);
        return 1;
    }
    for (int i = 1; i <= n; i++) //ввод значений в файл
    {
        fprintf(pFile, "%d\n", i);
    }
    fclose(pFile);
    return 0;
}

int writeFile12(char* filename, int n)
{
    
    FILE* pFile;
    if ((pFile = fopen(filename, "w+t")) == NULL) {
        perror("Не удалось открыть файл %s", filename);
        return 1;
    }
    int ch = 0;
    for (int i = 1; i <= n; i++) //ввод значений в файл
    {
        scanf("%d", ch);
        fprintf(pFile, "%d ", ch); 
    }
    fclose(pFile);
    return 0;
}

int writeFile2(char *filename1, char *filename2) 
{
    FILE* pFile1;
    if ((pFile1 = fopen(filename1, "rt")) == NULL) {
        perror("Не удалось открыть файл %s", filename1);
        return 1;
    }

    FILE* pFile2;
    if ((pFile2 = fopen(filename2, "w+t")) == NULL) {
        perror("Не удалось открыть файл %s", filename2);
        return 1;
    }

    int value; int cal = 0;
        while (fscanf(pFile1, "%d ", &value) != EOF) {
            if (value%2 != 0)
            {
                fprintf(pFile2, "%d ", value);
                cal++;
            }
            
        }
        fprintf(pFile2, "\n%d ", cal);
    fclose(pFile1);
    fclose(pFile2);
    return 0;
}

int printFile(char* filename)
{
    FILE* pFile;
    if ((pFile = fopen(filename, "rt")) == NULL) {
        perror("Не удалось открыть файл %s", filename);
        return 1;
    }

    printf("Содержимое файла %s:\n", filename);
    int value;
    while (fscanf(pFile, "%d ", &value) != EOF)
    {
        printf("%d ", value);
    }
    printf("\n");
    fclose(pFile);
    return 0;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    char filename1[20];
    printf("Первый файл: ");
    gets(filename1);

    char filename2[20];
    printf("Второй файл: ");
    gets(filename2);

   // int n;
   // printf("Введи количество чисел: ");
   // scanf("%d", &n);

   // int errorCode = writeFile11(filename1, n);
    //int errorCode = writeFile12(filename1, n);
  //  if (errorCode != 0)
   //     return errorCode;
   int errorCode = printFile(filename1);
    printf("\n");

    errorCode = writeFile2(filename1, filename2);
    if (errorCode != 0)
        return errorCode;
    errorCode = printFile(filename2);
    return errorCode;
}