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

bool strcmp(char *str1, char *str2);
int string_length(char *str);

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) 
{
	int i;

	if (Arr == NULL || len == NULL || date == NULL)
		return -1;

	for (i = len - 1; i >= 0; i--)
	{
		if (strcmp(Arr[i].date, date))
			break;
	}

	if (i == -1)
		return NULL;

	return len - i - 1;
}

bool strcmp(char *str1, char *str2)
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

int string_length(char *str){
	int i;
	for (i = 0; str[i] != '\0'; i++);
	return i;
}