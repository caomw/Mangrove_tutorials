/*************************************************************************************************************************************************************************
 * This source code provides the 'Tutorial Example-003' for the Mangrove Topological Data Structure Library (Mangrove TDS Library 3.0)
 *                                                                           				    
 * David Canino (canino.david@gmail.com)
 *
 * Main website for the experimental version 3.0 (GitHub) of the 'Mangrove TDS Library': http://mangrovetds.github.io
 *
 * The 'Tutorial Examples' are distributed independently on the 'Mangrove TDS Library' on the GitHub repository: 'http://github.com/davidcanino/Mangrove_tutorials'
 *
 * Last update: February 2017
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

/// The <i>main function</i> for the <i>Mangrove_tutorial003</i> program.
/**
 * \file Mangrove_tutorial003.cpp
 * \author <A href="http://davidcanino.github.io">David Canino</A> (e-mail: <A href="mailto:canino.david@gmail.com">David Canino</A>)
 */

/// The <i>main function</i> for the <i>Mangrove_tutorial003</i> program.
/**
 * \return <ul><li>the built-in <i>EXIT_SUCCESS</i> constant value (provided by the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), if all is ok</li><li>the built-in <i>EXIT_FAILURE</i> constant value (provided by 
 * the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), otherwise</li></ul>
 * \see mangrove_tds::Mangrove_exportCopyrightDisclaimer()
 */
int main(void)
{
	/* Now, we extract the range and the number of the bytes for the C++ built-in type, and validate the 'Mangrove_exportCopyrightDisclaimer()' function in the 'Mangrove_Miscellanea.h' file. */
	Mangrove_exportCopyrightDisclaimer ("Mangrove_tutorial003");
	cout<<"\tThe size of the 'bool' C++ built-in type: "<<sizeof(bool)<<" byte ("<<(sizeof(bool)*8)<<" bits)"<<endl;
	cout<<"\tThe range for the values of the C++ built-in 'bool' type: [ "<<std::numeric_limits<bool>::min()<<" , "<<std::numeric_limits<bool>::max()<<" ]"<<endl<<endl;
	cout<<"\tThe size of the 'char' C++ built-in type: "<<sizeof(char)<<" byte ("<<(sizeof(char)*8)<<" bits)"<<endl;
	cout<<"\tThe range for the values of the C++ built-in 'char' type: [ "<<(int)std::numeric_limits<char>::min()<<" , "<<(int)std::numeric_limits<char>::max()<<" ]"<<endl<<endl;
	cout<<"\tThe size of the 'unsigned char (uchar)' C++ built-in type: "<<sizeof(uchar)<<" byte ("<<(sizeof(uchar)*8)<<" bits)"<<endl;
	cout<<"\tThe range for the values of the C++ built-in 'unsigned char (uchar)' type: [ "<<(uint)std::numeric_limits<unsigned char>::min()<<" , "<<(uint)std::numeric_limits<unsigned char>::max()<<" ]"<<endl<<endl;
	cout<<"\tThe size of the 'short' C++ built-in type: "<<sizeof(short)<<" bytes ("<<(sizeof(short)*8)<<" bits)"<<endl;
	cout<<"\tThe range for the values of the C++ built-in 'short' type: [ "<<std::numeric_limits<short>::min()<<" , "<<std::numeric_limits<short>::max()<<" ]"<<endl<<endl;
	cout<<"\tThe size of the 'unsigned short (ushort)' C++ built-in type: "<<sizeof(ushort)<<" bytes ("<<(sizeof(ushort)*8)<<" bits)"<<endl;
	cout<<"\tThe range for the values of the C++ built-in 'unsigned short (ushort)' type: [ "<<std::numeric_limits<unsigned short>::min()<<" , "<<std::numeric_limits<unsigned short>::max()<<" ]"<<endl<<endl;
	cout<<"\tThe size of the 'int' C++ built-in type: "<<sizeof(int)<<" bytes ("<<(sizeof(int)*8)<<" bits)"<<endl;
	cout<<"\tThe range for the values of the C++ built-in 'int' type: [ "<<std::numeric_limits<int>::min()<<" , "<<std::numeric_limits<int>::max()<<" ]"<<endl<<endl;
	cout<<"\tThe size of the 'unsigned int (uint)' C++ built-in type: "<<sizeof(uint)<<" bytes ("<<(sizeof(uint)*8)<<" bits)"<<endl;
	cout<<"\tThe range for the values of the C++ built-in 'unsigned int (uint)' type: [ "<<std::numeric_limits<unsigned int>::min()<<" , "<<std::numeric_limits<unsigned int>::max()<<" ]"<<endl<<endl;
	cout<<"\tThe size of the 'long' C++ built-in type: "<<sizeof(long)<<" bytes ("<<(sizeof(long)*8)<<" bits)"<<endl;
	cout<<"\tThe range for the values of the C++ built-in 'long' type: [ "<<std::numeric_limits<long>::min()<<" , "<<std::numeric_limits<long>::max()<<" ]"<<endl<<endl;
	cout<<"\tThe size of the 'unsigned long (ulong)' C++ built-in type: "<<sizeof(ulong)<<" bytes ("<<(sizeof(ulong)*8)<<" bits)"<<endl;
	cout<<"\tThe range for the values of the C++ built-in 'unsigned long (ulong)' type: [ "<<std::numeric_limits<unsigned long>::min()<<" , "<<std::numeric_limits<unsigned long>::max()<<" ]"<<endl<<endl;
	cout<<"\tThe size of the 'float' C++ built-in type: "<<sizeof(float)<<" bytes ("<<(sizeof(float)*8)<<" bits)"<<endl;
	cout<<"\tThe range for the values of the C++ built-in 'float' type: [ "<<std::numeric_limits<float>::min()<<" , "<<std::numeric_limits<float>::max()<<" ]"<<endl<<endl;
	cout<<"\tThe size of the 'double' C++ built-in type: "<<sizeof(double)<<" bytes ("<<(sizeof(double)*8)<<" bits)"<<endl;
	cout<<"\tThe range for the values of the C++ built-in 'double' type: [ "<<std::numeric_limits<double>::min()<<" , "<<std::numeric_limits<double>::max()<<" ]"<<endl<<endl;
	cout.flush();
	return EXIT_SUCCESS;
}
