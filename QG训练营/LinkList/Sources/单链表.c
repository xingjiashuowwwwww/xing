#include"linklist.h"

//��ʼ������
struct linklist* start_linklist()
{
	int many,i,data;     //many����ڵ�����i����������data����
	struct linklist* current, * next,*header;
	i = 2;
	//������һ���ڵ�
	header = (struct linklist*)malloc(sizeof(struct linklist));
	current = header;
	header->data = -1;
	header->next = NULL;
	//����
	printf("���������ڵ�(������20������");
	scanf_s("%d", &many);
	if (many > 20)
	{
		printf("���벻�淶������������\n");
		scanf_s("%d", &many);
	}
	printf("�������1���ڵ�����ݣ�");
	scanf_s("%d", &current->data);
	do
	{
		next= (struct linklist*)malloc(sizeof(struct linklist));  //nextָ���µĽڵ�
		current->next = next;  //ʹ��һ���ڵ��е�ָ��ָ����һ���ڵ�
		current = next;
		printf("�������%d���ڵ�����ݣ�", i);
		scanf_s("%d", &current->data);   //���뵱ǰ�ڵ������
		i++;
	} while (i <= many);
	current->next = NULL;
	printf("�����ʼ����ɣ�\n");
	return header;
}
//��x��λ�ú�����½ڵ�
void insert_linklist(struct linklist* header)
{
	int adress,i,olddata,newdata;  //adress��ʾ������ݵ�λ�ã�i���ڼ���
	i = 1;
	struct linklist* new;   //ָ������ָ�������ɵĽڵ�
	bianli_linklist(header);
	printf("������Ҫ����λ�õ�ǰ������ݣ�");
	scanf_s("%d", &olddata);
	printf("\n");
	printf("������������ݵ�λ�ã�");
	scanf_s("%d", &adress);
	if (header == NULL)
	{
		printf("û�иýڵ�/n");
		return;
	}
	//��������ָ�� 
	struct linklist* current = header;
	struct linklist* cnext = current->next;
	while (i<adress)
	{
		current = cnext;					//����ָ����������
		if (current == NULL)
		{
			printf("�Ҳ����ýڵ�\n");
			return;
		}
		cnext = current->next;
		i++;
	}
	if (current->data==olddata)
	{
		printf("������Ҫ��������ݣ�");
		scanf_s("%d", &newdata);
		printf("\n");
		new = (struct linklist*)malloc(sizeof(struct linklist));  //�����½ڵ�
		new->data = newdata;
		current->next = new;     //�½ڵ���������Ӧλ��
		new->next = cnext;
		bianli_linklist(header);
		printf("����ɹ�!\n");
		return;
	}
}
//��������
void bianli_linklist(struct linklist* header)
{
	if (header == NULL)  return;
	struct linklist* pcurrent = header;  //����ָ��
	printf("�������ݣ�");
	while (pcurrent!=NULL)
	{
		printf("%d-> ", pcurrent->data);
		pcurrent = pcurrent->next;
	}
	printf("NULL\n");
}
//ɾ��ֵΪdelvalue�Ľڵ㣨����ͷ�⣩
void remove_linklist(struct linklist* header)
{
	int delvalue,adress,i;
	i = 2;
	bianli_linklist(header);
	printf("������Ҫɾ�������ݣ�");
	scanf_s("%d", &delvalue);
	printf("\n");
	printf("���������ݵ�λ��(�ڼ�������");
	scanf_s("%d", &adress);
	printf("\n");
	if (header == NULL)  return;
	struct linklist* prev = header;
	struct linklist* pcurrent = prev->next;	//��������ָ��
	if (prev->data == delvalue)
	{
		printf("��ͷ����ɾ��\n");
	}
	while (pcurrent!=NULL)
	{
		if (pcurrent->data == delvalue)
		{
			break;
		}
		prev = pcurrent;					//�ƶ�����ָ��
		pcurrent = pcurrent->next;
		i++;
		if (i >= adress)   break;
	}
	if (pcurrent == NULL) return;
	if (pcurrent->data == delvalue )
	{
		prev->next = pcurrent->next;		//����ɾ���ڵ��ǰ�������ڵ�
		free(pcurrent);		//ɾ���ڵ�
		printf("ɾ���ɹ���");
		bianli_linklist(header);
	}
	else  printf("û�д�����");
}
//����
void break_linklist(struct linklist* header)
{
	struct linklist* pcurrent = header->next;
	struct linklist* pnext;			//��������ָ��
	if (header->next == NULL) return;
	while (pcurrent->next != NULL)
	{
		pnext = pcurrent->next;		//������һ���ڵ��ַ
		free(pcurrent);		//�ͷŵ�ǰ�ڵ�
		pcurrent = pnext;		//����ƶ�
	}
	free(pcurrent);
	printf("����������\n");
}
//Ѱ���е�
void fing_middle(struct linklist* header)
{
	int i = 0;
	struct linklist* fast = header;
	struct linklist* slow = header;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		i++;
	}
	if (i % 2==0&&i!=1  )  printf("�м���Ϊ%d\n", slow->data);
	else printf("û���м�ڵ�\n");
}
//�˵�
void menu_linklist()
{
	printf("\t\t*****************************************\n");
	printf("\t\t1.��ʼ������				*\n");
	printf("\t\t2.�����½ڵ�				*\n");
	printf("\t\t3.ɾ����ͷ��Ľڵ�			*\n");
	printf("\t\t4.�������				*\n");
	printf("\t\t5.��������				*\n");
	printf("\t\t6.Ѱ���е�				*\n");
	printf("\t\t7.�˳�ϵͳ				*\n");
	printf("\t\t*****************************************\n");
}