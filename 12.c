#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int gcd(int a, int b){
    a = abs(a);
    b = abs(b);
    int c = 0;
    for(int i = 1; i <= 1e6; i++){
        if(a % i == 0 && b % i == 0) c = i;
    }
    return c;
}

int main() {
    while(1){
        char str1[100], str2[100];
        memset(str1, '\0', 100);
        memset(str2, '\0', 100);
        char cmd[100];
        scanf("%s", &str1);
        scanf("%s", &str2);
        char a[100], b[100], c[100], d[100];
        memset(a, '\0', 100);
        memset(b, '\0', 100);
        memset(c, '\0', 100);
        memset(d, '\0', 100);
        memset(cmd, '\0', 100);
        int i = 0, j = 0;
        for(i; i < strlen(str1); i++){
            if(str1[i] == '/'){
                break;
            }else{
                a[i] = str1[i];
            }
        }
        i += 1;
        for(i; i < strlen(str1); i++){
            if(str1[i] == '\0'){
                break;
            }else{
                b[i-strlen(a)-1] = str1[i];
            }
        }
        for(j; j < strlen(str2); j++){
            if(str2[j] == '/'){
                break;
            }else{
                c[j] = str2[j];
            }
        }
        j += 1;
        for(j; j < strlen(str2); j++){
            if(str2[j] == '\0'){
                break;
            }else{
                d[j-strlen(c)-1] = str2[j];
            }
        }
        int e = atoi(a), f = atoi(b), g = atoi(c), h = atoi(d);
        char operator[100];
        memset(operator, '\0', 100);
        scanf("%s", &operator);
        if(f == 0 || h == 0){
            printf("ERROR\n");
        }else {
            int k = 0, l = 0;
            if (strcmp(operator, "+") == 0) {
                k = (f * g + e * h);
                l = f * h;
            } else if (strcmp(operator, "-") == 0) {
                k = (e * h - f * g);
                l = f * h;
            } else if (strcmp(operator, "*") == 0) {
                k = e * g;
                l = f * h;
            } else if (strcmp(operator, "/") == 0) {
                k = e * h;
                l = f * g;
            }
            if (k == 0) {
                printf("0\n");
            } else if (abs(k) > abs(l)) {
                if (k % l == 0) {
                    printf("%d\n", k / l);
                } else if (k < 0 && l > 0 || k > 0 && l < 0) {
                    printf("-%d(%d/%d)\n", abs(k / l), abs(abs(k % l) / gcd(k % l, l)), abs(l / gcd(k % l, l)));
                } else {
                    printf("%d(%d/%d)\n", abs(k / l), abs(abs(k % l) / gcd(k % l, l)), abs(l / gcd(k % l, l)));
                }
            } else {
                if (k % l == 0) {
                    printf("%d\n", k / l);
                } else if (k < 0 && l > 0 || k > 0 && l < 0) {
                    printf("-%d/%d\n", abs(k / gcd(k, l)), abs(l / gcd(k, l)));
                } else {
                    printf("%d/%d\n", abs(k / gcd(k, l)), abs(l / gcd(k, l)));
                }
            }
        }
        scanf("%s", &cmd);
        if(strcmp(cmd, "n") == 0){
            break;
        }
    }
}
