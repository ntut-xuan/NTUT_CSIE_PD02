#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Pair{
	char* str;
	int count;
};

int compare(const void* a, const void* b){
	struct Pair *c = (struct Pair*)a;
	struct Pair *d = (struct Pair*)b;
	if(c->count > d->count){
		return -1;
	}else if(c->count == d->count){
		return strcmp(c->str, d->str);
	}else{
		return 1;
	}
}

void _count(char* s, int len){
	char** table = calloc(100, sizeof(char*));
	for(int i = 0; i < 100; i++){
		table[i] = calloc(100, sizeof(char));
	}
	int index = 0;
	char* temp = calloc(100, sizeof(char));
	for(int i = 0; i < len; i++){
		if(s[i] == ' '){
			strcpy(table[index], temp);
			temp = calloc(100, sizeof(char));
			index += 1;
		}else{
			temp[strlen(temp)] = s[i];
		}
	}
	struct Pair* array = calloc(100, sizeof(struct Pair)); 
	int tmp = 0;
	strcpy(table[index], temp);
	index += 1;
	for(int i = 0; i < index; i++){
		int find = 0;
		for(int j = i-1; j >= 0; j--){
			if(strcmp(table[i], table[j]) == 0) 
			find = 1;
		}
		//printf("%d %d %s\n", i, find, table[i]);
		if(!find){
			int count = 0;
			for(int j = 0; j < index; j++){
				if(strcmp(table[i], table[j]) == 0){
					count += 1;
				}
			}
			array[tmp].str = calloc(100, sizeof(char));
			strcpy(array[tmp].str, table[i]);
			array[tmp].count = count;
			//printf("%s %d\n", table[i], count);
			tmp += 1;
		}
	}
	qsort(array, tmp, sizeof(struct Pair), compare);
	for(int i = 0; i < tmp; i++){
		printf("%s : %d\n", array[i].str, array[i].count);
	}
}

char* _rem(char* s, int len, char* r, char* br){
	char** table = calloc(100, sizeof(char*));
	for(int i = 0; i < 100; i++){
		table[i] = calloc(100, sizeof(char));
	}
	int index = 0;
	char* temp = calloc(100, sizeof(char));
	for(int i = 0; i < len; i++){
		if(s[i] == ' '){
			strcpy(table[index], temp);
			temp = calloc(100, sizeof(char));
			index += 1;
		}else{
			temp[strlen(temp)] = s[i];
		}
	}
	strcpy(table[index], temp);
	index += 1;
	char* buffer = calloc(100, sizeof(char));
	for(int i = 0; i < index; i++){
		if(strcmp(table[i], r) == 0){
			continue;
		}
		printf("%s ", table[i]);
	}
	printf("\n");
}


char* _ins(char* s, int len, char* r, char* br){
	char** table = calloc(100, sizeof(char*));
	for(int i = 0; i < 100; i++){
		table[i] = calloc(100, sizeof(char));
	}
	int index = 0;
	char* temp = calloc(100, sizeof(char));
	for(int i = 0; i < len; i++){
		if(s[i] == ' '){
			strcpy(table[index], temp);
			temp = calloc(100, sizeof(char));
			index += 1;
		}else{
			temp[strlen(temp)] = s[i];
		}
	}
	strcpy(table[index], temp);
	index += 1;
	char* buffer = calloc(100, sizeof(char));
	sprintf(buffer, "%s %s", br, r);
	strcpy(br, buffer);
	for(int i = 0; i < index; i++){
		if(strcmp(table[i], r) == 0){
			strcpy(table[i], br);
		}
	}
	for(int i = 0; i < index-1; i++){
		printf("%s ", table[i]); 
	}
	printf("%s\n", table[index-1]);
}

char* rep(char* s, int len, char* r, char* br){
	char** table = calloc(100, sizeof(char*));
	for(int i = 0; i < 100; i++){
		table[i] = calloc(100, sizeof(char));
	}
	int index = 0;
	char* temp = calloc(100, sizeof(char));
	for(int i = 0; i < len; i++){
		if(s[i] == ' '){
			strcpy(table[index], temp);
			temp = calloc(100, sizeof(char));
			index += 1;
		}else{
			temp[strlen(temp)] = s[i];
		}
	}
	strcpy(table[index], temp);
	index += 1;
	for(int i = 0; i < index; i++){
		if(strcmp(table[i], r) == 0){
			strcpy(table[i], br);
		}
	}
	for(int i = 0; i < index-1; i++){
		printf("%s ", table[i]); 
	}
	printf("%s\n", table[index-1]);
}

int main(){
	char* array = calloc(1000, sizeof(char));
	int index = 0;
	while(1){
		char c;
		scanf("%c", &c);
		if(c == '\n') break;
		array[index] = c;
		index += 1;
	}
	char* replace = calloc(100, sizeof(char));
	char* bereplaced = calloc(100, sizeof(char));
	scanf("%s", replace);
	scanf("%s", bereplaced);
	rep(array, index, replace, bereplaced);
	_ins(array, index, replace, bereplaced);
	_rem(array, index, replace, bereplaced);
	_count(array, index);
} 
