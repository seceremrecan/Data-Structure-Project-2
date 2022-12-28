/**
 * @file : System.hpp
 * @description  : System.cpp kodlarının icindeki fonksiyonların basliklarinin tutuldugu yer
 * @course : Veri Yapıları 2.Ogretim B grubu
 * @assignment :  2
 * @date : 11.12.2022
 * @author : Emre Can SEÇER // emre.secer@ogr.sakarya.edu.tr
 */
#ifndef System_HPP
#define System_HPP
#include "Binary_Tree.hpp"
#include "Organ.hpp"

struct system_Node
{
public:
    system_Node(int data_node);
    int data;
    system_Node *left;
    system_Node *right;
};
struct system_List
{
public:
    system_List();

    organList **organ;
    Binary_Tree *tree;
    tissue *firstLine;
    system_Node *root;

    bool delete_Node(system_Node *sys_Node);
};

#endif