/**
 * @file : System.cpp
 * @description : Sistemi oluşturan methodların ve node ların silindiği dosya
 * @course : Veri Yapıları 2.Ogretim B grubu
 * @assignment :  2
 * @date : 11.12.2022
 * @author : Emre Can SEÇER // emre.secer@ogr.sakarya.edu.tr
 */
#include "System.hpp"
#include "ReadFile.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

system_List::system_List()
{
    organ = new organList *[100];
}

system_Node::system_Node(int data_node)
{
    data = data_node;
    left = NULL;
    right = NULL;
}
bool system_List::delete_Node(system_Node *tmp_Sys)
{
    system_Node *DelNode = tmp_Sys;

    if (tmp_Sys->right == NULL)
        tmp_Sys = tmp_Sys->left;
    else if (tmp_Sys->left == NULL)
        tmp_Sys = tmp_Sys->right;
    else
    {
        DelNode = tmp_Sys->left;
        system_Node *parent = tmp_Sys;
        while (DelNode->right != NULL)
        {
            parent = DelNode;
            DelNode = DelNode->right;
        }
        tmp_Sys->data = DelNode->data;
        if (parent == tmp_Sys)
            tmp_Sys->left = DelNode->left;
        else
            parent->right = DelNode->left;
    }
    delete DelNode;
    return true;
}
