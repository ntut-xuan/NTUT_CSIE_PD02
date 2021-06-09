#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct LinkedList{
	struct LinkedList* left;
	struct LinkedList* right;
	char* name;
	int ages;
	int year;
	int month;
	int day;
};

void create(struct LinkedList** ll){
	(*ll)->left = NULL;
	(*ll)->right = NULL;
	(*ll)->name = calloc(100, sizeof(char));
	(*ll)->ages = 0;
	(*ll)->year = 0;
	(*ll)->month = 0;
	(*ll)->day = 0;
}

struct LinkedList* peek(struct LinkedList* ll){
	if(ll == NULL) return NULL;
	struct LinkedList* temp = ll;
	while(temp->right != NULL){
		temp = temp->right;
	}
	return temp;
}

void pop(struct LinkedList** ll){
	if(*ll == NULL){
		printf("The Stack is empty\n");
		return;
	}
	struct LinkedList* temp = *ll;
	while(temp->right != NULL){
		temp = temp->right;
	}
	if(*ll == temp){
		*ll = NULL;
		free(temp);
		return;
	}
	temp->left->right = NULL;
	free(temp->left->right);
}

void print_linkedlist(struct LinkedList** ll){
	struct LinkedList* temp = *ll;
	while(temp->left != NULL){
		temp = temp->left;
	}
	while(temp != NULL){
		printf("%d ", temp->ages);
		temp = temp->right;
	}
	printf("\n");
}

void insert_right(struct LinkedList** ll, char* name, int ages, int year, int month, int day){
	struct LinkedList* temp = *ll;
	struct LinkedList* newNode = calloc(1, sizeof(struct LinkedList));
	create(&newNode);
	strcpy(newNode->name, name);
	newNode->ages = ages;
	newNode->year = year;
	newNode->month = month;
	newNode->day = day;
	if(*ll == NULL){
		*ll = newNode;
		return;
	}
	while(temp->right != NULL){
		temp = temp->right;
	}
	temp->right = newNode;
	newNode->left = temp;
}

int main(){
	struct LinkedList* ll = NULL;
	int oper = 0;
	while(scanf("%d", &oper) != EOF){
		if(oper == 1){
			char* name = calloc(100, sizeof(char));
			int ages = 0, year = 0, month = 0, day = 0;
			scanf(" \"%[^\"]\" ", name);
			scanf("%d %d %d %d", &ages, &year, &month, &day);
			insert_right(&ll, name, ages, year, month, day);
//			print_linkedlist(&ll);
		}else if(oper == 2){
			int sub_oper = 0;
			scanf("%d", &sub_oper);
			struct LinkedList* top = peek(ll);
			if(top != NULL){
				if(sub_oper == 1){
					printf("%s\n", top->name);
				}else if(sub_oper == 2){
					printf("%d\n", top->ages);
				}else{
					printf("%d_%d_%d\n", top->year, top->month, top->day);
				}
			}
			pop(&ll);
		}else{
			break;
		}
	} 
}
