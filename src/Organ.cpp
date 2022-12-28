/**
 * @file : Organ.cpp
 * @description : Dokuların ağacı oluşturduğu dosya
 * @course : Veri Yapıları 2.Ogretim B grubu
 * @assignment :  2
 * @date : 11.12.2022
 * @author : Emre Can SEÇER // emre.secer@ogr.sakarya.edu.tr
 */
#include "Organ.hpp"
#include "ReadFile.hpp"

organList::organList()
{
    this->tree = new Binary_Tree();
}
