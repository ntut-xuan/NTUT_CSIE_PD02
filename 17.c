#include<stdio.h>
#include<stdlib.h>

int main(){
	int array[9][9] = {
	{4, 4, 4, 4, 4, 4, 4, 4, 4},
	{2, 2, 2, 2, 2, 2, 2, 2, 2}, 
	{3, 3, 3, 3, 3, 3, 3, 3, 3}, 
	{5, 5, 5, 5, 5, 5, 5, 5, 5}, 
	{1, 1, 1, 1, 1, 1, 1, 1, 1}, 
	{6, 6, 6, 6, 6, 6, 6, 6, 6}};
	// 1 -> 4 -> 6 -> 3 
	// 4 -> 2 -> 3 -> 5
	int n;
	scanf("%d", &n);
	while(n--){
		int a;
		scanf("%d", &a);
		if(a/10 == 1){
			for(int i = a%10; i <= 8; i+=3){
				int top = array[4][i];
				array[4][i] = array[0][i];
				array[0][i] = array[5][i];
				array[5][i] = array[2][i];
				array[2][i] = top;
			}
			if(a % 10 == 0){
				int* temp = calloc(9, sizeof(int));
				for(int i = 0; i < 3; i++){
					for(int j = 0; j < 3; j++){
						temp[i*3+j] = array[3][3*j+i];
					}
				}
				for(int i = 0; i < 9; i++){
					array[3][i] = temp[i];
				} 
			}
			if(a % 10 == 2){
				int* temp = calloc(9, sizeof(int));
				for(int i = 0; i < 3; i++){
					for(int j = 0; j < 3; j++){
						temp[i*3+j] = array[1][(3*(j+1))-i-1];
					}
				}
				for(int i = 0; i < 9; i++){
					array[1][i] = temp[i];
				}
			}
		}else if(a/10 == 2){
			int temp[] = {array[0][3*(a%10)], array[0][3*(a%10)+1], array[0][3*(a%10)+2]}; 
			for(int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j++){
					array[i][3*(a%10)+j] = array[(i+1)%4][3*(a%10)+j];
				}
			}
			for(int i = 0; i < 3; i++){
				array[3][i] = temp[i];
			}
			if(a % 10 == 0){
				int* temp = calloc(9, sizeof(int));
				for(int i = 0; i < 3; i++){
					for(int j = 0; j < 3; j++){
						temp[i*3+j] = array[4][3*(2-j)+i];
					}
				}
				for(int i = 0; i < 9; i++){
					array[4][i] = temp[i];
				} 
			}
			if(a % 10 == 2){
				int* temp = calloc(9, sizeof(int));
				for(int i = 0; i < 3; i++){
					for(int j = 0; j < 3; j++){
						temp[i*3+j] = array[5][3*j+i];
					} 
				}
				for(int i = 0; i < 9; i++){
					array[5][i] = temp[i];
				} 
			}
		}
	}
	for(int r = 4; r <= 4; r++){
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 2; j++){
				printf("%d ", array[r][3*i+j]);
			}
			printf("%d\n", array[r][3*i+2]);
		}
	}
	
}
