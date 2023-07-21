# Stock_market_project

A program that allows Users to buy and sell stocks and manage their portfolio.

## How to Run

g++ main.cpp portfolio.cpp stock.cpp -o ready.exe

.\ready.exe

## Functions

* Display the User's portfolio including Stock symbols, number of shares, price of stock, cost of transaction.
* Allow the User to buy stocks and then update the User's account balance.
* Allow the User to sell stocks from their portfolio and then update the User's account balance.

## LOGIC

* This program has two classes, Stock and Portfolio.
* The Stock class stores the symbol of the stocks and the price of the stocks.
* The Portfolio class stores the information after a stock is bought. It includes stock symbol, number of shares and price of the stock
* The program uses vector to store stock data and portfolio data
## STEPS
    1) Take the User account balance
    2) Give User the option to display portfolio,buy stocks and sell stocks
    3) User can choose which stock to buy and then choose the number of shares to buy, it is then added to User's portfolio, then updates User's account balance.
    4) User can choose which stock to sell and then choose the number of shares to sell, it is then removed from the User's portfolio, then updates User's account balance
    5) This program can be run mutliple times allowing the user to buy and sell different stocks mutliple times.
