/**
 * @file : Cell.cpp
 * @description : Hücrelerin oluşturulması için liste mantığının değişkenlerinin atandığı dosya
 * @course : Veri Yapıları 2.Ogretim B grubu
 * @assignment :  2
 * @date : 11.12.2022
 * @author : Emre Can SEÇER // emre.secer@ogr.sakarya.edu.tr
 */
#include "Cell.hpp"
#include <iostream>
using namespace std;

Cell::Cell(int data)
{
    this->item = data;
    this->next = 0;
    this->prev = 0;
}
