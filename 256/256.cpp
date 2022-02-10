#include <cstdio>
#include <iostream>
#include <map>
#include <iomanip>

using namespace std ;


int main(){
    int number_digits ;
    unsigned int from = 0 ;
    unsigned int end ;
    int first ;
    int second ;
    unsigned int mutlipy ;
    unsigned int mutlipy_1 ;
    map<int, unsigned int> find_where = {{2, 9,}, {4, 99,}, {6, 999}, {8, 9999}};
    map<int, int> exp_term = {{2, 10,}, {4, 100,}, {6, 1000}, {8, 10000}};
    while(scanf("%d ", &number_digits)!=EOF){
        end = find_where[number_digits] ;
        for(int i=0; i<=end; i++){
            mutlipy = i * i ;
            first = mutlipy/exp_term[number_digits] ;
            second = mutlipy%exp_term[number_digits] ;
            mutlipy_1 = (first+second)*(first+second) ;
            if (mutlipy_1==mutlipy){                
                cout<<setfill('0')<<setw(number_digits)<<mutlipy<<endl;                
            }
        }
    }
}