/*************************************************************************************************************************************************************************
 * This source code provides the 'Tutorial Example-010' for the Mangrove Topological Data Structure Library (Mangrove TDS Library 3.0)
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
 * Mangrove_tutorial010.cpp - the 'Tutorial Example-010' for the 'Mangrove TDS Library 3.0'.
 *************************************************************************************************************************************************************************/
 
#include "Mangrove_Miscellanea.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
using namespace mangrove_tds;

/// The <i>main function</i> for the <i>'Mangrove_tutorial010'</i> program.
/**
 * \file Mangrove_tutorial010.cpp
 * \author <A href="http://davidcanino.github.io">David Canino</A> (e-mail: <A href="mailto:canino.david@gmail.com">David Canino</A>)
 */

/// The <i>main function</i> for the <i>'Mangrove_tutorial010'</i> program.
/**
 * \return <ul><li>the built-in <i>EXIT_SUCCESS</i> constant value (provided by the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), if all is ok</li><li>the built-in <i>EXIT_FAILURE</i> constant value (provided by 
 * the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), otherwise</li></ul>
 * \see mangrove_tds::Mangrove_exportCopyrightDisclaimer(), mangrove_tds::Mangrove_pause(), mangrove_tds::Mangrove_removeFile(), mangrove_tds::Mangrove_DataComparator, mangrove_tds::Mangrove_DataComparatorWithHashing
 */
