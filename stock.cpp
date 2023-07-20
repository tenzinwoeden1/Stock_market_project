
#include "stock.h"
#include<string>

//Constructor implementation
Stock::Stock(string symbol,double price){
    stock_symbol=symbol;
    stock_price=price;
}
//Implementation for setting stock symbol
void Stock::set_symbol(string symbol){
    stock_symbol=symbol;
}
//Implementation for setting stock price
void Stock::set_price(double price){
    stock_price=price;
}

//Implementation for getting stock symbol
string Stock::get_symbol(){
    return stock_symbol;
}
//Implementation for getting stock price
double Stock::get_price(){
    return stock_price;
}
