/*************************************************************************************************************************************************************************
 * This source code provides the 'Tutorial Example-010' for the Mangrove Topological Data Structure Library (Mangrove TDS Library 3.0)
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
 * Mangrove_tutorial010.cpp - the 'Tutorial Example-010' for the 'Mangrove TDS Library 3.0'.
 *************************************************************************************************************************************************************************/
 
#include "Mangrove_Miscellanea.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
using namespace mangrove_tds;

/// The <i>main function</i> for the <i>Mangrove_tutorial010</i> program.
/**
 * \file Mangrove_tutorial010.cpp
 * \author <A href="http://davidcanino.github.io">David Canino</A> (e-mail: <A href="mailto:canino.david@gmail.com">David Canino</A>)
 */

/// The <i>main function</i> for the <i>Mangrove_tutorial010</i> program.
/**
 * \return <ul><li>the built-in <i>EXIT_SUCCESS</i> constant value (provided by the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), if all is ok</li><li>the built-in <i>EXIT_FAILURE</i> constant value (provided by 
 * the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), otherwise</li></ul>
 * \see mangrove_tds::Mangrove_exportCopyrightDisclaimer()
 */
int main(void)
{
	deque<uint> d0,d1,d01;
	uint p;
	ofstream out;
	ifstream in;

	/* Now, we validate several functions in the 'Mangrove_Miscellanea.h' file, focused for manipulating the deques of several template values (here, specialized for the 'uint' values). */
	Mangrove_exportCopyrightDisclaimer ("Mangrove_tutorial010");
	cout<<"\tCreating the new deque 'd0', formed by several 'uint' values, ... ";
	d0.push_back(3);
	d0.push_back(0);
	d0.push_back(54);
	d0.push_back(11);
	d0.push_back(0);
	cout<<"ok"<<endl;
	cout<<"\tThe 'debug' representation for the content of the deque 'd0' is:"<<endl;
	Mangrove_debug(d0);
	cout<<endl;
	cout.flush();
	
	/* Validating the 'Mangrove_exportHybrid()' and the 'Mangrove_reconstructFromHybrid()' template functions for the deques of several template values. */
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
	cout<<"\tThe 'hybrid' representation for the resulting deque is: ";
	Mangrove_exportHybrid(d1);
	
	/* Validating the 'Mangrove_theSame()' template function for the deques of several template values. */
	if(Mangrove_theSame(d0,d1)) cout<<"\tThe reconstructed deque is 'the same as' the initial deque 'd0'"<<endl<<endl;
	else cout<<"\tThe reconstructed deque is not 'the same as' the initial deque 'd0'"<<endl<<endl;
	cout<<"\tRemoving the 'hybrid_deque.txt' file ... ";
	Mangrove_removeFile("hybrid_deque.txt");
	cout<<"ok"<<endl<<endl;
	cout.flush();
	d1.clear();
	
	/* Validating the '<<' and the '>>' template operators for the deques of several template values. */
	cout<<"\tThe 'compact' representation for the content of the deque 'd0' is: "<<d0;
	cout.flush();
	cout<<endl<<"\tExporting the 'compact' representation for the content of the deque 'd0' on the 'compact_deque.txt' file ... ";
	out.open("compact_deque.txt");
	out<<d0;
	out.close();
	cout<<"ok"<<endl;
	cout<<"\tReconstructing the content of the deque 'd0' from the 'compact_deque.txt' file ... ";
	in.open("compact_deque.txt");
	in>>d1;
	in.close();
	cout<<"ok"<<endl;
	cout<<"\tThe 'compact' representation for the resulting deque is: "<<d1;
	
	/* Validating the 'Mangrove_theSame()' template function for the deques of several template values. */
	if(Mangrove_theSame(d0,d1)) cout<<"\tThe reconstructed deque is 'the same as' the initial deque 'd0'"<<endl<<endl;
	else cout<<"\tThe reconstructed deque is not 'the same as' the initial deque 'd0'"<<endl<<endl;
	d1.clear();
	cout<<"\tRemoving the 'compact_deque.txt' file ... ";
	Mangrove_removeFile("compact_deque.txt");
	cout<<"ok"<<endl<<endl;
	cout.flush();
	Mangrove_pause();
	
	/* Validating the 'Mangrove_getPosition()' template function for the deques of several template values. */
	if(Mangrove_getPosition(d0,(uint)54,p)==true) { cout<<"\tThe deque 'd0' contains the 'uint' value '54' in position "<<p<<endl; }
	else { cout<<"\tThe deque 'd0' does not contain the 'uint' value '54'"<<endl; }
	if(Mangrove_getPosition(d0,(uint)58,p)==true) { cout<<"\tThe deque 'd0' contains the 'uint' value '58' in position "<<p<<endl<<endl; }
	else { cout<<"\tThe deque 'd0' does not contain the 'uint' value '58'"<<endl<<endl; }
	cout.flush();
	
	/* Validating the 'Mangrove_findProjection()' template function for the deques of several template values. */
	cout<<"\tRetrieving the canonical projection of the deque 'd0' with respect to the position 0 ... ";
	Mangrove_findProjection(0,d0,d1);
	cout<<"ok"<<endl;
	cout<<"\tThe resulting canonical projection of interest is: ";
	Mangrove_exportHybrid(d1);
	cout.flush();
	cout<<"\tRetrieving the canonical projection of the deque 'd0' with respect to the position 4 ... ";
	Mangrove_findProjection(4,d0,d1);
	cout<<"ok"<<endl;
	cout<<"\tThe resulting canonical projection of interest is: ";
	Mangrove_exportHybrid(d1);
	cout<<endl;
	cout.flush();
	d1.clear();
	Mangrove_pause();
	
	/* Creating a new deque of several 'uint' values. */
	cout<<"\tThe content of the existing deque 'd0' is: ";
	Mangrove_exportHybrid(d0);
	cout<<"\tCreating the new deque 'd1', formed by several 'uint' values, ... ";
	d1.push_back(1);
	d1.push_back(5);
	d1.push_back(4);
	d1.push_back(11);
	d1.push_back(54);
	cout<<"ok"<<endl;
	cout<<"\tThe content of the new deque 'd1' is: ";
	Mangrove_exportHybrid(d1);
	cout<<endl;
	cout.flush();
	if(d0<d1) { cout<<"\tThe deque 'd0' is 'strictly less than' the deque 'd1' (see the (template) comparison operator '<')"<<endl; }
	else { cout<<"\tThe deque 'd0' is not 'strictly less than' the deque 'd1' (see the (template) comparison operator '<')"<<endl; }
	if( Mangrove_DataComparator<uint>()(d0,d1) ) { cout<<"\tThe deque 'd0' is 'strictly less than' the deque 'd1' (see the 'Mangrove_DataComparator' template class)"<<endl; }
	else { cout<<"\tThe deque 'd0' is not 'strictly less than' the deque 'd1' (see the 'Mangrove_DataComparator' template class)"<<endl; }
	if(d1<d0) { cout<<"\tThe deque 'd1' is 'strictly less than' the deque 'd0' (see the comparison template operator '<')"<<endl; }
	else { cout<<"\tThe deque 'd1' is not 'strictly less than' the deque 'd0' (see the comparison template operator '<')"<<endl; }
	if( Mangrove_DataComparator<uint>()(d1,d0) ) { cout<<"\tThe deque 'd1' is 'strictly less than' the deque 'd0' (see the 'Mangrove_DataComparator' template class)"<<endl<<endl; }
	else { cout<<"\tThe deque 'd1' is not 'strictly less than' the deque 'd0' (see the 'Mangrove_DataComparator' template class)"<<endl<<endl; }
	cout<<"\tThe hashing value of the deque 'd0' (see the 'boost::hash_value()' template function) is: "<<boost::hash_value(d0)<<endl;
	cout<<"\tThe hashing value of the deque 'd1' (see the 'boost::hash_value()' template function) is: "<<boost::hash_value(d1)<<endl<<endl;
	if( Mangrove_DataComparatorWithHashing<uint>()(d1,d0) ) { cout<<"\tThe deque 'd1' is 'strictly less than' the deque 'd0' (see the 'Mangrove_DataComparatorWithHashing' template class)"<<endl; }
	else { cout<<"\tThe deque 'd1' is not 'strictly less than' the deque 'd0' (see the 'Mangrove_DataComparatorWithHashing' template class)"<<endl; }
	if( Mangrove_DataComparatorWithHashing<uint>()(d0,d1) ) { cout<<"\tThe deque 'd0' is 'strictly less than' the deque 'd1' (see the 'Mangrove_DataComparatorWithHashing' template class)"<<endl<<endl; }
	else { cout<<"\tThe deque 'd0' is not 'strictly less than' the deque 'd1' (see the 'Mangrove_DataComparatorWithHashing' template class)"<<endl<<endl; }
	cout.flush();
	Mangrove_pause();
	
	/* Validating the 'Mangrove_isPermutation()' template function for the deques of several template values. */
	if(Mangrove_isPermutation(d0,d1)==true) cout<<"\tThe 'uint' values in the deque 'd0' are a permutation of the 'uint' values in the deque 'd1'"<<endl;
	else cout<<"\tThe 'uint' values in the deque 'd0' are not a permutation of the 'uint' values in the deque 'd1'"<<endl;
	cout<<endl;
	cout.flush();
	
	/* Validating the 'Mangrove_includes()' template function for the deques of several template values. */
	if(Mangrove_includes(d0,d1)==true) cout<<"\tThe deque 'd0' contains all 'uint' values of the deque 'd1' in the same order as they appear (but not forming a block of consecutive 'uint' values)"<<endl;
	else cout<<"\tThe deque 'd0' does not contain all 'uint' values of the deque 'd1' in the same order as they appear (but not forming a block of consecutive 'uint' values)"<<endl;
	if(Mangrove_includes(d1,d0)==true) cout<<"\tThe deque 'd1' contains all 'uint' values of the deque 'd0' in the same order as they appear (but not forming a block of consecutive 'uint' values)"<<endl;
	else cout<<"\tThe deque 'd1' does not contain all 'uint' values of the deque 'd0' in the same order as they appear (but not forming a block of consecutive 'uint' values)"<<endl;
	cout<<endl;
	cout.flush();
	
	/* Validating the 'Mangrove_intersection()' template function for the deques of several template values. */
	cout<<"\tIntersecting the deques 'd0' and 'd1' (without sorting the template values in the deques of interest) ... ";
	Mangrove_intersection(d0,d1,d01);
	cout<<"ok"<<endl;
	cout<<"\tThe (wrong) content for the intersection of interest (obtained without sorting the template values in the deques 'd0' and 'd1') is: ";
	Mangrove_exportHybrid(d01);
	cout<<endl;
	cout.flush();
	cout<<"\tIntersecting the deques 'd0' and 'd1' (by also sorting the template values in the deques of interest) ... ";
	Mangrove_intersection(d0,d1,d01,true);
	cout<<"ok"<<endl;
	cout<<"\tThe sorted template values in the updated deque 'd0' are: ";
	Mangrove_exportHybrid(d0);
	cout<<"\tThe sorted template values in the updated deque 'd1' are: ";
	Mangrove_exportHybrid(d1);
	cout<<"\tThe correct content for the intersection of interest (obtained by also sorting the template values in the deques 'd0' and 'd1') is: ";
	Mangrove_exportHybrid(d01);
	cout<<endl;
	
	/* If we arrive here, then all is ok. */
	cout<<"\tDeallocating all deques of interest ... ";
	d0.clear();
	d1.clear();
	d01.clear();
	cout<<"ok"<<endl<<endl;
	cout.flush();
	return EXIT_SUCCESS;
}
 