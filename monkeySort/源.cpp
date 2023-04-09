#include <stdio.h>     
#include <stdbool.h>
#include <stdlib.h>  
#include <math.h>
#include <time.h>
void change(int* a, int* b)   //������Ԫ�ص�ֵ
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void printArray(int a[], int count)   //��ӡ����Ԫ��
{
    int i;
    for (i = 0; i < count; i++)
        printf("%d ", a[i]);
    printf("\n");
}

bool isOrder(int a[], int n)  //�ж������Ƿ��Ѿ�����
{
    int i;
    for (i = 0; i < n - 1; i++)//����i�ǱȽϴ���������<n-1 
    {
        if (a[i] > a[i + 1])  return false;
    }
    return true;
}

void shuffle(int a[], int n)
{
    int i, changePosition;
    for (i = 0; i < n; i++)
    {
        changePosition = rand() % n;
        change(&a[i], &a[changePosition]);//��������±겻ͬ��Ԫ��
    }
}

void bogoSort(int a[], int n)
{
    int count = 0;
    while (!isOrder(a, n))
    {
        shuffle(a, n);
        count++;
        printf("��%d������\n", count);
    }
    printf("\n\n�������Ϊ��%d��\n\n", count);
}

int main(void)
{
    int a[] = { 7,4,0,9,2,6};
    int n = sizeof(a) / sizeof(*a);//��������Ԫ�ظ���
    srand((unsigned)time(NULL)); //��������� 
    printArray(a, n);//�������
    bogoSort(a, n);//��������
    printArray(a, n);//������� 
    system("pause");
    return 0;
}
