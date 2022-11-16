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

	recipeBook addRecipe(recipe input) {
		recipes.push_back(input);
		return *this;
	}

private:
	std::string bookTitle;
	std::string bookDescription;
	std::vector<recipe> recipes;
};