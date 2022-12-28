/**
 * @file : Control.cpp
 * @description : Organizmaların kontrol edildiği dosya
 * @course : Veri Yapıları 2.Ogretim B grubu
 * @assignment :  2
 * @date : 11.12.2022
 * @author : Emre Can SEÇER // emre.secer@ogr.sakarya.edu.tr
 */
#include "Binary_Tree.hpp"
#include "Tissue.hpp"
#include "Organ.hpp"
#include "ReadFile.hpp"
#include "Control.hpp"
#include "Organism.hpp"
#include <iomanip>
#include <cmath>
#include <iostream>
using namespace std;

void Control::mutation_Organism(read_File *files)
{

    for (int i = 0; i < files->organCount; i++)
    {
        if (i % 100 == 0)
        {
            if (i != 0)
            {
                cout << endl;
            }
        }

        imp_mutation(files->organ, files->organCount);
        balanced(files->organ[i]->tree);
    }
}
bool Control::balanced(Binary_Tree *tree)
{

    if (tree->isBalanced())
    {
        cout << " ";
    }

    else
    {
        cout << "#";
    }
}
void Control::imp_mutation(organList **member, int meter)
{

    int mutation = 0;
    while (mutation < meter)
    {
        if (member[mutation]->tree->root->data->mid_values % 50 == 0)
        {
            member[mutation]->tree->separate();

            member[mutation]->tree = member[mutation]->tree->sort();
        }
        mutation++;
    }
}
int Control::bringLineNumber(string fileName)
{

    this->tmpLine;
    ifstream readFile;
    readFile.open(fileName);
    while (getline(readFile, tmpLine))
    {
        lineNumber++;
    }
    readFile.close();
    return lineNumber;
}
void Control::bringReal()
{
    read_File *bringFile = new read_File();
    Control *controlMutation = new Control();
    organism *bring_real;

    bringFile->read_Folder(bringFile->folder_Name);

    cout << setw(27) << "ORGANIZMA \n"
         << endl;
    bring_real->real_Organism(bringFile);
    cout << endl;

    if (cin.get() == '\n')
    {
        cout << setw(45) << "ORGANIZMA (MUTASYONA UGRADI) \n"
             << endl;
        controlMutation->mutation_Organism(bringFile);
    }
}