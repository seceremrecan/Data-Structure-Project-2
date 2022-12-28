/**
 * @file : Queue.cpp
 * @description : Radix sort mantığının oluşması için gerekli kuyruk methodlarının olduğu dosya
 * @course : Veri Yapıları 2.Ogretim B grubu
 * @assignment :  2
 * @date : 11.12.2022
 * @author : Emre Can SEÇER // emre.secer@ogr.sakarya.edu.tr
 */
#include "Queue.hpp"
#include <iomanip>
#include <iostream>
using namespace std;
queueNode::queueNode(int itm)
{
    data = itm;
    Next = NULL;
}
Queue::Queue()
{
    Front = NULL;
    back = NULL;
    size = 0;
}
Queue::~Queue()
{
    Clear();
}
void Queue ::Clear()
{
    while (!Empty())
        Dequeue();
}
int Queue::Meter()
{
    return size;
}
bool Queue::Empty()
{
    return size == 0;
}
int Queue::Peek()
{
    if (Empty())
        throw "Queue is empty";
    return Front->data;
}
void Queue::Enqueue(int item)
{
    queueNode *last = new queueNode(item);
    if (Empty())
        Front = back = last;
    else
    {
        back->Next = last;
        back = last;
    }
    size++;
}
void Queue::Dequeue()
{
    if (Empty())
        throw "Queue is empty";
    queueNode *eskiOn = Front;
    Front = Front->Next;
    delete eskiOn;
    size--;
}
