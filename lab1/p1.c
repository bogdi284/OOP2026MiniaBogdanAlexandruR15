#include <stdio.h>

int conversie (char* s) {
    int res = 0 , i = 0 ;
    while (s[i]>='0' && s[i]<='9') {
        res = res * 10 + (s[i] - '0') ;
        i++;
    }
    return res;
}
int main () {
    FILE *f ;
    f = fopen ("ini.txt" , "r");
    int s = 0 ;
    char l[256];
    while (fgets(l , 256 , f)) {
        int aux = conversie (l) ;
        s = s + aux ;
    }
    fclose (f);
    printf("%d" , s);
    return 0;
}