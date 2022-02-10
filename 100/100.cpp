#include <iostream>
#include <cstdio>

using namespace std ;


void swap(int *a, int *b){
    *a = *a^*b ;
    *b = *a^*b ;
    *a = *a^*b ;
}

int find_cycle(int number){
    int answer = 1 ;
    while(number!=1){
        answer = answer + 1 ;
        if (number%2==1){
            number = 3 * number  + 1 ;
        }
        else{
            number = int(number/2) ;
        }
    }
    return answer ;
}


int main(){
    int a ;
    int b ;
    int cycle ;
    while(scanf("%d %d", &a, &b)!=EOF){
        int flag=0 ;
        int max_ = -1 ;
        if (b < a){
            swap(a, b);
            flag = 1 ;
        }
        for(int i=a ; i<=b ; i++){
            cycle = find_cycle(i) ;
            if(cycle>max_){
                max_ = cycle ;
            }
        }
        if(flag==1){
            swap(a, b);
        }
        printf("%d %d %d\n", a, b, max_) ;
    }
    return 0 ;
}
