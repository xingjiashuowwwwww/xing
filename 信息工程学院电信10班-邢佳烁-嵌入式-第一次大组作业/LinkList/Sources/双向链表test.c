#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"����.h" 

int main()
{
	link* nadress = NULL;
	dulist* list = NULL;
	int a, olddata, newdata,adress;
	menu_list();
	printf("�������Ӧ���֣�");
	scanf_s("%d", &a);
	while (a != 1)
	{
		printf("������������������:\n");
		scanf_s("%d", &a);
	}
	do
	{
		if (a == 9)
		{
			printf("������ɾ��\n�˳��ɹ�\n");
			break;
		}
		switch (a)
		{
		case 1: list = creat_list();								 //��ʼ������
			break;
		case 2:show_list(list);
			printf("������봦�Ľڵ�����:");					//��ָ��������һ���ڵ�
			scanf_s("%d", &olddata);
			printf("\n");
			printf("������ýڵ��λ�ã�");
			scanf_s("%d", &adress);
			printf("\n");
			printf("�����½ڵ�����ݣ�");
			scanf_s("%d", &newdata);
			nadress = find(list, olddata, adress);
			if (nadress == NULL) break;
			insert(list,nadress ,newdata);
			break;
		case 3:printf("�����½ڵ�����ݣ�");					//��ͷ������ڵ�
			scanf_s("%d", &newdata);
			insert_start(list, newdata);
			break;
		case 4:printf("�����½ڵ�����ݣ�");					//��β������ڵ�
			scanf_s("%d", &newdata);
			insert_back(list, newdata);
			break;
		case 5:delete_back(list);								//ɾ��β�ڵ�
			break;
		case 6:delete_start(list);								//ɾ��ͷ�ڵ���Ǹ��ڵ�
			break;
		case 7:show_list(list);
			printf("������Ҫɾ���ڵ�����ݣ�");				//ɾ��ָ�����ݵ��Ǹ��ڵ�
			scanf_s("%d", &olddata);
			delete(list, olddata);
			break;
		case 8:clear(list);										//�������
			break;
		case 9:destory(list);									//��������
			break;
		case 10:sort(list);										//��������
			break;
		case 11:reverse(list);									//����ת
			break;
		case 12:show_list(list);								//�������
			break;
		}
		printf("�밴������Լ���....\n");
		getch();
		system("cls");
		menu_list();
		printf("�������Ӧ���֣�");
		scanf_s("%d", &a);
	} while (a != 13);
	system("pause");
	return EXIT_SUCCESS;
}