#include"address.h"
//�������Ա����䡢�绰��סַ
void _Print()
{
	printf("*************************\n");
	printf("1.	�����ϵ����Ϣ\n");
	printf("2.	ɾ��ָ����ϵ����Ϣ\n");
	printf("3.	����ָ����ϵ����Ϣ\n");
	printf("4.	�޸�ָ����ϵ����Ϣ\n");
	printf("5.	��ʾ������ϵ����Ϣ\n");
	printf("6.	����������ϵ����Ϣ\n");
	printf("7.	���������ϵ��\n");
	printf("0.      �˳�\n");
	printf("*************************\n");
	printf("��ѡ���� (0-7):>\n");
}

/*
��Ϊ�ü������������õ����Һ��������Ե�����סһ��find������
*/
int find(con Con, char arr[])//���ò��Һ�����
{
	int i = 0;
	for (; i<Con->size; i++)
	{
		if (strcmp(Con->people[i].name, arr) == 0)
			return i;
	}
	return -1;
}

void Add(con Con)//���ӳ�Ա��
{
	if (Con->size < MAX)//�ж�ͨѶ¼�Ƿ������
	{
		printf("׼�����һ���³�Ա��>\n");
		printf("������������\n");
		scanf("%s", &(Con->people[Con->size].name));
		printf("�������Ա�\n");
		scanf("%s", &(Con->people[Con->size].sex));
		printf("���������䣺\n");
		scanf("%d", &(Con->people[Con->size].age));
		printf("������绰��\n");
		scanf("%s", &(Con->people[Con->size].tel));
		printf("�������ַ��\n");
		scanf("%s", &(Con->people[Con->size].home));
		printf("����ɹ���\n");
		Con->size++;//ע�⣺ÿ����һ����Ա��ͨѶ¼������size����+1��
	}
	else
		printf("ͨѶ¼������\n");
}

void Del(con Con)//ɾ����Ա��
{

	int ret = 0;
	char name[20] = { 0 };

	if (Con->size == 0)
	{
		printf("�ף���ǰͨѶ¼�ǿյģ�\n");
		return;
	}

	printf("��������Ҫɾ���˵�������\n");
	scanf("%s", &name);

	ret = find(Con, name);
	/*
	ɾ���ķ����ǽ����һ����Ա�ŵ�ɾ���������Աλ���ϣ�
	ע��: ��������size--;
	*/
	if (ret >= 0)
	{
		Con->people[ret] = Con->people[Con->size - 1];
		(Con->size)--;
		printf("ɾ���ɹ���\n");

	}
	else
		printf("û���ҵ�Ҫɾ���Ķ���\n");

}



void Search(con Con)//���ҳ�Ա��ֱ�ӵ���find������
{
	int ret = 0;
	char name[20] = { 0 };

	printf("������Ҫ��ѯ�˵�������\n");
	scanf("%s", &name);

	ret = find(Con, name);
	if (ret >= 0)
	{
		printf("%10s\t%4s\t%3s\t%13s\t%10s\n", "name", "sex", "age", "tel", "address");

		printf("%10s\t%4s\t%3d\t%13s\t%10s\n", Con->people[ret].name,
			Con->people[ret].sex, Con->people[ret].age,
			Con->people[ret].tel, Con->people[ret].home);
	}
	else
		printf("û�ҵ���ͨѶ¼���ѣ�\n");


}

void Mod(con Con)//�ı��Ա��
{
	int i = 0;
	int ret = 0;
	char name[20] = { 0 };
	char *ptr[] = { "name", "sex", "age", "tel", "address" };
	//ÿ�θı��Ա�ĵ������ݣ�
	printf("��������Ҫ�޸ĵ���ϵ�ˣ�\n");
	scanf("%s", &name);

	ret = find(Con, name);//���ò��Һ�����

	if (ret >= 0)
	{
		int ages = 0;
		char mod[20] = { 0 };
		int sel = 0;
		printf("��������Ҫ�޸ĵ�ѡ�\n");
		printf("1.name\n2.sex\n3.age\n4.tel\n5.adress\n");
		scanf("%d", &sel);
		printf("������\n");
		//���ѡ��switch��䣻�Ƚ����׿�������ʵ���Խ��з�װ��
		switch (sel)
		{
		case 1:
			scanf("%s", &mod);
			strcpy(Con->people[ret].name, mod);
			printf("�޸ĳɹ���\n");
			break;
		case 2:
			scanf("%s", &mod);
			strcpy(Con->people[ret].sex, mod);
			printf("�޸ĳɹ���\n");
			break;
		case 3:
			scanf("%d", &ages);
			Con->people[ret].age = ages;
			printf("�޸ĳɹ���\n");
			break;
		case 4:
			scanf("%s", &mod);
			strcpy(Con->people[ret].tel, mod);
			printf("�޸ĳɹ���\n");
			break;
		case 5:
			scanf("%s", &mod);
			strcpy(Con->people[ret].home, mod);
			printf("�޸ĳɹ���\n");
			break;
		default:
			printf("�޸�ʧ�ܣ�\n");
			break;
		}
	}
	else
		printf("û�иó�Ա!\n");

}


void Show(con Con)//��ʾ���г�Ա��
{
	int i = 0;
	printf("%10s\t%4s\t%3s\t%13s\t%10s\n", "name", "sex", "age", "tel", "address");
	//ѭ����ӡÿ��ͨѶ¼��Ա��
	for (; i < Con->size; i++)
	{
		printf("%10s\t%4s\t%3d\t%13s\t%10s\n", Con->people[i].name,
			Con->people[i].sex, Con->people[i].age,
			Con->people[i].tel, Con->people[i].home);
	}

}

void Empty(con Con)//�����ϵ�ˣ�
{
	/*
	���ͨѶ¼ֻ��Ҫ��ͨѶ¼�ܳ�Ա��size��Ϊ 0��
	*/
	Con->size = 0;
	printf("ͨѶ¼�ѿգ�\n");
}


void Sort(con Con)//����������ϵ�ˣ�
{
	/*
	ð���������г�Ա�����֣�
	*/
	int flag = 0;
	int i = 0;
	int j = 0;
	for (i = 0; i < Con->size - 1; i++)
	{
		flag = 1;
		for (j = 0; j <(Con->size) - i - 1; j++)
		{
			if ((strcmp(Con->people[j].name, Con->people[j + 1].name))> 0)
			{
				person tmp = Con->people[j];
				Con->people[j] = Con->people[j + 1];
				Con->people[j + 1] = tmp;
				flag = 0;
			}
		}
		if (flag == 1)
			break;
	}
}

void Exit(con Con)//�˳�������
{
	exit(0);
}

//����һ������ָ�����飬����Ժ����ĵ��ã�
void(*str[8])(con Con) = { Exit, Add, Del, Search, Mod, Show, Sort, Empty };


void Check(con Con)//ѡ������
{
	int select = 0;
	_Print();
	scanf("%d", &select);

	if (select == 0 || select == 1 || select == 2 || select == 3 || select == 4 || select == 5 || select == 6 || select == 7)
		str[select](Con);
	/*
	�����main�����в�����whileѭ��ֱ����Check�����е����Լ���
	ȱ���ǣ������ݹ����Check�������ᵼ��ջ�����
	Check(Con);
	*/
	else
		printf("�����ʽ����\n");
	//��ʱû�н������ѡ���0-7���쳣��

}