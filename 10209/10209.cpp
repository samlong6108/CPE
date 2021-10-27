#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std ; 

int main(){
    double input ;
    double input2 ;
    double a, b, c ;
    double pi = M_PI ;
    while(scanf("%lf", &input)!=EOF){
        // cout << "=========" << endl ;
        // cout << input << endl ;
        input2 = input*input ; 
        // cout << input2 << endl ;
        c = input2 - sqrt(3) * input2 / 4 - input2 * pi /6 ;
        b = input2 * pi - 3 * input2 + 4*c ;
        a = (input2 - b - 4*c)/4 ;
        // cout << roundf(b  << " " << 4*a << " " << 4*c << endl ;
        printf("%.3f %.3f %.3f\n", b, 4*a, 4*c) ;
    }
}