#include "player.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "test_algorithm.h"
#include "management.h"
#ifndef PLAYER_INT
#include "player_interface.h"
#endif

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

class MockPlayer : public PlayerInterface {
    public:
        MockPlayer() {}
        MOCK_METHOD0(get_portfolio, std::map<string, Share>());
        MOCK_METHOD0(get_current_funds, float());
        MOCK_METHOD0(get_starting_funds, float());
        MOCK_METHOD2(execute_trades, void(const std::map<string, float>, long));
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
    float assets = manager.get_assets(player_mock);
    ASSERT_EQ(assets, 10020);
}

TEST(ManagerTest, ParseTestTime) {
    Manager manager(0, 0);
    manager.parse_line_feed("1420520460,Jell:81.3100000,Prisons:12.8600000,Armchair:230.1523800");
    long time = manager.get_time();
    ASSERT_EQ(time, 1420520460);
}
TEST(ManagerTest, ParseTestPrices) {
    Manager manager(0, 0);
    manager.parse_line_feed("1420520460,Jell:81.3100000,Prisons:12.8600000,Armchair:230.1523800");
    std::map<string, float> prices = manager.get_prices();
    float JellPrice = prices["Jell"];
    ASSERT_FLOAT_EQ(JellPrice, 81.31);
    float PrisonsPrice = prices["Prisons"];
    ASSERT_FLOAT_EQ(PrisonsPrice, 12.86);
    float ArmchairPrice = prices["Armchair"];
    ASSERT_FLOAT_EQ(ArmchairPrice, 230.15238);
    ASSERT_EQ(prices.size(), 3);
}

TEST(ManagerTest, TestIntegration) {
    TestAlgorithm test;
    Player player(&test, 10000);
    Manager manager(0, 0);
    manager.add_player(&player);
    while (!manager.eof() && manager.file_num() < 3) {
        manager.progress_one_timestep();
    }
    ASSERT_FLOAT_EQ(manager.get_assets(player), 10160.188);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
