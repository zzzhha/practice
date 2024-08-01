#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

////2
//#include "cpu_types.h"
//int cpu_type()
//{
//#if defined( VAX )
//	return CPU_VAX;
//#elif defined( M68000 )
//	return CPU_68000;
//#elif defined( M68020 )
//	return CPU_68020;
//#elif defined( I80386 )
//	return CPU_80386;
//#elif defined( X6809 )
//	return CPU_6809;
//#elif defined( X6502 )
//	return CPU_6502;
//#elif defined( U3B2 )
//	return CPU_3B2;
//#else
//	return CPU_UNKNOWN;
//#endif
//}
////1
//void print_ledger(int x)
//{
//#ifdef OPTION_LONG
//#define OK 1;
//	print_ledger_long(x);
//#endif
//
//#ifdef OPTION_DETAILED
//#define OK 1;
//	print_ledger_detailed(x);
//#endif
//
//#ifndef OK
//	print_ledger_default(x);
//#endif
//}