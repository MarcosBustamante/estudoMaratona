#include <stdio.h>
#include <math.h>

#define min(a,b) a > b ? b : a

int main(){
    double a,b;
    while (scanf("%lf %lf", &a, &b) && a + b){
        double x1 = (4 * (a + b) + sqrt(pow(4 * (a + b), 2) - (48 * a * b))) / 24;
        double x2 = (4 * (a + b) - sqrt(pow(4 * (a + b), 2) - (48 * a * b))) / 24;
        double x = min(x1,x2);
        printf("%.4lf %.4lf\n", x, (a - (2*x)) * (b - (2*x)) * x );
    }

    return 0;
}
