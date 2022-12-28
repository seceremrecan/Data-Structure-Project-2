/**
 * @file : Binary_Tree.hpp
 * @description  : Binary_Tree.cpp kodlarının icindeki fonksiyonların basliklarinin tutuldugu yer
 * @course : Veri Yapıları 2.Ogretim B grubu
 * @assignment :  2
 * @date : 11.12.2022
 * @author : Emre Can SEÇER // emre.secer@ogr.sakarya.edu.tr
 */

#ifndef Binary_Tree_hpp
#define Binary_Tree_hpp
#include <iostream>
#include "Tissue.hpp"
#include "Radix_Sort.hpp"

struct tree_node
{
public:
    tissue *data;
    tree_node *left;
    tree_node *right;
    tree_node(tissue *real_node);
    int height;
};
struct Binary_Tree
{
public:
    Binary_Tree();
    ~Binary_Tree();

    tree_node *root;

    Binary_Tree *sort();

    void separate();
    void separate(tree_node *below);

    void insert(tissue *data);
    void insert(tree_node *&add_Node, tissue *newItem);

    int height();
    int height(tree_node *real_Node);

    bool isBalanced(tree_node *real_Node);
    bool isBalanced();

    bool find(int furniture, tree_node *real);
    void postOrder(tree_node *real, Binary_Tree *tmp_Tree);
    void printLevel(tree_node *, int level);
    void levelorder();
    int bringLineNumber(std::string);

    int lineNumber = 0;
    string tmpLine = "";
    int left;
    int right;
    int left_Height;
    int right_Height;
};

#endif