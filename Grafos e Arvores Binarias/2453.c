#include <stdio.h>
#include <string.h>
int main(){
    char s[1100];
    while(fgets(s, sizeof(s), stdin)){
        int len = strlen(s);
        if(len && s[len-1]=='\n') s[len-1] = '\0';
        int i = 0;
        while(s[i]){
            if(s[i]==' '){
                putchar(' ');
                i++;
            } else {
                putchar(s[i+1]);
                i += 2;
            }
        }
        putchar('\n');
    }
    return 0;
}
