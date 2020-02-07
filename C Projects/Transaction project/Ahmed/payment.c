#include "payment.h"

/*Total number of trasnsactions*/
ST_transaction Total_Transactions[255] = {0};

/*Total number of accounts ----> [Primary account number , Balance]*/
ST_accountBalance Accounts[10] = {{"123456789","0100.00"},
								  {"234567891","6000.00"},
								  {"567891234","3250.25"},
								  {"456789123","1500.12"},
								  {"258649173","0500.00"},
								  {"654823719","2100.00"},
								  {"971362485","0000.00"},
								  {"793148625","0001.00"},
								  {"123123456","0010.12"},
								  {"456789321","0000.55"}};

/*State of the transactions*/
EN_transStat transaction_state = DECLINED;   

/*Receipt refrence number*/
u16_t refrence_number = 0;

u16_t trans_arr = 0;

/*Operation flags*/
u8_t expiry_flag = 1;
u8_t maximum_amount_flag = 1;
u8_t account_check_flag  = 1;
u8_t terminal_check_flag  = 1;


void fillCardData(ST_transaction *transaction)
{
    printf("Please Enter Card Data:\n");
    printf("Please Enter the Card Holder Name:\n");
    fgets((transaction -> cardHolderData).cardHolderName,sizeof((transaction -> cardHolderData).cardHolderName),stdin);
    
    printf("Please Enter the Primary Account Number:\n");
    scanf("%s",(transaction -> cardHolderData).primaryAccountNumber);
    
    printf("Please card Expiry Date:\n");
    scanf("%s",(transaction -> cardHolderData).cardExpirationDate);

    refrence_number++;

    return;
}

void checkAmount(ST_transaction *transaction)
{
    strcpy((transaction -> transData).maxTransAmount , "5000.00");

    for(u8_t i = 0 ; i < MAXIMUM_AMOUNT_DIGITS ; i++)
    {
        if( ((transaction -> transData).transAmount[i] - '0') < ((transaction -> transData).maxTransAmount[i] - '0') )
        {
            break;
        }
        else if (((transaction -> transData).transAmount[i] - '0') > ((transaction -> transData).maxTransAmount[i] - '0') )
        {
            (transaction ->transResponse).transactionStatus = DECLINED;
            (transaction ->transResponse).receiptReferenceNumber = refrence_number;
            printf("Transaction is DECLINED!\n");
            maximum_amount_flag = 1;
            return;
        }
        else
        {
            //Do nothing
        }
    }
    maximum_amount_flag = 0;
    return;
}

void fillTerminalData(ST_transaction *transaction)
{
    printf("Please Enter Terminal Data:\n");
    printf("Please Enter the transaction Amount:\n");
    scanf("%s",(transaction -> transData).transAmount);

    checkAmount(transaction);

    if(maximum_amount_flag)
    {
        terminal_check_flag = 1;
        return;
    }
    else
    {
        printf("Please Enter Transaction Date:\n");
        scanf("%s",(transaction -> transData).transactionDate);
    }
    terminal_check_flag = 0;
    return;
}

void checkExpiryDate(ST_transaction *transaction)
{ 
    //Transaction date format : DD/MM/YYYY
    u16_t month_transaction = ((transaction -> transData).transactionDate[3] - '0') * 10 + ((transaction -> transData).transactionDate[4] - '0');
    u16_t year_transaction  = ((transaction -> transData).transactionDate[8] - '0') * 10 + ((transaction -> transData).transactionDate[9] - '0');
	
    //Expiry date format : MM/YY
    u16_t month_expiry = ((transaction -> cardHolderData).cardExpirationDate[0] - '0') * 10 + ((transaction -> cardHolderData).cardExpirationDate[1] - '0');
    u16_t year_expiry  = ((transaction -> cardHolderData).cardExpirationDate[3] - '0') * 10 + ((transaction -> cardHolderData).cardExpirationDate[4] - '0');
	
    if(year_transaction > year_expiry)
    {
        (transaction ->transResponse).transactionStatus = DECLINED;
        printf("Transaction is DECLINED!\n");
        expiry_flag = 1;
        return;
    }
    else if(month_transaction > month_expiry)
    {
        (transaction ->transResponse).transactionStatus = DECLINED;
        printf("Transaction is DECLINED!\n");
        expiry_flag = 1;
        return;
    }
    expiry_flag = 0;
    return;
}

void saveTransactionIntoServer(ST_transaction *transaction)
{
    if(terminal_check_flag)
    {
        Total_Transactions[trans_arr] = *transaction;
        trans_arr++;
        return;
    }
    else
    {
        //Do nothing   
    }
    
    checkExpiryDate(transaction);

    if(expiry_flag)
    {
        Total_Transactions[trans_arr] = *transaction;
        trans_arr++;
        return;
    }
    else
    {
        checkBalance(transaction);

        if(account_check_flag)
        {
            Total_Transactions[trans_arr] = *transaction;
            trans_arr++;
            return;
        }
        else
        {
            
        }
        
    }
    Total_Transactions[trans_arr] = *transaction;
    trans_arr++;
    return;
}

void checkBalance(ST_transaction *transaction)
{
	s8_t account_num = -1;
    for(u8_t i = 0 ; i < MAXIMUM_ACCOUNTS ; i++)
    {
        if(strcmp((transaction -> cardHolderData).primaryAccountNumber , Accounts[i].primaryAccountNumber) == 0)
        {
			account_num = i;
			break;
        }
        else
        {
            //Do nothing   
        }
        
    }
	
	if(account_num >= 0)
	{
		for(u8_t i = 0 ; i < MAXIMUM_AMOUNT_DIGITS ; i++)
		{
			if( ((transaction ->transData).transAmount[i] - '0') < (Accounts[account_num].balance[i] - '0') )
			{
				break;
			}
			else if ( ((transaction ->transData).transAmount[i] - '0') > (Accounts[account_num].balance[i] - '0') ) 
			{
				(transaction ->transResponse).transactionStatus = DECLINED;
				printf("The transaction is DECLINED\n");
				account_check_flag = 1;
				return;
			}
			else
			{
				
			}
			
		}

	}
	else
	{
		(transaction ->transResponse).transactionStatus = DECLINED;
		printf("The transaction is DECLINED\n");
		account_check_flag = 1;
		return;    

	}

	(transaction ->transResponse).transactionStatus = APPROVED;
    printf("The transaction is APPROVED\n");
    account_check_flag = 0;
    return;		
}