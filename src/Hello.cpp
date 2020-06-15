#include "Hello.h"

std::vector<Good> goods = {
    {"ITEM000001", "Apple", 460},
    {"ITEM000003", "Cup", 100},
    {"ITEM000005", "Banana", 300},
};

std::map<size_t, size_t> getOrder(std::vector<std::string>& barcodes)
{
    std::map<size_t, size_t> orders;//[goodsIndex,number]

    std::vector<size_t> goodsIndex;
    for (int i = 0; i < barcodes.size(); ++i) {
        for (int j = 0; j < goods.size(); ++j) {
            if (barcodes[i] == goods[j].barcode) {
                orders[j]++;
                break;
            }
        }
    }
    return orders;
}
size_t countOrdersPrice(std::map<size_t, size_t>& orders){
    size_t totalPrice = 0;
    for(auto it = orders.begin(); it != orders.end(); it++){
        totalPrice += goods[it->first].price * it->second;
    }
    return totalPrice;
}
std::string printReceipt(std::vector<std::string>& barcodes){

    std::string receipt = "Receipts:\n----------------\n";

    std::map<size_t, size_t> orders = getOrder(barcodes);

    for(auto it = orders.begin(); it != orders.end(); it++){
        receipt += goods[it->first].barcode + ", " + goods[it->first].name + ", x" +
                   std::to_string(it->second) + ", " + std::to_string(goods[it->first].price) + "\n";
    }
    receipt += "\n----------------\nTOTAL:     " + std::to_string(countOrdersPrice(orders));
    return receipt;
}

