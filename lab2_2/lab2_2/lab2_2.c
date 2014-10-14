/* File: lab2_2.c */
/* Alexander Ustyuzhanin, IE SO1 group 1, WS14, 13.10.2014 */

#define _CRT_SECURE_NO_WARNINGS													// suppress warnings about unsafe scanf (C4996)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ASCII_LF 10																// no magic numbers, right?

int main()
{
	char op1 = 0;																// stores the first part of the operator
	char op2 = 0;																// stores the second part of the operator (if present)
	char isE = 0;																// exit condition for the cycle
	signed short operand1;														// stores the first operand
	signed short operand2;														// stores the second operand
	signed short res;															// stores the result

	do																			// the main cycle
	{
		printf("============================== Lab 2 Assignment 2 ==============================\n");
		printf("** Test of some operators:\n\n");
		printf("Addition  +\nIncrement ++\n\n");
		printf("Enter a valid operator or 'e' or 'E' to terminate program: ");
		fflush(stdin);
		scanf("%c%c", &op1, &op2);												// get desired operators from user
		printf("Input finished, desired operator is %c%c\n", op1, op2);
		if(op2 == ASCII_LF)														// if second operator was LINE FEED, then the user had entered only one operator
		{
			switch(op1)															// we determine what exactly was that operator
			{
				case 'e':
				case 'E':
				{
					isE = 1;													// set the cycle exit condtion
					printf("Exiting!\n");
					break;
				}
				case '+':
				{
					printf("Enter the operands: ");
					fflush(stdin);
					if((scanf("%hi %hi", &operand1, &operand2)) == 2)			// plus requires two operands. Get them from the user, check if both are entered correctly (return value from scanf should be 2)
					{
						res = operand1 + operand2;
						printf("%hi + %hi results in %hi, in HEX %#x\n\n", operand1, operand2, res, res);
					}
					else
					{
						printf("Sorry, could not recognise the operands. Try again.\n\n");	// if scanf didn't return 2, this means that at least one of the operands was entered incorrectly
					}
					break;
				}
				default:														// if the first operator is not e, E or + and the second was LINE FEED, notify the user that he failed to input a correct operand
				{
					printf("Operator not recognised. Please try again.\n\n");
					break;
				}
			}
		}
		else																	// so the second operator is not LINE FEED
		{
			if(op1=='+')														// this however doesn't mean that the first one was plus. Check that
			{
				if(op2 == '+')													// if the second operator is plus and the first one is plus
				{
					printf("Enter the operand: ");
					fflush(stdin);
					if((scanf("%hi", &operand1)) == 1)							// we ask the user to enter only one operand and therefore expect scanf to return 1
					{
						res = operand1+1;
						printf("%hi++ results in %hi, in HEX %#x\n\n", operand1, res, res);
					}
					else														// if scanf didn't return 1, then the operand wasn't correctly read from the input
					{
						printf("Sorry, could not recognise the operands. Please try again.\n\n");
					}	
				}
				else															// if the second operator was not +, then it's invalid input. Notify the user
				{
					printf("Operator not recognised. Please try again.\n\n");
				}
			}
			else																// if the first operator was not +, then it's invalid input. Notify the user
			{
				printf("Operator not recognised. Please try again.\n\n");
			}
		}
	}
	while(!isE);																// the cycle continues until isE is set to 1

	system("pause");
	return 0;
}