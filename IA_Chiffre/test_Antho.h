#pragma once
#ifndef _TEST_ANTHO_H_
#define _TEST_ANTHO_H_

#include <stdio.h>  /*FILE, fopen, puts, printf*/
#include <stdlib.h> /*EXIT_SUCCESS*/

#include "csv_image.h"
#include "saveBMP.h"
#include "reseau.h"



void test_Antho(void);
void test_GetLine(void);
void test_parametersImages(void);
void test_loadImage(void);
void test_saveBMP(void);
void test_load_dataBase(void);
void test_load_neuralNetwork(void);
void test_feedforward(void);
void test(void);

NETWORK* load_neuralNetwork(FILE* stream);

#endif // !_TEST_ANTHO_H_
