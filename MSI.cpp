#include <stdlib.h>
#include <iostream>
#include "MSI.h"

MSI::MSI (int processorsNum, Processor **p) {
    processors = p;
    procNum = processorsNum;
}

void MSI::readRequest(int processorId, int address) {
    std::cout<<"1 " << processorId << " " << address <<"\n";
    int cacheLine = processors[processorId]->cache->findCacheLine(address);
    std::cout<<"2\n";
    int tag = processors[processorId]->cache->findTag(address);
    std::cout<<"3 " <<cacheLine<< " "<<address<< " " <<tag<<"\n";
    int word = processors[processorId]->cache->retWord(cacheLine, tag);
    std::cout<<"4\n";

    
    if (word != address || processors[processorId]->cache->retStateOfLine(cacheLine) == 0) {
        // set this block as Shared (state == 1)
        processors[processorId]->cache->setStateOfLine(cacheLine, 1); 
        processors[processorId]->cache->cacheWord(cacheLine, tag, address);
    }
    else {
        std::cout<< "Hit\n";
    }

}

void MSI::writeRequest(int processorId, int address) {
    int cacheLine = processors[processorId]->cache->findCacheLine(address);
    int tag = processors[processorId]->cache->findTag(address);
    int word = processors[processorId]->cache->retWord(cacheLine, tag);

    // set this block as Modified
    processors[processorId]->cache->setStateOfLine(cacheLine, 2); 
    processors[processorId]->cache->cacheWord(cacheLine, tag, address);
    for (int i = 0; i < procNum; i++){
        if (i != processorId) {
            int line = processors[i]->cache->findCacheLine(address);
            int tag = processors[i]->cache->findTag(address);
            if (processors[i]->cache->retWord(line, tag) == address){
                processors[i]->cache->setStateOfLine(cacheLine, 0); 
            }
        }
    }
    // invalidate other blocks in other caches that may have this word
    // cached.

}
