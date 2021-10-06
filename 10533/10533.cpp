#include <iostream>
#include <cstdio>
#include <list>
#define MAX  1000000
using namespace std ;

bool prime[MAX+1] ;
int dprime[MAX+1] ;


int digitSum(int x){
    int answer = 0 ;
    while(x>0){
        answer = answer + x%10 ;
        x = x / 10 ;
    }
    return answer ;
}

void seive(){
    long long i, j;
    for(i = 0 ; i<=MAX ; i++){
        prime[i] = true ;
        dprime[i] = 0 ;
    }
    
    prime[0] = false ;
    prime[1] = false ;
    for(i = 2 ; i<=MAX ; i++){        
        dprime[i] = dprime[i-1] ;        
        if(prime[i]){            
            if (prime[digitSum(i)]){
                dprime[i] = dprime[i] + 1;
            }            
            for(j = i * i ; j<=MAX; j = j+i){
                prime[j] = false ;
            }
        }
    }
}

int is_prime(int x){
    if(x<2) return 0 ;
    for(int i=2 ; i*i<=x; i++){
        if(x%i==0) return 0 ;
    }
    return 1 ;
}

int main(){
    int number, front, end, count;
    scanf("%d", &number);    
    seive() ;     
    for(int i=0; i<number; i++){
        scanf("%d %d", &front, &end);
        printf("%d\n", dprime[end] - dprime[front-1]);
    }
}