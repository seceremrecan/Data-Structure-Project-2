/**
 * @file : Radix_Sort.cpp
 * @description : Radix sort için gerekli methodların olduğu dosya
 * @course : Veri Yapıları 2.Ogretim B grubu
 * @assignment :  2
 * @date : 11.12.2022
 * @author : Emre Can SEÇER // emre.secer@ogr.sakarya.edu.tr
 */
#include "Radix_Sort.hpp"
#include "ReadFile.hpp"
#include "Organ.hpp"

int Radix::step_Number()
{
	int max = 0;
	for (int i = 0; i < length; i++)
	{
		if (step_Count(numbers[i]) > max)
			max = step_Count(numbers[i]);
	}
	return max;
}
int Radix::step_Count(int number)
{
	number = abs(number);
	int basamak = 0;
	while (number > 0)
	{
		basamak++;
		number /= 10;
	}
	return basamak;
}
Radix::Radix(int *numbers, int length)
{
	this->numbers = new int[length];
	this->length = length;
	for (int i = 0; i < length; i++)
	{
		this->numbers[i] = numbers[i];
	}
	queues = new Queue *[10];
	for (int j = 0; j < 10; j++)
	{
		queues[j] = new Queue();
	}
	max_step = step_Number();
}
Radix::Radix(tissue *tmpRadix)
{
	Cell *radix;
	int count = tmpRadix->size;
	this->numbers = new int[count];
	this->length = length;
	int counter = 0;

	while (tmpRadix->IsEmpty())
	{
		radix = tmpRadix->bringNode(counter);
		this->numbers[counter] = radix->item;
		counter++;
		tmpRadix->in_line();
	}
	for (int i = 0; i < length; i++)
	{
		this->numbers[i] = numbers[i];
	}
	queues = new Queue *[10];
	for (int j = 0; j < 10; j++)
	{
		queues[j] = new Queue();
	}
	max_step = step_Number();
}
int *Radix::QueueCurrentLengths()
{
	int *lengths = new int[10];
	for (int i = 0; i < 10; i++)
	{
		lengths[i] = queues[i]->Meter();
	}
	return lengths;
}
tissue *Radix::SortTissue()
{
	int numberIndex = 0;

	for (; numberIndex < length; numberIndex++)
	{
		int stepValue = numbers[numberIndex] % 10;
		int num = numbers[numberIndex];
		queues[stepValue]->Enqueue(num);
	}

	for (int i = 1; i < max_step; i++)
	{

		int *qlengths = QueueCurrentLengths();
		for (int index = 0; index < 10; index++)
		{
			int len = qlengths[index];
			for (; len > 0; len--)
			{
				int number = queues[index]->Peek();
				queues[index]->Dequeue();
				int stepValue = (number / (int)pow(10, i)) % 10;
				queues[stepValue]->Enqueue(number);
			}
		}
		delete[] qlengths;
	}
	tissue *ordered = new tissue();
	numberIndex = 0;
	for (int index = 0; index < 10; index++)
	{
		while (!queues[index]->Empty())
		{
			int number = queues[index]->Peek();
			ordered->insert(number);
			queues[index]->Dequeue();
		}
	}
	int orderedcount = ordered->size;
	ordered->mid_values = ordered->bringNode(orderedcount / 2)->item;
	return ordered;
}
void Radix::radix_Control()
{
	read_File *sort_Array;
	this->radix = new Radix(radix_array, sort_Array->space_Value);
	this->inOrder = Sort();
}
int *Radix::Sort()
{
	int numberIndex = 0;

	for (; numberIndex < length; numberIndex++)
	{
		int stepValue = numbers[numberIndex] % 10;
		int num = numbers[numberIndex];
		queues[stepValue]->Enqueue(num);
	}

	for (int i = 1; i < max_step; i++)
	{

		int *qlengths = QueueCurrentLengths();
		for (int index = 0; index < 10; index++)
		{
			int len = qlengths[index];
			for (; len > 0; len--)
			{
				int number = queues[index]->Peek();
				queues[index]->Dequeue();
				int stepValue = (number / (int)pow(10, i)) % 10;
				queues[stepValue]->Enqueue(number);
			}
		}
		delete[] qlengths;
	}
	int *ordered = new int[length];
	numberIndex = 0;
	for (int index = 0; index < 10; index++)
	{
		while (!queues[index]->Empty())
		{
			int number = queues[index]->Peek();
			ordered[numberIndex++] = number;
			queues[index]->Dequeue();
		}
	}

	return ordered;
}
Radix::~Radix()
{
	delete[] numbers;
	for (int i = 0; i < 10; i++)
		delete queues[i];
	delete[] queues;
}