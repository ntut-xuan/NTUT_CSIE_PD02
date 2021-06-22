
#define GATEVALUE(TYPE) int(*GateValue)(void)

typedef struct _Gate{
  GATEVALUE();
}Gate;

int GateGetValue(){
  return 0;
}

typedef struct _GateAnd{
  GATEVALUE();
}GateAnd;

int GateAndValue(){
  return 1;
}

void CreateGate(Gate *obj){
  obj->GateValue = GateGetValue;
}

void CreateGateAND(GateAnd *obj){
  obj->GateValue = GateAndValue;
}

int main(int argc, char *argv[]){
  Gate gate;
  CreateGate(&gate);
  GateAnd and;
  CreateGateAND(&and);
  printf("Gate = %d, GateAND = %d\n", gate.GateValue(), and.GateValue());
  return 0;
} 
