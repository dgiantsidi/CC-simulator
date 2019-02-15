#pragma once
#include "processor.h"

class MSI {
    public:
        MSI (int processorsNum, Processor **p);
        ~MSI (){};
        int readRequest(int processorId, int address);
        int writeRequest(int processorId, int address);

    private:
        int procNum;
        Processor **processors;

};
