/*************************************************************************************************************************************************************************
 * This source code provides the 'Tutorial Example-011' for the Mangrove Topological Data Structure Library (Mangrove TDS Library 3.0)
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
 * Mangrove_tutorial011.cpp - the 'Tutorial Example-011' for the 'Mangrove TDS Library 3.0'.
 *************************************************************************************************************************************************************************/
 
#include "Mangrove_Miscellanea.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
using namespace mangrove_tds;

/// The <i>main function</i> for the <i>Mangrove_tutorial011</i> program.
/**
 * \file Mangrove_tutorial011.cpp
 * \author <A href="http://davidcanino.github.io">David Canino</A> (e-mail: <A href="mailto:canino.david@gmail.com">David Canino</A>)
 */

/// The <i>main function</i> for the <i>Mangrove_tutorial011</i> program.
/**
 * \return <ul><li>the built-in <i>EXIT_SUCCESS</i> constant value (provided by the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), if all is ok</li><li>the built-in <i>EXIT_FAILURE</i> constant value (provided by 
 * the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), otherwise</li></ul>
 * \see mangrove_tds::Mangrove_exportCopyrightDisclaimer()
 */
int main(void)
{
	list<uint> l0,l1,l01;
	uint p;
	ofstream out;
	ifstream in;
	
	/* Now, we validate several functions in the 'Mangrove_Miscellanea.h' file, focused for manipulating the lists of several template values (here, specialized for the 'uint' values). */
	Mangrove_exportCopyrightDisclaimer("Mangrove_tutorial011");
	cout<<"\tCreating the new list 'l0', formed by several 'uint' values, ... ";
	l0.push_back(3);
	l0.push_back(0);
	l0.push_back(54);
	l0.push_back(11);
	l0.push_back(5);
	cout<<"ok"<<endl;
	cout<<"\tThe 'debug' representation for the content of the list 'l0' is:"<<endl;
	Mangrove_debug(l0);
	cout<<endl;
	cout.flush();
	
	/* Validating the 'Mangrove_exportHybrid()' and the 'Mangrove_reconstructFromHybrid()' template functions for the lists of several template values. */
	cout<<"\tThe 'hybrid' representation for the content of the list 'l0' is: ";
	Mangrove_exportHybrid(l0);
	cout<<endl<<"\tExporting the 'hybrid' representation for the content of the list 'l0' on the 'hybrid_list.txt' file ... ";
	out.open("hybrid_list.txt");
	Mangrove_exportHybrid(l0,out);
	out.close();
	cout<<"ok"<<endl;
	l1.resize(5);
	cout<<"\tReconstructing the content of the list 'l0' from the 'hybrid_list.txt' file ... ";
	in.open("hybrid_list.txt");
	Mangrove_reconstructFromHybrid(l1,in);
	in.close();
	cout<<"ok"<<endl;
	cout<<"\tThe 'hybrid' representation for the resulting list is: ";
	Mangrove_exportHybrid(l1);
	
	/* Validating the 'Mangrove_theSame()' template function for the lists of several template values. */
	if(Mangrove_theSame(l0,l1)) cout<<"\tThe reconstructed list is 'the same as' the initial list 'l0'"<<endl<<endl;
	else cout<<"\tThe reconstructed list is not 'the same as' the initial list 'l0'"<<endl<<endl;
	cout<<"\tRemoving the 'hybrid_list.txt' file ... ";
	Mangrove_removeFile("hybrid_list.txt");
	cout<<"ok"<<endl<<endl;
	cout.flush();
	l1.clear();
	
	/* Validating the '<<' and the '>>' template operators for the lists of several template values. */
	cout<<"\tThe 'compact' representation for the content of the list 'l0' is: "<<l0;
	cout.flush();
	cout<<endl<<"\tExporting the 'compact' representation for the content of the list 'l0' on the 'compact_list.txt' file ... ";
	out.open("compact_list.txt");
	out<<l0;
	out.close();
	cout<<"ok"<<endl;
	cout<<"\tReconstructing the content of the list 'l0' from the 'compact_list.txt' file ... ";
	in.open("compact_list.txt");
	in>>l1;
	in.close();
	cout<<"ok"<<endl;
	cout<<"\tThe 'compact' representation for the resulting list is: "<<l1;
	
	/* Validating the 'Mangrove_theSame()' template function for the lists of several template values. */
	if(Mangrove_theSame(l0,l1)) cout<<"\tThe reconstructed list is 'the same as' the initial list 'l0'"<<endl<<endl;
	else cout<<"\tThe reconstructed list is not 'the same as' the initial list 'l0'"<<endl<<endl;
	l1.clear();
	cout<<"\tRemoving the 'compact_list.txt' file ... ";
	Mangrove_removeFile("compact_list.txt");
	cout<<"ok"<<endl<<endl;
	cout.flush();
	Mangrove_pause();
	
	/* Validating the 'Mangrove_getPosition()' template function for the lists of several template values. */
	if(Mangrove_getPosition(l0,(uint)5,p)==true) { cout<<"\tThe list 'l0' contains the 'uint' value '5' in position "<<p<<endl; }
	else { cout<<"\tThe list 'l0' does not contain the 'uint' value '5'"<<endl; }
	if(Mangrove_getPosition(l0,(uint)49,p)==true) { cout<<"\tThe list 'l0' contains the 'uint' value '49' in position "<<p<<endl<<endl; }
	else { cout<<"\tThe list 'l0' does not contain the 'uint' value '49'"<<endl<<endl; }
	cout.flush();
	
	/* Validating the 'Mangrove_findProjection()' template function for the lists of several template values. */
	cout<<"\tRetrieving the canonical projection of the list 'l0' with respect to the position 0 ... ";
	Mangrove_findProjection(0,l0,l1);
	cout<<"ok"<<endl;
	cout<<"\tThe resulting canonical projection of interest is: ";
	Mangrove_exportHybrid(l1);
	cout.flush();
	cout<<"\tRetrieving the canonical projection of the list 'l0' with respect to the position 4 ... ";
	Mangrove_findProjection(4,l0,l1);
	cout<<"ok"<<endl;
	cout<<"\tThe resulting canonical projection of interest is: ";
	Mangrove_exportHybrid(l1);
	cout<<endl;
	cout.flush();
	l1.clear();
	Mangrove_pause();
	
	/* Creating a new list of several 'uint' values. */
	cout<<"\tThe content of the existing list 'l0' is: ";
	Mangrove_exportHybrid(l0);
	cout<<"\tCreating the new list 'l1', formed by several 'uint' values, ... ";
	l1.push_back(54);
	l1.push_back(11);
	l1.push_back(0);
	l1.push_back(3);
	l1.push_back(0);
	cout<<"ok"<<endl;
	cout<<"\tThe content of the new list 'l1' is: ";
	Mangrove_exportHybrid(l1);
	cout<<endl;
	cout.flush();
	if(l0<l1) { cout<<"\tThe list 'l0' is 'strictly less than' the list 'l1' (see the (template) comparison operator '<')"<<endl; }
	else { cout<<"\tThe list 'l0' is not 'strictly less than' the list 'l1' (see the (template) comparison operator '<')"<<endl; }
	if( Mangrove_DataComparator<uint>()(l0,l1) ) { cout<<"\tThe list 'l0' is 'strictly less than' the list 'l1' (see the 'Mangrove_DataComparator' template class)"<<endl; }
	else { cout<<"\tThe list 'l0' is not 'strictly less than' the list 'l1' (see the 'Mangrove_DataComparator' template class)"<<endl; }
	if(l1<l0) { cout<<"\tThe list 'l1' is 'strictly less than' the list 'l0' (see the comparison template operator '<')"<<endl; }
	else { cout<<"\tThe list 'l1' is not 'strictly less than' the list 'l0' (see the comparison template operator '<')"<<endl; }
	if( Mangrove_DataComparator<uint>()(l1,l0) ) { cout<<"\tThe list 'l1' is 'strictly less than' the list 'l0' (see the 'Mangrove_DataComparator' template class)"<<endl<<endl; }
	else { cout<<"\tThe list 'l1' is not 'strictly less than' the list 'l0' (see the 'Mangrove_DataComparator' template class)"<<endl<<endl; }
	cout<<"\tThe hashing value of the list 'l0' is: "<<boost::hash_value(l0)<<endl;
	cout<<"\tThe hashing value of the list 'l1' is: "<<boost::hash_value(l1)<<endl<<endl;
	if( Mangrove_DataComparatorWithHashing<uint>()(l1,l0) ) { cout<<"\tThe list 'l1' is 'strictly less than' the list 'l0' (see the 'Mangrove_DataComparatorWithHashing' template class)"<<endl; }
	else { cout<<"\tThe list 'l1' is not 'strictly less than' the list 'l0' (see the 'Mangrove_DataComparatorWithHashing' template class)"<<endl; }
	if( Mangrove_DataComparatorWithHashing<uint>()(l0,l1) ) { cout<<"\tThe list 'l0' is 'strictly less than' the list 'l1' (see the 'Mangrove_DataComparatorWithHashing' template class)"<<endl<<endl; }
	else { cout<<"\tThe list 'l0' is not 'strictly less than' the list 'l1' (see the 'Mangrove_DataComparatorWithHashing' template class)"<<endl<<endl; }
	cout.flush();
	Mangrove_pause();
	
	/* Validating the 'Mangrove_isPermutation()' template function for the lists of several template values. */
	if(Mangrove_isPermutation(l0,l1)==true) cout<<"\tThe 'uint' values in the list 'l0' are a permutation of the 'uint' values in the list 'l1'"<<endl;
	else cout<<"\tThe 'uint' values in the list 'l0' are not a permutation of the 'uint' values in the list 'l1'"<<endl;
	cout<<endl;
	cout.flush();
	
	/* Validating the 'Mangrove_includes()' template function for the lists of several template values. */
	if(Mangrove_includes(l0,l1)==true) cout<<"\tThe list 'l0' contains all 'uint' values of the list 'l1' in the same order as they appear (but not forming a block of consecutive 'uint' values)"<<endl;
	else cout<<"\tThe list 'l0' does not contain all 'uint' values of the list 'l1' in the same order as they appear (but not forming a block of consecutive 'uint' values)"<<endl;
	if(Mangrove_includes(l1,l0)==true) cout<<"\tThe list 'l1' contains all 'uint' values of the list 'l0' in the same order as they appear (but not forming a block of consecutive 'uint' values)"<<endl;
	else cout<<"\tThe list 'l1' does not contain all 'uint' values of the list 'l0' in the same order as they appear (but not forming a block of consecutive 'uint' values)"<<endl;
	cout<<endl;
	cout.flush();
	
	/* Validating the 'Mangrove_intersection()' template function for the lists of several template values. */
	cout<<"\tIntersecting the lists 'l0' and 'l1' (without sorting the template values in the lists of interest) ... ";
	Mangrove_intersection(l0,l1,l01);
	cout<<"ok"<<endl;
	cout<<"\tThe (wrong) content for the intersection of interest (obtained without sorting the template values in the lists 'l0' and 'l1') is: ";
	Mangrove_exportHybrid(l01);
	cout<<endl;
	cout.flush();
	cout<<"\tIntersecting the lists 'l0' and 'l1' (by also sorting the template values in the lists of interest) ... ";
	Mangrove_intersection(l0,l1,l01,true);
	cout<<"ok"<<endl;
	cout<<"\tThe sorted template values in the updated list 'l0' are: ";
	Mangrove_exportHybrid(l0);
	cout<<"\tThe sorted template values in the updated list 'l1' are: ";
	Mangrove_exportHybrid(l1);
	cout<<"\tThe correct content for the intersection of interest (obtained by also sorting the template values in the lists 'l0' and 'l1') is: ";
	Mangrove_exportHybrid(l01);
	cout<<endl;
	
	/* Validating the 'Mangrove_isPermutation()' template function for the (sorted) lists of several template values. */
	if(Mangrove_isPermutation(l0,l1)==true) cout<<"\tThe (sorted) 'uint' values in the list 'l0' are a permutation of the (sorted) 'uint' values in the list 'l1'"<<endl;
	else cout<<"\tThe (sorted) 'uint' values in the list 'l0' are not a permutation of the (sorted) 'uint' values in the list 'l1'"<<endl;
	cout<<endl;
	cout.flush();
	
	/* Validating the 'Mangrove_includes()' template function for the lists of several template values. */
	if(Mangrove_includes(l0,l1,true)==true) cout<<"\tThe (sorted) list 'l0' contains all 'uint' values of the (sorted) list 'l1' in the same order as they appear (but not forming a block of consecutive 'uint' values)"<<endl;
	else cout<<"\tThe (sorted) list 'l0' does not contain all 'uint' values of the (sorted) list 'l1' in the same order as they appear (but not forming a block of consecutive 'uint' values)"<<endl;
	if(Mangrove_includes(l1,l0)==true) cout<<"\tThe (sorted) list 'l1' contains all 'uint' values of the (sorted) list 'l0' in the same order as they appear (but not forming a block of consecutive 'uint' values)"<<endl;
	else cout<<"\tThe (sorted) list 'l1' does not contain all 'uint' values of the (sorted) list 'l0' in the same order as they appear (but not forming a block of consecutive 'uint' values)"<<endl;
	cout<<endl;
	cout.flush();
	
	/* If we arrive here, then all is ok. */
	cout<<"\tDeallocating all lists of interest ... ";
	l0.clear();
	l1.clear();
	l01.clear();
	cout<<"ok"<<endl<<endl;
	cout.flush();
	return EXIT_SUCCESS;
}
