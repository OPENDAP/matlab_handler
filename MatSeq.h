/*
*
  This file contains common extern declarations used by the DODS-MATLAB code.
  ReZa, Dec-1996
*
*/

/* $Log: MatSeq.h,v $
/* Revision 1.1  1997/01/15 16:42:13  reza
/* Added (array to) sequence server.
/* */

#define NVALS 250
#define TOKEN 40

extern int nVars;
extern int row;
extern char varName[NVALS][TOKEN];
extern dods_float64 *varValue;
