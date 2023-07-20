#ifndef STOCK_H
#define STOCK_H
#include<iostream>
//#include<string>
using namespace std;

class Stock{
    public:
        Stock(string symbol,double price); //Constructor
        void set_symbol(string symbol); //set Stock symbol
        void set_price(double price);   //set Stock price
        string get_symbol();    //get the stock symbol
        double get_price();     //get the stock price
    private:
        string stock_symbol;    //variable for storing stock symbol name
        double stock_price;     //variable for storing stock price

};

#endif

