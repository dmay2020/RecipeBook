//
//     Source.cpp
//     RecipeBook Source
//     Copyright © 2022 Derek May. All rights reserved.
//

#include <iostream>
#include "RecipeBook.h"
using namespace std;

vector<vector<string>> inputMeasurementsAndIngredients() {
	vector<vector<string>> measurementsAndIngredients;
	vector<string> ingredient;
	vector<string> measurement;
	bool loop = true;
	while (loop) {
		string input;
		cout << "    Enter the measurement for this ingredient (or Type X to quit): ";
		std::getline(std::cin, input);
		if (input == "X") {
			loop = false;
		}
		else {
			measurement.push_back(input);
			input = "NULL";
			cout << "    Enter the name of this ingredient (or Type X to cancel and quit): ";
			std::getline(std::cin, input);
			if (input == "X") {
				measurement.pop_back();
				loop = false;
			}
			else {
				ingredient.push_back(input);
				cout << "    Ingredient added. Total ingredients: [" << ingredient.size() << "]\n";
			}
		}
	}
	measurementsAndIngredients.push_back(measurement);
	measurementsAndIngredients.push_back(ingredient);

	return measurementsAndIngredients;
}

vector<string> inputInstructions() {
	vector<string> instructions;
	bool loop = true;
	while (loop) {
		string input = "NULL";
		cout << "    Enter instruction #" << instructions.size()+1 << " (or Type X to quit): ";
		std::getline(std::cin, input);
		if (input == "X") {
			loop = false;
		}
		else {
			instructions.push_back(input);
			cout << "    Instruction added. Total instructions: [" << instructions.size() << "]\n";
		}
	}
	return instructions;
}

recipeBook newRecipe(recipeBook rb) {
	cout << "Write a title for this new recipe: ";
	string title = "NULL";
	std::getline(std::cin, title);
	cout << "Now, write a short description: ";
	string description = "NULL";
	std::getline(std::cin, description);
	recipe r(title, description);
	cout << "Now, list the ingredients you will need and their measurements:\n";
	vector<vector<string>> measurementsAndIngredients = inputMeasurementsAndIngredients();
	cout << "Now, list the steps needed to make this:\n";
	vector<string> instruction = inputInstructions();

	for (int i = 0; i < measurementsAndIngredients[1].size(); i++) {
		r.addIngredient(measurementsAndIngredients[0][i], measurementsAndIngredients[1][i]);
	}
	for (int i = 0; i < instruction.size(); i++) {
		r.addInstruction(instruction[i]);
	}

	rb.addRecipe(r);
	return rb;
}
	
int main() {
	recipe a("Chicken Stew", "Everyone's favorite stew!");

	a.addIngredient("1 tbsp", "Butter");
	a.addIngredient("1 qt", "Chicken Broth");
	a.addIngredient("1", "Whole chicken");

	a.addInstruction("Melt butter.");
	a.addInstruction("Add to pot with broth and chicken.");
	a.addInstruction("Bring to a simmer and serve.");

	recipeBook grandmasCookbook("Grandma's Cookbook", "Stored on the top shelf for years!");
	grandmasCookbook.addRecipe(a);

	cout << grandmasCookbook.getRecipe(0) << "\n\nNow starting test of recipe addition to a book object...\n\n";

	recipeBook book("My Recipe Book", "Contains many recipes.");
	book = newRecipe(book);

	cout << book.getTitle() << "\n" << book.getDescription() << "\n\n" << book.getRecipe(0);

	return 0;
}