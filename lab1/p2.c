#include <stdio.h>
#include <string.h>

int main () {
    char s[256] ;
    char v[100][100];
    int n = 0 , i = 0;

    fgets (s , sizeof (s) , stdin);

    while (s[i] != '\0') {
        while (s[i] == ' ') {
            i++;
        }
        if (s[i] == '\0') {
            break;
        }
        int j = 0 ;
        while (s[i] != ' ' && s[i] != '\0') {
            v[n][j] = s[i];
            j++ ;
            i++ ;
        }
        v[n][j] = '\0' ;
        n++ ;
    }

    for (int i = 0 ; i< n-1 ; i++) {
        for (int j=i+1 ; j<n ; j++) {
            if (strlen(v[i])<strlen(v[j])) {
                char temp[100];
                strcpy(temp , v[i]);
                strcpy(v[i] , v[j]);
                strcpy(v[j] , temp);
            }
        }
    }
    for (int i = 0 ; i < n ; i++) {
        printf("%s\n" , v[i]);
    }
    return 0 ;
}