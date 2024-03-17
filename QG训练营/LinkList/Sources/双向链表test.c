#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"链表.h" 

int main()
{
	link* nadress = NULL;
	dulist* list = NULL;
	int a, olddata, newdata,adress;
	menu_list();
	printf("请输入对应数字：");
	scanf_s("%d", &a);
	while (a != 1)
	{
		printf("链表创建，请重新输入:\n");
		scanf_s("%d", &a);
	}
	do
	{
		if (a == 9)
		{
			printf("链表已删除\n退出成功\n");
			break;
		}
		switch (a)
		{
		case 1: list = creat_list();								 //初始化链表
			break;
		case 2:show_list(list);
			printf("输入插入处的节点数据:");					//在指定处插入一个节点
			scanf_s("%d", &olddata);
			printf("\n");
			printf("请输入该节点的位置：");
			scanf_s("%d", &adress);
			printf("\n");
			printf("输入新节点的数据：");
			scanf_s("%d", &newdata);
			nadress = find(list, olddata, adress);
			if (nadress == NULL) break;
			insert(list,nadress ,newdata);
			break;
		case 3:printf("输入新节点的数据：");					//在头部插入节点
			scanf_s("%d", &newdata);
			insert_start(list, newdata);
			break;
		case 4:printf("输入新节点的数据：");					//在尾部插入节点
			scanf_s("%d", &newdata);
			insert_back(list, newdata);
			break;
		case 5:delete_back(list);								//删除尾节点
			break;
		case 6:delete_start(list);								//删除头节点后那个节点
			break;
		case 7:show_list(list);
			printf("请输入要删除节点的数据：");				//删除指定数据的那个节点
			scanf_s("%d", &olddata);
			delete(list, olddata);
			break;
		case 8:clear(list);										//清空链表
			break;
		case 9:destory(list);									//销毁链表
			break;
		case 10:sort(list);										//链表排序
			break;
		case 11:reverse(list);									//链表反转
			break;
		case 12:show_list(list);								//输出链表
			break;
		}
		printf("请按任意键以继续....\n");
		getch();
		system("cls");
		menu_list();
		printf("请输入对应数字：");
		scanf_s("%d", &a);
	} while (a != 13);
	system("pause");
	return EXIT_SUCCESS;
}