#ifndef CART_H
#define CART_H

#include<iostream>
#include<vector>
#include<string>
#include "../models/MenuItem.h"
#include "../models/Resturant.h"

using namespace std;

class Cart{
        private:
        Restaurant* restaurant;
        vector<MenuItem> items;
        public:
        Cart(){
            restaurant=nullptr;
        }
        void addItem(Restaurant* restaurant, MenuItem item){
            if(this->restaurant == nullptr){
                this->restaurant = restaurant;
            }
            else if(this->restaurant != restaurant){
                cout << "Cannot add items from different restaurants to the cart." << endl;
                return;
            }
            items.push_back(item);
        }
        double getTotalPrice(){
            double total = 0;
            for(auto it:items){
                total+=it.getPrice();
            }
        }

        bool isEmpty(){
            return items.empty();
        }

        void clearCart(){
            items.clear();
            restaurant=nullptr;
        }

        void setRestaurant(Restaurant* r){
            this->restaurant = r;
        }
        Restaurant* getRestaurant(){
            return restaurant;
        }

        vector<MenuItem> getItems(){
            return items;
        }

};

#endif // CART_H