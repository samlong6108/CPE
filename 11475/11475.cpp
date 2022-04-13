#include <bits/stdc++.h>
#include <iostream>

using namespace std ;

int main(){
    string input ;
    string reverse ;
    while(cin >> input){        
        // cout << "===========" << endl ;

        // Reverse input
        reverse.assign(input) ;
        for(int i=0; i<input.length(); i++){
            reverse[i] = input[input.length()-1-i] ;
        }

        // cout << input << endl ;
        // cout << reverse << endl ;
        // cout << input.length() << endl ;

        if(input.compare(reverse)==0){
            cout << input << endl ;
        }
        else{
            int index ;
            index = 0 ;
            for(int i=input.length()-1; i>0; i--){
                string input_back ; 
                string reverse_front ;
                input_back.assign(input.end()-i, input.end()) ;
                reverse_front.assign(reverse.begin(), reverse.begin()+i) ;
                // cout << "---" << endl ;
                // cout << input_back << endl ;
                // cout << reverse_front << endl ;
                if(input_back.compare(reverse_front)==0){
                    index = i ;
                    break ;
                }
            }
            // cout << index << endl ;
            input.append(reverse.begin()+index, reverse.end()) ;
            cout << input << endl ;
        }
    }
    return 0 ;
}