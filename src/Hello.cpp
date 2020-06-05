#include "Hello.h"

struct Good {
    std::string barcode;
    std::string name;
    size_t price;
};

std::vector<Good> goods = {
    {"ITEM000001", "Apple", 460},
    {"ITEM000003", "Cup", 100},
    {"ITEM000005", "Banana", 300},
};

std::string BuildReceipt(const std::vector<std::string>& barcodes)
{
    return "";
}
