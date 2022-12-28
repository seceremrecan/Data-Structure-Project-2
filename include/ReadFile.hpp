/**
 * @file : ReadFile.hpp
 * @description  : ReadFile.cpp kodlarının icindeki fonksiyonların basliklarinin tutuldugu yer
 * @course : Veri Yapıları 2.Ogretim B grubu
 * @assignment :  2
 * @date : 11.12.2022
 * @author : Emre Can SEÇER // emre.secer@ogr.sakarya.edu.tr
 */
#ifndef ReadFile_HPP
#define ReadFile_HPP
#include <string>
#include "Cell.hpp"
#include "Tissue.hpp"
#include "Organ.hpp"
#include "System.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

struct read_File
{
public:
    std::string folder_Name = "veri.txt";
    int organCount = 0;
    int count = 0;

    organList **organ;
    system_List **sistem;
    Binary_Tree *bringLine;
    tissue **dynamicTissue;
    Radix *radixSortBy;
    int *serial;

    void organInsert(tissue *data);
    int read_Folder(std::string);
    int bringLineNumber(std::string);
    void systemInsert();
    void controlOrganism();
    void getLineValues();
    void bringRadix();

    string tmpLine = "";
    int organVariable;
    int systemVariable;
    int lineNumber = 0;
    int space_Value;
    bool indicator;
    int number[];

    read_File();
    ~read_File();
};

#endif