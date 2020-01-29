//
//  main.c
//  17d Final Answer With Recursion
//
//  Created by MC on 5/21/16.
//  Copyright © 2016 MEC. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int countString(char num[]);
void stringToNum (char num[]);


int i, decimalOccurrence = 0;
double result = 0;


int main(int argc, const char * argv[])
{
    int vartype;
    char num[] = "31417.876876";
//    int decLength = countString(num) - decimalOccurrence - 1;
//    printf("Original alphanumeric string is: \n %s\n", num);
      stringToNum(num);
    //Pass original alphanumeric string to function stringToNum.  The function
    //turns it into actual number that can be used for mathematical calculations
    
    return  0;
}

int countString(char num[])//Function counts string length
{
    int c = 0;
    while (num[c] != '\0')
    {
        c++;
    }
    //printf("The number of characters in the above string is %d\n\n", c);
    return c;
}


void stringToNum (char num[])
{
    int i, decimalOccurrence = 0;
    int len = countString(num);
//  int decLength = countString(num) - decimalOccurrence - 1;
    int vartype = 0;
    printf("Alphanumeric string is: \n %s\n", num);

    int n = (len - decimalOccurrence - 1);
//  printf("Alphanumeric string is: \n %s\n", num);
    
    //The algorithm below will look for a decimal point in the string. If one is found
    //it will move the decimal point the correct number of positions to the left after
    //the string is turned into a number by dividing by the correct power of 10.
    printf("Length is %d:  \n", len);
    
    for(i=0; i<countString(num); i++)
    {
        if( num[i] == '.'){
            result = result * 1.0 ;
            decimalOccurrence = i;//decimal occurs at this index in string array
        }//end of if
        
        else{
            result = result * 10 + (num[i] - '0' );
        }//end of else
       
    }//end of for

    
    if ((decimalOccurrence > 0))
    {
        n = (countString(num) - decimalOccurrence - 1);//n figures # of decimal places necessary to move left
        result = result/(pow(10, n)); //result becomes correct numeric after dividing by 10 to nth power
        printf("\nThe decimal point needs to move to the left by this number: %d\n", n);
    }
    else{
        result = result;
    }
    
    n = len - decimalOccurrence - 1;
    printf("\nDecimal occurence = %d:  \n", decimalOccurrence);
    printf("\nResult of alphanumeric after turned into a number type is \n %.*f \n\n", n , result);

/*
    switch(vartype)
    {
    case 0:
    printf("\nResult of alphanumeric after turned into a number type is \n %.*f \n\n", n , result);
            break;
            
    case 2:
    printf("\nResult of alphanumeric after turned into a number type is \n %.*lf \n\n", n , result);
            break;
            
    case 3:
    printf("\nResult of alphanumeric after turned into a number type is \n %d \n\n", result);
            break;
            
    case 4:
    printf("\nResult of alphanumeric after turned into a number type is \n %lu \n\n",  result);
            break;
    }
 */

}
