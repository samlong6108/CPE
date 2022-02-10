#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std ;

int solve(int num_cola, int give_empty_bottle){    
    int empty = num_cola + give_empty_bottle;     
    int answer = num_cola ;
    int temp_non_empty = 0 ;
    int temp_empty = 0 ;
    while (empty>=3){                
        temp_empty = empty%3 ;
        temp_non_empty = empty/3 ;
        // cout << "--" << endl ;
        // cout << temp_non_empty << "\t" << temp_empty << endl ;            
        empty = temp_empty + temp_non_empty ;
        answer += temp_non_empty ;
    }
    empty = temp_empty + temp_non_empty ;
    if (empty < give_empty_bottle){
        // cout << "Nonthing" << endl ;
        // cout << answer << endl ;
        return 0 ;
    }
    else{
        // cout << answer << endl ;
        return answer ;
    }
}

int main(){
    int num_cola ;        
    int answer_temp ;
    while(scanf("%d", &num_cola)!=EOF){
        int answer=0 ;
        // cout << "========" << endl ;
        // cout << num_cola << endl ; 
        for(int i=0; i<3; i++){
            // cout << "------" << i << "------" << endl ;
            answer_temp = solve(num_cola, i) ;    
            if (answer_temp>answer){
                answer = answer_temp ;
            }
        }                
        cout << answer << endl ;                
    }
}
