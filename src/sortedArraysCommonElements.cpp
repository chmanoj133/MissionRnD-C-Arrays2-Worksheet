/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <stdlib.h>

bool stringcompare(char *str1, char *str2);
int stringlength(char *str);
void string_copy(char *target, char *source);

struct transaction {
	int amount;
	char date[11];
	char description[20];
};


struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) 
{
	int i, j, len = 0;
	struct transaction *result = NULL;

	if (A == NULL || B == NULL || ALen == NULL || BLen == NULL)
		return NULL;

	for (i = 0; i < ALen; i++)
		for (j = 0; j < BLen; j++)
		{
			if (stringcompare(A[i].date, B[j].date))
			{
				if (A[i].amount == B[j].amount && stringcompare(A[i].description, B[j].description))
				{
					len++;
					result = (struct transaction*)realloc(result, len*sizeof(struct transaction));
					result[len - 1].amount = A[i].amount;
					string_copy(result[len - 1].date, A[i].date);
					string_copy(result[len - 1].description, A[i].description);
				}
				// For the given testcases and question , this else is not needed.(special case)
				else
				{
					len++;
					result = (struct transaction*)realloc(result, len*sizeof(struct transaction));
					result[len - 1].amount = A[i].amount;
					string_copy(result[len - 1].date, A[i].date);
					string_copy(result[len - 1].description, A[i].description);
					len++;
					result = (struct transaction*)realloc(result, len*sizeof(struct transaction));
					result[len - 1].amount = B[j].amount;
					string_copy(result[len - 1].date, B[j].date);
					string_copy(result[len - 1].description, B[j].description);
				}
			}
		}
	return result;
}

// String comparsion
bool stringcompare(char *str1, char *str2)
{
	int i;
	int len = stringlength(str1);

	if (len != stringlength(str2))
		return false;

	for (i = 0; i < len; i++)
	{
		if (str1[i] != str2[i])
			return false;
	}
	return true;
}

void string_copy(char *target, char *source) 
{
	while (*source) {
		*target = *source;
		source++;
		target++;
	}
	*target = '\0';
}


// String length finder
int stringlength(char *str)
{
	int i;
	for (i = 0; str[i] != '\0'; i++);
	return i;
}