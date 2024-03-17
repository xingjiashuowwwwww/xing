#include<stdio.h>
#include"链表.h"
#include<malloc.h>
//创建一个链表
dulist* creat_list()
{
	int i,many,newdata;
	i = 0;
	dulist* list = calloc(1, sizeof(dulist));					//创建链表
	if (list != NULL)
	{
		list->front = calloc(1, sizeof(link));					//创建头节点
	}
	if (list->front != NULL)
	{
		list->tail = list->front;								//让头指针和尾指针都指向头节点
	}
	list->front->prev = list->front;
	list->tail->next = list->front;
	printf("请输入节点个数：");
	scanf_s("%d", &many);
	printf("\n");
	while (i < many)
	{
		printf("请输入节点数据：");
		scanf_s("%d", &newdata);							//输入节点数据
		link* newnode = calloc(1, sizeof(link));
		newnode->next = list->tail->next;					//新节点的后继指针指向NULL
		newnode->prev = list->tail;							//新节点的前驱指针指向原先最后一个
		list->tail->next = newnode;							//让原先的尾节点的next指向新节点
		list->tail = newnode;								//让尾指针指向新节点
		list->front->prev = newnode;
		newnode->data = newdata;
		list->size++;
		i++;
	}
	printf("链表创建成功\n");
	return list;
}
//遍历输出
void show_list(dulist* list)
{
	if (list == NULL)  return;
	link* plink = list->front->next;
	printf("当前链表：");
	while (plink != list->front)
	{
		printf("%d  ", plink->data);
		plink = plink->next;
	}
	printf("\n");
}
//在指定数据的节点前插入一个新节点
void insert(dulist* list, link* adress, int newdata)
{
	link* newnode = calloc(1, sizeof(link));
	link* prevnode = adress->prev;						//保存要插入的位置的上一个节点
	newnode->next = adress;								//让新节点是连上去
	newnode->prev = prevnode;
	adress->prev = newnode;								//让前后节点连上新节点
	prevnode->next = newnode;
	newnode->data = newdata;
	printf("插入成功！\n");
	show_list(list);
}
//在尾部插入一个节点
void insert_back(dulist* list, int newdata)
{
	link* newnode = calloc(1, sizeof(link));
	newnode->next = list->tail->next;					//新节点的后继指针指向NULL
	newnode->prev = list->tail;							//新节点的前驱指针指向原先最后一个
	list->tail->next = newnode;							//让原先的尾节点的next指向新节点
	list->tail = newnode;								//让尾指针指向新节点
	list->front->prev = newnode;
	newnode->data = newdata;							//为新节点赋值
	list->size++;
	printf("插入成功！\n");
	show_list(list);
}
//在头部插入一个节点
void insert_start(dulist* list, int newdata)
{
	link* newnode = calloc(1, sizeof(link));			//创建一个新节点
	newnode->next = list->front->next;					//将新节点的后继指针连接下一个节点
	newnode->prev = list->front;						//将新节点的前驱指针与头节点连接
	list->front->next->prev = newnode;					//将新节点的下一个节点的前驱指针与新节点相连
	list->front->next = newnode;						//将头节点的后继指针与新节点连接
	newnode->data = newdata;
	list->size++;
	printf("插入成功！\n");
	show_list(list);
}
//删除尾节点
void delete_back(dulist* list)
{
	if (list == NULL) return;
	list->tail = list->tail->prev;						//将尾指针指向倒数第二个节点
	free(list->tail->next);								//删除尾节点
	list->tail->next = list->front;						//将新的尾节点和头节点连接
	list->front->prev = list->tail;						
	list->size--;
	printf("删除成功！\n");
	show_list(list);
}
//删除头节点后的那个节点
void delete_start(dulist* list)
{
	if (list == NULL) return;
	link* newnode = list->front->next;					//保存删除的节点
	list->front->next = newnode->next;
	if (newnode->next != NULL)							//判断是不是只有一个节点
	{
		newnode->next->prev = list->front;				//多个节点
	}
	else
	{
		list->tail = list->front;						//只有一个节点，对尾指针进行处理
	}
	free(newnode);										//删除该节点
	list->size--;
	printf("删除成功！\n");
	show_list(list);
}
//删除指定某数据的节点
void delete(dulist* list, int olddata)
{
	int adress = 0;											//用于存放地址
	printf("请输入该节点位置：");
	scanf_s("%d", &adress);
	link* node = find(list, olddata,adress);
	if (node == NULL)  return;
	link* prevnode = node->prev;						//保存上一个节点
	prevnode->next = node->next;
	node->next->prev = prevnode;						//将该节点前后两个节点连接上
	free(node);
	list->size--;
	printf("删除成功！\n");
	show_list(list);
}
//查找某数据所在节点位置
link* find(dulist* list, int olddata,int adress)
{
	int i = 0;										//i用于判断该位置的数据是否正确
	if (list == NULL) return;
	link* newnode = list->front;					//指针指向头节点
	while (newnode != NULL)
	{
		newnode = newnode->next;					//从头结点的下一个节点开始
		i++;
		if (newnode->data == olddata &&i==adress)	//符合情况
		{
			return newnode;
		}
		if (i > adress)
		{
			printf("该数据不存在\n");
			return NULL;
		}
	}
}
//清除链表
void clear(dulist* list)
{
	if (list == NULL)  return;
	while (list->front->next != list->front)		//清除一圈
	{
		delete_start(list);
	}
	list->size = 0;
	printf("清除成功！\n");
}
//销毁链表
void destory(dulist* list)
{
	clear(list);									//清除一圈
	free(list->front);								//清除头节点
	free(list);										//全部清除
	list = NULL;
	printf("销毁成功\n");
}
//排序
void sort(dulist* list)
{
	if (list == NULL)  return;
	for (link* i = list->front->next; i->next != list->front; i = i->next)
	{
		for (link* k = list->front->next; k->next != list->front; k = k->next)
		{
			if (k->data > k->next->data)
			{
				int t = k->data;
				k->data = k->next->data;
				k->next->data = t;
			}
		}
	}
	printf("排序成功！\n");
	show_list(list);
}
//反转
void reverse(dulist* list)
{
	if (list->size <= 1) return;
	link* currentnode = list->front->next;
	link* prevnode = list->front;
	link* nextnode = NULL;
	list->tail = currentnode;
	while (currentnode != list->front)
	{
		nextnode = currentnode->next;
		currentnode->next = prevnode;
		currentnode->prev = nextnode;

		prevnode = currentnode;
		currentnode = nextnode;
	}
	list->front->next= prevnode;
	prevnode->prev = list->front;
	printf("反转成功！\n");
	show_list(list);
}
//菜单
void menu_list()
{
	printf("\t\t*****************************************\n");
	printf("\t\t1.初始化链表				*\n");
	printf("\t\t2.在指定数据处插入新节点		*\n");
	printf("\t\t3.头插法插入节点			*\n");
	printf("\t\t4.尾插法插入节点			*\n");
	printf("\t\t5.删除尾节点				*\n");
	printf("\t\t6.删除头节点之后那个节点		*\n");
	printf("\t\t7.删除指定数据的节点			*\n");
	printf("\t\t8.清除链表				*\n");
	printf("\t\t9.销毁链表				*\n");
	printf("\t\t10.链表排序				*\n");
	printf("\t\t11.链表反转				*\n");
	printf("\t\t12.输出链表				*\n");
	printf("\t\t13.退出系统				*\n");
	printf("\t\t*****************************************\n");
}