#include<stdio.h>
#include<windows.h>
#include<stdlib.h> 
#pragma warning (disable :4996)
//int Find(int arr[][6],int row,int col, int target)
//{
//	int i = 0;
//	int j = col-1;
//	while (i < row && j>0)
//	{
//		if (target > arr[i][j])
//		{
//			i++;
//		}
//		else if (target < arr[i][j])
//		{
//			j--;
//		}
//		else
//		{
//			return  1;
//
//		}
//	}
//	return -1;
//
//}




//
//int main()
//{
//	int arr[5][6] = { { 2, 3, 4, 5, 6, 7 },
//	{ 10, 11, 12, 13, 14, 15 },
//	{ 21, 22, 23, 24, 25, 26 },
//	{ 31, 32, 33, 34, 35, 36 },
//	{ 41, 42, 43, 44, 45, 46 } };
//	int x = 0;
//	scanf("%d", &x);
//	Find(arr,5,6, x);
//	printf("%d", Find(arr, 5, 6, x));
//	system("pause");
//	return 0;
//}
//void qsort(void* base, size_t num, size_t size,
//	int(*compar)(const void*, const void*))
int compare(const void * a, const void * b)
{
	return (*(double*)a - *(double*)b);
}
void Show(double arr[], int num)
{
	int i = 0;
	for (; i < num; i++)
		printf("%5.2f ", arr[i]);
}
int main()
{
	/*int arr[] = { 12, 32, 45, 89, 65, 43, 90, 22567, 567, 21, 1, 2, 4 };*/
	double arr[] = { 12.3, 34, 51.3, 1.2, 45.6, 90.7, 11.3, 90.6 };

	int num = sizeof(arr) / sizeof(arr[0]);	
	Show(arr,num);
	printf("\n");
	qsort(arr, num, sizeof(double), compare);
	Show(arr,num);
	system("pause");
	return 0;
}