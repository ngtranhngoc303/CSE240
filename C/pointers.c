#include <stdio.h>

int main(){
    int b;
    b = 255;
    printf("%x ", *((unsigned char*)&b+0));
    printf("%x ", *((unsigned char*)&b+1));
    printf("%x ", *((unsigned char*)&b+2));
    printf("%x ", *((unsigned char*)&b+3));
}