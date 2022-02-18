#include <iostream>
#include <bits/stdc++.h>

using namespace std ;

int GCD(int a, int b){
    return b == 0 ? a : GCD(b, a%b) ;
}

int str_to_int(char *a, char *b){
    int num1=0 ;
    int num2=0 ;
    
    for(int i=0; i<strlen(a); i++){
        num1 = (num1 << 1) + (a[i]- '0') ;
    }
    
    for(int i=0; i<strlen(b); i++){
        num2 = (num2 << 1) + (b[i] - '0') ;
    }
    return GCD(num1, num2) ;
}

int main(){
    int testcase ;         
    scanf("%d\n", &testcase) ;
    for(int i=0; i<testcase; i++){        
        char S1[31] = {0} ; 
        char S2[31] = {0} ;
        scanf("%s %s", S1, S2) ;        
        int temp ; 
        temp = str_to_int(S1, S2) ;
        if(temp==1){
            cout << "Pair #" << i+1 << ": Love is not all you need!" << endl ;
        }
        else{
            cout << "Pair #" << i+1 << ": All you need is love!" << endl;
        }
    }
    return 0 ;
}