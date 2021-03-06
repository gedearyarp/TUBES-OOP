#include "../header/recipes.hpp"

#include <iostream>
#include <vector>

using namespace std;

SingleRecipe::SingleRecipe()
{
    this->filename = "";
    this->NRowRecipe = 0;
    this->NColRecipe = 0;
    this->ItemResultName = "-";
    this->ItemResultQuantity = 0;
    this->ItemPlacement = vector<vector<string>>(0, vector<string>(0));
}

SingleRecipe::SingleRecipe(string filename, int Row, int Col, string ItemResultName, int ItemResultQuantity, vector<vector<string>> ItemPlacement)
{
    this->filename = filename;
    this->NRowRecipe = Row;
    this->NColRecipe = Col;
    this->ItemResultName = ItemResultName;
    this->ItemResultQuantity = ItemResultQuantity;
    this->ItemPlacement = ItemPlacement;
}

string SingleRecipe::getFilename()
{
    return this->filename;
}

int SingleRecipe::getNRowRecipe()
{
    return this->NRowRecipe;
}

int SingleRecipe::getNColRecipe()
{
    return this->NColRecipe;
}

string SingleRecipe::getItemResultName()
{
    return this->ItemResultName;
}

int SingleRecipe::getItemResultQuantity()
{
    return this->ItemResultQuantity;
}

vector<vector<string>> SingleRecipe::getItemPlacement()
{
    return this->ItemPlacement;
}

SingleRecipe SingleRecipe::getItemMirroredInPlacement()
{
    SingleRecipe mirroredRecipe;
    mirroredRecipe.NRowRecipe = this->getNRowRecipe();
    mirroredRecipe.NColRecipe = this->getNColRecipe();
    mirroredRecipe.ItemResultName = this->getItemResultName();
    mirroredRecipe.ItemResultQuantity = this->getItemResultQuantity();
    vector<vector<string>> originalPlacement = this->getItemPlacement();
    vector<vector<string>> mirroredPlacement = this->getItemPlacement();

    // mirrored matrix
    for (int i = 0; i < mirroredRecipe.NRowRecipe; i++)
    {
        for (int j = 0; j < mirroredRecipe.NColRecipe; j++)
        {
            mirroredPlacement[i][mirroredRecipe.NColRecipe - 1 - j] = originalPlacement[i][j];
        }
    }
    mirroredRecipe.ItemPlacement = mirroredPlacement;

    return mirroredRecipe;
}

// panggilnya nanti
// mirroredRecipe = getItemMirroredInPlacement(SingleRecipe originalRecipe)
// isOriginalRecipeSameAsMirroredRecipe(mirroredRecipe)
bool SingleRecipe::isOriginalRecipeSameAsMirroredRecipe(SingleRecipe mirroredRecipe)
{
    for (int i = 0; i < this->getNRowRecipe(); i++)
    {
        for (int j = 0; j < this->getNColRecipe(); j++)
        {
            if (this->ItemPlacement[i][j] != mirroredRecipe.ItemPlacement[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

void SingleRecipe::showItemPlacement()
{
    for (int i = 0; i < NRowRecipe; i++)
    {
        for (int j = 0; j < NColRecipe; j++)
        {
            cout << ItemPlacement[i][j] << " ";
        }
        cout << endl;
    }
}

Recipes::Recipes()
{
    this->totalRecipe = 0;
    vector<SingleRecipe> temp;
    this->recipesList = temp;
}

// Recipes::Recipes(int totalRecipe){
//     this->RecipesList = new SingleRecipe[totalRecipe];
// }

int Recipes::getTotalRecipe()
{
    return this->totalRecipe;
}

void Recipes::setTotalRecipe(int totalRecipe)
{
    this->totalRecipe = totalRecipe;
}

vector<SingleRecipe> Recipes::getRecipesList()
{
    return this->recipesList;
}

void Recipes::AddNewSingleRecipe(SingleRecipe newSingleRecipe)
{
    this->setTotalRecipe(this->getTotalRecipe() + 1);
    this->recipesList.push_back(newSingleRecipe);
}
