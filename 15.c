#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a, int b){
	return a > b ? a : b;
}

int cmp(char* a, char* b){
	if(strlen(a) > strlen(b)){
		return -1;
	}else if(strlen(a) < strlen(b)){
		return 1;
	}else{
		for(int i = 0; i < strlen(a); i++){
			if(a[i] > b[i]) return -1;
			else if(a[i] < b[i]) return 1;
		}
		return 0;
	}
}

char* addn(char* a){
	char* fix = calloc(100, sizeof(char));
	fix[0] = '-';
	for(int i = 1; i < strlen(a)+1; i++){
		fix[i] = a[i-1];
	}
	return fix;
}

char* sabs(char* a){
	if(a[0] == '-'){
		char* fix = calloc(100, sizeof(char));
		for(int i = 1; i < strlen(a); i++){
			fix[i-1] = a[i];
		}
		return fix;
	}else{
		return a;
	}
}

void int_print(int n, int* array){
	for(int i = 0; i < n; i++){
		printf("%d", array[i]);
	}
	printf("\n");
}

char* transform(int n, int* array){
	int i = 0;
	char* result = calloc(100, sizeof(char));
	for(i = 0; i < n; i++){
		if(array[i] == 0) continue;
		if(array[i] != 0) break;
	}
	for(int j = 0; j < n-i; j++){
		result[j] = '0' + array[i+j];
	}
	return result;
}

char* minus(char* a, char* b){
	int mx = max(strlen(a), strlen(b)); 
	int* fia = calloc(100, sizeof(int));
	int* fib = calloc(100, sizeof(int));
	int* result = calloc(100, sizeof(int));
	int i = 0;
	for(i = 0; i < mx+1-strlen(a); i++){
		fia[i] = 0;
	}
	for(int j = 0; j < mx+1; j++){
		fia[i+j] = a[j]-'0';
	}
	for(i = 0; i < mx+1-strlen(b); i++){
		fib[i] = 0;
	}
	for(int j = 0; j < mx+1; j++){
		fib[i+j] = b[j]-'0';
	}
	//int_print(mx+1, fia);
	//int_print(mx+1, fib);
	result[0] = 0;
	for(int j = mx; j >= 1; j--){
		if(fia[j] < fib[j]){
			result[j] = 10 - fib[j] + fia[j];
			fia[j-1] -= 1;
		}else{
			result[j] = fia[j] - fib[j];
		}
	}
	//int_print(mx+1, result);
	return transform(mx+1, result);
}

char* plus(char* a, char* b){
	int mx = max(strlen(a), strlen(b)); 
	int* fia = calloc(100, sizeof(int));
	int* fib = calloc(100, sizeof(int));
	int* result = calloc(100, sizeof(int));
	int i = 0;
	for(i = 0; i < mx+1-strlen(a); i++){
		fia[i] = 0;
	}
	for(int j = 0; j < mx+1; j++){
		fia[i+j] = a[j]-'0';
	}
	for(i = 0; i < mx+1-strlen(b); i++){
		fib[i] = 0;
	}
	for(int j = 0; j < mx+1; j++){
		fib[i+j] = b[j]-'0';
	}
	//int_print(mx+1, fia);
	//int_print(mx+1, fib);
	result[0] = 0;
	for(int j = mx; j >= 1; j--){
		result[j-1] += (fia[j]+fib[j]+result[j])/10;
		result[j] = (fia[j]+fib[j]+result[j])%10;
	}
	//int_print(mx+1, result);
	return transform(mx+1, result);
}

char* mul(char* a, char* b){
	char* result = calloc(100, sizeof(char));
	result[0] = '0';
	int index = 0;
	for(int i = strlen(a)-1; i >= 0; i--){
		char* temp = calloc(100, sizeof(char));
		for(int j = 0; j < a[i]-'0'; j++){
			strcpy(temp, plus(temp, b));
		}
		for(int j = 0; j < index; j++){
			temp[strlen(temp)] = '0';
		}
		index += 1;
		strcpy(result, plus(result, temp));
	}
	return result;
}

char* _plus(char* a, char* b){
	char* fa = calloc(100, sizeof(char));
	char* fb = calloc(100, sizeof(char));
	char* zero = calloc(100, sizeof(char));
	zero[0] = '0';
	strcpy(fa, sabs(a));
	strcpy(fb, sabs(b));
	//printf("%s\n", sabs(a));
	if(a[0] == '-' && b[0] == '-'){
		return addn(plus(fa, fb));
	}else if(a[0] == '-'){
		if(cmp(fa, fb) == -1){
			return addn(minus(fa, fb));
		}else if(cmp(fa, fb) == 0){
			return zero;
		}else{
			return minus(fb, fa);
		}
	}else if(b[0] == '-'){
		if(cmp(fa, fb) == 1){
			return addn(minus(fb, fa));
		}else if(cmp(fa, fb) == 0){
			return zero;
		}else{
			return minus(fa, fb);
		}
	}else{
		return plus(fa, fb);
	}
}

char* _minus(char* a, char* b){
	char* fa = calloc(100, sizeof(char));
	char* fb = calloc(100, sizeof(char));
	char* zero = calloc(100, sizeof(char));
	zero[0] = '0';
	strcpy(fa, sabs(a));
	strcpy(fb, sabs(b));
	//printf("%s\n", sabs(a));
	if(a[0] == '-' && b[0] == '-'){
		if(cmp(fa, fb) == -1){
			return addn(minus(fa, fb));
		}else if(cmp(fa, fb) == 0){
			return zero;
		}else{
			return minus(fb, fa);
		}
	}else if(a[0] == '-'){
		return addn(plus(fa, fb)); 
	}else if(b[0] == '-'){
		return plus(fa, fb);
	}else{
		if(cmp(fa, fb) == -1){
			return minus(fa, fb);
		}else if(cmp(fa, fb) == 0){
			return zero;
		}else{
			return addn(minus(fb, fa));
		}
	}
}

char* _mul(char* a, char* b){
	char* fa = calloc(100, sizeof(char));
	char* fb = calloc(100, sizeof(char));
	char* zero = calloc(100, sizeof(char));
	zero[0] = '0';
	strcpy(fa, sabs(a));
	strcpy(fb, sabs(b));
	if(a[0] == '-' ^ b[0] == '-'){
		return addn(mul(fa, fb));
	}else{
		return mul(fa, fb);
	}
}

int main(){
	char* a = calloc(100, sizeof(char));
	char* b = calloc(100, sizeof(char));
	scanf("%s", a);
	scanf("%s", b);
	printf("%s\n", _plus(a, b));
	printf("%s\n", _minus(a, b));
	printf("%s\n", _mul(a, b));
}

