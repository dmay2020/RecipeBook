//
//     RecipeBook.h
//     RecipeBook
//     Copyright © 2022 Derek May. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>


class recipe {
public:
	recipe(
		std::string title_ = "Title goes here.",
		std::string description_ = "Write a decription.",
		std::vector<std::string> ingredient_ = { "NULL" },
		std::vector<std::string> measurement_ = { "NULL" },
		std::vector<std::string> instruction_ = { "NULL" }
	)
		: title(title_), description(description_), ingredient(ingredient_), measurement(measurement_), instruction(instruction_) {}

	friend std::ostream& operator<<(std::ostream& os, const recipe& obj) {
		os << obj.title << "\n" << obj.description << "\n\nIngredients:\n";
		for (int i = 0; i < obj.measurement.size(); i++) {
			os << "   -" << obj.measurement[i];
			os << " " << obj.ingredient[i] << "\n";
		} os << "\nInstructions:\n";
		for (int i = 0; i < obj.instruction.size(); i++) {
			os << std::setw(5) << i + 1 << ". " << obj.instruction[i] << "\n";
		}
		return os;
	}

	std::string getTitle() { return title; }
	std::string getDescription() { return description; }
	std::vector<std::string> getIngredients() { return ingredient; }
	std::vector<std::string> getMeasurements() { return measurement; }
	std::vector<std::string> getInstructions() { return instruction; }
	std::vector<std::string> getSteps() { return instruction; }

	std::string getIngredient(int index) {
		if (!index || index > ingredient.size()) { index = 1; }
		index--;
		return ingredient.at(index);
	}
	std::string getMeasurement(int index) {
		if (!index || index > measurement.size()) { index = 1; }
		index--;
		return measurement.at(index);
	}
	std::string getInstruction(int index) {
		if (!index || index > instruction.size()) { index = 1; }
		index--;
		return instruction.at(index);
	} inline std::string getStep(int index) { return getInstruction(index); }

	recipe addIngredient(std::string measurement_ = "[Placeholder]", std::string ingredient_ = "[Placeholder]") {
		if (measurement[0] == "NULL") { measurement.pop_back(); }
		if (ingredient[0] == "NULL") { ingredient.pop_back(); }
		measurement.push_back(measurement_);
		ingredient.push_back(ingredient_);
		return *this;
	}
	recipe addInstruction(std::string instruction_ = "[Placeholder]") {
		if (instruction[0] == "NULL") { instruction.pop_back(); }
		instruction.push_back(instruction_);
		return *this;
	} inline recipe addStep(std::string argz) { addInstruction(argz); return *this; }

private:
	std::string title;
	std::string description;
	std::vector<std::string> ingredient;
	std::vector<std::string> measurement;
	std::vector<std::string> instruction;
};


class recipeBook {
public:
	recipeBook(
				std::string bookTitle_,
				std::string bookDescription_
			  )
			  : bookTitle(bookTitle_), bookDescription(bookDescription_) {}

	recipe getRecipe(unsigned int index) { return recipes[index]; }

	std::string getTitle() { return bookTitle; }

	std::string getDescription() { return bookDescription; }

	recipeBook addRecipe(recipe input, bool feedback = false) {
		recipes.push_back(input);
		if (feedback){ std::cout << "Added new recipe '" << input.getTitle() << "' to '" << bookTitle << "'. Recipes added: " << recipes.size() << "\n"; }
		return *this;
	}

	recipeBook addTerminalRecipe(bool feedback = false) {
		std::cout << "Write a title for this new recipe: ";
		std::string title = "NULL";
		std::getline(std::cin, title);
		std::cout << "Now, write a short description: ";
		std::string description = "NULL";
		std::getline(std::cin, description);
		recipe r(title, description);
		std::cout << "Now, list the ingredients you will need and their measurements:\n";
		std::vector<std::vector<std::string>> mi = inputMeasurementsAndIngredients();
		std::cout << "Now, list the steps needed to make this:\n";
		std::vector<std::string> in = inputInstructions();

		for (int i = 0; i < mi[1].size(); i++) {
			r.addIngredient(mi[0][i], mi[1][i]);
		}
		for (int i = 0; i < in.size(); i++) {
			r.addInstruction(in[i]);
		}

		recipes.push_back(r);
		if (feedback) { std::cout << "Added new recipe '" << r.getTitle() << "' to '" << bookTitle << "'. Recipes added: " << recipes.size() << "\n"; }
		return *this;
	}

private:
	std::string bookTitle;
	std::string bookDescription;
	std::vector<recipe> recipes;
	std::vector<std::vector<std::string>> inputMeasurementsAndIngredients() {
		std::vector<std::vector<std::string>> measurementsAndIngredients;
		std::vector<std::string> ingredient;
		std::vector<std::string> measurement;
		bool loop = true;
		while (loop) {
			std::string input;
			std::cout << "    Enter the measurement for this ingredient (or Type X to quit): ";
			std::getline(std::cin, input);
			if (input == "X") {
				loop = false;
			}
			else {
				measurement.push_back(input);
				input = "NULL";
				std::cout << "    Enter the name of this ingredient (or Type X to cancel and quit): ";
				std::getline(std::cin, input);
				if (input == "X") {
					measurement.pop_back();
					loop = false;
				}
				else {
					ingredient.push_back(input);
					std::cout << "    Ingredient added. Total ingredients: [" << ingredient.size() << "]\n";
				}
			}
		}
		measurementsAndIngredients.push_back(measurement);
		measurementsAndIngredients.push_back(ingredient);

		return measurementsAndIngredients;
	}
	std::vector<std::string> inputInstructions() {
		std::vector<std::string> instructions;
		bool loop = true;
		while (loop) {
			std::string input = "NULL";
			std::cout << "    Enter instruction #" << instructions.size() + 1 << " (or Type X to quit): ";
			std::getline(std::cin, input);
			if (input == "X") {
				loop = false;
			}
			else {
				instructions.push_back(input);
				std::cout << "    Instruction added. Total instructions: [" << instructions.size() << "]\n";
			}
		}
		return instructions;
	}
};