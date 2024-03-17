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
	printf("请输入对应数字：");
	scanf_s("%d", &a);
	while (a != 1)
	{
		printf("链表未初始化，请重新输入:\n");
		scanf_s("%d",&a);
	}
	do
	{
		if (a == 5)
		{
			printf("链表已删除\n退出成功\n");
			break;
		}
		switch (a)
		{
		case 1:header = start_linklist();               //初始化链表
			break;
		case 2:insert_linklist(header);					//插入节点
			break;
		case 3: remove_linklist(header);				//删除节点
			break;
		case 4:bianli_linklist(header);					//遍历输出链表
			break;
		case 5:break_linklist(header);					//销毁链表
			break;
		case 6:fing_middle(header);						//寻找中点
			break;
		
		}
		if (a == 7) break;
		printf("请按任意键以继续....\n");
		getch();
		system("cls");
		menu_linklist();
		printf("请输入对应数字：");
		scanf_s("%d", &a);
	} while (1);
	system("pause");
	return EXIT_SUCCESS;
}