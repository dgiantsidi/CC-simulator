#include <iostream>
#include "cache.h"
#include <stdlib.h>     /* atoi */
int main (int argc, char* argv[]) {
    int lineSize = 1024;
    int linesNumber = 4;
    if (argc < 3) {
        std::cout << "Not enough arguments\n";
        exit(1);
    }
    
    lineSize = atoi(argv[1]);
    linesNumber = atoi(argv[2]);

    Cache cache(lineSize, linesNumber);
    std::cout << "Cache line size: " << cache.retLineSize() << std::endl;
    std::cout << "Cache lines number: " << cache.retLinesNumber() << std::endl;
    std::cout << "cache Line of 17: " << cache.findCacheLine(17) << std::endl;
}
