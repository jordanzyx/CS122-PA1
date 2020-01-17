//
// Created by Jordan Muehlbauer on 1/16/20.
//
#include <stdlib.h>
#include <stdio.h>
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

    //Loop over each line of the csv file
    while (!feof(file)){
        //Collect line
        fgets(string,256,file);

        printf("%s\n",string);
    }
}

