#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"linklist.h"

int main()
{
	struct linklist* header=NULL;
	int a = 0;
	menu_linklist();
	printf("�������Ӧ���֣�");
	scanf_s("%d", &a);
	while (a != 1)
	{
		printf("����δ��ʼ��������������:\n");
		scanf_s("%d",&a);
	}
	do
	{
		if (a == 5)
		{
			printf("������ɾ��\n�˳��ɹ�\n");
			break;
		}
		switch (a)
		{
		case 1:header = start_linklist();               //��ʼ������
			break;
		case 2:insert_linklist(header);					//����ڵ�
			break;
		case 3: remove_linklist(header);				//ɾ���ڵ�
			break;
		case 4:bianli_linklist(header);					//�����������
			break;
		case 5:break_linklist(header);					//��������
			break;
		case 6:fing_middle(header);						//Ѱ���е�
			break;
		
		}
		if (a == 7) break;
		printf("�밴������Լ���....\n");
		getch();
		system("cls");
		menu_linklist();
		printf("�������Ӧ���֣�");
		scanf_s("%d", &a);
	} while (1);
	system("pause");
	return EXIT_SUCCESS;
}