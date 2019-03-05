
#include "config.h"

using namespace std;
using namespace libconfig;

int config (int argc, char **argv)
{
    Config cfg;

    try {
        cfg.readFile("testConfig.cfg");
    }
    catch(const FileIOException &fioex)
    {
        std::cerr << "I/O error while reading the file." << std::endl;
        return(EXIT_FAILURE);
    }
    catch(const ParseException &pex)
    {
        std::cerr << "Pare error at " << pex.getError() << ":" << pex.getLine() << " - " << pex.getError() <<std::endl;
        return(EXIT_FAILURE);
    }
    try {
        int microseconds = cfg.lookup("microseconds");

    }
    catch(const SettingNotFoundException &nfex)
    {
        cerr << "No 'microseconds' setting in configuration file." << endl;
    }


    return 1;
}