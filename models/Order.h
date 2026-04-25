#ifndef OREDER_H
#define OREDER_H

#include<bits/stdc++.h>
#include "MenuItem.h"
#include "Resturant.h"
#include "User.h"

class Order{
      static int nextOrderId;
      int orderId;
      User* user;
      Restaurant* restaurant;
      vector<MenuItem>items;
      PaymentStrategy* paymentStrategy;
      double total;
      string scheduled;

      public:
      Order(){
        user=nullptr;
        restaurant=nullptr;
        paymentStrategy=nullptr;
        total=0.0;
        scheduled="";
        orderId=nextOrderId++;
      }

      bool processPayment(){
        if(paymentStrategy){
            paymentStrategy->pay(total);
            return true;
        }else{
            cout<<"please choose a payment mode first"<<endl;
            return false;
        }
      }

      virtual string getType()=0;

      int getOrderId(){
        return orderId;
      }

      void setUser(User* u){
        this->user=u;
      }

      User* getUser(){
        return user;
      }

      void setRestaurant(Restaurant* r){
           this->restaurant=r;
      }
      void setItems(vector<MenuItem>& its){
           this->items=its;
           total=0;
           for(auto it:items){
            total+=it->getPrice();
           }
      }

      vector<MenuItem> getItems(){
        return items;
      }

      void setPaymentStrategy(PaymentStrategy* p){
        this->paymentStrategy=p;
      }

      string getScheduled(){
        return scheduled;
      }

      double getTotal(){
        return total;
      }
      void setTotal(double total){
        this->total=total;
      }
};

int Order:: nextOrderId=0;
#endif // OREDER_H
