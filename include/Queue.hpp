/**
 * @file : Queue.hpp
 * @description  : Queue.cpp kodlarının icindeki fonksiyonların basliklarinin tutuldugu yer
 * @course : Veri Yapıları 2.Ogretim B grubu
 * @assignment :  2
 * @date : 11.12.2022
 * @author : Emre Can SEÇER // emre.secer@ogr.sakarya.edu.tr
 */
#ifndef Queue_hpp
#define Queue_hpp
#include <iostream>
using namespace std;
struct queueNode
{
public:
    int data;
    queueNode *Next;
    queueNode(int data);
};
class Queue
{
public:
    Queue();
    ~Queue();

    int Peek();
    void Enqueue(int item);
    void Dequeue();
    void Clear();
    int Meter();
    bool Empty();

    int size;
    queueNode *Front;
    queueNode *back;
};
#endif