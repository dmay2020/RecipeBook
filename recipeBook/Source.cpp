//
//     Source.cpp
//     RecipeBook Source
//     Copyright © 2022 Derek May. All rights reserved.
//

#include <iostream>
#include "RecipeBook.h"
using namespace std;


int main() {
	recipeBook book("My Recipe Book", "Contains many recipes.");
	recipe a("Chicken Stew", "Everyone's favorite stew!");
	a.addIngredient("1 tbsp", "Butter");
	a.addIngredient("1 qt", "Chicken Broth");
	a.addIngredient("1", "Whole chicken");
	a.addInstruction("Melt butter.");
	a.addInstruction("Add to pot with broth and chicken.");
	a.addInstruction("Bring to a simmer and serve.");
	book.addRecipe(a, true);
	//book.addTerminalRecipe(true);

	return 0;
}