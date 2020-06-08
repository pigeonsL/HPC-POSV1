#include "Hello.h"

std::vector<Good> goods = {
    {"ITEM000001", "Apple", 460},
    {"ITEM000003", "Cup", 100},
    {"ITEM000005", "Banana", 300},
};

std::map<size_t, size_t> getItems(std::vector<std::string>& barcodes)
{
    std::map<size_t, size_t> items;//[goodsIndex,number]

    std::vector<size_t> goodsIndex;
    for (int i = 0; i < barcodes.size(); ++i) {
        for (int j = 0; j < goods.size(); ++j) {
            if (barcodes[i] == goods[j].barcode) {
                if (items.count(j) == 0) {
                    items.insert(std::make_pair(j, 1));
                }else{
                    items[j]++;
                }
            }
        }
    }
    return items;
}
size_t countOrdersPrice(std::vector<size_t>& orders){
    size_t totalPrice=0;
    for(int i=0;i<orders.size();++i){
        totalPrice += goods[orders[i]].price;
    }
    return totalPrice;
}

