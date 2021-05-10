#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double f1(double a, double x){
	return sqrt(a-x*x);
}

double f2(double a, double x){
	double result = (a*x*x*x+7*x)/sqrt(a+x);
	if(result < 0) result *= -1.0;
	return result;
}

double dof1(double a, double p, double q, int n){
	double result = f1(a, p)+f1(a, q);
	double h = (q-p)/n;
	for(double xi = p+h; xi < q; xi += h){
		result += 2*sqrt(a-xi*xi);
//		printf("%.12f\n", xi);
	}
	result *= (q-p);
	result /= 2*n;
	return result;
}

double dof2(double a, double p, double q, double n){
	double result = f2(a, p)+f2(a, q);
	double h = (q-p)/n;
	for(double xi = p+h; xi < q; xi += h){
		result += 2*f2(a, xi);
	}
	result *= (q-p);
	result /= (2*n);
	return result;
//	printf("%.12Lf\n", result);
}

double _abs(double a){
	if(a < 0) return -a;
	else return a;
}

int main(){
	double type, a, p, q, err;
	while(scanf("%lf", &type)){
		if(type == 0){
			break;
		}
		scanf("%lf %lf %lf %lf", &a, &p, &q, &err);
		if(type == 1){ 
			int n = 1;
			double answer = dof1(a, p, q, n);
			double temp = dof1(a, p, q, 2*n);
			n *= 2;
			double derr = pow(10, -err);
			while(_abs(answer-temp) >= derr){
				n *= 2;
				answer = temp;
				temp = dof1(a, p, q, n);
			}
			printf("%.12lf\n", temp);
		}else if(type == 2){
			int n = 1;
			double answer = dof2(a, p, q, n);
			double temp = dof2(a, p, q, 2*n);
			n *= 2;
			double derr = pow(10, -err);
			while(_abs(answer-temp) >= derr){
				n *= 2;
				answer = temp;
				temp = dof2(a, p, q, n);
			}
			printf("%.12lf\n", temp);
		}
	}
}
