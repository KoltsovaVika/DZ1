#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
	
    int n, i;
    printf("Amount of elements: ");
    scanf("%d", &n); getchar();
    char *bin1[n];
    for(i = 0; i < n; i++)
        bin1[i] = calloc(1, sizeof(char));
        
    int a = 0, b = 0, flag = 1;
    char c;
    printf("Enter %d element: ",a+1);
    while( flag == 1 && (c=getchar()) != EOF){
        if((c >=  '0' && c <= '9') || (c == '-' && b == 0)){
            bin1[a][b] = c;
            b++;
            bin1[a] = (char*) realloc(bin1[a], b+1);
        } else if (c == '\n'){
            if(a+2 <= n)
                printf("Enter %d element: ",a+2);
            
            bin1[a] = (char*) realloc(bin1[a], b+1);
            bin1[a][b] = '\0';
            a++;
            b=0;
        }
        if (a >= n){
            flag = 0;
        }
    }
    
    i=0;
    long int *bin1_temp;
    bin1_temp = calloc(n, sizeof(long int));
    for(i; i < n; i++){
        bin1_temp[i] = 0;
        int sgnd = 0, j = 0;
        if(bin1[i][0] == '-'){
            sgnd=1; j++;
        }
        
        while(bin1[i][j] != '\0'){
            bin1_temp[i] *= 10;
            bin1_temp[i] += bin1[i][j] - '0';
            j++;
        }
        
        if(sgnd == 1)
            bin1_temp[i]*=-1;
    }
    
    
    char *dec2[n];
    
    
    i=0;
    for(i; i< n; i++){
        int j = 0;
        dec2[i] = calloc(1, sizeof(char));
        
        if(bin1_temp[i] < 0){
            dec2[i][0] = '-';
            dec2[i] = (char*) realloc(dec2[i], j+2);
            bin1_temp[i]*=-1;
            j++;
        }
        
        while(bin1_temp[i] != '\0'){
            
            
            dec2[i][j] = '0' + (bin1_temp[i]%2);
            
            bin1_temp[i] /= 2;
            
            dec2[i] = (char*) realloc(dec2[i], j+2);
            j++;
        }
        dec2[i][j] = '\0';
        dec2[i] = (char*) realloc(dec2[i], j+1);
        
        
        
        
        
    }
    
    
    
    
    for(i=0; i< n; i++){
        printf( "in dec %s -> in bin %s\n", bin1[i], dec2[i]);
        
    }
    
    
    return 0;
}
