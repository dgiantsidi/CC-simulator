#pragma once
#include "cache.h"

class Processor {
    public:
        Processor(int processorId, Cache *privateCache);
        void request();
        Cache *cache;

    private:
        int id;
};
