#ifndef PORTFOLIO_H
#define PORTFOLIO_H
#include"stock.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Portfolio{
    public:
        Portfolio(string,int,double);   //Constructor
        void set_shares(int number);    //set number of shares
        string get_stock_name();    //get the stock symbol for a stock you own
        int get_number_of_shares();     //get the number of shares for a stock you own
        double get_stock_price();   //get the stock price
        

    private:
        double price;       //variable for storing stock price for a stock you own
        string stock;       //variable for storing stock name for a stock you own
        int shares;         //variable for storing number of shares you own

};


#endif