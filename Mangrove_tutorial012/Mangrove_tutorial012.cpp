/*************************************************************************************************************************************************************************
 * This source code provides the 'Tutorial Example-012' for the Mangrove Topological Data Structure Library (Mangrove TDS Library 3.0)
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
 * Mangrove_tutoriav012.cpp - the 'Tutorial Example-012' for the 'Mangrove TDS Library 3.0'.
 *************************************************************************************************************************************************************************/
 
#include "Mangrove_Miscellanea.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
using namespace mangrove_tds;

/// The <i>main function</i> for the <i>'Mangrove_tutoriav012'</i> program.
/**
 * \file Mangrove_tutoriav012.cpp
 * \author <A href="http://davidcanino.github.io">David Canino</A> (e-mail: <A href="mailto:canino.david@gmail.com">David Canino</A>)
 */

/// The <i>main function</i> for the <i>'Mangrove_tutoriav012'</i> program.
/**
 * \return <ul><li>the built-in <i>EXIT_SUCCESS</i> constant value (provided by the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), if all is ok</li><li>the built-in <i>EXIT_FAILURE</i> constant value (provided by 
 * the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), otherwise</li></ul>
 * \see mangrove_tds::Mangrove_exportCopyrightDisclaimer(), mangrove_tds::Mangrove_pause(), mangrove_tds::Mangrove_removeFile(), mangrove_tds::Mangrove_DataComparator, mangrove_tds::Mangrove_DataComparatorWithHashing
 */
