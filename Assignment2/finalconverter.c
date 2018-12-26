#include <stdio.h>

void inputChoice(char *c);//input reader
int main(){
int chr;
printf("Welcome to Converter");
do{
printf("\n Enter 1 for conversion between Kilometer and Mile.");
printf("\n Enter 2 for conversion between Meter and Feet.");
printf("\n Enter 3 for conversion between Centimeter and Inch.");
printf("\n Enter 4 for conversion between Celsius and Fahrenheit.");
printf("\n Enter 5 to exit.");
printf("\n Enter your choice: ");
scanf("%d",&chr);// scan the number entered and save it under chrs

switch(chr){// use switch function to activate the cases

case 1:
printf("\nEnter K for conversion from Kilometer to Mile. Enter M for conversion from Mile to Kilometer: ");
char cKMM;//convert Kilometer to Mile
scanf(" %c",&cKMM);//scan the character entered
if(cKMM == 'K'){// if K is entered calculate mile
float kilometer;
printf("\nEnter Kilometer value to convert to mile: ");
scanf("%f",&kilometer);
float calcMile = kilometer * 0.62137119;
printf("%0.2f kilometer is equal to %0.2f mile.\n\n",kilometer,calcMile);
}
else if(cKMM == 'M'){//if M is entered calculate km
float mile;
printf("\nEnter mile value to convert to kilometer: ");
scanf("%f",&mile);
float calcKilo = mile *1.60934;
printf("%0.2f mile is equal to %0.2f kilometer.\n\n",mile,calcKilo);
}
else{
printf("Invalid input");// if K or M is not entered then print
}
break;
case 2://same format followed in case 1

printf("\nEnter M for conversion from meter to feet. Enter F for conversion from feet to meter: ");
char cMF;
scanf(" %c",&cMF);
if(cMF == 'M'){
float meter;
printf("\nEnter meter value to convert to feet: ");
scanf("%f",&cMF);
float calcFeet = meter *3.2808399;
printf("%0.2f meter is equal to %0.2f feet.\n\n",meter,calcFeet);
}
else if(cMF =='F'){
float feet;
printf("\nEnter feet value to convert to meter: ");
scanf("%f",&feet);
float calcMeter = feet * 0.3048;
printf("%0.2f feet is equal to %0.2f meter.\n\n",feet,calcMeter);
}
else{
printf("Invalid input");
}

break;

case 3:// same format followed in case 1

printf("\nEnter C for conversion from centimetre to inch. Enter I for conversion from inch to centimetre: ");
char cCI;
scanf(" %c",&cCI);
if(cCI == 'C'){
float cm;
printf("\nEnter centimetre value to convert to inches: ");
scanf("%f",&cm);
float calcinch = cm * 0.323701;
printf("%0.2f centimetre is equal to %0.2f inches.\n\n",cm,calcinch);
}
else if(cCI=='I'){
float inch;
printf("\nEnter inch value to convert to centimetre: ");
scanf("%f",&inch);
float calccm = inch *2.54;
printf("%0.2f inch is equal to %0.2f centimeter.\n\n",inch,calccm);
}
else{
printf("Invalid input");
}
break;

case 4:// same format followed in case 1
printf("\nEnetr C for conversion from celsius to fahrenheit. Enter F for conversion from fahrenheit to celsius: ");
char cCF;
scanf(" %c",&cCF);
if(cCF== 'C'){
float celsius;
float calcfar;
printf("\nEnter celsius value to convert to fahrenheit: ");
scanf("%f",&celsius);
calcfar = ((celsius *9.0)/(5.0))+32;
printf("%0.2f celsius is equal to %0.2f fahrenheit.\n\n",celsius,calcfar);
}
else if(cCF=='F'){
float far;
printf("\nEnter fahrenheit value to convert to celsius: ");
scanf("%f",&far);
float calccel = ((far-32)*5.0)/(9.0);// convert far to cel
printf("%0.2f fahrenheit is equal to %0.2f celsius.\n\n",far,calccel);
}
else{
printf("Invalid input");
}
break;
case 5://if 5 is entered exit the program
return 0;
break;
}
}while(chr!=5);
return 0;
}

