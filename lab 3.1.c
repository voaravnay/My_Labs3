#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>
#include <math.h>


int main(void) {
    setlocale(LC_ALL, "RUS");
    
    FILE* input, * output;
    int** array;

    if ((input = fopen("input.txt", "r")) == NULL) {
        printf("\nОшибка при открытии файла\"input.txt\".");
        return 1;
    }
    else {
        printf("\nФайл \"input.txt\" открыт успешно.");
        printf("\nЗагрузка данных...\n");
    }
        
        
    input = fopen("input.txt", "r");
    int count = 0, v = 0;
    while (fscanf(input, "%i", &v) != EOF) {
        count++;
    }
    fclose(input);
    
    printf("\nКоличество элементов в файле - \"%d\".", count);

    int b = 0, space = 0, n = 0;
    input = fopen("input.txt", "r");
    do {

        b = fgetc(input);
        if (b == ' ')
            space++;
        if (b == '\n')
            break;
    } while (feof(input) == 0);
    space++;
    fclose(input);
    
    n = count / space;  
    int m = space;
    
    printf("\nКоличество строк в файле - \"%d\".", n);
    
    input = fopen("input.txt", "r");
//Кол-во строк
   

    array = (int**)malloc(n * sizeof(int*));
// Выделение памяти
    
    int i = 0, j = 0, ans = 0;
    for (i = 0; i < n; i++) {


        array[i] = (int*)malloc(m * sizeof(int));
        for (j = 0; j < m; j++) {

            fscanf(input, "%d", &mas[i][j]);
            if (array[i][j] == 0)
                ans++;
        }
    }
    fclose(input);
// Ввод из файла
    output = fopen("output.txt", "w");

    
    printf("\n");
    for (i = 0; i < n; i++) {

        for (j = 0; j < m; j++) { 

            fprintf(output, "%d ", array[i][j]);
        }
        if (i != m && j != n)
            fprintf(output, "\n");
    }
// Вывод данных в файл
    fprintf(output, "Количество нулей в файле - \"%d\".", ans);
    fprintf(output, "\nЕсли количество нулей - \"0\", \nТо возможно числовой ряд в файле \"input.txt\" записан без пробелов и только с переносом строки.(не корректно)");
    fclose(output);

}