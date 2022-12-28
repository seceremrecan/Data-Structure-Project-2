/**
 * @file : ReadFile.cpp
 * @description : Dosyanın okunduğu ve organa ekleme işlemlerinin olduğu dosya
 * @course : Veri Yapıları 2.Ogretim B grubu
 * @assignment :  2
 * @date : 11.12.2022
 * @author : Emre Can SEÇER // emre.secer@ogr.sakarya.edu.tr
 */
#include "ReadFile.hpp"
#include "Cell.hpp"
#include "Organ.hpp"
#include "Organism.hpp"
#include "Tissue.hpp"
#include "Radix_Sort.hpp"
#include "Binary_Tree.hpp"
#include "Control.hpp"
#include "System.hpp"
#include <iostream>
using namespace std;

read_File::read_File()
{
    bringLine = new Binary_Tree();
    this->systemVariable = 0;
    this->lineNumber = bringLine->bringLineNumber(folder_Name);
    controlOrganism();
}
void read_File::organInsert(tissue *data)
{
    organ[organCount]->tree->insert(data);

    if (count % 20 == 0)
    {
        if (count != 0)
        {
            organCount++;
        }
    }
}
void read_File::systemInsert()
{

    this->organVariable = 0;
    int k = 100;
    while (k < organCount)
    {
        this->sistem[systemVariable]->organ[organVariable] = organ[k];
        if (k % 100 == 0)
        {
            if (k != 0)
            {
                systemVariable++;
                organVariable = 0;
            }
        }
        organVariable++;
        k++;
    }
}
void read_File::controlOrganism()
{
    bringLine = new Binary_Tree();

    this->dynamicTissue = new tissue *[lineNumber];
    organ = new organList *[lineNumber / 20];
    sistem = new system_List *[lineNumber / 2000];
    int i = 0;
    while (i < lineNumber / 20)
    {
        organ[i] = new organList();
        i++;
    }
    int k = 0;
    while (k < lineNumber)
    {
        dynamicTissue[k] = new tissue();
        k++;
    }
    int p = 0;
    while (p < lineNumber / 2000)
    {
        sistem[p] = new system_List();
        p++;
    }
}
void read_File::bringRadix()
{
    this->radixSortBy = new Radix(number, space_Value);
    this->serial = radixSortBy->Sort();
}
int read_File::read_Folder(string fileName)
{
    tissue *tissueControl;
    string lineLength;
    std::string strTissue;
    this->indicator = true;
    int lineValues;
    number[100];
    ifstream readFile;
    readFile.open(fileName);

    if (readFile.is_open())
    {

        while (std::getline(readFile, lineLength))
        {

            tissueControl = dynamicTissue[count];
            std::istringstream iss(lineLength);

            if (this->indicator)
            {
                space_Value = 0;
                int controlCondition = 0;
                while (std::getline(iss, strTissue, ' '))
                {
                    iss >> lineValues;
                    number[controlCondition] = lineValues;
                    space_Value++;
                    controlCondition++;
                }
            }
            bringRadix();

            while (int i = 0 && i < space_Value)
            {
                tissueControl->insert(serial[i]);
                i++;
            }
            tissueControl->mid_values = serial[space_Value / 2];
            count++;
            organInsert(tissueControl);

            tissueControl->blank = space_Value;
            delete[] serial;
            delete radixSortBy;
        }
        systemInsert();
    }
}
