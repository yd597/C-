#pragma warning(disable:4996)//����scanf�ľ��棻

#ifndef __ADDRESS_H__//��ֹ�ض��壻
#define __ADDRESS_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NAME_MAX 20
#define SEX_MAX 4
#define HOME_MAX 10
#define TEL_MAX 13
#define MAX 1000

//�������Ա����䡢�绰��סַ
typedef struct person
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char tel[TEL_MAX];
	char home[HOME_MAX];
}person;

//ͨѶ¼��Ա�ṹ�壻
typedef struct count
{
	person people[MAX];
	int size;//ȷ��ͨѶ¼��ǰ������
}count, *con;//ָ�������ں����ڲ����ܽṹ��ָ�룻

enum op
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MOD,
	SHOW,
	SORT,
	EMPTY
};
void Exit(con Con);//�˳�������
void Add(con Con);//������Ա��
void Del(con Con);//ɾ����Ա��
void Search(con Con);//���ҳ�Ա��
void Mod(con Con);//�޸ĳ�Ա��
void Show(con Con);//��ʾ���г�Ա��
void Empty(con Con);//���ͨѶ¼��
void Sort(con Con);//�������г�Ա��
void Check(con Con);//ѡ������
void _Print();


#endif  //__ADDRESS_H__