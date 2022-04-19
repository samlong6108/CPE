#include <bits/stdc++.h>
#include <iostream>

using namespace std ;

long long answer[1024] ;

void parsing(string s, int index){
    // cout << "=========" << endl ;
    // cout << s << endl ;
    if(index > s.size()){
        return ;
    }
    int sign=1 ;
    int m=0 ;
    char pos;
    for(int i=index+1; i<s.size(); i++){
        if(s[i]=='-'){
            sign = -1 ;
        }
        else if(s[i]>='0' && s[i]<='9'){
            m = m*10 + s[i] - '0' ;
        }
        else{
            pos = s[i] ;
            index = i ;
            break ;
        }
    }
    m = m * sign ;
    if(pos=='+'){
        parsing(s, index+1) ;
        long long d = answer[0] ;
        answer[0] = m ;
        for(int i=1; i<50; i++){
            long long t = answer[i] ;
            answer[i] = answer[i-1] + d ; 
            d = t ; 
        }
    }
    else if(pos=='*'){
        parsing(s, index+1) ;
        answer[0] = answer[0] * m ;
        for(int i=1; i<50; i++){
            answer[i] = answer[i-1] * answer[i] ;
        }
    }
    else{
        for(int i=0; i<50; i++){
            answer[i] = m ;
        }
    }
}

int main(){
    string input ;
    int N ;
    int index=0 ;
    while(cin >> input){
        cin >> N ;
        parsing(input, index) ;
        for(int i=0; i<N; i++){
            cout << answer[i] << " " ;
        }        
        cout << endl ;
    }
}