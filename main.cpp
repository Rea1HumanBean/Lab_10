#include <iostream>
#include <vector>

class details
{
private:
	std::string c_name;
	unsigned int c_price = 0;
	unsigned int c_lvl = 0;
public:
	details( std::string name, unsigned int price, unsigned int lvl)
	{
		c_name = name;
		c_price = price;
		c_lvl = lvl;
	}

	std::string Name()
	{
		return c_name;
	}

	int Level()
	{
		return c_lvl;
	}

	int Price_D()
	{
		return c_price;
	}
};

class car
{
private:
	std::string c_name;
	unsigned int c_price = 0;
	unsigned int c_lvl = 0;
	std::vector<details*> x_details;
public:
	car(std::string name, unsigned int price, unsigned int lvl)
	{
		c_name = name;
		c_price = price;
		 
	}

	void AddDetails(details* detail){
		x_details.push_back(detail);
	}

	void infoCar() {
		std::cout << "Car info" << std::endl;
		std::cout << " You got a " << c_name << std::endl;
		for (int i = 0; i < x_details.size(); i++)
			std::cout << x_details[i]->Name()<<" Level details - "<< x_details[i]->Level() << std::endl;
	}
	int Price()
	{
		return c_price;
	}
};


int main()
{
	int n = 10000, n1 = n, m_x;
	
	details* engine_1 = new details("stock engine", 1500, 1);
	details* transmission_1 = new details("stock transmission", 1500, 1);
	details* body_1 = new details("stock body", 0, 1);
	details* wheels_1 = new details("stock wheels", 0, 1);
	std::cout << "money-" << n << std::endl;
	std::cout << "If you want to buy a car press 1, otherwise press other button" << std::endl;
	std::cin >> m_x;

	if (m_x == 1) {
		car* car_1 = new car("Bucket", 2500, 1);
		car_1->AddDetails(engine_1);
		car_1->AddDetails(transmission_1); 
		car_1->AddDetails(body_1);
		car_1->AddDetails(wheels_1);
		car_1->infoCar();
		n = n - car_1->Price() - engine_1->Price_D() - transmission_1->Price_D();
		std::cout << "Money = "<< n<<std::endl;
	}
	else {
		std::cout << "You don't have cars" << std::endl;
		return 0;
	}
}
