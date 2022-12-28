/**
 * @file : Radix_Sort.hpp
 * @description  : Radix_Sort.cpp kodlarının icindeki fonksiyonların basliklarinin tutuldugu yer
 * @course : Veri Yapıları 2.Ogretim B grubu
 * @assignment :  2
 * @date : 11.12.2022
 * @author : Emre Can SEÇER // emre.secer@ogr.sakarya.edu.tr
 */
#ifndef Radix_Sort_hpp
#define Radix_Sort_hpp
#include "Queue.hpp"
#include <cmath>
#include "Tissue.hpp"
class Radix
{
public:
	Radix(tissue *sort_Radix);
	Radix(int *, int);
	~Radix();
	tissue *SortTissue();
	Queue **queues;
	int *Sort();
	int *numbers;
	int *QueueCurrentLengths();
	void radix_Control();
	Radix *radix;
	int *inOrder;
	int step_Number();
	int step_Count(int);
	int radix_array[100];
	int length;
	int max_step;
};
#endif