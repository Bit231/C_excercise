#include<stdlib.h>
#include<stdio.h>

char *read_line(void){
    char tmp[2000];
    scanf("%[^\n]", tmp);
    return tmp;
}
int main(){
    char stringa[2000];

    stringa=*read_line();

}