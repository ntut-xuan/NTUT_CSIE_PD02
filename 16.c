#include<stdio.h>
#include<stdlib.h>

int count = 0;
int index = -1;

int** answer;

void execute(char* array, int a, int b, int len){
	//printf("%d\n", index);
	index += 1;
	if(array[index] == '1'){
		for(int i = 0; i < len; i++){
			for(int j = 0; j < len; j++){
				answer[a+i][b+j] = 1;
				count += 1;
			}
		}
	}else if(array[index] == '0'){
	}else{
		execute(array, a, b, len/2);
		execute(array, a, b+len/2, len/2);
		execute(array, a+len/2, b, len/2);
		execute(array, a+len/2, b+len/2, len/2);
	}
}

int main(){
	char* array = calloc(1e5, sizeof(char));
	scanf("%s", array);
	int size;
	scanf("%d", &size);
	answer = calloc(size, sizeof(int*));
	for(int i = 0; i < size; i++){
		answer[i] = calloc(size, sizeof(int));
	}
	execute(array, 0, 0, size);
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(answer[i][j]){
				printf("%d,%d\n", i, j);
			}
		}
	}
	if(!count){
		printf("all white\n");
	}
	//printf("%d\n", count);
}
