#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int array[32];
int gold[32];

int mx = 0;

void execute(int node, int n, int count, int rec, char* answer, int output){
	if(rec & (1 << node) || array[node] == 0){
		if(array[node] == 0) count += gold[node];
		if(output == 1 && count == mx){
			printf("%s\n", answer);
		}
//		printf("%s %d\n", answer, count);
		if(mx < count) mx = count;
		return;
	}
	rec |= 1 << (node);
	for(int i = 0; i < 32; i++){
		if((1 << i) & array[node]){
			char* temp = calloc(100, sizeof(char));
			temp[0] = '0' + i + 1;
			temp[1] = ' ';
			strcat(answer, temp);
			int index = strlen(answer);
//			printf("%d %d %s\n", node, i+1, answer);
			execute(i, n, count+gold[node], rec, answer, output);
			answer[strlen(answer)-1] = '\0';
			answer[strlen(answer)-1] = '\0';
		}
	}
	next:;
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		gold[i] = b;
		if(c || d){
			array[i] = (1 << (c-1)) | (1 << (d-1));
		}else{
			array[i] = 0;
		}
//		printf("%d\n", array[i]);
	}
	char* temp = calloc(100, sizeof(char));
	temp[0] = '0' + (k);
	temp[1] = ' ';
	execute(k-1, n, 0, 0, temp, 0);
	execute(k-1, n, 0, 0, temp, 1);
	printf("%d\n", mx);
}
