#include "ItemType.h"
#include "../String.h"
#include <iostream>
#include <string>

BoxOfDonuts::BoxOfDonuts(int _donuts) : m_donuts(_donuts) {}

void BoxOfDonuts::Use() {
    if (m_donuts > 0) {
        String("You eat a donut. Delicious!\n").WriteToConsole();
        m_donuts--;
    }
    else {
        String("The donuts are gone.\n").WriteToConsole();
    }
}

void BoxOfDonuts::Describe() const {
    if (m_donuts > 0) {
        String("A box of donuts. There are " + std::to_string(m_donuts) + " donuts left.\n").WriteToConsole();
    }
    else {
        String("An empty box of donuts.\n").WriteToConsole();
    }
}

BoxOfPizza::BoxOfPizza(int _slices) : m_slices(_slices) {}

void BoxOfPizza::Use() {
    if (m_slices > 0) {
        String("You eat a slice of pizza. Delicious!\n").WriteToConsole();
        m_slices--;
    }
    else {
        String("The pizza is gone.\n").WriteToConsole();
    }
}

void BoxOfPizza::Describe() const {
    if (m_slices > 0) {
        String("A pizza. There are " + std::to_string(m_slices) + " slices left.\n").WriteToConsole();
    }
    else {
        String("An empty pizza box.\n").WriteToConsole();
    }
}

BoxOfCandy::BoxOfCandy(int _candies) : m_candies(_candies) {}

void BoxOfCandy::Use() {
    if (m_candies > 0) {
        String("You eat a candy. Delicious!\n").WriteToConsole();
        m_candies--;
    }
    else {
        String("The box is empty.\n").WriteToConsole();
    }
}

void BoxOfCandy::Describe() const {
    if (m_candies > 0) {
        String("A box of candy. There are " + std::to_string(m_candies) + " candies left.\n").WriteToConsole();
    }
    else {
        String("An empty box of candy.\n").WriteToConsole();
    }
}

BoxOfCookies::BoxOfCookies(int _cookies) : m_cookies(_cookies) {}

void BoxOfCookies::Use() {
    if (m_cookies > 0) {
        String("You eat a cookie. Delicious!\n").WriteToConsole();
        m_cookies--;
    }
    else {
        String("The box is empty.\n").WriteToConsole();
    }
}

void BoxOfCookies::Describe() const {
    if (m_cookies > 0) {
        String("A box of cookies. There are " + std::to_string(m_cookies) + " cookies left.\n").WriteToConsole();
    }
    else {
        String("An empty box of cookies.\n").WriteToConsole();
    }
}
