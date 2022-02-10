#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>

using namespace std ;

int main(){
    vector<string> word_list ;
    string buf ;
    while(getline(cin, buf) && buf[0] != '0'){
        // cout << "====== Now processing buf is=======" << endl ;
        // cout << buf << endl ;
        int value = 0, state = 0 ; // 2:number , 1:Letter, 0:others
        string s ;
        for(int i=0; buf[i]; i++){
            if(isalpha(buf[i])){
                s = "" ;
                while(isalpha(buf[i])){
                    s.insert(s.end(), buf[i]) ;
                    i = i + 1 ;
                }
                cout << s    ; 
                word_list.push_back(s) ;
                i -- ; 
            }
            else if(isdigit(buf[i])){
                value = 0 ;
                while(isdigit(buf[i])){
                    value = value * 10 + buf[i] - '0' ;
                    i = i + 1 ;
                }
                s = word_list[word_list.size() - value ] ;
                word_list.erase(word_list.end() - value) ;
                word_list.push_back(s) ;
                i-- ;
                cout << s ;
            }
            else{
                cout << buf[i] ;
            }
            
        }
        cout << endl ;
    }
}