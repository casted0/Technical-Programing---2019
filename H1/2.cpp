#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Find all prime numbers untill a number n given by the user
// Optional: 
// Calculate also the sum of reciprocals of prime numbers
// less than n and reciprocals of twin primes less than n:

bool PrimeNumber(int N, vector<int> primes){

    for(vector<int>::size_type i = 0; i < primes.size(); i++){

        if(primes[i] >= 49){
            break;
        }else if(!(N % primes[i])){
            return false;
        }
    }

    return true;

}

int main(){

    vector<int> primes;
    int max_n;
    double reciprocal_sum = 0.0;
    double reciprocal_sum_twin = 0.0;

    do{

        cout << "Please, introduce a number higher than 2: ";
        cin >> max_n;

    }while(max_n < 3);

    primes.push_back(2);
    int i = 3;

    while(i < max_n){

        if((i % 2) && (i % 3) && (i % 5) && (i % 6)){   
            i++;
        }else if(PrimeNumber(i, primes)){
            primes.push_back(i);
            i++;
        }

    }

    for(vector<int>::size_type i = 0; i < primes.size(); i++){
        cout << "Prime[" << i+1 << "]: " << primes[i] << endl;
    }

    return 0;

}

// Fastest way to see if a number n is prime:
// Check if that number is divisible by any of the prime numbers that precede n square root