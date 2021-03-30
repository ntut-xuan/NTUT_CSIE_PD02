#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a, int b){
	return a > b ? a : b;
}

char* sabs(char* a){
	char* fx = calloc(200, sizeof(char));
	if(a[0] == '-'){
		for(int i = 0 ; i < strlen(a); i++){
			fx[i] = a[i+1];
		}
	}else{
		return a;
	}
	return fx;
}

int scmp(char* a, char* b){
	if(strlen(a) > strlen(b)){
		return 1;
	}else if(strlen(b) > strlen(a)){
		return -1;
	}else{
		for(int i = 0; i < strlen(a); i++){
			if(a[i] > b[i]) return 1;
			else if(b[i] > a[i]) return -1;
		}
	}
	return 0;
}

char* smax(char* a, char* b){
	if(scmp(a, b) == 1){
		return a;
	}else{
		return b;
	}
}

char* smin(char* a, char* b){
	if(scmp(a, b) == -1){
		return a;
	}else{
		return b;
	}
}

void printint(int len, int* array){
	for(int i = 0; i < len; i++){
		printf("%d", array[i]);
	}
	printf("\n");
}

char* minus(char* a, char* b){
	int mxlen = max(strlen(a), strlen(b))+1;
	int* fa = calloc(200, sizeof(int));
	int* fb = calloc(200, sizeof(int));
	int* fc = calloc(200, sizeof(int));
	int i;
	for(i = 0; i < mxlen - strlen(a); i++){
		fa[i] = 0;
	}
	for(int j = 0; j < strlen(a); j++){
		fa[i+j] = a[j]-'0';
	}
	for(i = 0; i < mxlen - strlen(b); i++){
		fb[i] = 0;
	}
	for(int j = 0; j < strlen(b); j++){
		fb[i+j] = b[j]-'0';
	}
	for(int j = mxlen-1; j >= 1; j--){
		if(fa[j] < fb[j]){
			fc[j] = 10 - fb[j] + fa[j];
			fa[j-1] -= 1;
		}else{
			fc[j] = fa[j] - fb[j];
		}
	}
	char* ans = calloc(200, sizeof(char));
	int index = 0;
	while(fc[index] == 0){
		index += 1;
	}
	for(int j = 0; j < mxlen - index; j++){
		ans[j] = fc[index+j] + '0';
	}
	return ans;
}

char* plus(char* a, char* b){
	int mxlen = max(strlen(a), strlen(b))+1;
	int* fa = calloc(200, sizeof(int));
	int* fb = calloc(200, sizeof(int));
	int* fc = calloc(200, sizeof(int));
	int i;
	for(i = 0; i < mxlen - strlen(a); i++){
		fa[i] = 0;
	}
	for(int j = 0; j < strlen(a); j++){
		fa[i+j] = a[j]-'0';
	}
	for(i = 0; i < mxlen - strlen(b); i++){
		fb[i] = 0;
	}
	for(int j = 0; j < strlen(b); j++){
		fb[i+j] = b[j]-'0';
	}
	for(int j = mxlen-1; j >= 1; j--){
		fc[j-1] += (fa[j]+fb[j]+fc[j])/10;
		fc[j] += (fa[j]+fb[j])%10;
		fc[j] %= 10;
	}
	char* ans = calloc(200, sizeof(char));
	int index = 0;
	while(fc[index] == 0){
		index += 1;
	}
	for(int j = 0; j < mxlen - index; j++){
		ans[j] = fc[index+j] + '0';
	}
	return ans;
}

char* mul(char* a, char* b){
	char temp1[] = "0";
	char temp2[] = "0";
	char* ans = plus(temp1, temp2);
	int offset = 0;
	for(int i = strlen(b)-1; i >= 0; i--){
		char* temp = plus(temp1, temp2);
		for(int j = 0; j < b[i]-'0'; j++){
			strcpy(temp, plus(temp, a));
		}
		for(int j = 0; j < offset; j++){
			temp[strlen(temp)] = '0';
		}
		offset += 1;
		strcpy(ans, plus(ans, temp)); 
	}
	return ans;
}


int main(){
	char* a = calloc(100, sizeof(char));
	char* b = calloc(100, sizeof(char));
	int oper = 0;
	scanf("%d", &oper);
	scanf("%s", a);
	scanf("%s", b);
	if(oper == 1){
		if(a[0] == '-' && b[0] == '-'){
			printf("-%s\n", plus(sabs(a), sabs(b)));
		}else if(a[0] == '-'){
			if(scmp(sabs(a), sabs(b)) == 1){
				printf("-%s\n", minus(sabs(a), sabs(b)));
			}else if(scmp(sabs(a), sabs(b)) == -1){
				printf("%s\n", minus(sabs(b), sabs(a)));
			}else{
				printf("0");
			}
		}else if(b[0] == '-'){
			if(scmp(sabs(a), sabs(b)) == 1){
				printf("%s\n", minus(sabs(a), sabs(b)));
			}else if(scmp(sabs(a), sabs(b)) == -1){
				printf("-%s\n", minus(sabs(b), sabs(a)));
			}else{
				printf("0");
			}
		}else{
			printf("%s\n", plus(a, b));
		}
	}else if(oper == 2){
		if(a[0] == '-' && b[0] == '-'){
			if(scmp(sabs(a), sabs(b)) == 1){
				printf("-%s\n", minus(sabs(a), sabs(b)));
			}else if(scmp(sabs(a), sabs(b)) == -1){
				printf("%s\n", minus(sabs(b), sabs(a)));
			}else{
				printf("0");
			}
		}else if(a[0] == '-'){
			if(scmp(sabs(a), sabs(b)) == 1){
				printf("%s\n", minus(sabs(a), sabs(b)));
			}else if(scmp(sabs(a), sabs(b)) == -1){
				printf("-%s\n", minus(sabs(b), sabs(a)));
			}else{
				printf("0");
			}
		}else if(b[0] == '-'){
			printf("%s\n", plus(sabs(a), sabs(b)));
		}else{
			if(scmp(sabs(a), sabs(b)) == 1){
				printf("%s\n", minus(sabs(a), sabs(b)));
			}else if(scmp(sabs(a), sabs(b)) == -1){
				printf("-%s\n", minus(sabs(b), sabs(a)));
			}else{
				printf("0");
			}
		}
	}else if(oper == 3){
		if(a[0] == '-' || b[0] == '-'){
			printf("-%s", mul(a, b));
		}else{
			printf("%s", mul(a, b));
		}
	}
} 
