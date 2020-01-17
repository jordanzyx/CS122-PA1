#include <stdio.h>
#include "source.h"

int main() {
    //Create file variables
    FILE *input;
    FILE *output;

    //Attempt to load files
    loadFitBitFile(input);
    loadResultFile(output);

    //Collect statistics
    collectStats(input);

    return 0;
}
