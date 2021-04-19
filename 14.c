#include<stdio.h>
#include<stdlib.h>

int main(){
	char* answer = calloc(100, sizeof(char));
	scanf("%s", answer);
	int find = 0;
	for(int r = 0; r < 6 && !find; r++){
		char* guess = calloc(100, sizeof(char));
		scanf("%s", guess);
		int a = 0, b = 0;
		for(int i = 0; i < 4; i++){
			if(guess[i] == answer[i]){
				a += 1;
			}
		}
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				if(i == j) continue;
				if(answer[i] == guess[j]){
					b += 1;
				}
			}
		}
		if(a == 4){
			printf("win\n");
			find = 1;
		}else{
			printf("%dA%dB\n", a, b);	
		}
	}
}
