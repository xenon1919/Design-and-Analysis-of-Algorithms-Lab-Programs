#include<stdio.h>
#include <time.h>
void main() {
clock_t t;
t=clock();
int i;
for (i=0;i<1000000000; i++) {
}
t=clock()-t;
double tt=((double) t)/CLOCKS_PER_SEC;
printf("Time=%f", tt);
}