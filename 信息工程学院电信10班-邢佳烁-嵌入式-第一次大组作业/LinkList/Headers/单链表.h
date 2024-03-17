#pragma once

#include<stdlib.h>
#include<stdlib.h>
#include<stdio.h>

#ifdef __cplusplus
extern "C" {
#endif
		//定义节点数据
	struct linklist
	{
		int data;
		struct linklist* next;
	};
		//初始化链表
	struct linklist* start_linklist();
		//插入新节点
	void insert_linklist(struct linklist* header);
		//删除某个节点
	void remove_linklist(struct linklist* header);
		//遍历
	void bianli_linklist(struct linklist* header);
		//销毁
	void break_linklist(struct linklist* header);
		//反转
	void fing_middle(struct linklist* header);
		//菜单
	void menu_linklist();

#ifdef __cplusplus
}
#endif

