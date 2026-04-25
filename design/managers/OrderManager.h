#ifndef ORDER_MANAGER_H
#define ORDER_MANAGER_H
#include "Order.h"
#include<bits/stdc++.h>
using namespace std;
class OrderManager{
    private:
    vector<Order*> orders;
    static OrderManager* instance;
    OrderManager(){}
    public:
    static OrderManager* getInstance(){
        if(!instance){
            instance=new OrderManager();
        }
        return instance;
    }
    void addOrder(Order* order){
        orders.push_back(order);
    }
    void listOrder(){
        cout<<"\n---- All order-----"<<endl;
        for(auto order:orders){
            cout<<order->getType()<<"order for"<<order->getUser()->getName()<<"| Total:"<<order->getTotal()<<"| at:"<<order->getScheduled()<<endl;
        }
    }
};

OrderManager* OrderManager::instance=nullptr;
#endif