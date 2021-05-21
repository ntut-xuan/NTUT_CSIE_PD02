#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct data_t{
	int machine;
	int time;
} Data;

int max(int a, int b){
	return a > b ? a : b;
}

int main(){
	int n, m;
	int* array = calloc(100, sizeof(int));
	int* dataCount = calloc(100, sizeof(int));
	int* dataPointer = calloc(100, sizeof(int));
	int* alreadyput = calloc(100, sizeof(int));
	Data** data = calloc(100, sizeof(Data*));
	for(int i = 0; i < 100; i++){
		data[i] = calloc(100, sizeof(Data*));
	}
	int taskCount = 0;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		int k;
		scanf("%d", &k);
		dataCount[i] = k;
		taskCount += k;
		for(int j = 0; j < k; j++){
			int a, b;
			scanf("%d %d", &a, &b);
			data[i][j].machine = a;
			data[i][j].time = b;
		}
	}
	int ans = 0;
	while(taskCount){
		int index = 0;
		int mn = 2147483647;
		for(int j = 0; j < m; j++){
			if(dataPointer[j] >= dataCount[j]) continue;
			int temp = max(alreadyput[j], array[data[j][dataPointer[j]].machine]) + data[j][dataPointer[j]].time;
			if(temp < mn){
				mn = temp;
				index = j;
			}
		}
		int targetMachine = data[index][dataPointer[index]].machine;
		int targetTime = data[index][dataPointer[index]].time;
		array[targetMachine] = max(alreadyput[index], array[targetMachine]) + targetTime;
		alreadyput[index] = array[targetMachine];
		taskCount -= 1;
		dataPointer[index] += 1;
//		printf("Put task %d into machind %d, task maxTime = %d\n", index, targetMachine, alreadyput[index]);
		if(dataPointer[index] == dataCount[index]){
			//printf("task %d done, task maxTime = %d\n", index, alreadyput[index]);
			ans += alreadyput[index];
		}
	}
	printf("%d\n", ans);
}
