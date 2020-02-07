#include "payment.h"

ST_transaction _Transaction;

unsigned char Expiration_flag=1;
unsigned char Max_amount_flag=1;
unsigned char Account_check_flag=1;
unsigned char Terminal_check_flag=1;
unsigned char x=0;
int main(void)
{
	do
	{
		fillCardData(&transaction_var);
		fillTerminalData(&transaction_var);
		saveTransactionIntoServer(&transaction_var);

		printf("Do you want to continue (y/n)?:\n");
		scanf(" %c",&x);
	} while (x == 'y' || x == 'Y');

	return 0;
}