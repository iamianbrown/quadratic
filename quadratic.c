/*
	Find the roots of any quadratic function with solutions
	Ian Brown
	May 14 2020
*/

#include <stdio.h>
#include <math.h>
#include <string.h>

// Reverses a string 'str' of length 'len'
void reverse(char* str, int len)
{       
        int i = 0, j = len -1, temp;
        while (i < j)
        {       
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
                i++;
                j--;
        }
}

//converts an integer to a string, returns length of string
int intToStr(int x, char str[], int d)
{       
        int i = 0;
        while (x)
        {       
                str[i++] = (x % 10) + '0';
                x = x / 10;
        }
        
        // If number of digits required is more, then add 0s at the beginning
        while(i<d)
                str[i++] = '0';
        
        reverse(str, i);
        str[i] = '\0';
        
        return i;
}
// Converts a double number to a string
void dtoa(double n, char *res, int afterpoint)
{       
        // Extract integer part
        int ipart = (int)n;         

        // Extract floating part
        double dpart = n - (double)ipart;
 
        // convert integer part to string
        int i = intToStr(ipart, res, 0);
        
        // check for display option after point
        if (afterpoint != 0)
        {       
                res[i] = '.'; // add dot
                
                /* Get the value of fraction part up to the
                   given number of points after dot. The third 
                   parameter is needed to handle cases like 233.007
                */
                
		dpart = dpart * pow(10, afterpoint);
                intToStr((int)(dpart+.1), res + i + 1, afterpoint);
	}
}
void cutZeroes(char *str)
{       
        //initialize storage string
        char temp[15];

        
        //remove trailing zeroes 
        while(str[strlen(str)-1] == '0')
        {       
                strncpy(temp, str, strlen(str)-1);
                strcpy(str, temp); 
                memset(temp, '\0', sizeof(temp));
        }
	
	// remove '.' if number is whole
        if(str[strlen(str) - 1] == '.')
        {       
                strncpy(temp, str, strlen(str)-1);
                strcpy(str, temp); 
                memset(temp, '\0', sizeof(temp)); 
        }
}

int main()
{
	//initialize variables
	double a = 0.0, b = 0.0, c = 0.0, root1, root2; //a = coeff. of x^2 term, b = coeff. of x term, c = coeff. of const. term
	char signb, signc; //these will be the signs of b and c in the initial output
	
	//input
	printf("Input coefficient of x^2 term: ");
	scanf("%lf", &a);
	printf("\nInput coefficient of x term: ");
	scanf("%lf", &b);
	printf("\nInput coefficient of constant term: ");
	scanf("%lf", &c);
	
	//return input
	if(b > 0)
	{
		signb = '+';
	}
	else if(b < 0)
	{
		signb = '-';
	}
	if(c > 0)
        {                                                  
                signc = '+';
        }
        else if(c < 0)
        {
		signc = '-';
	}
	
	//initialize strings for input return
	char stra[20];
	char strb[20];
	char strc[20];
	
	//convert input doubles to strings
	//fabs function on b and c because they are
	//proceeded by a signed operator in the printf statement
	dtoa(a, stra, 6);
	dtoa(fabs(b), strb, 6);
	dtoa(fabs(c), strc, 6);

	//remove trailing zeroes from strings
	cutZeroes(stra);
	cutZeroes(strb);
	cutZeroes(strc);
	
	//print statements
	printf("\n\nYou have input the function f(x) = %sx^2 ", stra);
		
	if(b != 0)
		printf("%c %sx ", signb, strb);
	if(c != 0)
		printf("%c %s", signc, strc);
	
	//check for real solutions
	if(b*b - 4*a*c < 0)
		printf("\n\nThis equation has no real solutions.\n");
	
	//calculation and output
	else
	{
		root1 = (-1.0*b-sqrt(b*b-4*a*c)/(2*a));
		root2 = (-1.0*b+sqrt(b*b-4*a*c)/(2*a));
		printf("\n\nThe solutions of f(x) are %lf and %lf.\n", root1, root2);
	}
	return 0;
}
