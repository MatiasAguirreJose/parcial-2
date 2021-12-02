/*
 * Parser.h
 *
 *  Created on: 12 nov. 2021
 *      Author: Matias
 */


#ifndef PARSER_H_
#define PARSER_H_

int parser_ElibroFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EditorialFromText(FILE* pFile , LinkedList* pArrayListEmployee);

int parser_eEditorialFromText(FILE* pFile , LinkedList* pArrayListEmployee);

#endif /* PARSER_H_ */
