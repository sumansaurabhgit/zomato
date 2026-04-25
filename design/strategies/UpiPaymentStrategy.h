#ifndef UPI_PAYMENT_STRATEGY_H
#define UPI_PAYMENT_STRATEGY_H

#include<bits/stdc++.h>
#include "PaymentStrategy.h"
using namespace std;

class UpiPaymentStrategy:public PaymentStrategy{
    private:
    string mobile;
    public:
    UpiPaymentStrategy(string mob){
        this->mobile=mob;
    }

    void pay(double amount)override{
        cout<<"paid"<<amount<<"using UPI"<<mobile<<endl;
    }
};

#endif