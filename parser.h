#include <fstream>  
#include <sstream>  

class Parser{
    private:
        std::ifstream infile;
        int id;
        std::string operation;
        int address;

    public:
        Parser () {
            infile.open("trace1.txt");
        }

        int parse() {
            std::string line;    
            if (std::getline(infile, line)) {
                std::cout << line << std::endl;
                processLine(line);
                return 1;
            }
            return 0;
        }

        void processLine(std::string line) {
            std::string str;
            std::string ss;
            std::stringstream sstream;
            std::stringstream linestream(line);
            int i = 0;
            while (std::getline(linestream, str, ' ')) {
               // std::cout<<str;
                switch(i) {
                    case 0:
                        sstream.str(str);
                        while (std::getline(sstream, ss, 'P')) {}
                        id = std::stoi(ss);
                        break;
                    case 1:
                        operation = str;
                        break;
                    case 2:
                        address = std::stoi(str);
                        break;
                }
                i++;
            }
        }

        int getProcessor() {
            return id;
        }

        int getAddress() {
            return address;
        }

        std::string getOper() {
            return operation;
        }
};
