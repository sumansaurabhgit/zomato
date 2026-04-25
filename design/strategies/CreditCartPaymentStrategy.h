#ifndef CREDIT_CARD_PAYMENT_STRATEGY_H
#define CREDIT_CARD_PAYMENT_STRATEGY_H

#include<bits/stdc++.h>
#include "PaymentStrategy.h"
using namespace std;

class CreditCartPaymentStrategy:public PaymentStrategy{
      private:
        string cardNumber;
        public:
        CreditCartPaymentStrategy(string cardNumber){
            this->cardNumber=cardNumber;
        }
        void pay(double amount){
            cout<<"Paid Rs"<<amount<<"using credit cart"<<cardNumber<<endl;
        }
};
#endif