/*************************************************************************************************************************************************************************
 * This source code provides the 'Tutorial Example-003' for the Mangrove Topological Data Structure Library (Mangrove TDS Library 3.0)
 *                                                                           				    
 * David Canino (canino.david@gmail.com)
 *
 * Main website for the experimental version 3.0 (GitHub) of the 'Mangrove TDS Library': http://mangrovetds.github.io
 *
 * The 'Tutorial Examples' are distributed independently on the 'Mangrove TDS Library' on the GitHub repository: 'http://github.com/davidcanino/Mangrove_tutorials'
 *
 * Last update: March 2017
 *                                                                    
 * This program is Free Software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.                                       
 *                                                                           
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License (http://www.gnu.org/licenses/gpl.txt) for
 * more details.
 *
 * Mangrove_tutorial003.cpp - the 'Tutorial Example-003' for the 'Mangrove TDS Library 3.0'.
 *************************************************************************************************************************************************************************/
 
#include <iostream>
#include <cstdlib>
#include "Mangrove_Miscellanea.h"
using namespace std;
using namespace mangrove_tds;

/// The <i>main function</i> for the <i>'Mangrove_tutorial003'</i> program.
/**
 * \file Mangrove_tutorial003.cpp
 * \author <A href="http://davidcanino.github.io">David Canino</A> (e-mail: <A href="mailto:canino.david@gmail.com">David Canino</A>)
 */

/// The <i>main function</i> for the <i>'Mangrove_tutorial003'</i> program.
/**
 * \return <ul><li>the built-in <i>EXIT_SUCCESS</i> constant value (provided by the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), if all is ok</li><li>the built-in <i>EXIT_FAILURE</i> constant value (provided by 
 * the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), otherwise</li></ul>
 * \see mangrove_tds::Mangrove_exportCopyrightDisclaimer()
 */
