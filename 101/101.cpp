#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

void move_onto(int a, int b){
    printf("Move_onto\n") ;
}

void move_over(int a, int b){
    printf("Move_over\n") ;
}

void pile_onto(int a, int b){
    printf("pile_onto\n") ;
}

void pile_over(int a, int b){
    printf("pile_over\n") ;
}

int main(){
    int number ;
    if(scanf("%d", &number)!=EOF){
        printf("%d\n", number) ;
    }


    string s1 ;
    string s2 ;
    int a ;
    int b ;
    while(cin >> s1){
        cout << s1  << "\t";
        cout << typeid(s1).name() ;
        printf("\n") ;
        // move_onto(a, b) ;
    }
    return 0 ;
}