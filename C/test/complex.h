#include <stdio.h>

typedef struct complex{
    float re;
    float imm;
} complex;

// FUNCTIONS DEFINITIONS
float m_mod(float n){
    if(n<0){
        return n * -1;
    }else{
        return n;
    }
}

int pow2(int n){
    if(n==0){
        return 1;
    }
    
    int r=1;
    
    for(int i=0; i<n; i++){
        r*=2;
    }

    return r;
}

double m_sqrt(float n){
    /*
    Approximation of the square root
    At this point the result should be good enough to work with.
    Refining the result using the Heron's method.
    Check: https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Babylonian_method
    */
    float a=n;
    int b=0;

    while(a>10){
        b+=1;
        a = n / pow2(2*b);
    }

    double r = (0.5 + 0.5*a) * pow2(b);
    
    for(int i=0; i<5; i++){
        r = 0.5 * (r + n / r);
    }
    
    return r;
}

void assignc(complex *cplx, float re, float imm){
    cplx->re = re;
    cplx->imm = imm;
}

void printc(complex *cplx){
    if(cplx->imm >= 0){
        printf("%.2f + %.2fi", cplx->re, m_mod(cplx->imm));
    }else{
        printf("%.2f - %.2fi", cplx->re, m_mod(cplx->imm));
    }
}

complex conjc(complex *cplx){
    complex r;

    float re = cplx->re;
    float i = cplx->imm * -1;

    assignc(&r, re, i);
    
    return r;
}

double modc(complex *cplx){
    double r;

    r = m_sqrt( (m_mod(cplx->re) * m_mod(cplx->re) ) + ( m_mod(cplx->imm) * m_mod(cplx->imm) ) );
    
    return r;
}

complex sumc(complex *cplx1, complex *cplx2){
    complex r;

    float re = cplx1->re + cplx2->re;
    float i = cplx1->imm + cplx2->imm;
    
    assignc(&r, re, i);
    
    return r;
}

complex subc(complex *cplx1, complex *cplx2){
    complex r;

    float re = cplx1->re - cplx2->re;
    float i = cplx1->imm - cplx2->imm;
    
    assignc(&r, re, i);
    
    return r;
}

complex multc(complex *cplx1, complex *cplx2){
    complex r;

    float re = cplx1->re * cplx2->re - cplx1->imm * cplx2->imm;
    float i = cplx1->re * cplx2->imm + cplx1->imm * cplx2->re;

    assignc(&r, re, i);

    return r;
}

complex divc(complex *cplx1, complex *cplx2){
     /* 
    Division a / b.
    Multiply the numerator and denominator by the complex conjugate of the denominator.
    Work out denominator, that will lose the immaginary part (the denominator ALWAYS becomes a difference of squares).
    Square of i is -1 --> denominator will ALWAYS be real.
    Expand the numerator.
    Obtain the coefficents (divide by the real part of the denominator like a normal fraction).
    Assign coefficients to the result variable and return it.
    */
    complex r;

    complex conj = conjc(cplx2);
    
    complex denominator = multc(cplx2, &conj);    
    complex numerator = multc(cplx1, &conj);

    float re = numerator.re / denominator.re;
    float i = numerator.imm / denominator.re;
    
    assignc(&r, re, i);

    return r;
}
