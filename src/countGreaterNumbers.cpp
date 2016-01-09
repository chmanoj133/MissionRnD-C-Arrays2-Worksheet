/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>

bool string_compare(char *str1, char *str2);
int string_length(char *str);
int* date_in_int(char* date);

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

/*

// This is linear search ! For less number of bank statements , it is preferred
int countGreaterNumbers(struct transaction *Arr, int len, char *date) 
{
	int i;

	// Here date validation can be done and can return NULL when ever a date is invalid
	// It is skipped to reduce time complexity
	if (Arr == NULL || len == NULL || date == NULL)
		return NULL;

	for (i = len - 1; i >= 0; i--)
	{
		if (string_compare(Arr[i].date, date))
			break;
	}

	if (i == -1)
		return NULL;

	return len - i - 1;
}

*/


/* Since in real, there will be high number of bank transitions, linear search is not preferable*/
/* THIS CAN BE OPTIMISED BY FIBONACCI SEARCH , BINARY SEARCH etc..*/
/* FOLLOWING CODE IS THE BINARY SEARCH IMPLEMENTATION (faster)*/

int countGreaterNumbers(struct transaction *Arr, int len, char *date)
{
	int i, *date1, *date2, d = 0, m = 1, y = 2, left = 0, right = len - 1;
	bool found = false;

	// Here date validation can be done and can return NULL when ever a date is invalid
	// It is skipped to reduce time complexity
	if (Arr == NULL || len == NULL || date == NULL)
		return NULL;

	date1 = date_in_int(date);

	while (left <= right)
	{
		i = (right + left) / 2;
		date2 = date_in_int(Arr[i].date);
		if (date1[y] == date2[y])
		{
			if (date1[m] == date2[m])
			{
				if (date1[d] == date2[d])
				{
					found = true;
					break;
				}
				else
				{
					if (date1[d] > date2[d])
						left = i + 1;
					else
						right = i - 1;
				}
			}
			else
			{
				if (date1[m] > date2[m])
					left = i + 1;
				else
					right = i - 1;
			}

		}
		else
		{
			if (date1[y] > date2[y])
				left = i + 1;
			else
				right = i - 1;
		}
	}

	// finding the last transition of that date
	if (found == true)
	{
		// This can also be optimised by incrementing i in powers of 2 but in general, 
		// Daily transitions are limited to small number of times, we can go with linear search here
		while (string_compare(Arr[i].date, date))
			i++;
	}
	else
		return NULL;

	return len - i;
}

// date in string splitter
int* date_in_int(char* date)
{
	int i;
	int *ans = (int*)calloc(3, sizeof(int));
	ans[0] = (date[0]  - '0')* 10 + (date[1] - '0');
	ans[1] = (date[3] - '0') * 10 + (date[4] - '0');
	ans[2] = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10  + (date[9] - '0');
	return ans;
}


// String comparsion
bool string_compare(char *str1, char *str2)
{
	int i;
	int len = string_length(str1);
	if (len != string_length(str2))
		return false;
	for (i = 0; i < len; i++)
	{
		if (str1[i] != str2[i])
			return false;
	}
	return true;
}


// String length finder
int string_length(char *str){
	int i;
	for (i = 0; str[i] != '\0'; i++);
	return i;
}