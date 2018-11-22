#include "cache.h"

class Processor {
    public:
        Processor(int processorId, Cache *privateCache);
        void request();

    private:
        int id;
        Cache *cache;
};
