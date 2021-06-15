#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
	struct Node* left;
	struct Node* right;
	char data;
};

int searchNode(char* inOrder, int start, int end, char value){
	for(int i = start; i <= end; i++){
		if(inOrder[i] == value) return i;
	}
}

struct Node* buildTreeByPostOrder(char* inOrder, char* pOrder, int inStat, int inEnd, int* postIndex){
	if(inStat > inEnd){
		return NULL;
	}	
	struct Node* tNode = calloc(1, sizeof(struct Node));
	tNode->data = pOrder[(*postIndex)--];
	tNode->left = NULL;
	tNode->right = NULL;	
	if(inStat == inEnd){
		return tNode;
	}	
	int inIndex = searchNode(inOrder, inStat, inEnd, tNode->data);
	tNode->right = buildTreeByPostOrder(inOrder, pOrder, inIndex + 1, inEnd, postIndex);
	tNode->left = buildTreeByPostOrder(inOrder, pOrder, inStat, inIndex - 1, postIndex);
	return tNode;
}

struct Node* buildTreeByPreOrder(char* inOrder, char* pOrder, int inStat, int inEnd, int* preIndex){
	if(inStat > inEnd){
		return NULL;
	}
	struct Node* tNode = calloc(1, sizeof(struct Node));
	tNode->data = pOrder[(*preIndex)++];
	tNode->left = NULL;
	tNode->right = NULL;
	if(inStat == inEnd){
		return tNode;
	}
	int inIndex = searchNode(inOrder, inStat, inEnd, tNode->data);
	tNode->left = buildTreeByPreOrder(inOrder, pOrder, inStat, inIndex - 1, preIndex);
	tNode->right = buildTreeByPreOrder(inOrder, pOrder, inIndex + 1, inEnd, preIndex);
	return tNode;
}

void printTree(struct Node* tree){
	struct Node** array = calloc(100, sizeof(struct Node*));
	int index = 0;
	int size = 0;
	array[0] = tree;
	size += 1;
	while(index < size){
		struct Node* front = array[index];
		printf("%c", front->data);
		if(front->left != NULL){
			array[size] = front->left;
			size += 1;
		}
		if(front->right != NULL){
			array[size] = front->right;
			size += 1;
		}
		index += 1;
	}
	printf("\n");
}

int main(){
	int oper = 2;
	char* inOrder = calloc(100, sizeof(char));
	char* pOrder = calloc(100, sizeof(char));
	char flag;
	scanf(" %c", &flag);
	if(flag == 'P' || flag == 'O'){
		if(flag == 'P') oper |= 4;
		else oper |= 1;
		scanf("%s", pOrder);
	}else{
		scanf("%s", inOrder);
	}
	scanf(" %c", &flag);
	if(flag == 'P' || flag == 'O'){
		if(flag == 'P') oper |= 4;
		else oper |= 1;
		scanf("%s", pOrder);
	}else{
		scanf("%s", inOrder);
	}
	if(oper == 6){
		int index = 0;
		struct Node* tree = buildTreeByPreOrder(inOrder, pOrder, 0, strlen(inOrder)-1, &index);
		printTree(tree);
	}else{
		int index = strlen(inOrder)-1;
		struct Node* tree = buildTreeByPostOrder(inOrder, pOrder, 0, strlen(inOrder)-1, &index);
		printTree(tree);
	}
} 
