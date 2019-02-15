#include <iostream>
#include "processor.h"
#include "parser.h"
#include "MSI.h"
#include <stdlib.h>     /* atoi */
int main (int argc, char* argv[]) {
    int lineSize = 1024;
    int linesNumber = 4;
    int procNumber = 1;
    int hits = 0;
    int invalidation_messages = 0;
    if (argc < 4) {
        std::cout << "Not enough arguments\n";
        std::cout << "Provide cache line size, lines' number and processors' number\n";
        exit(1);
    }

    lineSize = atoi(argv[1]);
    linesNumber = atoi(argv[2]);
    procNumber = atoi(argv[3]);

    Processor **procTable = new Processor*[procNumber];
    Cache **cacheTable = new Cache*[procNumber];
    for (int i = 0; i < procNumber; i++) {
        cacheTable[i] = new Cache(lineSize, linesNumber);
        procTable[i] = new Processor(i, cacheTable[i]);
    }

    MSI coherence_protocol(procNumber, procTable);
    
    Parser p;
    int ret;
    ret = p.parse();
    int pId;
    int adr;
    std::string opr;
    while (ret) {
        pId = p.getProcessor();
        adr = p.getAddress();
        opr = p.getOper();
        if (opr.compare("R") == 0) {
            std::cout<<"READ\n";
            hits += coherence_protocol.readRequest(pId, adr);
        }
        else  {
            std::cout<<"WRITE\n";
            invalidation_messages += coherence_protocol.writeRequest(pId, adr);
        }
        ret = p.parse();
    }

    std::cout<<"hits: "<< hits <<" invalidation_messages: "<< invalidation_messages << "\n";
}
