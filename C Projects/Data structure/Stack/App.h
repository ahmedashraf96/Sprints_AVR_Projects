#ifndef __APP_H__
#define __APP_H__

/*User defined macros*/
#define BALANCED_EXP    (1)
#define UNBALANCED_EXP  (0)

/*User efined data types*/
typedef uint8_t api_ret_type;
typedef uint8_t* api_str_type;

/*
* Description : Checks whether parentheses within application is balanced or not.
* @param expression or string to be checked
* @ret expression is balanced or not
*/
api_ret_type checkForBalancedParantheses(api_str_type expression);
#endif