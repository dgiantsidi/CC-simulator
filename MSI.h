#pragma once
#include "processor.h"

class MSI {
    public:
        MSI (int processorsNum, Processor **p);
        ~MSI (){};
        void readRequest(int processorId, int address);
        void writeRequest(int processorId, int address);
        Processor **processors;

    private:
        int procNum;

};
