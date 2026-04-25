#ifndef USER_H
#define USER_H

#include <string>
using namespace std;
#include "Cart.h"

class User {
    private:
        int userId;
        string name;
        string address;
        Cart* cart;

        public:
        User(int userId, string name, string address) {
            this->userId = userId;
            this->name = name;
            this->address = address;
            this->cart = new Cart();
        }

        ~User() {
            delete cart;
        }
        int getUserId() {
            return userId;
        }
        string getName() {
            return name;
        }
        string getAddress() {
            return address;
        }
        Cart* getCart(){
            return cart;
        }
};



#endif // USER_H