int main(void)
{
	ofstream out;
	ifstream in;

	/* This is the 'Mangrove_tutorial010' tutorial, where the deques, containing several 'unsigned int (uint)' C++ built-in values, are validated. */
	Mangrove_exportCopyrightDisclaimer ("The 'Mangrove_tutorial010' Tutorial");
	cout.flush();
	
	/* TASK #1 - creating a new deque 'd0' of several 'unsigned int (uint)' C++ built-in values, and validating functions for exporting its 'debug', 'hybrid', and compact representations. */
	cout<<"\tCreating the new deque 'd0' of several 'unsigned int (uint)' C++ built-in values ... ";
	deque<uint> d0={ 3,0,54,11, 0 },d1,d01;
	cout<<"ok"<<endl;
	Mangrove_debug(d0);
	cout<<"\tThe 'hybrid' representation for the content of the deque 'd0' is: ";
	Mangrove_exportHybrid(d0);
	cout<<endl<<"\tExporting the 'hybrid' representation for the content of the deque 'd0' on the 'hybrid_deque.txt' file ... ";
	out.open("hybrid_deque.txt");
	Mangrove_exportHybrid(d0,out);
	out.close();
	cout<<"ok"<<endl;
	d1.resize(5);
	cout<<"\tReconstructing the content of the deque 'd0' from the 'hybrid_deque.txt' file ... ";
	in.open("hybrid_deque.txt");
	Mangrove_reconstructFromHybrid(d1,in);
	in.close();
	cout<<"ok"<<endl;
	Mangrove_debug(d1);
	if(Mangrove_theSame(d0,d1)) cout<<"\tThe 'unsigned int (uint)' C++ built-in values in the reconstructed deque coincide position by position with the 'unsigned int (uint)' C++ built-in values in the deque 'd0'."<<endl<<endl;
	else cout<<"\tThe 'unsigned int (uint)' C++ built-in values in the reconstructed deque do not coincide position by position with the 'unsigned int (uint)' C++ built-in values in the deque 'd0'."<<endl<<endl;
	cout<<"\tRemoving the 'hybrid_deque.txt' file ... ";
	Mangrove_removeFile("hybrid_deque.txt");
	cout<<"ok"<<endl<<endl;
	cout.flush();
	d1.clear();
	cout<<"\tExporting the 'compact' representation for the content of the deque 'd0' on the 'compact_deque.txt' file ... ";
	out.open("compact_deque.txt");
	out<<d0;
	out.close();
	cout<<"ok"<<endl;
	cout<<"\tReconstructing the content of the deque 'd0' from the 'compact_deque.txt' file ... ";
	in.open("compact_deque.txt");
	in>>d1;
	in.close();
	cout<<"ok"<<endl;
	Mangrove_debug(d1);
	if(Mangrove_theSame(d0,d1)) cout<<"\tThe 'unsigned int (uint)' C++ built-in values in the reconstructed deque coincide position by position with the 'unsigned int (uint)' C++ built-in values in the deque 'd0'."<<endl<<endl;
	else cout<<"\tThe 'unsigned int (uint)' C++ built-in values in the reconstructed deque do not coincide position by position with the 'unsigned int (uint)' C++ built-in values in the deque 'd0'."<<endl<<endl;
	cout<<"\tRemoving the 'compact_deque.txt' file ... ";
	Mangrove_removeFile("compact_deque.txt");
	cout<<"ok"<<endl<<endl;
	cout.flush();
	d1.clear();
	Mangrove_pause();
	
	/* TASK #2 - validating the 'Mangrove_getPosition()' and the  'Mangrove_findProjection()' template functions for the deques of several template values (specialized for the 'unsigned int (uint)' C++ built-in values, in this case). */
	uint p;
	if(Mangrove_getPosition(d0,(uint)54,p)==true) { cout<<"\tThe deque 'd0' contains the 'unsigned int (uint)' C++ built-in value '54' in position "<<p<<"."<<endl; }
	else { cout<<"\tThe deque 'd0' does not contain the 'unsigned int (uint)' C++ built-in value '54'."<<endl; }
	if(Mangrove_getPosition(d0,(uint)58,p)==true) { cout<<"\tThe deque 'd0' contains the 'unsigned int (uint)' C++ built-in value '58' in position "<<p<<"."<<endl<<endl; }
	else { cout<<"\tThe deque 'd0' does not contain the 'unsigned int (uint)' C++ built-in value '58'."<<endl<<endl; }
	cout.flush();
	cout<<"\tRetrieving the canonical projection of the deque 'd0' with respect to the position 0 ... ";
	Mangrove_findProjection(0,d0,d1);
	cout<<"ok"<<endl;
	cout<<"\tThe resulting canonical projection of interest is: ";
	Mangrove_exportHybrid(d1);
	cout.flush();
	if(Mangrove_includes(d0,d1)==true) cout<<"\tThe deque 'd0' contains all 'unsigned int (uint)' C++ built-in values in the canonical projection of interest in the same order as they appear (but not forming necessarily a block of consecutive values)."<<endl<<endl;
	else cout<<"\tThe deque 'd0' does not contain all 'unsigned int (uint)' C++ built-in values in the canonical projection of interest in the same order as they appear (but not forming necessarily a block of consecutive values)."<<endl<<endl;
	cout<<"\tRetrieving the canonical projection of the deque 'd0' with respect to the position 4 ... ";
	Mangrove_findProjection(4,d0,d1);
	cout<<"ok"<<endl;
	cout<<"\tThe resulting canonical projection of interest is: ";
	Mangrove_exportHybrid(d1);
	if(Mangrove_includes(d0,d1)==true) cout<<"\tThe deque 'd0' contains all 'unsigned int (uint)' C++ built-in values in the canonical projection of interest in the same order as they appear (but not forming necessarily a block of consecutive values)."<<endl<<endl;
	else cout<<"\tThe deque 'd0' does not contain all 'unsigned int (uint)' C++ built-in values in the canonical projection of interest in the same order as they appear (but not forming necessarily a block of consecutive values)."<<endl<<endl;
	cout<<"\tIMPORTANT:\t\tthe operations (just performed) are executed without sorting the values of interest, and may produce wrong results."<<endl<<endl<<"\tSorting the 'unsigned int (uint)' C++ built-in values in the deque 'd0' ... ";
	sort(d0.begin(),d0.end());
	cout<<"ok"<<endl;
	cout<<"\tThe new deque 'd0' contains the following 'unsigned int (uint)' C++ built-in values: ";
	Mangrove_exportHybrid(d0);
	cout<<"\tRetrieving the canonical projection of the deque 'd0' with respect to the position 0 ... ";
	Mangrove_findProjection(0,d0,d1);
	cout<<"ok"<<endl;
	cout<<"\tThe resulting canonical projection of interest is: ";
	Mangrove_exportHybrid(d1);
	cout.flush();
	if(Mangrove_includes(d0,d1)==true) cout<<"\tThe deque 'd0' contains all 'unsigned int (uint)' C++ built-in values in the canonical projection of interest in the same order as they appear (but not forming necessarily a block of consecutive values)."<<endl<<endl;
	else cout<<"\tThe deque 'd0' does not contain all 'unsigned int (uint)' C++ built-in values in the canonical projection of interest in the same order as they appear (but not forming necessarily a block of consecutive values)."<<endl<<endl;
	cout<<"\tRetrieving the canonical projection of the deque 'd0' with respect to the position 4 ... ";
	Mangrove_findProjection(4,d0,d1);
	cout<<"ok"<<endl;
	cout<<"\tThe resulting canonical projection of interest is: ";
	Mangrove_exportHybrid(d1);
	if(Mangrove_includes(d0,d1)==true) cout<<"\tThe deque 'd0' contains all 'unsigned int (uint)' C++ built-in values in the canonical projection of interest in the same order as they appear (but not forming necessarily a block of consecutive values)."<<endl<<endl;
	else cout<<"\tThe deque 'd0' does not contain all 'unsigned int (uint)' C++ built-in values in the canonical projection of interest in the same order as they appear (but not forming necessarily a block of consecutive values)."<<endl<<endl;
	cout.flush();
	d1.clear();
	Mangrove_pause();
	
	/* TASK #3 - creating a new deque 'd1' to be compared with the existing deque 'd0'. */
	cout<<"\tThe deque 'd0' contains the following 'unsigned int (uint)' C++ built-in values: ";
	Mangrove_exportHybrid(d0);
	cout<<"\tCreating the new deque 'd1' of several 'unsigned int (uint)' C++ built-in values ... ";
	d1={1,5,4,11,54};
	cout<<"ok"<<endl;
	Mangrove_debug(d1);
	if(d0<d1) { cout<<"\tThe 'unsigned int (uint)' C++ built-in values in the deque 'd0' are 'strictly less than' the 'unsigned int (uint)' C++ built-in values in the deque 'd1' (with respect to the '<' operator)."<<endl; }
	else { cout<<"\tThe 'unsigned int (uint)' C++ built-in values in the deque 'd0' are not 'strictly less than' the 'unsigned int (uint)' C++ built-in values in the deque 'd1' (with respect to the '<' operator)."<<endl; }
	if( Mangrove_DataComparator<uint>()(d0,d1) ) 
		{ cout<<"\tThe 'unsigned int (uint)' C++ built-in values in the deque 'd0' are 'strictly less than' the 'unsigned int (uint)' C++ built-in values in the deque 'd1' (with respect to the 'Mangrove_DataComparator' template class)."<<endl; }
	else { cout<<"\tThe 'unsigned int (uint)' C++ built-in values in the deque 'd0' are not 'strictly less than' the 'unsigned int (uint)' C++ built-in values in the deque 'd1' (with respect to the 'Mangrove_DataComparator' template class)."<<endl; }
	if(d1<d0) { cout<<"\tThe 'unsigned int (uint)' C++ built-in values in the deque 'd1' are 'strictly less than' the 'unsigned int (uint)' C++ built-in values in the deque 'd0' (with respect to the '<' operator)."<<endl; }
	else { cout<<"\tThe 'unsigned int (uint)' C++ built-in values in the deque 'd1' are not 'strictly less than' the 'unsigned int (uint)' C++ built-in values in the deque 'd0' (with respect to the '<' operator)."<<endl; }
	if( Mangrove_DataComparator<uint>()(d1,d0) ) 
		{ cout<<"\tThe 'unsigned int (uint)' C++ built-in values in the deque 'd1' are 'strictly less than' the 'unsigned int (uint)' C++ built-in values in the deque 'd0' (with respect to the 'Mangrove_DataComparator' template class)."<<endl; }
	else { cout<<"\tThe 'unsigned int (uint)' C++ built-in values in the deque 'd1' are not 'strictly less than' the 'unsigned int (uint)' C++ built-in values in the deque 'd0' (with respect to the 'Mangrove_DataComparator' template class)."<<endl; }
	cout<<endl<<"\tThe hashing value of the deque 'd0' (see the 'boost::hash_value()' template function) is "<<boost::hash_value(d0)<<"."<<endl;
	cout<<"\tThe hashing value of the deque 'd1' (see the 'boost::hash_value()' template function) is "<<boost::hash_value(d1)<<"."<<endl;
	if( Mangrove_DataComparatorWithHashing<uint>()(d0,d1) ) 
		{ cout<<"\tThe 'unsigned int (uint)' C++ built-in values in the deque 'd0' are 'strictly less than' the 'unsigned int (uint)' C++ built-in values in the deque 'd1' (with respect to the 'Mangrove_DataComparatorWithHashing' template class)."<<endl; }
	else { cout<<"\tThe 'unsigned int (uint)' C++ built-in values in the deque 'd0' are not 'strictly less than' the 'unsigned int (uint)' C++ built-in values in the deque 'd1' (with respect to the 'Mangrove_DataComparatorWithHashing' template class)."<<endl; }
	if( Mangrove_DataComparatorWithHashing<uint>()(d1,d0) ) 
		{ cout<<"\tThe 'unsigned int (uint)' C++ built-in values in the deque 'd1' are 'strictly less than' the 'unsigned int (uint)' C++ built-in values in the deque 'd0' (with respect to the 'Mangrove_DataComparatorWithHashing' template class)."<<endl; }
	else { cout<<"\tThe 'unsigned int (uint)' C++ built-in values in the deque 'd1' are not 'strictly less than' the 'unsigned int (uint)' C++ built-in values in the deque 'd0' (with respect to the 'Mangrove_DataComparatorWithHashing' template class)."<<endl; }
	cout<<endl;
	if(Mangrove_isPermutation(d0,d1)==true) cout<<"\tThe 'unsigned int (uint)' C++ built-in values in the deque 'd0' are a permutation of the 'unsigned int (uint)' C++ built-in values in the deque 'd1'."<<endl;
	else cout<<"\tThe 'unsigned int (uint)' C++ built-in values in the deque 'd0' are not a permutation of the 'unsigned int (uint)' values in the deque 'd1'."<<endl;
	cout<<endl;
	cout<<"\tIntersecting the 'unsigned int (uint)' C++ built-in deques 'd0' and 'd1' ... ";
	Mangrove_intersection(d0,d1,d01);
	cout<<"ok"<<endl;
	cout<<"\tThe intersection between the deques of interest is given by the following 'unsigned int (uint)' C++ built-in values: ";
	Mangrove_exportHybrid(d01);
	cout<<endl;
	
	/* TASK #4 - deallocating all deques in this tutorial. */
	Mangrove_pause();
	cout<<"\tDeallocating all deques in this tutorial ... ";
	d0.clear();
	d1.clear();
	d01.clear();
	cout<<"ok"<<endl<<endl;
	cout.flush();
	return EXIT_SUCCESS;
}
