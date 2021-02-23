#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int a, b, c, d;
	scanf(" %d", &a);
	scanf(" %d", &b);
	scanf(" %d", &c);
	scanf(" %d", &d);
	int total = (a+b)*c;
	double tex = floor(100*total*0.08)/100.0;
	double uhh = floor(100*d*0.05)/100.0;
	double ans = total - tex - uhh;
	printf("%.1lf\n", floor(100*ans)/100.0);
	printf("%.1lf\n", uhh);
	printf("%.1lf\n", tex);
}
