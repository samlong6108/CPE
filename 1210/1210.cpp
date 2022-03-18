#include <bits/stdc++.h>
#include <iostream>

using namespace std ;

vector <long> primes ;
long len ;
bool visited[10050] ;

void PrimeGenerator(){
    primes.push_back(2) ;
    for(long i=4; i<10020; i+=2){
        visited[i] = true ;
    }

    for(long i=3; i<10020; i+=2){
        if(!visited[i]){
            primes.push_back(i) ;
            for(long j=i*i; j<10020; j+=2*i){
                visited[j] = true ;
            }
        }
    }

    len = primes.size() ;
}


int main(){
    PrimeGenerator() ;
    bool show ;
    show = false ;
    long testcase ; 
    testcase = 1 ;
    while(testcase!=0){
        scanf("%ld", &testcase) ;
        if(testcase==0){
            break ;
        }
        if(show==true){
            cout << "=======" << endl ;
            cout << testcase << endl ;
        }

        long count ; 
        long sum ;
        count = 0 ;
        sum = 0 ;
        for(long i=0; primes[i]<=testcase; i++){
            sum = primes[i] ; 
            for(long j=i+1; sum<testcase; j++){
                sum += primes[j] ;
                if(show==true){
                    cout << sum << endl ;
                }
                
            }
            if(sum==testcase){
                count += 1;
            }
        }
        
        cout << count << endl ;
        
    }
}