#pragma once

#include<stdlib.h>
#include<stdlib.h>
#include<stdio.h>

#ifdef __cplusplus
extern "C" {
#endif
		//����ڵ�����
	struct linklist
	{
		int data;
		struct linklist* next;
	};
		//��ʼ������
	struct linklist* start_linklist();
		//�����½ڵ�
	void insert_linklist(struct linklist* header);
		//ɾ��ĳ���ڵ�
	void remove_linklist(struct linklist* header);
		//����
	void bianli_linklist(struct linklist* header);
		//����
	void break_linklist(struct linklist* header);
		//��ת
	void fing_middle(struct linklist* header);
		//�˵�
	void menu_linklist();

#ifdef __cplusplus
}
#endif

