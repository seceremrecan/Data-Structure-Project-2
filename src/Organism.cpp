/**
 * @file : Organism.cpp
 * @description : Organizmayı oluşturan mutasyonsuz ağacın methodunun olduğu yer
 * @course : Veri Yapıları 2.Ogretim B grubu
 * @assignment :  2
 * @date : 11.12.2022
 * @author : Emre Can SEÇER // emre.secer@ogr.sakarya.edu.tr
 */
#include "Organ.hpp"
#include "ReadFile.hpp"
#include "Organism.hpp"
#include "Control.hpp"

void organism::real_Organism(read_File *files)
{
    Control *real_control_organism;
    for (int i = 0; i < files->organCount; i++)
    {
        if (i % 100 == 0)
        {
            if (i != 0)
            {
                cout << endl;
            }
        }

        real_control_organism->balanced(files->organ[i]->tree);
    }
}
