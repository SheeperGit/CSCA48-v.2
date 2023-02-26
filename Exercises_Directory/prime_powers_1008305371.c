#include<stdio.h>

int get_primes(int potential_prime){
    //Returns 0, if potential prime is not prime and 1 o/w.

    for(int i = 2; i <= potential_prime / 2; i++){
        if(potential_prime % i == 0){
            //Not prime...
            return 0;
        }
        
    }
    // Passed the check, so prime!
    return 1;
}

double power(double x, int i){

    double result = 1;

    for(int j = 0; j < i; j++){
        result *= x;
        // printf("The new result is: %f, j = %d\n", result, j);
    }

    // printf("result(%f, %d) = %f\n", x, i, result);
    return result;
}

#define BASE 1.4142

int main(){

    for(int i = 2; i < 100; i++){
        if(get_primes(i) == 1) printf("%u, %.4f^%u = %.6f\n", i, BASE, i, power(BASE, i));
    }

    return 0;
}