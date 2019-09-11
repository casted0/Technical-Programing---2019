#include <iostream>
#include <vector>
#include <cmath>
#define NOT_PRIME -1
using namespace std;

// Find all prime numbers untill a number n given by the user
// Optional: 
// Calculate also the sum of reciprocals of prime numbers
// less than n and reciprocals of twin primes less than n:

// V2 - Sieve of Eratosthenes: 
// 1 - Put all the numbers in a vector
// 2 - Sieve all the multiples of each number untill the next prime number found squared is bigger than N

int pow(int n){
    return n*n;
}

int main(){

    vector<int> primes;
    int max_n;
    int prime_checker;
    int checked;
    long normal_sum = 0;
    double reciprocal_sum = 0.0;
    double reciprocal_sum_twin = 0.0;

    do{

        cout << "Please, introduce a number higher than 2: ";
        cin >> max_n;

    }while(max_n < 3);

    for(vector<int>::size_type i = 2; i < max_n; i++){

        primes.push_back(i);
    }


    for(vector<int>::size_type i = 0; pow(prime_checker) < max_n; i++){

        if(primes.at(i) != NOT_PRIME){

            prime_checker = primes.at(i);
            cout << "Prime Checker: " << prime_checker << endl;

            for(vector<int>::size_type j = i+1; j < primes.size(); j++){

                checked = primes.at(j);
            
                if(checked != NOT_PRIME){

                    if(!(checked % prime_checker)){
                        primes[j] = NOT_PRIME;
                    }
                }
            }
        }

    }

    for(vector<int>::size_type i = 0; i < primes.size()-1; i++){

        if(primes[i] != NOT_PRIME){

            cout << "Prime: " << primes[i] << endl;
        }
    }

    for(vector<int>::size_type i = 0; i < primes.size(); i++){

        if(primes[i] != NOT_PRIME){

            reciprocal_sum += (1/(double)primes[i]);
            normal_sum ++;
        }
        
    }

    for(vector<int>::size_type i = 0, j = 2; i < primes.size(); i++, j++){

        if(primes[i] != NOT_PRIME && primes[j] != NOT_PRIME){
            reciprocal_sum_twin += (1/(double)primes[i]) + (1/(double)primes[j]);
        }
        
    }

    cout << "Prime numbers amount: " << normal_sum << endl;
    cout << "Reciprocal sum: " << reciprocal_sum << endl;
    cout << "Reciprocal sum of twin primes: " << reciprocal_sum_twin << endl;


    return 0;

}

