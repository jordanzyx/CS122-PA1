#include <stdio.h>
#include "source.h"

int main() {
    //Create file variables
    FILE *input = NULL;
    FILE *output = NULL;

    //Create fitbit data array
    FitbitData data[1440] = {};

    //Set up default values for the array
    defineArray(data);

    //Attempt to load files
    input = loadFitBitFile(input);
    output = loadResultFile(output);

    //Collect statistics
    collectStats(input,data);

    //Close files
    fclose(input);
    fclose(output);

    return 0;
}
