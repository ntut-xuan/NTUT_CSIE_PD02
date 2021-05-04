#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int score(char* type, char* data){
	if(strcmp(type, "G") == 0){
		if(strcmp(data, "A+") == 0){
			return 95;
		}
		if(strcmp(data, "A") == 0){
			return 87;
		}
		if(strcmp(data, "A-") == 0){
			return 82;
		}
		if(strcmp(data, "B+") == 0){
			return 78;
		}
		if(strcmp(data, "B") == 0){
			return 75;
		}
		if(strcmp(data, "B-") == 0){
			return 70;
		}
		if(strcmp(data, "C+") == 0){
			return 68;
		}
		if(strcmp(data, "C") == 0){
			return 65;
		}
		if(strcmp(data, "C-") == 0){
			return 60;
		}
		if(strcmp(data, "F") == 0){
			return 50;
		}
	}
	if(strcmp(type, "GPA") == 0){
		if(strcmp(data, "4.3") == 0){
			return 95;
		}
		if(strcmp(data, "4.0") == 0){
			return 87;
		}
		if(strcmp(data, "3.7") == 0){
			return 82;
		}
		if(strcmp(data, "3.3") == 0){
			return 78;
		}
		if(strcmp(data, "3.0") == 0){
			return 75;
		}
		if(strcmp(data, "2.7") == 0){
			return 70;
		}
		if(strcmp(data, "2.3") == 0){
			return 68;
		}
		if(strcmp(data, "2.0") == 0){
			return 65;
		}
		if(strcmp(data, "1.7") == 0){
			return 60;
		}
		if(strcmp(data, "0") == 0){
			return 50;
		}
	}
	if(strcmp(type, "S") == 0){
		if(strcmp(data, "90-100") == 0){
			return 95;
		}
		if(strcmp(data, "85-89") == 0){
			return 87;
		}
		if(strcmp(data, "80-84") == 0){
			return 82;
		}
		if(strcmp(data, "77-79") == 0){
			return 78;
		}
		if(strcmp(data, "73-76") == 0){
			return 75;
		}
		if(strcmp(data, "70-72") == 0){
			return 70;
		}
		if(strcmp(data, "67-69") == 0){
			return 68;
		}
		if(strcmp(data, "63-66") == 0){
			return 65;
		}
		if(strcmp(data, "60-62") == 0){
			return 60;
		}
		if(strcmp(data, "59以下") == 0){
			return 50;
		}
	} 
}

struct data_s{
	int score;
	char* id;
};

int cmp(const void* p1, const void* p2){
	struct data_s* a = (struct data_s*) p1;
	struct data_s* b = (struct data_s*) p2;
	if(a->score < b->score){
		return 1;
	}else{
		return -1;
	}
}

int main(){
	int m;
	scanf("%d", &m);
	char** types = calloc(100, sizeof(char*));
	for(int i = 0; i < m; i++){
		types[i] = calloc(100, sizeof(char));
		scanf("%s", types[i]);
	}
	int n;
	scanf("%d", &n);
	struct data_s* students = calloc(100, sizeof(struct data_s));
	for(int i = 0; i < n; i++){
		char* ID = calloc(100, sizeof(char));
		scanf("%s", ID);
		double total = 0;
		for(int j = 0; j < m; j++){
			char* data = calloc(100, sizeof(char));
			scanf("%s", data);
			total += score(types[j], data);
		}
		total /= (1.0 * m);
		total += 0.5;
		students[i].id = calloc(100, sizeof(char)); 
		strcpy(students[i].id, ID);
		students[i].score = (int)total; 
	}
	qsort((void*) students, n, sizeof(struct data_s), cmp);
	for(int i = 0; i < 3; i++){
		printf("%s\n", students[i].id);
		printf("%d\n", students[i].score);
	}
}
