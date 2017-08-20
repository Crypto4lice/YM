#include<stdio.h>

// Linked list
typedef struct node {
	int data;
	struct node* link;
}listnode;

typedef listnode* nodePtr;

void insert();
void list_delete();
nodePtr search(int num);
void print_list();

nodePtr head = NULL;
nodePtr tail = NULL;
nodePtr newNode = NULL;

int main()
{		
	while (1)
	{
		int a;
		printf("insert(1) or delete(2) or all print(3) or exit(4)\n");
		scanf_s("%d", &a);
		if (a == 1)
			insert();
		else if (a == 2)
			list_delete();
		else if (a == 3)
			print_list();
		else if (a == 4)
			break;
		else
			printf("Retry\n");	
	}	
	return 0;
}

void insert()
{
	int num;

	printf("삽입할 숫자 입력 : ");
	scanf_s("%d", &num);

	newNode = (listnode*)malloc(sizeof(listnode));
	newNode->data = num;
	newNode->link = NULL;

	if (head == NULL)
		head = newNode;
	else
		tail->link = newNode;

	tail = newNode;
	printf("\n");	
}

void list_delete()
{
	int num;

	printf("삭제할 숫자 입력 : ");
	scanf_s("%d", &num);

	nodePtr bn = search(num); // 이전노드

	if (bn == NULL)	
		printf("%d는 리스트에 없음\n", num);	
	else
	{
		nodePtr bn_next;

		bn_next = bn->link;

		if (num == head->data)
		{
			head = head->link;
			free(bn);
		}
		else
		{
			bn->link = bn_next->link;
			free(bn_next);
		}
	}
}

nodePtr search(int num)
{
	nodePtr cur = NULL;
	cur = head;

	if (num == head->data)
		return cur;
	else 
	{
		while ((cur->link) != NULL)
		{
			if (num == cur->link->data)
				return cur;
			else
				cur = cur->link;
		}
	}	
	return NULL;
}

void print_list()
{
	nodePtr cur = NULL;
	cur = head;

	printf("현재 리스트 : ");

	while (cur->link != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->link;
	}
	printf("%d\n", cur->data);
}

