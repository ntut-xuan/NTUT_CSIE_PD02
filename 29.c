#include <stdio.h> 
#include <stdlib.h>
#define GATEVALUE(TYPE) int(*GateValue)(void)
typedef struct _Gate{
	GATEVALUE();
} Gate;

typedef struct _GateAnd{
	GATEVALUE();
} GateAnd;

typedef struct _GateOr{
	GATEVALUE();
} GateOr;

typedef struct _GateXOR{
	GATEVALUE();
} GateXor;

typedef struct _GateNOT{
	GATEVALUE();
} GateNot;

typedef struct _GateEmpty{
	GATEVALUE();
} GateEmpty;

int GateGetValue(){
	return 0;
}

int GateAndValue(){
	return 1;
}

int GateOrValue(){
	return 2;
}

int GateXorValue(){
	return 3;
}

int GateNotValue(){
	return 4;
}

int GateEmptyValue(){
	return -1;
}

void CreateGate(Gate *obj){
	obj->GateValue = GateGetValue;
}

void CreateGateAND(GateAnd *obj){
	obj->GateValue = GateAndValue;
}

void CreateGateXOR(GateXor *obj){
	obj->GateValue = GateXorValue;
}

void CreateGateOR(GateOr *obj){
	obj->GateValue = GateOrValue;
}

void CreateGateNOT(GateNot *obj){
	obj->GateValue = GateNotValue;
}

void CreateGateEmpty(GateEmpty *obj){
	obj->GateValue = GateEmptyValue;
}

int processResult(int a, int b, int oper){
	if(oper == 1){
		return a*b > 0 ? 1 : 0;
	}else if(oper == 2){
		return a+b > 0 ? 1 : 0; 
	}else if(oper == 3){
		return a^b > 0 ? 1 : 0;
	}
	return 0;
}

int main(int argc, char *argv[]){
	int data[4];
	char word[6];
	Gate gate[6];
	int result[3];
	int tempResult = 0;
	scanf("%d,%d,%d,%d", &data[0], &data[1], &data[2], &data[3]);
	scanf(" %c,%c,%c,%c,%c,%c", &word[0], &word[1], &word[2], &word[3], &word[4], &word[5]);
	for(int i = 0; i < 6; i++){
		if(word[i] == 'N'){
			CreateGateNOT(((GateNot*)&gate[i]));
		}else if(word[i] == 'A'){
			CreateGateAND(((GateAnd*)&gate[i]));
		}else if(word[i] == 'X'){
			CreateGateXOR(((GateXor*)&gate[i]));
		}else if(word[i] == 'O'){
			CreateGateOR(((GateOr*)&gate[i]));
		}else if(word[i] == 'E'){
			CreateGateEmpty(((GateEmpty*)&gate[i]));
		}
	}
	if(gate[0].GateValue() == 4){
		data[0] = !data[0];
	}
	if(gate[4].GateValue() == 4){
		data[3] = !data[3];
	}
	result[0] = processResult(data[0], data[1], gate[1].GateValue());
	tempResult = processResult(result[0], data[2], gate[2].GateValue());
	result[1] = processResult(result[0], tempResult, gate[3].GateValue());
	result[2] = processResult(result[1], data[3], gate[5].GateValue());
	printf("%d,%d,%d\n", result[0], result[1], result[2]);
} 
