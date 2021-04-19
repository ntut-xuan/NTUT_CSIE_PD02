#include<stdio.h>
#include<stdlib.h>

int main(){
	int array[4][6] = {{4, 2, 3, 5, 1, 6}, {4, 2, 3, 5, 1, 6}, {4, 2, 3, 5, 1, 6}, {4, 2, 3, 5, 1, 6}};
	int n;
	scanf("%d", &n);
	while(n--){
		for(int i = 0; i < 4; i++){
			int oper = 0;
			scanf("%d", &oper);
			if(oper == 2){
				//1 -> 4 -> 6 -> 3
				int temp = array[i][4];
				array[i][4] = array[i][0];
				array[i][0] = array[i][5];
				array[i][5] = array[i][2];
				array[i][2] = temp;
			}else if(oper == 1){
				//1 -> 3 -> 6 -> 4
				int temp = array[i][4];
				array[i][4] = array[i][2];
				array[i][2] = array[i][5];
				array[i][5] = array[i][0];
				array[i][0] = temp;
			}else if(oper == 4){
				//1 -> 2 -> 6 -> 5
				int temp = array[i][4];
				array[i][4] = array[i][1];
				array[i][1] = array[i][5];
				array[i][5] = array[i][3];
				array[i][3] = temp;
  			}else if(oper == 3){
  				//1 -> 5 -> 6 -> 2
  				int temp = array[i][4];
  				array[i][4] = array[i][3];
  				array[i][3] = array[i][5];
  				array[i][5] = array[i][1];
  				array[i][1] = temp;
			}
		}
	}
	//printf("%d %d %d %d\n", array[0][4], array[1][4], array[2][4], array[3][4]);
	int* count = calloc(16, sizeof(int));
	for(int i = 0; i < 4; i++){
		count[array[i][4]] += 1;
	}
	int flag = 1;
	int result = 0;
	for(int i = 1; i <= 6; i++){
		if(count[i] == 4){
			result = 18;
			flag = 0;
		}
	}
	for(int i = 0; i <= 6; i++){
		for(int j = 0; j <= 6; j++){
			if(i == j) continue;
			if(count[i] == 2 && count[j] == 2){
				result = (i > j) ? i+i : j+j;
				flag = 0;
			}
		}
	}
	int exist = 0;
	for(int i = 1; i <= 6; i++){
		if(count[i] == 2){
			exist = 1;
		}
	}
	for(int i = 1; exist && i <= 6; i++){
		if(count[i] == 1){
			result += i;
		}
	}
	printf("%d\n", result);
}
