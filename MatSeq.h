/*
*
  This file contains common extern declarations used by the DODS-MATLAB code.
  ReZa, Dec-1996
*
*/

#define NVALS 250
#define TOKEN 40

extern int nVars;
extern int row;
extern char varName[NVALS][TOKEN];
extern dods_float64 *varValue;

/* 
 * $Log: MatSeq.h,v $
 * Revision 1.4  2003/12/08 18:09:05  edavis
 * Merge release-3-4 into trunk
 *
 * Revision 1.3  2003/02/10 22:42:05  jimg
 * Merged with 3.2.6.
 *
 * Revision 1.2.4.1  2001/10/09 22:35:49  jimg
 * Removed
 *
 * Revision 1.2  2000/10/10 00:03:07  jimg
 * Moved CVS Logs to the end of each file.
 * Added code to handle exceptions thrown by the dap library.
 * Added exceptions to the read methods.
 * Changed the definition of the read methods to match the dap library.
 *
 * Revision 1.1  1997/01/15 16:42:13  reza
 * Added (array to) sequence server.
 */
