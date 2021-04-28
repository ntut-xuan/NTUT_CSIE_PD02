#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* readline(){
	char* data = calloc(1000, sizeof(char));
	gets(data);
	return data;
}

int _len(char* c){
	int len = 0;
	for(int i = 0; i < 1000; i++){
		if(c[i] == '\n') break;
		len += 1;
	}
	return len;
}

int main(){
	char* data = calloc(1000, sizeof(char));
	strcpy(data, readline());
	char* split = strtok(data, " ");
	char** table = calloc(1000, sizeof(char*));
	for(int i = 0; i < 1000; i++){
		table[i] = calloc(1000, sizeof(char));
	}
	int table_len = 0;
	while(split != NULL){
		strcpy(table[table_len], split);
		split = strtok(NULL, " ");
		table_len += 1;
	}
	int n;
	scanf("%d", &n);
	readline();
	int* array = calloc(n, sizeof(int));
	for(int i = 0; i < n; i++){
		char* temp = strtok(readline(), " ");
		int r = 0;
		while(temp != NULL){
			for(int j = 0; j < table_len; j++){
				if(strcmp(table[j], temp) == 0){
					r |= 1 << j;
				}
			}
			temp = strtok(NULL, " ");
		}
		//printf("%d\n", r);
		array[i] = r;
	}
	int* visited = calloc(n, sizeof(int));
	int count = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(visited[i] || visited[j]) continue;
			if(array[i] + array[j] == (1 << table_len)-1){
				count += 1;
				visited[i] = 1;
				visited[j] = 1;
			}
		}
	}
	printf("%d\n", count);
} 
