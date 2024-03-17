#include"linklist.h"

//初始化链表
struct linklist* start_linklist()
{
	int many,i,data;     //many代表节点数，i用来计数，data用来
	struct linklist* current, * next,*header;
	i = 2;
	//创建第一个节点
	header = (struct linklist*)malloc(sizeof(struct linklist));
	current = header;
	header->data = -1;
	header->next = NULL;
	//功能
	printf("创建几个节点(不多于20个）：");
	scanf_s("%d", &many);
	if (many > 20)
	{
		printf("输入不规范，请重新输入\n");
		scanf_s("%d", &many);
	}
	printf("请输入第1个节点的数据：");
	scanf_s("%d", &current->data);
	do
	{
		next= (struct linklist*)malloc(sizeof(struct linklist));  //next指向新的节点
		current->next = next;  //使第一个节点中的指针指向下一个节点
		current = next;
		printf("请输入第%d个节点的数据：", i);
		scanf_s("%d", &current->data);   //输入当前节点的数据
		i++;
	} while (i <= many);
	current->next = NULL;
	printf("链表初始化完成！\n");
	return header;
}
//在x的位置后插入新节点
void insert_linklist(struct linklist* header)
{
	int adress,i,olddata,newdata;  //adress表示这个数据的位置，i用于计数
	i = 1;
	struct linklist* new;   //指针用于指向新生成的节点
	bianli_linklist(header);
	printf("请输入要插入位置的前面的数据：");
	scanf_s("%d", &olddata);
	printf("\n");
	printf("请输入这个数据的位置：");
	scanf_s("%d", &adress);
	if (header == NULL)
	{
		printf("没有该节点/n");
		return;
	}
	//两个辅助指针 
	struct linklist* current = header;
	struct linklist* cnext = current->next;
	while (i<adress)
	{
		current = cnext;					//两个指针往后搜索
		if (current == NULL)
		{
			printf("找不到该节点\n");
			return;
		}
		cnext = current->next;
		i++;
	}
	if (current->data==olddata)
	{
		printf("请输入要插入的数据：");
		scanf_s("%d", &newdata);
		printf("\n");
		new = (struct linklist*)malloc(sizeof(struct linklist));  //创建新节点
		new->data = newdata;
		current->next = new;     //新节点插入链表对应位置
		new->next = cnext;
		bianli_linklist(header);
		printf("插入成功!\n");
		return;
	}
}
//遍历链表
void bianli_linklist(struct linklist* header)
{
	if (header == NULL)  return;
	struct linklist* pcurrent = header;  //辅助指针
	printf("链表数据：");
	while (pcurrent!=NULL)
	{
		printf("%d-> ", pcurrent->data);
		pcurrent = pcurrent->next;
	}
	printf("NULL\n");
}
//删除值为delvalue的节点（除表头外）
void remove_linklist(struct linklist* header)
{
	int delvalue,adress,i;
	i = 2;
	bianli_linklist(header);
	printf("请输入要删除的数据：");
	scanf_s("%d", &delvalue);
	printf("\n");
	printf("请输入数据的位置(第几个）：");
	scanf_s("%d", &adress);
	printf("\n");
	if (header == NULL)  return;
	struct linklist* prev = header;
	struct linklist* pcurrent = prev->next;	//两个辅助指针
	if (prev->data == delvalue)
	{
		printf("表头不可删除\n");
	}
	while (pcurrent!=NULL)
	{
		if (pcurrent->data == delvalue)
		{
			break;
		}
		prev = pcurrent;					//移动两个指针
		pcurrent = pcurrent->next;
		i++;
		if (i >= adress)   break;
	}
	if (pcurrent == NULL) return;
	if (pcurrent->data == delvalue )
	{
		prev->next = pcurrent->next;		//连接删除节点的前后两个节点
		free(pcurrent);		//删除节点
		printf("删除成功！");
		bianli_linklist(header);
	}
	else  printf("没有此数据");
}
//销毁
void break_linklist(struct linklist* header)
{
	struct linklist* pcurrent = header->next;
	struct linklist* pnext;			//两个辅助指针
	if (header->next == NULL) return;
	while (pcurrent->next != NULL)
	{
		pnext = pcurrent->next;		//保存下一个节点地址
		free(pcurrent);		//释放当前节点
		pcurrent = pnext;		//向后移动
	}
	free(pcurrent);
	printf("链表已销毁\n");
}
//寻找中点
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
	if (i % 2==0&&i!=1  )  printf("中间结点为%d\n", slow->data);
	else printf("没有中间节点\n");
}
//菜单
void menu_linklist()
{
	printf("\t\t*****************************************\n");
	printf("\t\t1.初始化链表				*\n");
	printf("\t\t2.插入新节点				*\n");
	printf("\t\t3.删除表头外的节点			*\n");
	printf("\t\t4.输出链表				*\n");
	printf("\t\t5.销毁链表				*\n");
	printf("\t\t6.寻找中点				*\n");
	printf("\t\t7.退出系统				*\n");
	printf("\t\t*****************************************\n");
}