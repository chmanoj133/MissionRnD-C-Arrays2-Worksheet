/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

int* date_divided(char* date);
int smaller_date_is(char *date1, char* date2);
void stringcopy(char *target, char *source);

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) 
{
	int i = 0, j = 0, flag, len = 0;
	struct transaction *result = NULL;

	if (A == NULL || ALen <= 0 || B == NULL || BLen <= 0)
		return NULL;

	while (i < ALen || j < BLen)
	{
		if (i == ALen)
			flag = 2;
		else if (j == BLen)
			flag = 1;
		else
			flag = smaller_date_is(A[i].date, B[j].date);

		if (flag == 1)
		{
			len++;
			result = (struct transaction*)realloc(result, len*sizeof(struct transaction));
			result[len - 1].amount = A[i].amount;
			stringcopy(result[len - 1].date, A[i].date);
			stringcopy(result[len - 1].description, A[i].description);
			i++;
		}
		else if (flag == 2)
		{
			len++;
			result = (struct transaction*)realloc(result, len*sizeof(struct transaction));
			result[len - 1].amount = B[j].amount;
			stringcopy(result[len - 1].date, B[j].date);
			stringcopy(result[len - 1].description, B[j].description);
			j++;
		}
		else
		{
			len++;
			result = (struct transaction*)realloc(result, len*sizeof(struct transaction));
			result[len - 1].amount = A[i].amount;
			stringcopy(result[len - 1].date, A[i].date);
			stringcopy(result[len - 1].description, A[i].description);
			
			len++;
			result = (struct transaction*)realloc(result, len*sizeof(struct transaction));
			result[len - 1].amount = B[j].amount;
			stringcopy(result[len - 1].date, B[j].date);
			stringcopy(result[len - 1].description, B[j].description);
			i++;
			j++;
		}
	}

	return result;
}

int smaller_date_is(char *date1, char* date2)
{
	int *d1 = date_divided(date1), *d2 = date_divided(date2);
	int d = 0, m = 1, y = 2;

	if (d1[y] < d2[y])
		return 1;
	else if (d1[y] > d2[y])
		return 2;
	else
	{
		if (d1[m] < d2[m])
			return 1;
		else if (d1[m] > d2[m])
			return 2;
		else
		{
			if (d1[d] < d2[d])
				return 1;
			else if (d1[d] > d2[d])
				return 2;
			else
				return 0;
		}
	}
}

int* date_divided(char* date)
{
	int i;
	int *ans = (int*)calloc(3, sizeof(int));
	ans[0] = (date[0] - '0') * 10 + (date[1] - '0');
	ans[1] = (date[3] - '0') * 10 + (date[4] - '0');
	ans[2] = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');
	return ans;
}

void stringcopy(char *target, char *source)
{
	while (*source) {
		*target = *source;
		source++;
		target++;
	}
	*target = '\0';
}