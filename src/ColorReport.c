#include "ColorReport.h"
#include <stdio.h>

void PrintColorManual(void) {
    int pairNumber = 1;
    for(int i = 0; i < numberOfMajorColors; i++) {
        for(int j = 0; j < numberOfMinorColors; j++) {
            printf("%2d: %s %s\n", pairNumber, MajorColorNames[i], MinorColorNames[j]);
            pairNumber++;
        }
    }
}

void PrintColorCSV(void) {
    printf("PairNumber,MajorColor,MinorColor\n");
    int pairNumber = 1;
    for(int i = 0; i < numberOfMajorColors; i++) {
        for(int j = 0; j < numberOfMinorColors; j++) {
            printf("%d,%s,%s\n", pairNumber, MajorColorNames[i], MinorColorNames[j]);
            pairNumber++;
        }
    }
}
