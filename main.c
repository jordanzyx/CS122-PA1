/*******************************************************************************************
* Programmer: Jordan Muehlbayer *
* Class: CptS 122, Spring, 2019;
* Programming Assignment: PA1 *
* Date: January 24, 2020 *
* Description: This program computes information based on fitbit data. *
*******************************************************************************************/

#include <stdio.h>
#include "source.h"

int main() {
    //Create file variables
    FILE *input = NULL;
    FILE *output = NULL;

    //Create variables to be used when outputting to result.csv
    double calsBurned = 0;
    double totalDistance = 0;
    int totalFloors = 0;
    int totalSteps = 0;
    double heartRate = 0;
    int maxSteps = 0;
    char sleepS[9] = {};
    char sleepE[9] = {};

    //Create fitbit data array
    FitbitData data[1440] = {};

    //Set up default values for the array
    defineArray(data);

    //Attempt to load files
    input = loadFitBitFile(input);
    output = loadResultFile(output);

    //Collect statistics
    collectStats(input,data);

    //Analyze the data
    analyzeData(data,&calsBurned,&totalDistance,&totalFloors,&totalSteps,&heartRate,&maxSteps,sleepS,sleepE);

    //Output the data
    outputData(calsBurned,totalDistance,totalFloors,totalSteps,heartRate,maxSteps,sleepS,sleepE,output);

    //Close files
    fclose(input);
    fclose(output);

    return 0;
}
