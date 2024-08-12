/*
 ******************************************************************************
 * Created On     : Aug 10,2024
 * File           : Linked_list.h
 * Author         : Beshoy Emad
 ******************************************************************************
*/

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//effective data
struct Sdata
{
	int ID;
	char name[40];
	float height ;
};

//linked list node
struct Sstudent
{
	struct Sdata student;
	struct Sstudent* PNextStudent; 
};


// APIs
void Add_Student();
int Delete_Student();
void View_Students();
void Delete_All();
int Get_Nth ();
int Get_Nth_from_the_end ();
int Iterative_Length_linked_List();
int Recursive_Length_linked_List(struct Sstudent* plengthstudent);
int middle_linked_List();
int detect_loop();
void Reverse_linked_list();

#endif