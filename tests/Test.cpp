#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Hello.h"



//TEST(Pos, Case1)
//{
//    std::string receipt = BuildReceipt({"ITEM000001"});
//    const std::string expect = R"(Receipts:
//----------------
//ITEM000001, Apple, x1, 460
//
//----------------
//TOTAL:     460)";
//    EXPECT_THAT(receipt, Eq(expect));
//}
using ::testing::Eq;

TEST(Pos, should_return_goods_if_input_barcodes)
{
    std::vector<std::string> barCodes({"ITEM000001","ITEM000003","ITEM000005"});
    std::vector<size_t> expect = getGoodsInfo(barCodes);
    EXPECT_THAT(expect.size(), Eq(barCodes.size()));
}