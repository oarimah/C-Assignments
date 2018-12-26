#include<stdio.h>
#include<math.h>
long double calculatePi(double);

int main()
{
    double a;
    long double pi;
    printf("Enter the number: ");
    scanf("%lf", &a);
    pi = calculatePi(a);
    printf("\nValue of pie is: %Lf\n", pi);
}
/* function to calculate and return the calculated value of pi*/
long double calculatePi(double a)
{
    int i = 1;
    long double value = 0;
    long double calculated_pi = 0;
    long double calc_number = 1;

    while(calc_number >= a)
    {
        value = (long double)pow(-1, ((long double)i+1)) * 4/(2*(long double)i - 1);
        calculated_pi += value;
        calc_number = 4 / (2*((long double)i + 1) - 1);
        i++;
    }
    return calculated_pi;
}
