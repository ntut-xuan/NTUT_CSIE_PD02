#include<stdio.h>
#include<stdlib.h>

int main(){
	int name[3];
	int time[3];
	int data[3][100];
	for(int i = 0; i < 3; i++){
		int n, t;
		scanf("%d", &n);
		scanf("%d", &t);
		name[i] = n;
		time[i] = t;
		for(int j = 0; j < t; j++){
			scanf("%d", &data[i][j]);
		}
	}
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(i == j) continue;
			for(int k = 0; k < time[i]; k++){
				for(int l = 0; l < time[j]; l++){
					if(data[i][k] == data[j][l]){
						printf("%d and %d conflict on %d\n", name[i], name[j], data[i][k]);
						goto next;
					}
				}
			}
		}
	}
	next:;
}
