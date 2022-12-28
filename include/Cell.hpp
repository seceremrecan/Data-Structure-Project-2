/**
 * @file : Cell.hpp
 * @description  : Cell.cpp kodlarının icindeki fonksiyonların basliklarinin tutuldugu yer
 * @course : Veri Yapıları 2.Ogretim B grubu
 * @assignment :  2
 * @date : 11.12.2022
 * @author : Emre Can SEÇER // emre.secer@ogr.sakarya.edu.tr
 */

#ifndef Cell_HPP
#define Cell_HPP

class Cell
{
public:
  Cell *next;
  Cell *prev;

  Cell(int item);
  int item;
};

#endif