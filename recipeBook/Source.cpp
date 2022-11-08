#include <iostream>
#include "RecipeBook.h"
using namespace std;

int main() {
	recipe a("Chicken Stew", "Grandma's best recipe ever!");

	a.addIngredient("1 tbsp", "Butter");
	a.addIngredient("1 qt", "Chicken Broth");
	a.addIngredient("1", "Whole chicken");

	a.addInstruction("Melt butter.");
	a.addInstruction("Add to pot with broth and chicken.");
	a.addInstruction("Bring to a simmer and serve.");

	cout << a;

	return 0;
}