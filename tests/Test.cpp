#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Hello.h"

using ::testing::Eq;

TEST(getOrders, should_return_orders_if_input_barcodes)
{
    std::vector<std::string> barCodes({"ITEM000001","ITEM000003","ITEM000001"});

    std::map<size_t, size_t> expect = getOrder(barCodes);

    EXPECT_THAT(expect[0], Eq(2));
    EXPECT_THAT(expect[1], Eq(1));
}
TEST(countOrdersPrice, should_return_total_price_with_orders)
{
    std::map<size_t, size_t> orders({{0,1},{1,1},{2,1}});

    size_t expect = countOrdersPrice(orders);

    EXPECT_THAT(expect,Eq(860));
}
TEST(countOrdersPrice, should_return_total_price_with_orders_1)
{
    std::map<size_t, size_t> orders({{0,2},{1,1},{2,1}});

    size_t expect = countOrdersPrice(orders);

    EXPECT_THAT(expect,Eq(1320));
}
TEST(printReceipt, should_print_receipt_with_orders)
{
    std::vector<std::string> barCodes({"ITEM000001"});
    std::string receipt = printReceipt(barCodes);

    const std::string expect = R"(Receipts:
----------------
ITEM000001, Apple, x1, 460

----------------
TOTAL:     460)";
    EXPECT_THAT(receipt, Eq(expect));
}
TEST(printReceipt, should_print_receipt_with_orders_1)
{
    std::vector<std::string> barCodes({"ITEM000001", "ITEM000001"});
    std::string receipt = printReceipt(barCodes);

    const std::string expect = R"(Receipts:
----------------
ITEM000001, Apple, x2, 460

----------------
TOTAL:     920)";
    EXPECT_THAT(receipt, Eq(expect));
}
TEST(printReceipt, should_print_receipt_with_orders_2)
{
    std::vector<std::string> barCodes({"ITEM000001", "ITEM000001", "ITEM000003"});
    std::string receipt = printReceipt(barCodes);

    const std::string expect = R"(Receipts:
----------------
ITEM000001, Apple, x2, 460
ITEM000003, Cup, x1, 100

----------------
TOTAL:     1020)";
    EXPECT_THAT(receipt, Eq(expect));
}
TEST(printReceipt, should_print_receipt_with_orders_3)
{
    std::vector<std::string> barCodes({"ITEM000001", "ITEM000003", "ITEM000001", "ITEM000005"});
    std::string receipt = printReceipt(barCodes);

    const std::string expect = R"(Receipts:
----------------
ITEM000001, Apple, x2, 460
ITEM000003, Cup, x1, 100
ITEM000005, Banana, x1, 300

----------------
TOTAL:     1320)";
    EXPECT_THAT(receipt, Eq(expect));
}
