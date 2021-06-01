#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count = 0;
int graph[11][11];
int ans = 2147483647;

int min(int a, int b){
	return a > b ? b : a;
}

void solve(int a, int b, int n, int record, char* result){
	if(strlen(result) == n){
		int temp = 0;
		for(int i = 0; i < n-1; i++){
			temp += graph[result[i]-'0'-1][result[i+1]-'0'-1];
		}
		if(ans > temp){
			ans = min(ans, temp);
//			printf("%s\n", result);
		}
	}else{
//		printf("\n");
		for(int i = 1; i <= n; i++){
			int temp = (1 << i-1);
			int index = strlen(result);
			result[index] = '0' + i;
			if(!(temp & record)){
				solve(i, a, n, record | temp, result);
			}
			result[index] = '\0';
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int** array = calloc(n+1, sizeof(int*));
	for(int i = 0; i <= n; i++){
		array[i] = calloc(n+1, sizeof(int));
		for(int j = 0; j <= n; j++){
			scanf("%d", &array[i][j]);
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			graph[i-1][j-1] = array[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j) continue;
//			printf("%d %d %d\n",i+1, j+1, graph[i][j]);
		}
//		printf("\n");
	}
	char* temp = calloc(100, sizeof(char));
	temp[0] = '1';
	solve(1, 1, n, 1, temp);
	printf("%d\n", ans);
}