int main(void)
{
	/* This is the 'Mangrove_tutorial003' tutorial, where we extract the ranges of some basic C++ built-in types. */
	Mangrove_exportCopyrightDisclaimer ("The 'Mangrove_tutorial003' Tutorial");
	cout.flush();
	
	/* TASK #1 - extracting the ranges of the values, that can be represented by using some basic C++ built-in types. We start from the 'boolean (bool)' C++ built-in type. */
	cout<<"\tThe size of the 'boolean (bool)' C++ built-in type is "<<sizeof(bool)<<" byte ("<<(sizeof(bool)*8)<<" bits)."<<endl;
	cout<<"\tThe range for the values, that can be represented by using the C++ built-in 'boolean (bool)' type, is [ "<<std::numeric_limits<bool>::min()<<" , "<<std::numeric_limits<bool>::max()<<" ]."<<endl<<endl;
	cout.flush();
	
	/* TASK #2 - extracting the ranges of the values, that can be represented by using the 'character (char)' C++ built-in type. */
	cout<<"\tThe size of the 'character (char)' C++ built-in type is "<<sizeof(char)<<" byte ("<<(sizeof(char)*8)<<" bits)."<<endl;
	cout<<"\tThe range for the values, that can be represented by using the 'character (char)' C++ built-in ' type, is [ "<<(int)std::numeric_limits<char>::min()<<" , "<<(int)std::numeric_limits<char>::max()<<" ]."<<endl<<endl;
	cout.flush();
	
	/* TASK #2 - extracting the ranges of the values, that can be represented by using the 'unsigned char (uchar)' C++ built-in type. */
	cout<<"\tThe size of the 'unsigned character (uchar)' C++ built-in type is "<<sizeof(uchar)<<" byte ("<<(sizeof(uchar)*8)<<" bits)."<<endl;
	cout<<"\tThe range for the values of the 'unsigned character (uchar)' C++ built-in type is [ "<<(uint)std::numeric_limits<unsigned char>::min()<<" , "<<(uint)std::numeric_limits<unsigned char>::max()<<" ]."<<endl<<endl;
	cout.flush();
	
	/* TASK #3 - extracting the ranges of the values, that can be represented by using the 'short integer (short)' C++ built-in type. */
	cout<<"\tThe size of the 'short integer (short)' C++ built-in type is "<<sizeof(short)<<" bytes ("<<(sizeof(short)*8)<<" bits)."<<endl;
	cout<<"\tThe range for the values of the 'short integer (short)' type is: [ "<<std::numeric_limits<short>::min()<<" , "<<std::numeric_limits<short>::max()<<" ]."<<endl<<endl;
	cout.flush();
	
	/* TASK #4 - extracting the ranges of the values, that can be represented by using the 'unsigned short integer (ushort)' C++ built-in type. */
	cout<<"\tThe size of the 'unsigned short integer (ushort)' C++ built-in type is "<<sizeof(ushort)<<" bytes ("<<(sizeof(ushort)*8)<<" bits)."<<endl;
	cout<<"\tThe range for the values of the 'unsigned short integer (ushort)' type is: [ "<<std::numeric_limits<ushort>::min()<<" , "<<std::numeric_limits<ushort>::max()<<" ]."<<endl<<endl;
	cout.flush();
	
	/* TASK #5 - extracting the ranges of the values, that can be represented by using the 'integer (int)' C++ built-in type. */
	cout<<"\tThe size of the 'integer (int)' C++ built-in type is "<<sizeof(int)<<" bytes ("<<(sizeof(int)*8)<<" bits)."<<endl;
	cout<<"\tThe range for the values of the 'integer (int)' type is: [ "<<std::numeric_limits<int>::min()<<" , "<<std::numeric_limits<int>::max()<<" ]."<<endl<<endl;
	cout.flush();
	
	/* TASK #6 - extracting the ranges of the values, that can be represented by using the 'unsigned integer (uint)' C++ built-in type. */
	cout<<"\tThe size of the 'unsigned integer (uint)' C++ built-in type is "<<sizeof(uint)<<" bytes ("<<(sizeof(uint)*8)<<" bits)."<<endl;
	cout<<"\tThe range for the values of the 'unsigned integer (uint)' type is: [ "<<std::numeric_limits<uint>::min()<<" , "<<std::numeric_limits<uint>::max()<<" ]."<<endl<<endl;
	cout.flush();
	
	/* TASK #7 - extracting the ranges of the values, that can be represented by using the 'long integer (long)' C++ built-in type. */
	cout<<"\tThe size of the 'long integer (long)' C++ built-in type is "<<sizeof(long)<<" bytes ("<<(sizeof(long)*8)<<" bits)."<<endl;
	cout<<"\tThe range for the values of the 'long integer (long)' type is: [ "<<std::numeric_limits<long>::min()<<" , "<<std::numeric_limits<long>::max()<<" ]."<<endl<<endl;
	cout.flush();
	
	/* TASK #8 - extracting the ranges of the values, that can be represented by using the 'unsigned long integer (ulong)' C++ built-in type. */
	cout<<"\tThe size of the 'unsigned long integer (ulong)' C++ built-in type is "<<sizeof(ulong)<<" bytes ("<<(sizeof(ulong)*8)<<" bits)."<<endl;
	cout<<"\tThe range for the values of the 'unsigned long integer (ulong)' type is: [ "<<std::numeric_limits<ulong>::min()<<" , "<<std::numeric_limits<ulong>::max()<<" ]."<<endl<<endl;
	cout.flush();
	
	/* TASK #9 - extracting the ranges of the values, that can be represented by using the 'single floating-point (float)' C++ built-in type. */
	cout<<"\tThe size of the 'single floating-point (float)' C++ built-in type is "<<sizeof(float)<<" bytes ("<<(sizeof(float)*8)<<" bits)."<<endl;
	cout<<"\tThe range for the values of the 'single floating-point (float)' type is: [ "<<std::numeric_limits<float>::min()<<" , "<<std::numeric_limits<float>::max()<<" ]."<<endl<<endl;
	cout.flush();
	
	/* TASK #10 - extracting the ranges of the values, that can be represented by using the 'double floating-point (double)' C++ built-in type. */
	cout<<"\tThe size of the 'double floating-point (double)' C++ built-in type is "<<sizeof(double)<<" bytes ("<<(sizeof(double)*8)<<" bits)."<<endl;
	cout<<"\tThe range for the values of the 'double floating-point (double)' type is: [ "<<std::numeric_limits<double>::min()<<" , "<<std::numeric_limits<double>::max()<<" ]."<<endl<<endl;
	cout.flush();
	return EXIT_SUCCESS;
}
