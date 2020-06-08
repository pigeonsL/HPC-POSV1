#include "Hello.h"

std::vector<Good> goods = {
    {"ITEM000001", "Apple", 460},
    {"ITEM000003", "Cup", 100},
    {"ITEM000005", "Banana", 300},
};
std::vector<size_t> getGoodsInfo(std::vector<std::string>& barcodes){
    std::vector<size_t> orders;
    for(int i=0;i<barcodes.size();++i){
        for(int j=0;j<goods.size();++j){
            if(barcodes[i] == goods[j].barcode){
                orders.push_back(j);
            }
        }
    }
    return orders;
}

