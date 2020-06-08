#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Hello.h"

using ::testing::Eq;

TEST(getOrders, should_return_goods_if_input_barcodes)
{
    std::vector<std::string> barCodes({"ITEM000001","ITEM000003","ITEM000005"});
    std::vector<size_t> expect = getOrders(barCodes);
    EXPECT_THAT(expect.size(), Eq(barCodes.size()));
}
TEST(countOrdersPrice, should_return_total_price_if_input_orders)
{
    std::vector<size_t> orders({0,1,2});
    size_t expect = countOrdersPrice(orders);
    EXPECT_THAT(expect,Eq(860));
}
//TEST(printReceipt, should_print_receipt_with_orders)
//{
//    std::string receipt = printReceipt({"ITEM000001"});
//    const std::string expect = R"(Receipts:
//----------------
//ITEM000001, Apple, x1, 460
//
//----------------
//TOTAL:     460)";
//    EXPECT_THAT(receipt, Eq(expect));
//}