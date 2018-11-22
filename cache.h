class Cache {
    public:
        Cache(int size, int number);
        ~Cache();
        int retLineSize();
        int retLinesNumber();
        int retStateOfLine(int lineIndex);
        void setStateOfLine(int lineIndex, int state);
        int findCacheLine(int wordAddress);
        // TODO
        /*
         * int findTag(int wordAddress);
         * int retWord(int cacheLine, int tag);
         */
    
    private:
        int lineSize;
        int linesNumber;
        int *statePerLine;

};
