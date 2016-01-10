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
int date_compare(char *date1, char* date2);
int* date_in_array(char* date);

struct transaction {
	int amount;
	char date[11];
	char description[20];
};


/*

// THIS IS NORMAL METHOD AND WORKS EVEN IF THE GIVEN INPUTS ARE NOT SORTED BUT IT HAS HIGH TIME COMPLEXITY O(N2)
// SO THIS IS NOT PREFERABLE IF GIVEN INPUTS ARE SORTED
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

*/



// THIS METHOD IS OF TIME COMPLEXITY O(ALen + BLen) . Hence this is preferred
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen)
{
	int i = 0, j = 0, date, len = 0;
	struct transaction *result = NULL;

	if (A == NULL || B == NULL || ALen == NULL || BLen == NULL)
		return NULL;
	
	while (i < ALen && j < BLen)
	{
		date = date_compare(A[i].date, B[j].date);

		if (date == 1)
			j++;
		else if (date == 2)
			i++;
		else
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
			i++;
			j++;
		}
	}


	return result;
}

int date_compare(char *date1, char* date2)
{
	int *d1 = date_in_array(date1), *d2 = date_in_array(date2);
	int d = 0, m = 1, y = 2;

	if (d1[y] > d2[y])
		return 1;
	else if (d1[y] < d2[y])
		return 2;
	else
	{
		if (d1[m] > d2[m])
			return 1;
		else if (d1[m] < d2[m])
			return 2;
		else
		{
			if (d1[d] > d2[d])
				return 1;
			else if (d1[d] < d2[d])
				return 2;
			else
				return 0;
		}
	}
}

// Date will be converted from string to array of d, m, y format
int* date_in_array(char* date)
{
	int i;
	int *ans = (int*)calloc(3, sizeof(int));
	ans[0] = (date[0] - '0') * 10 + (date[1] - '0');
	ans[1] = (date[3] - '0') * 10 + (date[4] - '0');
	ans[2] = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');
	return ans;
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