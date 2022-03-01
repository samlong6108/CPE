#include <iostream>
#include <bits/stdc++.h>

using namespace std ;

string add(string s1, string s2){    
    string answer ;
    cout << s1 << endl ;
    cout << s2 << endl ;
    int sum ;
    int carry_bit=0 ;
    char temp ;
    for(int i=s1.size()-1; i>=0; i--){
        if(s1.at(i)=='.'){
            answer.insert(answer.begin(), '.') ;
            continue ;
        }
        sum = (s1.at(i) - '0') + (s2.at(i) - '0') + carry_bit ;        
        if(sum > 9){
            sum -= 10 ;
            carry_bit = 1 ;
            temp = sum + '0';
            answer.insert(answer.begin(), temp) ;
            if(i==0){
                answer.insert(answer.begin(), '1') ;
            }
        }
        else{
            carry_bit = 0 ;
            temp = sum + '0' ;
            answer.insert(answer.begin(), temp) ;
        }
    }
    return answer ;
}

int main(){
    string s1 = "123.321" ;
    string s2 = "921.9334" ;  
    int s1_index ;
    int s2_index ; 

    // Divied string 1 into left part and right part 
    s1_index = s1.find(".") ;
    string s1_left ;
    string s1_right = "" ;
    s1_left = s1.substr(0, s1_index) ;
    if (s1_index!= -1){        
        s1_right = s1.substr(s1_index) ;    
    }             

    // Divied string 1 into left part and right part 
    s2_index = s2.find(".") ;
    string s2_left ;
    string s2_right = "" ;
    s2_left = s2.substr(0, s2_index) ;
    if (s2_index!= -1){        
        s2_right = s2.substr(s2_index) ;    
    }

    // Padding zeros in left part 
    int s1_left_len = s1_left.size() ;
    int s2_left_len = s2_left.size() ;
    if (s1_left_len < s2_left_len){
        for(int i=0; i<s2_left_len-s1_left_len; i++){
            s1_left.insert(s1_left.begin(), '0') ;
        }
    }
    else{
        for(int i=0; i<s1_left_len-s2_left_len; i++){
            s2_left.insert(s2_left.begin(), '0') ;
        }   
    }

    // Padding zeros in right part 
    int s1_right_len = s1_right.size() ;
    int s2_right_len = s2_right.size() ;
    if (s1_right_len < s2_right_len){
        for(int i=0; i<s2_right_len-s1_right_len; i++){            
            s1_right.insert(s1_right.end(), '0') ;
        }
    }
    else{                
        for(int i=0; i<s1_right_len-s2_right_len; i++){
            s2_right.insert(s2_right.end(), '0') ;
        }   
    }

    // Combined
    s1 = s1_left + s1_right ;
    s2 = s2_left + s2_right ;

    string answer ;    
    answer = add(s1, s2) ;
    cout << answer << endl ;
} 