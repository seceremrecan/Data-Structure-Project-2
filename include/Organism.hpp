/**
 * @file : Organism.hpp
 * @description  : Organism.cpp kodlarının icindeki fonksiyonların basliklarinin tutuldugu yer
 * @course : Veri Yapıları 2.Ogretim B grubu
 * @assignment :  2
 * @date : 11.12.2022
 * @author : Emre Can SEÇER // emre.secer@ogr.sakarya.edu.tr
 */
#ifndef Organism_HPP
#define Organism_HPP
#include <string>
#include "Tissue.hpp"
#include "Organ.hpp"
#include "System.hpp"

class organism
{
public:
    void allSystemControl();
    organList **organ;
    system_List **sistem;
    tissue **dynamicTissue;
    void real_Organism(read_File *);
};

#endif