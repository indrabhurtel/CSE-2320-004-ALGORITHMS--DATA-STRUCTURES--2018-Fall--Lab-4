/*
*
*lab4
*
*Created by Indra Bhurtel on 11/09/18.
*
*
*Name:Indra Bhurtel
*I am senior at UTA. My major is software Engineering.
*UTA ID NO:1001542825
*
*lab 4 assignment
*
*This program  compute the kth smallest number in a sequence of n integers in the range 0 . . .999,999,999.
*This program indicate the number of remaining values after each counting sort.
*
*Professor Bob Weems
*
*Code compilation in Omega as follows:
*Make sure you make a.dat /b.dat / c.dat sample run from the sample run given by the professor.
*The input will be read as a shell redirect (<) from a file.
*    gcc lab4.c
*   ./a.out <a.dat
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isolating_Digit(int *input_Array, int *output_Array, int size, int numeral) /// function to reliably isolate a specific digit position from an int
{

    int i;
    int number = 10;

    for (i = 0; i < size; i++)
    {
        int count = 0;
        int last;
        int z;
        int num = input_Array[i];

        while(count < numeral)
        {
            z = num % 10;
            num = num /10;
            count++;
        }

        output_Array[i] = z;
    }



}
int printing_Array(int *print_Array, int size)
{
    int i = 0;
    for (i = 0; i < size; i++)
    {
        printf("%d: %d\n", i, print_Array[i]);
    }
}


void counting_sort(int *input_Array, int size, int *output_Array, int *numer, int *numerArrSize, int s, int numeral,int initial_Rank) /// counting sort function
{
    printf("position %d n %d\n", numeral,size);
    output_Array = (int*)malloc(size * sizeof(int));
    int* digitArr;
    digitArr = (int*)malloc(size * sizeof(int));
    isolating_Digit(input_Array, digitArr, size, numeral);
    int counting_Arrayy[10] = {0};
    int insert[10] = {0};
    int i = 0;
    int j = 0;

    int numDigits = 10;

    for (i = 0; i < size; i++)
    {
        counting_Arrayy[digitArr[i]]++;
    }


    insert[0] = 0;
    for (i = 1; i < numDigits; i++)
    {
        insert[i] = insert[i-1] + counting_Arrayy[i-1];
    }

    int start_position;
    int end_position;
    int searching_position = 0;
    int start_num = 0;
    int end_num;

    for (i = 0; i < numDigits; i++)
    {
        start_position = insert[i];
        end_position = insert[i]+counting_Arrayy[i] - 1;

        if (counting_Arrayy[i] == 0)
        {
            start_position = end_position = -1;
        }

        if ((s <= end_position) && (s >= start_position))
        {
            searching_position = 1;
            start_num = start_position;
            end_num = end_position;
            break;
        }
        else
        {
            searching_position = 0;
        }

    }


    for (i = 0; i < size; i++)
    {
        output_Array[insert[digitArr[i]]++] = input_Array[i];
    }


    *numerArrSize = end_num - start_num + 1;
    numer = (int*)malloc(*numerArrSize * sizeof(int));

    int a = start_num;
    for (i = 0; i < *numerArrSize; i++)
    {
        numer[i] = output_Array[a++];
    }

    numeral = numeral - 1;
    s = s - start_num;

    free(digitArr);

    if (*numerArrSize != 1)
    {
        counting_sort(numer, *numerArrSize, output_Array, numer, numerArrSize, s, numeral,initial_Rank);
        free(numer);
    }
    else
    {
        printf("position %d n %d\n", numeral, *numerArrSize); /// prints output
        printf("MSD 10 radix: The value with rank %d is %d\n", initial_Rank, numer[0]); /// prints output
    }
}


int main() /// main function
{
    int num;
    int numm;
    int* inserting_Arrray;
    int* digit_Array;
    int* sorted_Array;
    int* array;
    int array_size = 0;
    int i = 0;
    int j;

    scanf("%d", &num);
    scanf("%d", &numm);

    inserting_Arrray = (int*)malloc(num * sizeof(int));
    digit_Array = (int*)malloc(num * sizeof(int));
    sorted_Array = (int*)malloc(num * sizeof(int));

    for (i = 0; i < num; i++)
    {
        scanf("%d", inserting_Arrray + i);
    }
    counting_sort(inserting_Arrray, num, sorted_Array, array, &array_size, numm-1, 9,numm);

    free(inserting_Arrray);
    free(digit_Array);
    free(sorted_Array);
}

