#include "processor.h"

Processor::Processor(int processorId, Cache *privateCache) {
    id = processorId;
    cache = privateCache;
}

void Processor::request() {

}

