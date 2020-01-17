//
// Created by Jordan Muehlbauer on 1/16/20.
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

void collectStats(FILE *file){
    //Create local string to be analyzed
    char string[256] = {};

    //Skip the first line which is a template
    fscanf(file,"%s",string);

    //Create a sum of steps value
    int steps = 0;

    //Loop over each line of the csv file
    while (!feof(file)){
        //Collect line
        fgets(string,256,file);

        //Analyze the line
        analyzeLine(string,&steps);

        printf("%s\n",string);
    }

    printf("TOTAL STEPS: %d\n",steps);
}

void analyzeLine(char line[256],FitbitData* data){

}

void getCsv(char line[256], char new[256], int index){
    //Get the index of the commas
    int s = getIndexOfComma(line,index);
    int e = getIndexOfComma(line,index + 1);

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

void subString(char line[256], char new[256], int s,int e){
    strncat(new,&line[s + 1],e-(s + 1));
}