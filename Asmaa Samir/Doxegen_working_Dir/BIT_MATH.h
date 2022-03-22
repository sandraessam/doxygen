/** @file BIT_MATH.h
 *
 *	macros for defining all math functions used on bit operations
 *
 *  Created on: 14/01/2022
 *      @author AsmaaSamir
 */


#ifndef BIT_MATH_H_
#define BIT_MATH_H_


/** @brief change value of bit
 *
 * function to toggle bit from 1 to 0 and from 0 to 1.
 * function takes the register and number of bits from 0 to 7.
 *
 * @param VAR variable that need to change the bit on it
 * @param BITNO the number of bit in the variable
 * @return Should not return
 */
#define TOGGLE_BIT(VAR,BITNO) VAR^=(1<<BITNO)


/** @brief put zero
 *
 * function to clear a bit or to set a bit with value=0.
 * function take the register and number of bits from 0 to 7.
 *
 * @param VAR variable that need to change the bit on it
 * @param BITNO the number of bit in the variable
 * @return Should not return
 */
#define CLR_BIT(VAR,BITNO) VAR&=(~(1<<BITNO))


/** @brief put one
 *
 * function to set the value of bit by 1.
 * function takes the register and number bits a bit from 0 to 7.
 *
 * @param VAR variable that need to change the bit on it
 * @param BITNO the number of bit in the variable
 * @return Should not return
 */
#define SET_BIT(VAR,BITNO) VAR|=(1<<BITNO)


/** @brief know value of bit
 *
 * function to get the value of the specificity in the register.
 * function takes the register and number of bits from 0 to 7.
 *
 * @param VAR variable that need to change the bit on it
 * @param BITNO the number of bit in the variable
 * @return Should not return
 */
#define GET_BIT(VAR,BITNO) (((VAR) >> (BITNO)) & 0x01)


#endif /* BIT_MATH_H_ */
