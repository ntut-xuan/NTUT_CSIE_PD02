#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int min(int a, int b){
	return a > b ? b : a;
}

int main(){
	int n;
	scanf("%d", &n);
	int* array = calloc(200, sizeof(int));
	for(int i = 1; i <= n; i++){
		scanf("%d", &array[i]);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		int lm = 0, rm = 0;
		for(int j = i; j >= 0; j--){
			if(array[j] < array[i]){
				lm = j;
				break;
			}
		}
		for(int j = i; j < 200; j++){
			if(array[j] < array[i]){
				rm = j;
				break;
			}
		}
		ans += min(abs(lm-i), abs(rm-i));
	}
	printf("%d\n", ans);
}
