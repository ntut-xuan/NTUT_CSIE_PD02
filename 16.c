#include<stdio.h>
#include<stdlib.h>

int main(){
	char* array = calloc(100, sizeof(char));
	scanf("%s", array);
	int m;
	scanf("%d", &m);
	int answer = 0;
	for(int i = 0; i < strlen(array)-m; i++){
		int temp = 0;
		for(int j = i; j < i+m; j++){
			temp |= (1 << (array[j]-'0'));
		}
		int count = 0;
		while(temp){
			count += temp & 1;
			temp >>= 1;
		}
		if(count == m){
			answer += 1;
		}
	}
	printf("%d", answer);
}
