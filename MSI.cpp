#include <stdlib.h>
#include <iostream>
#include "MSI.h"

MSI::MSI (int processorsNum, Processor **p) {
    processors = p;
    procNum = processorsNum;
}

int MSI::readRequest(int processorId, int address) {
    int cacheLine = processors[processorId]->cache->findCacheLine(address);
    int tag = processors[processorId]->cache->findTag(address);
    int word = processors[processorId]->cache->retWord(cacheLine, tag);

    
    if (word != address || processors[processorId]->cache->retStateOfLine(cacheLine) == 0) {
        // set this block as Shared (state == 1)
        processors[processorId]->cache->setStateOfLine(cacheLine, 1); 
        processors[processorId]->cache->cacheWord(cacheLine, tag, address);
        return 0;
    }
    return 1;
}

// returns the number of invlidation messages
int MSI::writeRequest(int processorId, int address) {
    int cacheLine = processors[processorId]->cache->findCacheLine(address);
    int tag = processors[processorId]->cache->findTag(address);
    int word = processors[processorId]->cache->retWord(cacheLine, tag);
    int invalidation_messages = 0;
    /**
     * set this block as Modified invalidate other blocks 
     * in other caches that may have this word cached
     */
    if (processors[processorId]->cache->retStateOfLine(cacheLine) != 2) { 
    for (int i = 0; i < procNum; i++){
        if (i != processorId) {
            int line = processors[i]->cache->findCacheLine(address);
            int tag = processors[i]->cache->findTag(address);
            if (processors[i]->cache->retWord(line, tag) == address){
                processors[i]->cache->setStateOfLine(cacheLine, 0); 
                invalidation_messages++;
            }
        }
    }
    processors[processorId]->cache->setStateOfLine(cacheLine, 2); 
    processors[processorId]->cache->cacheWord(cacheLine, tag, address);
    }

}
