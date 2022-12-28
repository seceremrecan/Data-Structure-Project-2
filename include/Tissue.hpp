/**
 * @file : Tissue.hpp
 * @description  : Tissue.cpp kodlarının icindeki fonksiyonların basliklarinin tutuldugu yer
 * @course : Veri Yapıları 2.Ogretim B grubu
 * @assignment :  2
 * @date : 11.12.2022
 * @author : Emre Can SEÇER // emre.secer@ogr.sakarya.edu.tr
 */
#ifndef Tissue_hpp
#define Tissue_hpp
#include "Cell.hpp"
#include <iostream>
#include <iomanip>
using namespace std;
struct tissue
{
public:
    int blank;
    int mid_values;
    int size;

    Cell *early_Line;
    Cell *bringNode(int sira);
    tissue *next;
    tissue *prev;
    tissue *data;

    tissue();
    ~tissue();
    tissue(tissue *data);

    void insert(int data);
    void cikar();
    void separate();
    bool IsEmpty();
    void in_line();
    void variable();
};

#endif
