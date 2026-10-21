#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data data;
	data.id = 123;
	data.name = "Jan";

	Data *original = &data;
	uintptr_t raw = Serializer::serialize(original);
	Data *restored = Serializer::deserialize(raw);

	std::cout << original << std::endl;
	std::cout << raw << std::endl;
	std::cout << restored << std::endl;
	std::cout << (original == restored) << std::endl;
}
