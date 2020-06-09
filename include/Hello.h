#ifndef __HELLO_H__
#define __HELLO_H__
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cstring>

struct Good {
    std::string barcode;
    std::string name;
    size_t price;
};
struct Order{
    std::map<size_t, size_t> items;
    size_t totalPrice;
};

std::map<size_t, size_t> getOrder(std::vector<std::string>& barcodes);
size_t countOrdersPrice(std::map<size_t, size_t>& orders);
std::string printReceipt(std::vector<std::string>& barcodes);


#endif
