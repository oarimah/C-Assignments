#include <stdio.h>
#define POSITIVE(n) ((n) < 0 ? 0 - (n) : (n))
float exponential(float base, int exponent);

int main(){
	float base;
	int exponent;
	int finalresult;

	printf("\nEnter a base: ");//ask user for a base
	scanf("%f",&base);

	printf("\nEnter an exponent: ");//ask user for an exponent
	scanf("%d",&exponent);
	
	if(base>0){// if base is greater that 0 perfrom the following calculation
	
	finalresult = exponential(base, exponent);

	printf("\n%f ^ %d = %d\n",base,exponent,finalresult);
	}else{
	printf("The base enetered must be a positive number");// if base is less that 0 print this statement
}

	return 0;
}
float exponential(float base, int exponent){
	if(exponent == 0){// if exponent is 0 return 1
	return 1;
}
	if(exponent == -1){
	return(1/base);
}
	
	float result;
	if (exponent<0){
	result= exponential(base,-(exponent));
	return (1.0/result);
}

	if(exponent%2==0){// if exponent is even then perfom the exponential recursive call but divide the exponent by 2
	result = exponential(base,(exponent/2));
	return result * result;
	
	}else{
	result = exponential(base,((exponent-1)/2));// if exponent is odd then perfom the exponential recursive vall but subtract the exponent by one then divde by two
	return result*result*base;
}}

