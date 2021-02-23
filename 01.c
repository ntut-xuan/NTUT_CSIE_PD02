#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	double a, b, c;
	scanf("%Lf", &a); 
	scanf("%Lf", &b);
	scanf("%Lf", &c);
	double t = b*b-4*a*c;
	if(t < 0){
		printf("%.1Lf+%.1Lfi\n", -b/(2*a), sqrt(-t/2));
		printf("%.1Lf+%.1Lfi\n", -b/(2*a), sqrt(-t/2));
	}else{
		double d = (-b+sqrt(t))/(2*a);
		double e = (-b-sqrt(t))/(2*a);
		printf("%.1Lf\n", d);
		printf("%.1Lf\n", e);
	}
}
