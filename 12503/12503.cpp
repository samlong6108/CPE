#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>

using namespace std ;

int main(){
    int TestCase ;
    scanf("%d", &TestCase) ;    
    for(int i=0; i<TestCase; i++){
        int Action ;
        scanf("%d\n", &Action) ;        
        vector<int> action_list (1, 0) ;        
        for(int j=0; j<Action; j++){            
            string temp ; 
            getline(cin, temp) ;                                                
            if(temp[0]=='L'){
                action_list.push_back(-1) ;
            }
            else if(temp[0]=='R'){
                action_list.push_back(1) ;
            }
            else if(temp[0]=='S'){                
                stringstream ss(temp) ;
                string a, b ;
                int index ;
                ss >> a >> b >> index ;
                action_list.push_back(action_list[index]) ;                                
            }            
        }
        int answer = 0 ;
        for(int j=0; j<=Action; j++){
            answer += action_list[j] ;
        }
        cout << answer << endl ;
    }
    return 0 ;
}