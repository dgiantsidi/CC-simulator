#include "cache.h"
#include <stdlib.h>
#include <iostream>

Cache::Cache(int size, int number) {
    lineSize = size;
    linesNumber = number;
    statePerLine = new int[linesNumber];
    addrPerLine = new int*[linesNumber];
    for (int i = 0; i < lineSize; i ++) 
        addrPerLine[i] = new int[lineSize];
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
    return wordAddress-1;
}

int Cache::findTag(int wordAddress) {
    return wordAddress%linesNumber;
}

int Cache::retWord(int cacheLine, int tag) {
    return addrPerLine[cacheLine][tag];
}

void Cache::cacheWord(int cacheLine, int tag, int address) {
    addrPerLine[cacheLine][tag] = address;
}
