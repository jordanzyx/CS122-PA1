/*******************************************************************************************
* Programmer: Jordan Muehlbayer *
* Class: CptS 122, Spring, 2019;
* Programming Assignment: PA1 *
* Date: January 24, 2020 *
* Description: definition of structs and functions to be implemented in source.c *
*******************************************************************************************/
#include <stdio.h>

#ifndef PA1_SOURCE_H
#define PA1_SOURCE_H

typedef enum sleep
{
    NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

typedef struct fitbit
{
    char patient[10];
    char minute[9];
    double calories;
    double distance;
    unsigned int floors;
    unsigned int heartRate;
    unsigned int steps;
    Sleep sleepLevel;
} FitbitData;

FILE* loadFitBitFile(FILE *file);
FILE* loadResultFile(FILE *file);
void collectStats(FILE *file,FitbitData data[1440]);
void analyzeLine(char line[256],FitbitData data[1440]);
void getCsv(char line[256], char new[256], int index);
int getIndexOfComma(char line[256],int number);
void subString(char line[256], char new[256], int s,int e);
void defineArray(FitbitData data[1440]);
void clearString(char string[256]);
void analyzeData(FitbitData data[1440],double *calsBurned,double *distance,int *floors,int *steps,double *heartRate,int *maxSteps,char *sleepS,char *sleepE);
void outputData(double calsBurned,double distance,int floors,int steps,double heartRate,int maxSteps,char *sleepS,char *sleepE,FILE *output);
int getIndexOfColon(char str[9]);


#endif //PA1_SOURCE_H
