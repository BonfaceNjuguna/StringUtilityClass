#include "Item.cpp"
#include <iostream>

class BoxOfDonuts : public Item {
private:
	int m_donuts;

public:
	BoxOfDonuts(int _donuts) : m_donuts(_donuts) {}
	virtual void Use() override {
		if (m_donuts > 0) {
			std::cout << "You eat a donut. Delicious!" << std::endl;
			m_donuts--;
		}
		else {
			std::cout << "The box is empty." << std::endl;
		}
	}
	virtual void Describe() override {
		if (m_donuts > 0) {
			std::cout << "A box of donuts. There are " << m_donuts << " donuts left." << std::endl;
		}
		else {
			std::cout << "An empty box of donuts." << std::endl;
		}
	}
};

class BoxOfPizza : public Item {
	private:
		int m_slices;

	public:
		BoxOfPizza(int _slices) : m_slices(_slices) {}
		virtual void Use() override {
			if (m_slices > 0) {
				std::cout << "You eat a slice of pizza. Delicious!" << std::endl;
				m_slices--;
			}
			else {
				std::cout << "The pizza is gone." << std::endl;
			}
		}
		virtual void Describe() override {
			if (m_slices > 0) {
				std::cout << "A pizza. There are " << m_slices << " slices left." << std::endl;
			}
			else {
				std::cout << "An empty pizza box." << std::endl;
			}
		}
};