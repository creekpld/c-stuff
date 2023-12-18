#include <stdio.h>
#include <float.h>


int main(){
    printf("Hello Philipp!\n");
    printf("Hello Umlaute üöäÜÖÄß\n");
    printf("Hello Unicode 한글\n");
    //printf("max double=%f \n", DBL_MAX);
    //printf("min double=%lf \n", DBL_MIN);
    float f = 22222222222222222222222222.222222222;
    double d = 22222222222222222222222222.222222222;
    long double l = 22222222222222222222222222.222222222;

    printf("float       %f\n", f);
    printf("float       %.20e\n", f);
    printf("float       %a\n", f);

    printf("double      %lf\n", d);
    printf("double      %.20e\n", d);
    printf("double      %a\n", d);

    printf("long double %Lf\n", l);
    printf("long double %.20Le\n", l);
    printf("long double %La\n", l);

    getchar();
    return 0;
}