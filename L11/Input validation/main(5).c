#include <stdio.h>
#include <string.h>
int main(){
    char msg[] = "0101010101\n\r";
    _Bool input[128];
    unsigned int n = 0;
    printf("MESSAGE:\n  %s(C-string)",msg);
    for(int i = 0; i < strlen(msg); i++) {
        int s = sscanf(&msg[i], "%1u", (unsigned int*)&input[n]);
        if(s == 1) n++;
    }
    printf("\nINPUT:\n  ");
    for(int i = 0; i < n; i++)
        printf("%u", input[i]);
    printf("\n(_Bool array) ");   
    return 0;
}
