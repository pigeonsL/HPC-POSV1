#include "Hello.h"

int main(int argc, char* argv[])
{
    std::vector<std::string> barCodes({"ITEM000001", "ITEM000003", "ITEM000001", "ITEM000005", "ITEM000003"});
    std::cout<<printReceipt(barCodes)<<std::endl;
    return 0;
}
