#include "fn1.hpp"

int PrimeCount(int A, int B){
    if (A < 2) {
        A = 2; 
    }

    int count = 0;
    for (int i = A; i<= B; i++ ){
        bool isRight = true;
        for (int k  = 2; k <= std::sqrt(i); k++){
            if (i % k ==0){
                isRight = false;
                break;
            }
        }
        if(isRight){
            count++;
        }
    }
    return count;
};

float SinIntegral(float A, float B, float e) {
    int n = (B - A) / e;  
    float sum = 0.0;

    for (int i = 0; i < n; ++i) {
        float x = A + i * e; 
        sum += std::sin(x) * e;   
    }

    return sum;
}