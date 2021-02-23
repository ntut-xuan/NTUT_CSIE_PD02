#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int min(int a, int b){
	if(a < b) return a;
	return b;
}

void p(int a, int b, int c){
	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", c);
}

int main(){
	int i, j;
	char array[5];
	for(i = 0; i < 5; i++){
		char a = 'O';
		scanf(" %c", &a);
		array[i] = a;
	}
	int status[4];
	for(i = 0; i < 4; i++){
		status[i] = 0;
	} 
	int count = 0;
	for(i = 0; i < 5; i++){
		if(array[i] == 'O') count += 1;
		if(array[i] == 'H' || count == 3){
			status[3] = status[2] = status[1] = status[0] = 0;
			count %= 3;
			continue;
		}
		if(array[i] == 'O') continue; 
		int run = array[i]-'0';
		for(j = 3; j >= 1; j--){
			status[min((j+run), 4)%4] = status[j];
			status[j] = 0;
		}
		status[run] = 1;
		//p(status[1], status[2], status[3]);
	}
	p(status[1], status[2], status[3]);
}
