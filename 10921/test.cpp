#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>

int main(){

    char *c = (char *)malloc(10000*sizeof(char));
    // char c[30] ;
    c[0] = '0' ;
    printf("%p %c %p \n", c, *c, &c);
    // free(c) ; 
}
