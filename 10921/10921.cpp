#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <typeinfo>

using namespace std ;

int main(){
    string a; 
    int hyphens ;
    int letters ;
    int Number ; 
    map<string, int> string_to_int= {{"A", 2,}, {"B", 2,}, {"C", 2,}, {"D", 3,}, {"E", 3,}, {"F", 3,}, {"G", 4,}, {"H", 4,}, {"I", 4,},
    {"J", 5,}, {"K", 5,}, {"L", 5,}, {"M", 6,}, {"N", 6,}, {"O", 6,}, {"P", 7,}, {"Q", 7,}, {"R", 7,}, {"S", 7,}, 
    {"T", 8,}, {"U", 8,}, {"V", 8,}, {"W", 9,}, {"X", 9,}, {"Y", 9,}, {"Z", 9,}, {"1", 1,}, {"0", 0,}, {"-", 100}
    };
    while(cin>>a){
        // printf("================\n");
        hyphens = 0 ;
        letters = 0 ;

        for(int i=0; a[i] != '\0'; i++){
            // printf("%c", a[i]);
            string temp ;
            // cout<< a[i] ;
            temp = temp + a[i] ;
            // cout << temp ; 
            Number = string_to_int[temp] ;
            if(Number!=100){
                cout <<Number ; 
            }
            else{
                cout << "-" ;
            }
            // cout << typeid(temp).name() ;
        }
        // printf("%s\n", a.c_str());
        printf("\n");
    }
    
}