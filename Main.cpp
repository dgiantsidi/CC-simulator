#include <iostream>
#include "processor.h"
#include "parser.h"
#include "MSI.h"
#include <stdlib.h>     /* atoi */
int main (int argc, char* argv[]) {
    int lineSize = 1024;
    int linesNumber = 4;
    int procNumber = 1;

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
    
    std::cout << procTable[0]->cache->retLineSize() << "---\n";
    std::cout << coherence_protocol.processors[0]->cache->retLineSize() << "+++\n";
    Parser p;
    int ret;
    ret = p.parse();
    int pId;
    int adr;
    std::string opr;
    while (ret) {
        // here cache coherence should be implemented
        pId = p.getProcessor();
        adr = p.getAddress();
        opr = p.getOper();
        if (opr.compare("R") == 0) {
            std::cout<<"READ\n";
            // std::cout << "Processor: " << pId <<  " "  << opr << " " << adr << std::endl;
            coherence_protocol.readRequest(pId, adr);
        }
        else  {
            std::cout<<"WRITE\n";
            coherence_protocol.writeRequest(pId, adr);
        }
        ret = p.parse();
    }
}
