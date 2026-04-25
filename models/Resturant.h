#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>
#include <vector>   
#include "MenuItem.h"
#endif // RESTAURANT_H

using namespace std;

class Restaurant{
      private:
      static int nextRestaurantId;
      int restaurantId;
      string location;
      string name;
      vector<MenuItem> menu;

      public:
      Restaurant(string name, string location){
            this->name = name;
            this->location = location;
            this->restaurantId = nextRestaurantId++;
      }

        string getName(){
                return name;
        }
        string getLocation(){
                return location;
        }
        int getRestaurantId(){
                return restaurantId;
        }
        vector<MenuItem> getMenu(){
                return menu;
        }

        void setName(string name){
                this->name = name;
        }
        void addMenuItem(MenuItem item){
                menu.push_back(item);
        }
};

int Restaurant::nextRestaurantId = 0;