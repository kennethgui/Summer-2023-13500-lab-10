/*
Kenneth Guillont
Kenneth.guillont83@myhunter.cuny.edu
Lab Quiz 11
*/

#include <iostream>
using namespace std;

class Money {
    public:
        int dollars;
        int cents;
};

Money withdraw_money(Money balance, Money withdrawal)
{
    Money difference;
    int balanceAmount = (balance.dollars * 100) + balance.cents;
    int withdrawalAmount = (withdrawal.dollars * 100) + withdrawal.cents;

    int cost = balanceAmount - withdrawalAmount;

    difference.dollars = cost / 100;
    difference.cents = cost % 100;

    if(cost < 0)
    {
        difference.dollars = 0;
        difference.cents = 0;
    }

    return difference;

}

int main()
{
    Money starting = {100, 00};
    Money withdrawal = {2, 75};
    Money ending = withdraw_money(starting, withdrawal);
    cout << "$" << ending.dollars << "." << ending.cents << endl;
}