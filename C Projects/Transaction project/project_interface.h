#ifndef MAIN_INTERFACE_H
#define MAIN_INTERFACE_H

/*Function prototypes*/

//It fills the card data structure into the ST_transaction structure.
void fillCardData(ST_transaction *transaction);

//It reads the amount.
//It checks if the amount > maximum transaction Amount (5000.00)
//Then it saves the response as DECLINED and prints ”The transaction is DECLINED”
//Else do nothing.
void checkAmount(ST_transaction *transaction);

//It fills the transaction amount, maximum transaction amount and expiry date in the ST_transaction structure.
void fillTerminalData(ST_transaction *transaction);

//Reads the expiry and transaction dates from the transaction structure.
//It checks if the expiry date > than transaction date
//Then saves the response as DECLINED and prints ”The transaction is DECLINED”
//Else do nothing.
void checkExpiryDate(ST_transaction *transaction);

//It checks for the expiry date.
//It checks for balance.
//Saves the transaction data into the server array.
void saveTransactionIntoServer(ST_transaction *transaction);

//It reads the primary account number from the transaction structure.
//It searches for the primary account number into the account/balance array.
//If it is not exist
//Then saves the response as DECLINED and print ”The transaction is DECLINED”
//Else it checks if the transaction amount > account balance
//Then saves the response as DECLINED and print ”The transaction is DECLINED”
//Else saves the response as APPROVED and print ”The transaction is APPROVED”
void checkBalance(ST_transaction *transaction);

#endif