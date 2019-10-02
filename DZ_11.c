#include <stdio.h>
#include <math.h>
#include <locale.h>


long long convertDecimalToBinary(int n){
	long long bin=0;
	int rem, i=1, count=1;
	
	while(n!=0){
		rem=n%2;
		n /= 2;
		bin +=rem*i;
		i *= 10;
	}
	return bin;
}


int main(){
	setlocale(LC_ALL, "Rus");
	long long n;
	printf("¬ведите дес€тичное число: ");
	scanf("%d", &n);
	printf("%d (в дес€тичной) = %lld (в двоичной) \n", n, convertDecimalToBinary(n));
	
	return 0;
}
