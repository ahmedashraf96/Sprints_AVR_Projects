#ifndef PAYMENT_H
#define PAYMENT_H

#include <stdio.h>
#include <string.h>

void fillCardData(ST_transaction *transaction);
void checkAmount(ST_transaction *transaction);
void fillTerminalData(ST_transaction *transaction);
void checkExpiryDate(ST_transaction *transaction);
void saveTransactionIntoServer(ST_transaction *transaction);
void checkBalance(ST_transaction *transaction);


typedef enum EN_transStat
{
	DECLINED = 0,
	APPROVED
}EN_transStat;

typedef struct ST_serverData
{
	EN_transStat transactionStatus;
	unsigned int receiptReferenceNumber;
}ST_serverData;

typedef struct ST_terminalData
{
	unsigned char transAmount[8];
	unsigned char maxTransAmount[8];
	unsigned char transactionDate[11];
}ST_terminalData;

typedef struct ST_cardData
{
	unsigned char cardHolderName[25];
	unsigned char primaryAccountNumber[19];
	unsigned char cardExpirationDate[6];
}ST_cardData;

typedef struct ST_accountBalance
{
	unsigned char primaryAccountNumber[19];
	unsigned char balance[8];
}ST_accountBalance;

typedef struct ST_transaction
{
	ST_cardData cardHolderData;
	ST_terminalData transData;
	ST_serverData transResponse;
}ST_transaction;


#endif