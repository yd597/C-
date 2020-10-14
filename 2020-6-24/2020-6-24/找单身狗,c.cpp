#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <assert.h>
#include <windows.h>
void FindTwoSingle(int a[], int num, int *x, int *y)
{
	assert(a);
	assert(num > 0);
	assert(x);
	assert(y);

	//�������
	int result = a[0]; //result: 3, 011
	for (int i = 1; i < num; i++){
		result ^= a[i];
	}
	//�ҵ���ͬ�ı���λ��λ��
	int pos = 1;
	while (1)
	{
		if (result & pos){ //000001-> 000010
			break;
		}
		pos <<= 1;
	}
	*x = 0;
	*y = 0;
	//���ݲ�ͬ�ı���λ��λ��pos���������黮�֣������黮�ֳ�Ϊ2����
	for (int i = 0; i < num; i++){
		if (a[i] & pos){
			//A��
			*x ^= a[i];
		}
		else{
			//B��
			*y ^= a[i];
		}
	}
}
int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 11, 33, 1, 2, 3, 4, 5, 6, 7, 8 };
	int num = sizeof(a) / sizeof(a[0]);
	int x = 0;
	int y = 0;
	FindTwoSingle(a, num, &x, &y); //
	printf("X: %d, Y: %d\n", x, y);
	system("pause");
	return 0;
}

