/**
 * @file : Binary_Tree.cpp
 * @description : Ağaç yapısının oluşturulduğu dosya
 * @course : Veri Yapıları 2.Ogretim B grubu
 * @assignment :  2
 * @date : 11.12.2022
 * @author : Emre Can SEÇER // emre.secer@ogr.sakarya.edu.tr
 */
#include "Binary_Tree.hpp"
#include "Organ.hpp"
#include "Control.hpp"
#include "ReadFile.hpp"
#include <iomanip>
#include <cmath>
#include <iostream>
using namespace std;
tree_node::tree_node(tissue *data_node)
{
    data = data_node;
    left = NULL;
    right = NULL;
    height = 0;
}
Binary_Tree::Binary_Tree()
{
    root = NULL;
}
Binary_Tree::~Binary_Tree()
{
}

void Binary_Tree::insert(tree_node *&real_node, tissue *newItem)
{

    if (real_node == NULL)
        real_node = new tree_node(newItem);
    else if (newItem->mid_values < real_node->data->mid_values)
        insert(real_node->left, newItem);
    else if (newItem->mid_values == real_node->data->mid_values)
        insert(real_node->left, newItem);
    else if (newItem->mid_values > real_node->data->mid_values)
        insert(real_node->right, newItem);
    else
        return;
}
void Binary_Tree::postOrder(tree_node *real, Binary_Tree *tmp_Tree)
{
    if (real)
    {
        postOrder(real->left, tmp_Tree);
        postOrder(real->right, tmp_Tree);
        tmp_Tree->insert(real->data);
    }
}
int Binary_Tree::height(tree_node *real_node)
{
    if (real_node == NULL)
        return 0;

    return 1 + max(height(real_node->left), height(real_node->right));
}
int Binary_Tree::height()
{
    return height(root);
}
void Binary_Tree::printLevel(tree_node *add_Node, int level)
{
    if (add_Node == NULL)
        return;
    if (level == 0)
        cout << add_Node->data << " ";
    else
    {
        printLevel(add_Node->left, level - 1);
        printLevel(add_Node->right, level - 1);
    }
}
void Binary_Tree::insert(tissue *newItem)
{
    insert(root, newItem);
}

bool Binary_Tree::find(int item, tree_node *add_Node)
{
    if (add_Node == NULL)
        return false;
    if (add_Node->data->mid_values == item)
        return true;
    if (item < add_Node->data->mid_values)
        return find(item, add_Node->left);
    else
        return find(item, add_Node->right);
}
void Binary_Tree::levelorder()
{
    int h = height();
    for (int level = 0; level <= h; level++)
    {
        printLevel(root, level);
    }
}
void Binary_Tree::separate(tree_node *below)
{
    if (below)
    {
        separate(below->left);
        separate(below->right);
        below->data->separate();
    }
}
bool Binary_Tree::isBalanced()
{
    return isBalanced(root);
}
void Binary_Tree::separate()
{
    separate(this->root);
}
Binary_Tree *Binary_Tree::sort()
{
    Binary_Tree *hardWood = new Binary_Tree();
    postOrder(this->root, hardWood);
    return hardWood;
}
int Binary_Tree::bringLineNumber(string fileName)
{
    this->tmpLine;
    ifstream readFolder;
    readFolder.open(fileName);
    while (getline(readFolder, tmpLine))
    {
        lineNumber++;
    }
    readFolder.close();
    return lineNumber;
}
bool Binary_Tree::isBalanced(tree_node *root)
{

    if (root == NULL)
        return 1;

    left_Height = height(root->left);
    right_Height = height(root->right);

    if (abs(left_Height - right_Height) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;

    return 0;
}
