#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.14159

int main(){
	double d;
	scanf("%lf", &d);
	printf("%.3lf\n", d*d*PI);
	printf("%.3lf\n", 2*d*PI);
}
