#ifndef __HELLO_H__
#define __HELLO_H__
#include <string>
#include <vector>

struct Good {
    std::string barcode;
    std::string name;
    size_t price;
};

//std::string BuildReceipt(const std::vector<std::string>& barcodes);
std::vector<size_t> getGoodsInfo(std::vector<std::string>& barcodes);

#endif
