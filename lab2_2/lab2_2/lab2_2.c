/* File: lab2_2.c */
/* Alexander Ustyuzhanin, IE SO1 group 1, WS14, 13.10.2014 */

#define _CRT_SECURE_NO_WARNINGS													// suppress warnings about unsafe scanf (C4996)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	char op1 = 0;																// stores the first part of the operator
	char op2 = 0;																// stores the second part of the operator (if present)
	char isE = 0;																// exit condition for the cycle
	signed short operand1;														// stores the first operand
	signed short operand2;														// stores the second operand
	signed short res;															// stores the result

	do
	{
		printf("============================== Lab 2 Assignment 2 ==============================\n");
		printf("** Test of some operators:\n\n");
		printf("Addition  +\nIncrement ++\n\n");
		printf("Enter a valid operator or 'e' or 'E' to terminate program: ");
		fflush(stdin);
		scanf("%c%c", &op1, &op2);
		printf("Input finished, desired operator is %c%c\n", op1, op2);
		if(op2 == 10)
		{
			switch(op1)
			{
				case 'e':
				case 'E':
				{
					isE = 1;
					printf("Exiting!\n");	
					break;
				}
				case '+':
				{
					printf("Enter the operands: ");
					fflush(stdin);
					if((scanf("%hi %hi", &operand1, &operand2)) == 2)
					{
						res = operand1 + operand2;
						printf("%hi + %hi results in %hi, in HEX %#x\n\n", operand1, operand2, res, res);	
					}
					else
					{
						printf("Sorry, could not recognise the operands. Try again.\n\n");
					}
					break;
				}
				default:
				{
					printf("Operator not recognised. Please try again.\n\n");
					break;
				}
			}
		}
		else
		{
			if(op2 == '+')
			{
				printf("Enter the operand: ");
				fflush(stdin);
				if((scanf("%hi", &operand1)) == 1)
				{
					res = operand1+1;
					printf("%hi++ results in %hi, in HEX %#x\n\n", operand1, res, res);
				}
				else
				{
					printf("Sorry, could not recognise the operands. Please try again.\n\n");
				}	
			}
			else
			{
				printf("Operator not recognised. Please try again.\n\n");
			}
		}
	}
	while(!isE);

	system("pause");
	return 0;
}