#pragma once

#include<stdlib.h>
#include<stdlib.h>
#include<stdio.h>

#ifdef __cplusplus
extern "C" {
#endif
	typedef struct double_link
	{
		int data;							//����
		struct double_link* next;			//ָ����һ���ڵ�
		struct double_link* prev;			//ָ����һ���ڵ�
	}link;
	typedef struct double_list
	{
		int size;							//��ǰ�ڵ�����
		link* front;						//ָ��ͷ�ڵ�
		link* tail;							//ָ��β�ڵ�
	}dulist;
	//����һ��˫������
	dulist* creat_list();
	//�������
	void show_list(dulist* list);
	//��ָ�����ݵĽڵ�ǰ����һ���½ڵ�
	void insert(dulist* list, link* adress, int newdata);
	//��β������һ���ڵ�
	void insert_back(dulist* list, int newdata);
	//��ͷ������һ���ڵ�
	void insert_start(dulist* list, int newdata);
	//ɾ��β�ڵ�
	void delete_back(dulist* list);
	//ɾ��ͷ�ڵ����Ǹ��ڵ�
	void delete_start(dulist* list);
	//ɾ��ָ��ĳ���ݵĽڵ�
	void delete(dulist* list, int olddata);
	//����ĳ�������ڽڵ�λ��
	link* find(dulist* list, int olddata,int adress);
	//�������
	void clear(dulist* list);
	//��������
	void destory(dulist* list);
	//����
	void sort(dulist* list);
	//��ת
	void reverse(dulist* list);
	//�˵�
	void menu_list();
#ifdef __cplusplus
}
#endif