int main(void)
{
	ofstream out;
	ifstream in;

	/* This is the 'Mangrove_tutoriav012' tutorial, where the arrays, containing several 'uint' C++ built-in values, are validated. */
	Mangrove_exportCopyrightDisclaimer ("The 'Mangrove_tutoriav012' Tutorial");
	cout.flush();
	
	/* TASK #1 - creating a new array 'v0' of several 'uint' C++ built-in values, and validating functions for exporting its 'debug', 'hybrid', and compact representations. */
	cout<<"\tCreating the new array 'v0' of several 'uint' C++ built-in values ... ";
	vector<uint> v0={ 3,0,54,11, 0 },v1,v01;
	cout<<"ok"<<endl;
	Mangrove_debug(v0);
	cout<<"\tThe 'hybrid' representation for the content of the array 'v0' is: ";
	Mangrove_exportHybrid(v0);
	cout<<endl<<"\tExporting the 'hybrid' representation for the content of the array 'v0' on the 'hybrid_array.txt' file ... ";
	out.open("hybrid_array.txt");
	Mangrove_exportHybrid(v0,out);
	out.close();
	cout<<"ok"<<endl;
	v1.resize(5);
	cout<<"\tReconstructing the content of the array 'v0' from the 'hybrid_array.txt' file ... ";
	in.open("hybrid_array.txt");
	Mangrove_reconstructFromHybrid(v1,in);
	in.close();
	cout<<"ok"<<endl;
	Mangrove_debug(v1);
	if(Mangrove_theSame(v0,v1)) cout<<"\tThe 'uint' C++ built-in values in the reconstructed array coincide position by position with the 'uint' C++ built-in values in the array 'v0'."<<endl<<endl;
	else cout<<"\tThe 'uint' C++ built-in values in the reconstructed array do not coincide position by position with the 'uint' C++ built-in values in the array 'v0'."<<endl<<endl;
	cout<<"\tRemoving the 'hybrid_array.txt' file ... ";
	Mangrove_removeFile("hybrid_array.txt");
	cout<<"ok"<<endl<<endl;
	cout.flush();
	v1.clear(); 
	cout<<"\tExporting the 'compact' representation for the content of the array 'v0' on the 'compact_array.txt' file ... ";
	out.open("compact_array.txt");
	out<<v0;
	out.close();
	cout<<"ok"<<endl;
	cout<<"\tReconstructing the content of the array 'v0' from the 'compact_array.txt' file ... ";
	in.open("compact_array.txt");
	in>>v1;
	in.close();
	cout<<"ok"<<endl;
	Mangrove_debug(v1);
	if(Mangrove_theSame(v0,v1)) cout<<"\tThe 'uint' C++ built-in values in the reconstructed array coincide position by position with the 'uint' C++ built-in values in the array 'v0'."<<endl<<endl;
	else cout<<"\tThe 'uint' C++ built-in values in the reconstructed array do not coincide position by position with the 'uint' C++ built-in values in the array 'v0'."<<endl<<endl;
	cout<<"\tRemoving the 'compact_array.txt' file ... ";
	Mangrove_removeFile("compact_array.txt");
	cout<<"ok"<<endl<<endl;
	cout.flush();
	v1.clear();
	Mangrove_pause();
	
	/* TASK #2 - validating the 'Mangrove_getPosition()' and the  'Mangrove_findProjection()' template functions for the arrays of several template values (specialized for the 'uint' C++ built-in values, in this case). */
	uint p;
	if(Mangrove_getPosition(v0,(uint)54,p)==true) { cout<<"\tThe array 'v0' contains the 'uint' C++ built-in value '54' in position "<<p<<"."<<endl; }
	else { cout<<"\tThe array 'v0' does not contain the 'uint' C++ built-in value '54'."<<endl; }
	if(Mangrove_getPosition(v0,(uint)58,p)==true) { cout<<"\tThe array 'v0' contains the 'uint' C++ built-in value '58' in position "<<p<<"."<<endl<<endl; }
	else { cout<<"\tThe array 'v0' does not contain the 'uint' C++ built-in value '58'."<<endl<<endl; }
	cout.flush();
	cout<<"\tRetrieving the canonical projection of the array 'v0' with respect to the position 0 ... ";
	Mangrove_findProjection(0,v0,v1);
	cout<<"ok"<<endl;
	cout<<"\tThe resulting canonical projection of interest is: ";
	Mangrove_exportHybrid(v1);
	cout.flush();
	if(Mangrove_includes(v0,v1)==true) cout<<"\tThe array 'v0' contains all 'uint' C++ built-in values in the canonical projection of interest in the same order as they appear (but not forming necessarily a block of consecutive values)."<<endl<<endl;
	else cout<<"\tThe array 'v0' does not contain all 'uint' C++ built-in values in the canonical projection of interest in the same order as they appear (but not forming necessarily a block of consecutive values)."<<endl<<endl;
	cout<<"\tRetrieving the canonical projection of the array 'v0' with respect to the position 4 ... ";
	Mangrove_findProjection(4,v0,v1);
	cout<<"ok"<<endl;
	cout<<"\tThe resulting canonical projection of interest is: ";
	Mangrove_exportHybrid(v1);
	if(Mangrove_includes(v0,v1)==true) cout<<"\tThe array 'v0' contains all 'uint' C++ built-in values in the canonical projection of interest in the same order as they appear (but not forming necessarily a block of consecutive values)."<<endl<<endl;
	else cout<<"\tThe array 'v0' does not contain all 'uint' C++ built-in values in the canonical projection of interest in the same order as they appear (but not forming necessarily a block of consecutive values)."<<endl<<endl;
	cout<<"\tIMPORTANT:\t\tthe operations (just performed) are executed without sorting the values of interest, and may produce wrong results."<<endl<<endl<<"\tSorting the 'uint' C++ built-in values in the array 'v0' ... ";
	sort(v0.begin(),v0.end());
	cout<<"ok"<<endl;
	cout<<"\tThe new array 'v0' contains the following 'uint' C++ built-in values: ";
	Mangrove_exportHybrid(v0);
	cout<<"\tRetrieving the canonical projection of the array 'v0' with respect to the position 0 ... ";
	Mangrove_findProjection(0,v0,v1);
	cout<<"ok"<<endl;
	cout<<"\tThe resulting canonical projection of interest is: ";
	Mangrove_exportHybrid(v1);
	cout.flush();
	if(Mangrove_includes(v0,v1)==true) cout<<"\tThe array 'v0' contains all 'uint' C++ built-in values in the canonical projection of interest in the same order as they appear (but not forming necessarily a block of consecutive values)."<<endl<<endl;
	else cout<<"\tThe array 'v0' does not contain all 'uint' C++ built-in values in the canonical projection of interest in the same order as they appear (but not forming necessarily a block of consecutive values)."<<endl<<endl;
	cout<<"\tRetrieving the canonical projection of the array 'v0' with respect to the position 4 ... ";
	Mangrove_findProjection(4,v0,v1);
	cout<<"ok"<<endl;
	cout<<"\tThe resulting canonical projection of interest is: ";
	Mangrove_exportHybrid(v1);
	if(Mangrove_includes(v0,v1)==true) cout<<"\tThe array 'v0' contains all 'uint' C++ built-in values in the canonical projection of interest in the same order as they appear (but not forming necessarily a block of consecutive values)."<<endl<<endl;
	else cout<<"\tThe array 'v0' does not contain all 'uint' C++ built-in values in the canonical projection of interest in the same order as they appear (but not forming necessarily a block of consecutive values)."<<endl<<endl;
	cout.flush();
	v1.clear();
	Mangrove_pause();
	
	/* TASK #3 - creating a new array 'v1' to be compared with the existing array 'v0'. */
	cout<<"\tThe array 'v0' contains the following 'uint' C++ built-in values: ";
	Mangrove_exportHybrid(v0);
	cout<<"\tCreating the new array 'v1' of several 'uint' C++ built-in values ... ";
	v1={1,5,4,11,54};
	cout<<"ok"<<endl;
	Mangrove_debug(v1);
	if(v0<v1) { cout<<"\tThe 'uint' C++ built-in values in the array 'v0' are 'strictly less than' the 'uint' C++ built-in values in the array 'v1' (with respect to the '<' operator)."<<endl; }
	else { cout<<"\tThe 'uint' C++ built-in values in the array 'v0' are not 'strictly less than' the 'uint' C++ built-in values in the array 'v1' (with respect to the '<' operator)."<<endl; }
	if( Mangrove_DataComparator<uint>()(v0,v1) ) { cout<<"\tThe 'uint' C++ built-in values in the array 'v0' are 'strictly less than' the 'uint' C++ built-in values in the array 'v1' (with respect to the 'Mangrove_DataComparator' template class)."<<endl; }
	else { cout<<"\tThe 'uint' C++ built-in values in the array 'v0' are not 'strictly less than' the 'uint' C++ built-in values in the array 'v1' (with respect to the 'Mangrove_DataComparator' template class)."<<endl; }
	if(v1<v0) { cout<<"\tThe 'uint' C++ built-in values in the array 'v1' are 'strictly less than' the 'uint' C++ built-in values in the array 'v0' (with respect to the '<' operator)."<<endl; }
	else { cout<<"\tThe 'uint' C++ built-in values in the array 'v1' are not 'strictly less than' the 'uint' C++ built-in values in the array 'v0' (with respect to the '<' operator)."<<endl; }
	if( Mangrove_DataComparator<uint>()(v1,v0) ) { cout<<"\tThe 'uint' C++ built-in values in the array 'v1' are 'strictly less than' the 'uint' C++ built-in values in the array 'v0' (with respect to the 'Mangrove_DataComparator' template class)."<<endl; }
	else { cout<<"\tThe 'uint' C++ built-in values in the array 'v1' are not 'strictly less than' the 'uint' C++ built-in values in the array 'v0' (with respect to the 'Mangrove_DataComparator' template class)."<<endl; }
	cout<<endl<<"\tThe hashing value of the array 'v0' (see the 'boost::hash_value()' template function) is "<<boost::hash_value(v0)<<"."<<endl;
	cout<<"\tThe hashing value of the array 'v1' (see the 'boost::hash_value()' template function) is "<<boost::hash_value(v1)<<"."<<endl;
	if( Mangrove_DataComparatorWithHashing<uint>()(v0,v1) ) 
		{ cout<<"\tThe 'uint' C++ built-in values in the array 'v0' are 'strictly less than' the 'uint' C++ built-in values in the array 'v1' (with respect to the 'Mangrove_DataComparatorWithHashing' template class)."<<endl; }
	else { cout<<"\tThe 'uint' C++ built-in values in the array 'v0' are not 'strictly less than' the 'uint' C++ built-in values in the array 'v1' (with respect to the 'Mangrove_DataComparatorWithHashing' template class)."<<endl; }
	if( Mangrove_DataComparatorWithHashing<uint>()(v1,v0) ) 
		{ cout<<"\tThe 'uint' C++ built-in values in the array 'v1' are 'strictly less than' the 'uint' C++ built-in values in the array 'v0' (with respect to the 'Mangrove_DataComparatorWithHashing' template class)."<<endl; }
	else { cout<<"\tThe 'uint' C++ built-in values in the array 'v1' are not 'strictly less than' the 'uint' C++ built-in values in the array 'v0' (with respect to the 'Mangrove_DataComparatorWithHashing' template class)."<<endl; }
	cout<<endl;
	if(Mangrove_isPermutation(v0,v1)==true) cout<<"\tThe 'uint' C++ built-in values in the array 'v0' are a permutation of the 'uint' C++ built-in values in the array 'v1'."<<endl;
	else cout<<"\tThe 'uint' C++ built-in values in the array 'v0' are not a permutation of the 'uint' values in the array 'v1'."<<endl;
	cout<<endl;
	cout<<"\tIntersecting the 'uint' C++ built-in arrays 'v0' and 'v1' ... ";
	Mangrove_intersection(v0,v1,v01);
	cout<<"ok"<<endl;
	cout<<"\tThe intersection between the arrays of interest is given by the following 'uint' C++ built-in values: ";
	Mangrove_exportHybrid(v01);
	cout<<endl;
	
	/* TASK #4 - deallocating all arrays in this tutorial. */
	Mangrove_pause();
	cout<<"\tDeallocating all arrays in this tutorial ... ";
	v0.clear();
	v1.clear();
	v01.clear();
	cout<<"ok"<<endl<<endl;
	cout.flush();
	return EXIT_SUCCESS;
}
