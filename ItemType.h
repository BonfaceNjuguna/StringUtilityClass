#pragma once
#include "Item.h"
#include <iostream>

class BoxOfDonuts : public Item {
private:
	int m_donuts;

public:
	BoxOfDonuts(int _donuts);
	void Use() override;
	void Describe() const override;
};

class BoxOfPizza : public Item {
private:
	int m_slices;

public:
	BoxOfPizza(int _slices);
	void Use() override;
	void Describe() const override;
};

class BoxOfCandy : public Item {
private:
	int m_candies;

public:
	BoxOfCandy(int _candies);
	void Use() override;
	void Describe() const override;
};

class BoxOfCookies : public Item {
private:
	int m_cookies;

public:
	BoxOfCookies(int _cookies);
	void Use() override;
	void Describe() const override;
};