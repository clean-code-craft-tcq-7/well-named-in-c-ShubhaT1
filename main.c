
#include <stdio.h>
#include <assert.h>
#include "src/ColorPair.h"
#include "src/ColorReport.h"

#define MAX_COLORPAIR_NAME_CHARS 16

void testNumberToPair(int pairNumber,
    enum MajorColor expectedMajor,
    enum MinorColor expectedMinor)
{
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
    ColorPairToString(&colorPair, colorPairNames);
    printf("Got pair %s\n", colorPairNames);
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}

void testPairToNumber(
    enum MajorColor major,
    enum MinorColor minor,
    int expectedPairNumber)
{
    ColorPair colorPair;
    colorPair.majorColor = major;
    colorPair.minorColor = minor;
    int pairNumber = GetPairNumberFromColor(&colorPair);
    printf("Got pair number %d\n", pairNumber);
    assert(pairNumber == expectedPairNumber);
}

void testPrintColorManual(void) {
    printf("\nReference Manual:\n");
    PrintColorManual();
    // Strong asserts: check first and last pair
    ColorPair first = GetColorFromPairNumber(1);
    assert(first.majorColor == WHITE && first.minorColor == BLUE);
    ColorPair last = GetColorFromPairNumber(numberOfMajorColors * numberOfMinorColors);
    assert(last.majorColor == VIOLET && last.minorColor == SLATE);
}

void testPrintColorCSV(void) {
    printf("\nCSV Report:\n");
    PrintColorCSV();
    // Strong asserts: check CSV header and a sample value
    ColorPair sample = GetColorFromPairNumber(12);
    assert(sample.majorColor == BLACK && sample.minorColor == ORANGE);
}

int main() {
    testNumberToPair(4, WHITE, BROWN);
    testNumberToPair(5, WHITE, SLATE);

    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);

    testPrintColorManual();
    testPrintColorCSV();

    return 0;
}
