#include "portfolio.h"

//Constructor for Portfolio
Portfolio::Portfolio( string name, int num, double port_price){
    //account_balance=balance;
    stock=name;
    shares=num;
    price=port_price;
}



//Implementation for getting the stock stock symbol you own
string Portfolio::get_stock_name(){
    return stock;
}
//Implementation for getting the number of shares of stock you own
int Portfolio::get_number_of_shares(){
    return shares;
}
//Implementation for getting the stock price
double Portfolio::get_stock_price(){
    return price;
}
//Implementation for setting the number of shares
void Portfolio::set_shares(int number){
    shares=number;
}
