#include "player.h"
#include <gtest/gtest.h>
#include "test_algorithm.h"

TEST(PlayerTest, BuyTest) { 
    TestAlgorithm test;
    Player player(&test, 10000);
    std::map<std::string, float> prices;
    prices["a"] = 100;
    prices["b"] = 10;
    long time = 5;
    ASSERT_EQ(player.get_current_funds(), 10000);
    ASSERT_EQ(player.get_starting_funds(), 10000);
    player.execute_trades(prices, time);
    ASSERT_EQ(player.get_current_funds(), 0);
    ASSERT_EQ(player.get_starting_funds(), 10000);
    std::map<std::string, Share> portfolio = player.get_portfolio();
    ASSERT_EQ(portfolio.size(), 1);
}
/*
TEST(SquareRootTest, NegativeNos) {
    ASSERT_EQ(-1.0, squareRoot(-15.0));
    ASSERT_EQ(-1.0, squareRoot(-0.2));
}
*/
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
