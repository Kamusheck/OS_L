#include "fn2.hpp"

int PrimeCount(int A, int B){
    std::vector<bool> isRight(std::sqrt(B) + 1, true);
    isRight[0] = false;
    isRight[1]= false;

    std::vector<bool>nCount(B - A + 1, true);

    for (int i =2; i * i <= B; i++){
        if (isRight[i]){
            for (int k = i * i; k<=B;k +=i){
            if (k >= A){
                nCount[k-A]= false;
            }
        }
        }
    }

    int count = 0;
    for (int i= 0; i<= B-A; i++){
        if(A+i>1 && nCount[i]){
            count++;
        }
    }
    return count;
}

float SinIntegral(float A, float B, float e) {
    int n = (B - A) / e;  
    float sum = 0.0;

    for (int i = 1; i < n; ++i) {
        float x = A + i * e;
        sum += std::sin(x);
    }

    sum += (std::sin(A) + std::sin(B)) / 2.0;
    sum *= e;
    return sum;
}