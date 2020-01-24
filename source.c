//
// Created by Jordan Muehlbauer on 1/16/20
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "source.h"

FILE* loadFitBitFile(FILE *file){
    //Attempt to load the file
    file = fopen("FitbitData.csv","r");

    //Check if the file opened successfully
    if(file == NULL){
        printf("Error while opening FitbitData.csv\n");
        system("exit");
        return file;
    }

    //Inform success
    printf("FitbitData.csv was successfully loaded\n");
    return file;
}

FILE* loadResultFile(FILE *file){
    //Attempt to load the file
    file = fopen("Result.csv","w");

    //Check if the file opened successfully
    if(file == NULL){
        printf("Error while opening Result.csv\n");
        system("exit");
        return file;
    }

    //Inform success
    printf("Result.csv was successfully loaded\n");
    return file;
}

void collectStats(FILE *file,FitbitData data[1440]){
    //Create local string to be analyzed
    char string[256] = {};

    //Skip the first line which is a template
    fgets(string,256,file);

    //Clear the string
    clearString(string);

    //Loop over each line of the csv file
    for (int j = 0; j < 1440; ++j) {
        //Collect line
        fgets(string,256,file);

        //Analyze the line
        analyzeLine(string,&data[j]);
    }

}

void analyzeData(FitbitData data[1440],double *calsBurned,double *distance,int *floors,int *steps,double *heartRate,int *maxSteps,char *sleepS,char *sleepE){
    //Collect totals for data

    //Create indexes for the longest range of sleep
    int start = 0;
    int end = 0;
    int sleepSum = 0;
    int tempStart = 0;
    int tempEnd = 0;
    int tempSum = 0;

    for (int i = 0; i < 1440; ++i) {
        //Get item at index
        FitbitData item = data[i];

        if(*maxSteps < item.steps)*maxSteps = item.steps;

        //Find sleep range
        if(item.sleepLevel >= 1){
            if(tempSum == 0)tempStart = i;
            tempSum += item.sleepLevel;
            tempEnd = i;

            if(tempSum > sleepSum){
                sleepSum = tempSum;
                start = tempStart;
                end = tempEnd;
            }
        }else tempSum = 0;


        //Add up totals for each field
        *calsBurned = *calsBurned + item.calories;
        *distance = *distance + item.distance;
        *floors = *floors + item.floors;
        *steps = *steps + item.steps;
        *heartRate = *heartRate + item.heartRate;
    }

    *heartRate = *heartRate / 1440;
    for (int j = 0; j < 9; ++j) {
        sleepS[j] = data[start].minute[j];
        sleepE[j] = data[end].minute[j];
    }

}

void outputData(double calsBurned,double distance,int floors,int steps,double heartRate,int maxSteps,char *sleepS,char *sleepE,FILE *output){
    fprintf(output,"Cals burned: %.2lf\n",calsBurned);
    fprintf(output,"Distance %.2lf\n",distance);
    fprintf(output,"Total Floors %d\n",floors);
    fprintf(output,"Total Steps %d\n",steps);
    fprintf(output,"Heartrate %.2lf\n",heartRate);
    fprintf(output,"Max steps %d\n",maxSteps);
    fprintf(output,"Poor sleep %s to %s\n",sleepS,sleepE);
}


void analyzeLine(char line[256],FitbitData* data){
    char temp[256] = {};
    char *converter = "";
    double value = 0.0;
    int val = 0;

    //Get the patient id
    getCsv(line,temp,0);

    //Copy the characters from temp to the data's patient name
    strcpy(data->patient,temp);
    clearString(temp);

    //Get the minutes
    getCsv(line,temp,1);

    //Copy the character from temp to the data's minute
    strcpy(data->minute,temp);
    clearString(temp);

    //Get the calories
    getCsv(line,temp,2);

    //Convert to double
    value = strtod(temp,&converter);

    //Set the data calories to this value
    data->calories = value;
    clearString(temp);
    value = 0;

    //Get the distance
    getCsv(line,temp,3);

    //Conver to double
    value = strtod(temp,&converter);

    //Set the data distance to this value
    data->distance = value;
    clearString(temp);
    value = 0;

    //Get the floors
    getCsv(line,temp,4);

    //Convert to integer
    val = atoi(temp);

    //Set the data floors to val
    data->floors = val;
    clearString(temp);
    val = 0;

    //Get the heartrate
    getCsv(line,temp,5);

    //Conver to integer
    val = atoi(temp);

    //Set the data heartrate to val
    data->heartRate = val;
    clearString(temp);
    val = 0;

    //Get the steps
    getCsv(line,temp,6);

    //Convert to integer
    val = atoi(temp);

    //Set the data steps to val
    data->steps = val;
    clearString(temp);
    value = 0;

    //Get the sleep level
    getCsv(line,temp,7);

    //Convert to integer
    val = atoi(temp);

    //Set up the data's sleep level
    if(val == 1)data->sleepLevel = ASLEEP;
    if(val == 2)data->sleepLevel = AWAKE;
    if(val == 3)data->sleepLevel = REALLYAWAKE;
    clearString(temp);
    val = 0;
}

void getCsv(char line[256], char new[256], int index){
    //Get the index of the commas
    int s = getIndexOfComma(line,index);
    int e = getIndexOfComma(line,index + 1);

    //Incase there isnt a comma at the end
    if(e == -1)e = strlen(line);

    //Substring the value out into the new-string
    subString(line,new,s,e);
}

int getIndexOfComma(char line[256],int number){
    //The count of commas found
    int count = 0;

    int length = strlen(line);
    //Loop through the string until you find the # of the comma specified
    for (int i = 0; i < length; ++i) {
        //Get character
        char c = line[i];

        //Check if that character is a comma
        if(c == ',')count++;

        if(count == number)return i;
    }
    return -1;
}

void defineArray(FitbitData data[1440]){
    for (int i = 0; i < 1440; ++i) {
        FitbitData item = data[i];
        item.calories = 0;
        item.distance = 0;
        item.floors = 0;
        item.heartRate = 0;
        item.sleepLevel = NONE;
        item.steps = 0;
    }
}

void subString(char line[256], char new[256], int s,int e){
    if(s == 0)s = - 1;
    strncat(new,&line[s + 1],e-(s + 1));
}

void clearString(char string[256]){
    //Set all characters in the string to null
    for (int i = 0; i < 256; ++i) {
        string[i] = 0;
    }
}