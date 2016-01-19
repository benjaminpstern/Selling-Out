#include "player.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "test_algorithm.h"
#include "management.h"

using ::testing::Return;
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

    prices["b"] = 101;
    time++;
    player.execute_trades(prices, time);
    ASSERT_EQ(player.get_current_funds(), 101000);
    portfolio = player.get_portfolio();
    ASSERT_EQ(portfolio.size(), 0);
}

class MockPlayer : public Player {
    public:
        MockPlayer() : Player(NULL, 0) {}
        MOCK_METHOD0(get_portfolio, std::map<string, Share>());
        MOCK_METHOD0(get_current_funds, float());
};

TEST(ManagerTest, AssetsTest) {
    MockPlayer player_mock;
    std::map<string, Share> portfolio;
    Share share("a", 10, 100, 1);
    std::pair<string, Share> pair("a", share);
    portfolio.insert(pair);
    EXPECT_CALL(player_mock, get_portfolio()).WillOnce(Return(portfolio));
    EXPECT_CALL(player_mock, get_current_funds()).WillOnce(Return(20));
    Manager manager(0, 0);
    std::map<string, float> prices;
    prices["a"] = 100;
    manager.set_prices(prices);
    float assets = manager.get_assets((Player&)player_mock);
    ASSERT_EQ(assets, 10000);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
