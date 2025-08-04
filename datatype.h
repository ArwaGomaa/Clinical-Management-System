#ifndef DATA_TYPE_H
#define DATA_TYPE_H
#include <stdio.h> 
typedef unsigned  char u8;
typedef signed  char s8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef signed short int s16;
typedef signed long int s32;
typedef float f32;
typedef double f64;
typedef struct{
    u8 name[100];
    u16 age;
    u8 gender;
    u32 ID;
	s8 reserved;
}Patient;
extern u32 reservations[5];
extern u32 count;
#endif