//
// Created by Jordan Muehlbauer on 1/16/20.
//
#include <stdlib.h>
#include <stdio.h>
#include "source.h"

void loadFitBitFile(FILE *file){
    //Attempt to load the file
    file = fopen("FitbitData.csv","r");

    //Check if the file opened successfully
    if(file == NULL){
        printf("Error while opening FitbitData.csv\n");
        system("exit");
        return;
    }

    //Inform success
    printf("FitbitData.csv was successfully loaded\n");
}

void loadResultFile(FILE *file){
    //Attempt to load the file
    file = fopen("Result.csv","w");

    //Check if the file opened successfully
    if(file == NULL){
        printf("Error while opening Result.csv\n");
        system("exit");
        return;
    }

    //Inform success
    printf("Result.csv was successfully loaded\n");
}

void collectStats(FILE *file){
    //Create local string to be analyzed
    char string[256];

    //Skip the first line which is a template
    fgets(string,256,file);
    printf("String  = %s\n",string);

    //Loop over each line of the csv file
    while (!feof(file)){
        //Collect line
        fgets(string,256,file);

        printf("%s\n",string);
    }
}

