/**
 * @file : Control.hpp
 * @description  : Control.cpp kodlarının icindeki fonksiyonların basliklarinin tutuldugu yer
 * @course : Veri Yapıları 2.Ogretim B grubu
 * @assignment :  2
 * @date : 11.12.2022
 * @author : Emre Can SEÇER // emre.secer@ogr.sakarya.edu.tr
 */

#ifndef Control_HPP
#define Control_HPP
#include "Binary_Tree.hpp"
#include "Tissue.hpp"
#include "Organ.hpp"
#include "ReadFile.hpp"
#include "Control.hpp"
#include "Organism.hpp"
#include <iomanip>
#include <cmath>
#include <iostream>

class Control
{

public:
    organList **mutation_Organ;

    bool balanced(Binary_Tree *tree);
    void mutation_Organism(read_File *);
    void bringReal();
    void imp_mutation(organList **member, int meter);
    int bringLineNumber(std::string);
    int lineNumber = 0;
    string tmpLine = "";
};

#endif