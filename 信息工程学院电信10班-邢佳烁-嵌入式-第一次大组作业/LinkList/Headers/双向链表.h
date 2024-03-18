#pragma once

#include<stdlib.h>
#include<stdlib.h>
#include<stdio.h>

#ifdef __cplusplus
extern "C" {
#endif
	typedef struct double_link
	{
		int data;							//数据
		struct double_link* next;			//指向下一个节点
		struct double_link* prev;			//指向上一个节点
	}link;
	typedef struct double_list
	{
		int size;							//当前节点数量
		link* front;						//指向头节点
		link* tail;							//指向尾节点
	}dulist;
	//创建一个双向链表
	dulist* creat_list();
	//遍历输出
	void show_list(dulist* list);
	//在指定数据的节点前插入一个新节点
	void insert(dulist* list, link* adress, int newdata);
	//在尾部插入一个节点
	void insert_back(dulist* list, int newdata);
	//在头部插入一个节点
	void insert_start(dulist* list, int newdata);
	//删除尾节点
	void delete_back(dulist* list);
	//删除头节点后的那个节点
	void delete_start(dulist* list);
	//删除指定某数据的节点
	void delete(dulist* list, int olddata);
	//查找某数据所在节点位置
	link* find(dulist* list, int olddata,int adress);
	//清除链表
	void clear(dulist* list);
	//销毁链表
	void destory(dulist* list);
	//排序
	void sort(dulist* list);
	//反转
	void reverse(dulist* list);
	//菜单
	void menu_list();
#ifdef __cplusplus
}
#endif