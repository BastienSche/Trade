#ifndef TRADE_HPP_
#define TRADE_HPP_

#include <vector>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>

typedef struct next_candles_s {
    int date = 0;
    long double high = 0;
    long double low = 0;
    long double open = 0;
    long double close = 0;
    long double volume = 0;
} next_candles_t;

//pair , date , high , low , open , close , volume
class trade
{
private:

    int testing;
    int _period;
    std::vector<std::string> _InputStr;

    next_candles_t _BTC_ETH;
    next_candles_t _USDT_ETH;
    next_candles_t _USDT_BTC;

    std::vector<next_candles_t> _vector_BTC_ETH;
    std::vector<next_candles_t> _vector_USDT_ETH;
    std::vector<next_candles_t> _vector_USDT_BTC;

    long double _USDT;
    long double _BTC;
    long double _ETH;
    
    long double _g_BTC_ETH;
    long double _r_BTC_ETH;
    long double _s_BTC_ETH;
    long double _m_BTC_ETH;

    long double _g_USDT_ETH;
    long double _r_USDT_ETH;
    long double _s_USDT_ETH;
    long double _m_USDT_ETH;

    long double _g_USDT_BTC;
    long double _r_USDT_BTC;
    long double _s_USDT_BTC;
    long double _m_USDT_BTC;

public:
    trade(/* args */);
    ~trade();
    void loop();
    int receive(char *str);
    void setting();
    void update();
    void action();
    void parser_update();
    void stacks();
    void next_candles();
    void buy_or_sell();
    void follow_BTC_ETH();
    void follow_USDT_ETH();
    void follow_USDT_BTC();

    int calcul_s_BTC_ETH();
    int calcul_r_BTC_ETH();
    int calcul_g_BTC_ETH();
    int calcul_moy_BTC_ETH();

    int calcul_s_USDT_ETH();
    int calcul_r_USDT_ETH();
    int calcul_g_USDT_ETH();
    int calcul_moy_USDT_ETH();

    int calcul_s_USDT_BTC();
    int calcul_r_USDT_BTC();
    int calcul_g_USDT_BTC();
    int calcul_moy_USDT_BTC();
};


#endif// TRADE_HPP_