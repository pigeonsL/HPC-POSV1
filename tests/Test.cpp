#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Hello.h"

using ::testing::Eq;

TEST(Pos, Case1)
{
    std::string receipt = BuildReceipt({"ITEM000001"});
    const std::string expect = R"(Receipts:
----------------
ITEM000001, Apple, x1, 460

----------------
TOTAL:     460)";
    EXPECT_THAT(receipt, Eq(expect));
}
