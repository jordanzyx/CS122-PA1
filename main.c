#include <stdio.h>
#include "source.h"

int main() {
    //Create file variables
    FILE *input = NULL;
    FILE *output = NULL;

    //Attempt to load files
    input = loadFitBitFile(input);
    output = loadResultFile(output);

    //Collect statistics
    collectStats(input);

    return 0;
}
