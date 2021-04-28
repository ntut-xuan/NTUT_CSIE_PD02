#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int getFlag(char c){
	if('a' <= c && c <= 'z') return 1;
	return -1;
}

int main(){
	int n;
	scanf("%d", &n);
	char* data = calloc(1e6, sizeof(char));
	scanf("%s", data);
	int index = 0;
	int* array = calloc(1e6, sizeof(char));
	int flag = getFlag(data[0]);
	int r = 0;
	for(int i = 0; i < strlen(data); i++){
		if(flag == getFlag(data[i])){
			r += 1;
		}else{
			array[index] = r;
			flag = getFlag(data[i]);
			r = 1;
			index += 1;
		}
	}
	array[index] = r;
	index += 1;
	int s = -1, e = 0, ts = -1, te = 0, lf = 0, lt = 0;
	for(int i = 0; i < index; i++){
		if(ts == -1 && array[i] == n){
			ts = i;
		}
		if(ts != -1 && array[i] == n){
			te = i;
			lt += 1;
		}
		if(ts != -1 && array[i] != n){
			if(lt > lf){
				e = te;
				s = ts;
				lf = lt;
			}
			te = 0;
			ts = -1;
			lt = 0;
		}
	}
	if(lt > lf){
		lf = lt;
		e = te;
		s = ts;
	}
	int ans = (lf)*n;
	if(index == 1 && strlen(data) >= n){
		ans += n; 
	} 
	if(s > 0 && array[s-1] >= n){
		ans += n;
	}
	if(e < index-1 && array[e+1] >= n){
		ans += n;
	}
	printf("%d\n", ans);
} 
