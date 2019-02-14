#include "cache.h"
#include <stdlib.h>
#include <iostream>

Cache::Cache(int size, int number) {
    lineSize = size;
    linesNumber = number;
    statePerLine = new int[linesNumber];
    addrPerLine = new int*[linesNumber];
    for (int i = 0; i < linesNumber; i ++) 
        addrPerLine[i] = new int[lineSize];
    for (int i = 0; i < linesNumber; i ++) 
        statePerLine[i] = 0;
    int i;
    for (i = 0; i < linesNumber; i ++) 
            for (int j = 0; j < lineSize; j++)
                addrPerLine[i][j] = -1;
}

Cache::~Cache(){
    delete[] statePerLine;
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
    if (wordAddress >= linesNumber) {
        return findCacheLine(wordAddress/linesNumber);
    }

    return wordAddress;
}

int Cache::findTag(int wordAddress) {
    return wordAddress%lineSize;
}

int Cache::retWord(int cacheLine, int tag) {
    return addrPerLine[cacheLine][tag];
}

void Cache::cacheWord(int cacheLine, int tag, int address) {
    addrPerLine[cacheLine][tag] = address;
}
