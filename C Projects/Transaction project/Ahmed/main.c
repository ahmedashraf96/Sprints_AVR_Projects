#include "payment.h"

ST_transaction transaction_var;

u8_t process = 0;

int main(void)
{
	do
	{
		fillCardData(&transaction_var);
		fillTerminalData(&transaction_var);
		saveTransactionIntoServer(&transaction_var);

		printf("Do you want to continue (y/n)?:\n");
		scanf(" %c",&process);
	} while (process == 'y' || process == 'Y');

	return 0;
}