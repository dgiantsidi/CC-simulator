#include <iostream>
#include "processor.h"
#include "parser.h"
#include <stdlib.h>     /* atoi */
int main (int argc, char* argv[]) {
    int lineSize = 1024;
    int linesNumber = 4;
    int procNumber = 1;

    if (argc < 4) {
        std::cout << "Not enough arguments\n";
        exit(1);
    }

    lineSize = atoi(argv[1]);
    linesNumber = atoi(argv[2]);
    procNumber = atoi(argv[3]);
    
    Processor **procTable = new Processor*[procNumber];
    for (int i = 0; i < procNumber; i++) {
        Cache cache(lineSize, linesNumber);
        procTable[i] = new Processor(i, &cache);
        std::cout << "Cache line size: " << cache.retLineSize() << std::endl;
        std::cout << "Cache lines number: " << cache.retLinesNumber() << std::endl;
        std::cout << "cache Line of 17: " << cache.findCacheLine(17) << std::endl;
        std::cout << "cache tag of 17: " << cache.findTag(17) << std::endl;
        cache.cacheWord(cache.findCacheLine(17), cache.findTag(17), 17);
        std::cout << "address: " << cache.retWord(cache.findCacheLine(17), cache.findTag(17)) << std::endl;
    }

    Parser p;
    int ret;
    ret = p.parse();
    int pId;
    int adr;
    while (ret) {
        // here cache coherence should be implemented
        pId = p.getProcessor();
        adr = p.getAddress();
        std::cout << pId << " " << adr << std::endl;
        ret = p.parse();
    }
}
