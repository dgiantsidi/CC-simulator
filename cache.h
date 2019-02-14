#pragma once

class Cache {
    public:
        Cache(int size, int number);
        ~Cache();
        int retLineSize();
        int retLinesNumber();
        int retStateOfLine(int lineIndex);
        void setStateOfLine(int lineIndex, int state);
        int findCacheLine(int wordAddress);
        int findTag(int wordAddress);
        int retWord(int cacheLine, int tag);
        void cacheWord(int cacheLine, int tag, int address);
    
    private:
        int lineSize;
        int linesNumber;
        int *statePerLine;
        int **addrPerLine;

};
