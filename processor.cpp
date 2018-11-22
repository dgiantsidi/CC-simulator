#include "processor.h"
// #include "cache.h"

Processor::Processor(int processorId, Cache *privateCache) {
    id = processorId;
    cache = privateCache;
}

void Processor::request() {

}

