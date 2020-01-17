//
// Created by Jordan Muehlbauer on 1/16/20.
//
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
void collectStats(FILE *file);
void analyzeLine(char line[256]);


#endif //PA1_SOURCE_H
