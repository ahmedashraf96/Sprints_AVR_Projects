#ifndef __APP_H__
#define __APP_H__

/*User defined data types*/
typedef uint8_t*  api_str_type;
typedef sint32_t  api_ret_type;

/*
* Description : Evaluate arithmetic expression without care of precedence.
* @param expresion to be evaluated
* @ret result of the expression
*/
api_ret_type evaluate(api_str_type expression);

#endif