#include <iostream>


#include "Node.h"
#include "List.h"
#include "String.h"
#include "Parser.h"
#include "CSS.h"


namespace tests {
	void testList() {
		List<int> integersList;
		integersList.append(1);
		integersList.append(2);
		integersList.append(3);
		integersList.append(4);
		integersList.append(5);
		std::cerr << integersList;

		List<String> stringsList;
		stringsList.append("Hello");
		stringsList.append("World");
		stringsList.append("!");
		std::cerr << stringsList;

		List<List<int>> listOfIntegersLists;
		listOfIntegersLists.append(integersList);
		listOfIntegersLists.append(integersList);
		listOfIntegersLists.append(integersList);
		listOfIntegersLists.print();

		List<List<String>> stringListList;
		stringListList.append(stringsList);
		stringListList.append(stringsList);
		stringListList.append(stringsList);
		stringListList.print();
	}


	void testString() {
		String string1 = "Hello";
		String string1Copy = string1;
		String string2 = "World";
		String string3 = string1 + " " + string2;
		String string4 = "Vivat";
		string4 += " ";
		string4 += string3;

		std::cerr << string1 << std::endl;
		std::cerr << string1Copy << std::endl;
		std::cerr << string2 << std::endl;
		std::cerr << string3 << std::endl;
		std::cerr << string4 << std::endl;

		for (int i = 0; i < 5; i++) {
			std::cerr << string1[i] << std::endl;
		}

		std::cerr << string1.getLength() << std::endl;
		std::cerr << string2.getLength() << std::endl;
		std::cerr << string3.getLength() << std::endl;
		std::cerr << string4.getLength() << std::endl;

		std::cerr << (string1 == string1Copy) << std::endl;
		std::cerr << (string1 == string2) << std::endl;
	}


	void runTests() {
		testList();
		testString();
	}
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	//tests::runTests();

	Parser parser;
	
	parser.loadInput();
	parser.parseInput();
	
	parser.executeCommands();

	return 0;
}
