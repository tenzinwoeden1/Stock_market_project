#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include"stock.h"
#include"portfolio.h"
using namespace std;

void vecstocks(vector<Stock>&);//function for initilizing vector that stores stocks symbol and prices
void display_stocks(vector<Stock>&);//function for displaying the list of stocks and their prices
void portstocks(vector<Portfolio>&);//function for initilizing the vector that stores the stocks and number of shares you own
void display_portfolio(double& balance,vector<Portfolio>&);//function for displaying your Portfolio with stocks and number of shares
double buy_stock(double&,string name, double price,double num,vector<Portfolio>&);//function for buying stocks including number of shares, returns account balance
double sell_stock(double& balance,string name,double price, double num, vector<Portfolio>&);// function for selling stocks including number of shares, returns account balance


int main(){
    double account_balance;//variable for storing account balance
    cout<<endl<<endl;
    cout<<"Enter Account balance: ";
    cin>>account_balance;
    cout<<endl<<endl;
    
    vector<Stock> Stocks; //object for initilizing the list Stocks and prices
    vecstocks(Stocks);
    display_stocks(Stocks);
    
    vector<Portfolio> port; //object for initilizing the list of stocks and number of shares that are in your portfolio
    portstocks(port);
    int counter;//variable used for switch case, allows the program to run mulitple times
    string st_name;//variable for storing name of stocks that can be used for conditional purposes
    double no_shares;//variable for storing number of shares that can be used for conditional purposes
    do{
        cout<<"1)DISPLAY MY PORTFOLIO "<<endl;
        cout<<"2)BUY STOCKS "<<endl;
        cout<<"3)SELL STOCKS "<<endl;
        cout<<"4)CLOSE THE PROGRAM "<<endl;
        cout<<"ENTER YOUR CHOICE:  ";
        cin>>counter;
        cout<<endl;
        switch(counter){
            case 1:
                display_portfolio(account_balance,port);
                break;
            case 2:
                cout<<"which stock would you like to buy:  ";
                cin>>st_name;
                for(int i=0;i<Stocks.size();i++){
                    if(st_name==Stocks[i].get_symbol()){
                        cout<<"Enter number of shares you would like to purchase: ";
                        cin>>no_shares;
                       account_balance=buy_stock(account_balance,Stocks[i].get_symbol(),Stocks[i].get_price(),no_shares,port);
                    }
                }
                break;
            case 3:
                cout<<"Which stock would you like to sell:  ";
                cin>>st_name;
                for(int i=0;i<port.size();i++){
                    if(st_name==port[i].get_stock_name()){
                        cout<<"Enter number of shares you would like to sell:  ";
                        cin>>no_shares;
                        if(no_shares<=port[i].get_number_of_shares()){
                            account_balance=sell_stock(account_balance,port[i].get_stock_name(),port[i].get_stock_price(),no_shares,port);
                            break;
                        }
                        else{
                            cout<<"Number of shares Invalid"<<endl;
                            break;
                        }
                    }
                }
                break;
            case 4:
                cout<<"Thank you for using my service "<<endl;
                break;
        }
    }while(counter<4);
    return 0;
}
//Implementation for initilizing vector that stores stocks symbol and price
void vecstocks(vector<Stock>& Stocklist){
    cout<<"LIST OF STOCKS"<<endl;
    cout<<"______________"<<endl<<endl;
    Stocklist.push_back(Stock("AAPL",192.82));
    Stocklist.push_back(Stock("GOOGL",125.39));
    Stocklist.push_back(Stock("NVDA",460.31));
    Stocklist.push_back(Stock("AMZN",133.77));
}
//Implementation for displaying the list of stocks and their prices
void display_stocks( vector<Stock>& Stocklist){
    cout<<"SYMBOL "<<" PRICE"<<endl<<endl;
    for(int i=0;i<Stocklist.size();i++){
        cout<<Stocklist[i].get_symbol()<<"   "<<Stocklist[i].get_price()<<endl<<endl;

    }
}
//Implementation for initilizing vector that stores the stocks and number of shares in Porfolio
void portstocks(vector<Portfolio>& portfolio_stocks){
    portfolio_stocks.push_back(Portfolio("N/A",0,0));

}
//Implementation for displaying your Porfolio with stocks and number of shares
void display_portfolio(double& balance,vector<Portfolio>& portfolio_stocks){
    cout<<"BALANCE: "<<balance<<endl;
    cout<<"___________________"<<endl<<endl;
    cout<<" SYMBOL "<<" SHARES "<<"PRICE "<<"COST "<<endl;
    cout<<"_______________________________________"<<endl<<endl;

    for(int i=0;i<portfolio_stocks.size();i++){
        cout<<"  "<<portfolio_stocks[i].get_stock_name()<<"  "<<portfolio_stocks[i].get_number_of_shares()<<"      "<<portfolio_stocks[i].get_stock_price()<<" "<<portfolio_stocks[i].get_number_of_shares()*portfolio_stocks[i].get_stock_price()<<endl<<endl;
    }

}


//Implementation for buying stocks including number of shares, returns account balance
double buy_stock(double& balance,string name, double price,double num,vector<Portfolio>& portfolio_stocks){
    double new_balance;
    double cost=price*num;
    new_balance=balance-cost;
    bool found=false;
    for(int i=0;i<portfolio_stocks.size();i++){
        if(name==portfolio_stocks[i].get_stock_name()){
            portfolio_stocks[i].set_shares(portfolio_stocks[i].get_number_of_shares()+num);
            found=true;
            break;
        }
        
    }
    
    if(found==false)
    portfolio_stocks.push_back(Portfolio(name,num,price));
    cout<<"You have bought "<<num<<" shares of "<<name<<" stock and its been added to your Portfolio"<<endl;
    cout<<"This amount is deducted from your account balance: "<<cost<<endl<<endl;
    return new_balance;

 }

 //Implementation for selling stocks including number of shares, returns account balanc
 double sell_stock(double& balance,string name, double price, double num, vector<Portfolio>& portfolio_stocks){
    double new_balance;
    double new_sharesno=portfolio_stocks.back().get_number_of_shares()-num;
    double cost=price*num;
    new_balance=balance+cost;
    for(int i=0;i<portfolio_stocks.size();i++){
        if(name==portfolio_stocks[i].get_stock_name()){
            portfolio_stocks[i].set_shares(portfolio_stocks[i].get_number_of_shares()-num);
            if(portfolio_stocks[i].get_number_of_shares()==0){
                portfolio_stocks.erase(portfolio_stocks.begin()+(i));
            }
        }
    }
    cout<<"You have sold "<<num<<" shares of "<<name<<endl;
    cout<<"This amount is added to your account balance: "<<cost<<endl<<endl;
    return new_balance;
 }