#include "cache.h"
#include <stdlib.h>
#include <iostream>

Cache::Cache(int size, int number) {
    lineSize = size;
    linesNumber = number;
    statePerLine = (int*)calloc(linesNumber, sizeof(int));
//TODO:     wordIdsPerLine = (int*)(linesNumber, sizeof(int));
}

Cache::~Cache(){
    free(statePerLine);
}

int Cache::retLineSize() {
    return lineSize;
}

int Cache::retLinesNumber() {
    return linesNumber;
}

int Cache::retStateOfLine(int lineIndex) {
    return statePerLine[lineIndex];
}

void Cache::setStateOfLine(int lineIndex, int state) {
    statePerLine[lineIndex] = state;
}

int Cache::findCacheLine(int wordAddress) {
    std::cout<< wordAddress << std::endl;
    if (wordAddress >= linesNumber) {
        return findCacheLine(wordAddress/linesNumber);
    }
    std::cout<< wordAddress << " " << linesNumber << std::endl;
    return wordAddress;
}
