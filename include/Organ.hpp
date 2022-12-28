/**
 * @file : Organ.hpp
 * @description  : Organ.cpp kodlarının icindeki fonksiyonların basliklarinin tutuldugu yer
 * @course : Veri Yapıları 2.Ogretim B grubu
 * @assignment :  2
 * @date : 11.12.2022
 * @author : Emre Can SEÇER // emre.secer@ogr.sakarya.edu.tr
 */
#ifndef Organ_HPP
#define Organ_HPP
#include "Tissue.hpp"
#include "Binary_Tree.hpp"

struct organ_Node
{
public:
    tissue *data;
    organ_Node *left;
    organ_Node *right;
    organ_Node(tissue *data_node);
};
class organList
{
public:
    organList();
    ~organList();
    Binary_Tree *tree;

private:
    tissue *firstLine;
    organ_Node *root;
};
#endif