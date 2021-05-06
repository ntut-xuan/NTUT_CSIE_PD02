#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

double f1(double a, double x){
	return sqrt(a-x*x);
}

double f2(double a, double x){
	return (a*x*x*x+7*x)/sqrt(a+x);
}

double dof1(double a, double p, double q, int n){
	double result = f1(a, p)+f1(a, q);
	double h = (q-p)/n;
	for(double xi = p+h; xi < q; xi += h){
		result += 2*f1(a, xi);
//		printf("%.12f\n", xi);
	}
	result *= (q-p);
	result /= 2*n;
	return result;
}

double dof2(double a, double p, double q, double n){
	double result = f2(a, p)+f2(a, q);
	double h = ((q-p)*1.0)/n;
	double xi = p+h;
	for(int i = 0; i < n-1; i++){
		double temp = (2*f2(a, xi));
		result += temp;
		xi += h;
	}
	result *= (q-p);
	result /= (2*n);
	return result;
//	printf("%.12Lf\n", result);
}

double f1ans(double a, double x){	
	return (sqrt(a)*x*sqrt((a-x*x)/(a)))/2 + (a*asin(x/sqrt(a)))/2;
}

double f2ans(double a, double x){
	return ((2*sqrt(a+x))*(-48*a*a*a*a+24*a*a*a*x-18*a*a*x*x+15*a*x*x*x-490*a+245*x))/105;
}

double _abs(double a){
	if(a < 0) return -a;
	else return a;
}

double _pow(int n){
	double a = 1;
	while(n++){
		a /= 10.0;
	}
	return a;
}

int main(){
	int type, a, p, q, err, ul;
	while(scanf("%d %d %d %d %d %d", &type, &a, &p, &q, &err, &ul)){
		if(type == 1){ 
			double answer = f1ans(a, q) - f1ans(a, p);
			int n = 1;
			double temp = dof1(a, p, q, n);
//			printf("%.12lf %.12lf\n", answer, temp);
			double derr = _pow(-err);
//			printf("%.12lf\n", _abs(answer-temp));
			while(_abs(answer-temp) >= derr){
				n *= 2;
				temp = dof1(a, p, q, n);
//				printf("%d %.12lf %.12lf %.12lf\n", n, _abs(answer - temp), derr, temp);
			}
			printf("%.12lf\n", temp);
		}else if(type == 2){
			double answer = f2ans(a, q) - f2ans(a, p);
			int n = 1;
			double temp = dof2(a, p, q, n);
//			printf("%.12Lf %.12Lf\n", answer, temp);
			double derr = _pow(-err-1);
//			printf("%.12Lf\n", _abs(answer-temp));
			while(_abs(answer-temp) >= derr){
				n *= 2;
				temp = dof2(a, p, q, n);
//				printf("%d %.12lf %.12lf %.12lf\n", n, _abs(answer - temp), derr, temp);
			}
			printf("%.12lf\n", temp);
		}
	}
}
