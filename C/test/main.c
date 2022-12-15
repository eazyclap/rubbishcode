#include <stdio.h>
#include <math.h>
#include "complex.h"

int main(void)
{
    /*
    complex cplx;
    assignc(&cplx, 10, -5);
    printf("Complex number z = "); printc(&cplx); printf("\n\n");
    return 0;
    */
   printf("Math.h dice: \t\t%.20f\n", sqrt(2));
   printf("La mia libreria: \t%.20f", m_sqrt(2));
   printf("\n\n\n");
}
