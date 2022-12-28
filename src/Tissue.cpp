/**
 * @file : Tissue.cpp
 * @description : Dokuları oluşturan ve ekleme yapan bağlı listelerin olduğu dosya
 * @course : Veri Yapıları 2.Ogretim B grubu
 * @assignment :  2
 * @date : 11.12.2022
 * @author : Emre Can SEÇER // emre.secer@ogr.sakarya.edu.tr
 */
#include "Tissue.hpp"
#include "ReadFile.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

tissue::tissue()
{
    early_Line = 0;
    this->size = 0;
    blank = 0;
}
tissue::~tissue()
{
    Cell *gec = early_Line;
    while (gec != 0)
    {
        Cell *sil = gec;
        gec = gec->next;
        delete sil;
    }
}
void tissue::in_line()
{
    Cell *tmp = this->early_Line;
    if (tmp != 0)
    {
        this->early_Line = this->early_Line->next;
        delete tmp;
        this->size--;
    }
}
void tissue::separate()
{
    Cell *tmp = this->early_Line;
    while (tmp != 0)
    {
        if (tmp->item % 2 == 0)
            tmp->item = tmp->item / 2;
        tmp = tmp->next;
    }
}
Cell *tissue::bringNode(int sequence)
{
    Cell *tardy = early_Line;
    while (sequence >= 0 && tardy != 0)
    {
        if (sequence == 0)
            return tardy;
        tardy = tardy->next;
        sequence--;
    }
    return 0;
}
bool tissue::IsEmpty()
{
    return this->size == 0;
}
ostream &operator<<(ostream &os, tissue &tissue)
{
    return os;
}
void tissue::insert(int data)
{
    Cell *recent = new Cell(data);
    if (early_Line == 0)
    {
        early_Line = recent;
    }
    else
    {
        Cell *gec = early_Line;
        while (gec->next != 0)
            gec = gec->next;

        gec->next = recent;
    }
    this->size++;
}
