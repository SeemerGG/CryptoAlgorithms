#include<iostream>
#include<vector>
#include<ctime>
#include<fstream>

using namespace std;

bool isMutuallyPrime(const int n,const int m){
    int min = (n < m) ? n : m;
    for(int i = 2; i <= min; i++){
        if(n % i == 0 && m % i == 0){
            return false;
        }
    }
    return true;
}

int FunctionEyler(const int n){
    int count = 0;
    for(int i = 1; i < n; i++){
        if(isMutuallyPrime(n, i)){
            count++;
        }
    }
    return count;
}

float FunctionEyler2(const int n){
    int n_clone = n;
    float res = n;
    int i = 2;
    while(n_clone != 1){
        if(n_clone % i == 0){
            res *= i-1;
            res /= i;
            while(n_clone % i == 0){
                n_clone /= i;
            }
        }
        i++;
    }
    return res;
}

void Lab1(int n, int begin = 10000000, int end = 99999999){
    ofstream fout("result.txt");
    int digits[n];
    int start;

    for(int i = 0; i < n; i++){
        digits[i] = rand() % (end - begin + 1) + begin;
    }

    start = clock();
    for(int i : digits){
        FunctionEyler(i);
    }
    fout << "By definition: " << clock() - start / CLOCKS_PER_SEC << endl;

    start = clock();
    for(int i : digits){
        FunctionEyler2(i);
    }
    fout << "By formula: " << clock() - start / CLOCKS_PER_SEC << endl;
    
    fout.close();
}

int main(){
    Lab1(100, 10000, 99999);

    return 0;
}