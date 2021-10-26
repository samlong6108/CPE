#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std ;


int DigitSum(int Number){
    int sum = 0 ;
    int temp ;
    while(Number>0){
        temp = Number%10 ;
        sum = sum + temp ;
        Number = Number / 10 ;
    }
    return sum ; 
}



int main(){
    int testcase ;
    scanf("%d", &testcase) ;

    int Prime_Table[50000] = {1, 1, 0} ;
    for(int i=2; i<50000; i++){
        if(!Prime_Table[i]){
            for(int j= i+i; j<50000; j=j+i){
                Prime_Table[j] = 1 ;
            }
        }
    }

    for(int i=0; i<testcase; i++){
        int number ; 
        scanf("%d", &number);
        int smith_number ; 
        int left_sum, right_sum ;
        left_sum = 0 ;
        
        while(true){            
            right_sum = 0 ;            
            smith_number = number + 1 ;
            left_sum = DigitSum(smith_number) ;
            int sqrt_number = sqrt(smith_number) ;            
            for(int j=2; j<=sqrt_number; j++){
                if(!Prime_Table[j]){

                    while(smith_number % j ==0){                                            
                        right_sum = right_sum + DigitSum(j) ;
                        smith_number = smith_number / j ;
                    }
                }
            }
            if(smith_number==number+1){
                number +=1 ;
                continue ;
            }
            
            if (sqrt_number < smith_number){
                right_sum += DigitSum(smith_number) ;
            }

            if (left_sum==right_sum){
                cout << number+1 << endl ;                
                break ;
            }
            number +=1 ;                 
        }
    }
}