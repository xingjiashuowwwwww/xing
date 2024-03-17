#include<stdio.h>
#include"����.h"
#include<malloc.h>
//����һ������
dulist* creat_list()
{
	int i,many,newdata;
	i = 0;
	dulist* list = calloc(1, sizeof(dulist));					//��������
	if (list != NULL)
	{
		list->front = calloc(1, sizeof(link));					//����ͷ�ڵ�
	}
	if (list->front != NULL)
	{
		list->tail = list->front;								//��ͷָ���βָ�붼ָ��ͷ�ڵ�
	}
	list->front->prev = list->front;
	list->tail->next = list->front;
	printf("������ڵ������");
	scanf_s("%d", &many);
	printf("\n");
	while (i < many)
	{
		printf("������ڵ����ݣ�");
		scanf_s("%d", &newdata);							//����ڵ�����
		link* newnode = calloc(1, sizeof(link));
		newnode->next = list->tail->next;					//�½ڵ�ĺ��ָ��ָ��NULL
		newnode->prev = list->tail;							//�½ڵ��ǰ��ָ��ָ��ԭ�����һ��
		list->tail->next = newnode;							//��ԭ�ȵ�β�ڵ��nextָ���½ڵ�
		list->tail = newnode;								//��βָ��ָ���½ڵ�
		list->front->prev = newnode;
		newnode->data = newdata;
		list->size++;
		i++;
	}
	printf("�������ɹ�\n");
	return list;
}
//�������
void show_list(dulist* list)
{
	if (list == NULL)  return;
	link* plink = list->front->next;
	printf("��ǰ����");
	while (plink != list->front)
	{
		printf("%d  ", plink->data);
		plink = plink->next;
	}
	printf("\n");
}
//��ָ�����ݵĽڵ�ǰ����һ���½ڵ�
void insert(dulist* list, link* adress, int newdata)
{
	link* newnode = calloc(1, sizeof(link));
	link* prevnode = adress->prev;						//����Ҫ�����λ�õ���һ���ڵ�
	newnode->next = adress;								//���½ڵ�������ȥ
	newnode->prev = prevnode;
	adress->prev = newnode;								//��ǰ��ڵ������½ڵ�
	prevnode->next = newnode;
	newnode->data = newdata;
	printf("����ɹ���\n");
	show_list(list);
}
//��β������һ���ڵ�
void insert_back(dulist* list, int newdata)
{
	link* newnode = calloc(1, sizeof(link));
	newnode->next = list->tail->next;					//�½ڵ�ĺ��ָ��ָ��NULL
	newnode->prev = list->tail;							//�½ڵ��ǰ��ָ��ָ��ԭ�����һ��
	list->tail->next = newnode;							//��ԭ�ȵ�β�ڵ��nextָ���½ڵ�
	list->tail = newnode;								//��βָ��ָ���½ڵ�
	list->front->prev = newnode;
	newnode->data = newdata;							//Ϊ�½ڵ㸳ֵ
	list->size++;
	printf("����ɹ���\n");
	show_list(list);
}
//��ͷ������һ���ڵ�
void insert_start(dulist* list, int newdata)
{
	link* newnode = calloc(1, sizeof(link));			//����һ���½ڵ�
	newnode->next = list->front->next;					//���½ڵ�ĺ��ָ��������һ���ڵ�
	newnode->prev = list->front;						//���½ڵ��ǰ��ָ����ͷ�ڵ�����
	list->front->next->prev = newnode;					//���½ڵ����һ���ڵ��ǰ��ָ�����½ڵ�����
	list->front->next = newnode;						//��ͷ�ڵ�ĺ��ָ�����½ڵ�����
	newnode->data = newdata;
	list->size++;
	printf("����ɹ���\n");
	show_list(list);
}
//ɾ��β�ڵ�
void delete_back(dulist* list)
{
	if (list == NULL) return;
	list->tail = list->tail->prev;						//��βָ��ָ�����ڶ����ڵ�
	free(list->tail->next);								//ɾ��β�ڵ�
	list->tail->next = list->front;						//���µ�β�ڵ��ͷ�ڵ�����
	list->front->prev = list->tail;						
	list->size--;
	printf("ɾ���ɹ���\n");
	show_list(list);
}
//ɾ��ͷ�ڵ����Ǹ��ڵ�
void delete_start(dulist* list)
{
	if (list == NULL) return;
	link* newnode = list->front->next;					//����ɾ���Ľڵ�
	list->front->next = newnode->next;
	if (newnode->next != NULL)							//�ж��ǲ���ֻ��һ���ڵ�
	{
		newnode->next->prev = list->front;				//����ڵ�
	}
	else
	{
		list->tail = list->front;						//ֻ��һ���ڵ㣬��βָ����д���
	}
	free(newnode);										//ɾ���ýڵ�
	list->size--;
	printf("ɾ���ɹ���\n");
	show_list(list);
}
//ɾ��ָ��ĳ���ݵĽڵ�
void delete(dulist* list, int olddata)
{
	int adress = 0;											//���ڴ�ŵ�ַ
	printf("������ýڵ�λ�ã�");
	scanf_s("%d", &adress);
	link* node = find(list, olddata,adress);
	if (node == NULL)  return;
	link* prevnode = node->prev;						//������һ���ڵ�
	prevnode->next = node->next;
	node->next->prev = prevnode;						//���ýڵ�ǰ�������ڵ�������
	free(node);
	list->size--;
	printf("ɾ���ɹ���\n");
	show_list(list);
}
//����ĳ�������ڽڵ�λ��
link* find(dulist* list, int olddata,int adress)
{
	int i = 0;										//i�����жϸ�λ�õ������Ƿ���ȷ
	if (list == NULL) return;
	link* newnode = list->front;					//ָ��ָ��ͷ�ڵ�
	while (newnode != NULL)
	{
		newnode = newnode->next;					//��ͷ������һ���ڵ㿪ʼ
		i++;
		if (newnode->data == olddata &&i==adress)	//�������
		{
			return newnode;
		}
		if (i > adress)
		{
			printf("�����ݲ�����\n");
			return NULL;
		}
	}
}
//�������
void clear(dulist* list)
{
	if (list == NULL)  return;
	while (list->front->next != list->front)		//���һȦ
	{
		delete_start(list);
	}
	list->size = 0;
	printf("����ɹ���\n");
}
//��������
void destory(dulist* list)
{
	clear(list);									//���һȦ
	free(list->front);								//���ͷ�ڵ�
	free(list);										//ȫ�����
	list = NULL;
	printf("���ٳɹ�\n");
}
//����
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
	printf("����ɹ���\n");
	show_list(list);
}
//��ת
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
	printf("��ת�ɹ���\n");
	show_list(list);
}
//�˵�
void menu_list()
{
	printf("\t\t*****************************************\n");
	printf("\t\t1.��ʼ������				*\n");
	printf("\t\t2.��ָ�����ݴ������½ڵ�		*\n");
	printf("\t\t3.ͷ�巨����ڵ�			*\n");
	printf("\t\t4.β�巨����ڵ�			*\n");
	printf("\t\t5.ɾ��β�ڵ�				*\n");
	printf("\t\t6.ɾ��ͷ�ڵ�֮���Ǹ��ڵ�		*\n");
	printf("\t\t7.ɾ��ָ�����ݵĽڵ�			*\n");
	printf("\t\t8.�������				*\n");
	printf("\t\t9.��������				*\n");
	printf("\t\t10.��������				*\n");
	printf("\t\t11.����ת				*\n");
	printf("\t\t12.�������				*\n");
	printf("\t\t13.�˳�ϵͳ				*\n");
	printf("\t\t*****************************************\n");
}