/*************************************************************************************************************************************************************************
 * This source code provides the 'Tutorial Example-012' for the Mangrove Topological Data Structure Library (Mangrove TDS Library 3.0)
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
 * Mangrove_tutorial012.cpp - the 'Tutorial Example-012' for the 'Mangrove TDS Library 3.0'.
 *************************************************************************************************************************************************************************/
 
#include "Mangrove_Miscellanea.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
using namespace mangrove_tds;

/// The <i>main function</i> for the <i>Mangrove_tutorial012</i> program.
/**
 * \file Mangrove_tutorial012.cpp
 * \author <A href="http://davidcanino.github.io">David Canino</A> (e-mail: <A href="mailto:canino.david@gmail.com">David Canino</A>)
 */

/// The <i>main function</i> for the <i>Mangrove_tutorial012</i> program.
/**
 * \return <ul><li>the built-in <i>EXIT_SUCCESS</i> constant value (provided by the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), if all is ok</li><li>the built-in <i>EXIT_FAILURE</i> constant value (provided by 
 * the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), otherwise</li></ul>
 * \see
 */
int main(void)
{
	vector<uint> v0,v1,v01;
	uint p;
	ofstream out;
	ifstream in;
	
	/* Now, we validate several functions in the 'Mangrove_Miscellanea.h' file, focused for manipulating the arrays of several template values (here, specialized for the 'uint' values). */
	Mangrove_exportCopyrightDisclaimer ("Mangrove_tutorial010");
	cout<<"\tCreating the new array 'v0', formed by several 'uint' values, ... ";
	v0.push_back(3);
	v0.push_back(0);
	v0.push_back(54);
	v0.push_back(11);
	v0.push_back(0);
	cout<<"ok"<<endl;
	cout<<"\tThe 'debug' representation for the content of the array 'v0' is the following:"<<endl;
	Mangrove_debug(v0);
	cout<<endl;
	cout.flush();
	
	/* Validating the 'Mangrove_exportHybrid()' and the 'Mangrove_reconstructFromHybrid()' template functions for the arrays of several template values. */
	cout<<"\tThe 'hybrid' representation for the content of the array 'v0' is the following: ";
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
	cout<<"\tThe 'hybrid' representation for the resulting array is the following: ";
	Mangrove_exportHybrid(v1);
	
	/* Validating the 'Mangrove_theSame()' template function for the arrays of several template values. */
	if(Mangrove_theSame(v0,v1)) cout<<"\tThe reconstructed array is 'the same as' the initial array 'v0'"<<endl<<endl;
	else cout<<"\tThe reconstructed array is not 'the same as' the initial array 'v0'"<<endl<<endl;
	cout<<"\tRemoving the 'hybrid_array.txt' file ... ";
	Mangrove_removeFile("hybrid_array.txt");
	cout<<"ok"<<endl<<endl;
	cout.flush();
	v1.clear();
	
	/* Validating the '<<' and the '>>' template operators for the arrays of several template values. */
	cout<<"\tThe 'compact' representation for the content of the array 'v0' is the following: "<<v0;
	cout.flush();
	cout<<endl<<"\tExporting the 'compact' representation for the content of the array 'v0' on the 'compact_array.txt' file ... ";
	out.open("compact_array.txt");
	out<<v0;
	out.close();
	cout<<"ok"<<endl;
	cout<<"\tReconstructing the content of the array 'v0' from the 'compact_array.txt' file ... ";
	in.open("compact_array.txt");
	in>>v1;
	in.close();
	cout<<"ok"<<endl;
	cout<<"\tThe 'compact' representation for the resulting array is the following: "<<v1;
	
	/* Validating the 'Mangrove_theSame()' template function for the arrays of several template values. */
	if(Mangrove_theSame(v0,v1)) cout<<"\tThe reconstructed array is 'the same as' the initial array 'v0'"<<endl<<endl;
	else cout<<"\tThe reconstructed array is not 'the same as' the initial array 'v0'"<<endl<<endl;
	v1.clear();
	cout<<"\tRemoving the 'compact_array.txt' file ... ";
	Mangrove_removeFile("compact_array.txt");
	cout<<"ok"<<endl<<endl;
	cout.flush();
	Mangrove_pause();
	
	/* Validating the 'Mangrove_getPosition()' template function for the arrays of several template values. */
	if(Mangrove_getPosition(v0,(uint)11,p)==true) { cout<<"\tThe array 'v0' contains the 'uint' value '11' in position "<<p<<endl; }
	else { cout<<"\tThe array 'v0' does not contain the 'uint' value '11'"<<endl; }
	if(Mangrove_getPosition(v0,(uint)58,p)==true) { cout<<"\tThe array 'v0' contains the 'uint' value '58' in position "<<p<<endl<<endl; }
	else { cout<<"\tThe array 'v0' does not contain the 'uint' value '58'"<<endl<<endl; }
	cout.flush();
	
	/* Validating the 'Mangrove_findProjection()' template function for the arrays of several template values. */
	cout<<"\tRetrieving the canonical projection of the array 'v0' with respect to the position 0 ... ";
	Mangrove_findProjection(0,v0,v1);
	cout<<"ok"<<endl;
	cout<<"\tThe resulting canonical projection of interest is the following: ";
	Mangrove_exportHybrid(v1);
	cout.flush();
	cout<<"\tRetrieving the canonical projection of the array 'v0' with respect to the position 4 ... ";
	Mangrove_findProjection(4,v0,v1);
	cout<<"ok"<<endl;
	cout<<"\tThe resulting canonical projection of interest is the following: ";
	Mangrove_exportHybrid(v1);
	cout<<endl;
	cout.flush();
	v1.clear();
	Mangrove_pause();
	
	/* Creating a new array of several 'uint' values. */
	cout<<"\tThe existing array 'v0': ";
	Mangrove_exportHybrid(v0);
	cout<<"\tCreating the new array 'v1', formed by several 'uint' values, ... ";
	v1.push_back(54);
	v1.push_back(11);
	v1.push_back(0);
	v1.push_back(3);
	v1.push_back(0);
	cout<<"ok"<<endl;
	cout<<"\tThe content of the new array 'v1': ";
	Mangrove_exportHybrid(v1);
	cout<<endl;
	cout.flush();
	if(v0<v1) { cout<<"\tThe array 'v0' is 'strictly less than' the array 'v1' (see the (template) comparison operator '<')"<<endl; }
	else { cout<<"\tThe array 'v0' is not 'strictly less than' the array 'v1' (see the (template) comparison operator '<')"<<endl; }
	if( Mangrove_DataComparator<uint>()(v0,v1) ) { cout<<"\tThe array 'v0' is 'strictly less than' the array 'v1' (see the 'Mangrove_DataComparator' template class)"<<endl; }
	else { cout<<"\tThe array 'v0' is not 'strictly less than' the array 'v1' (see the 'Mangrove_DataComparator' template class)"<<endl; }
	if(v1<v0) { cout<<"\tThe array 'v1' is 'strictly less than' the array 'v0' (see the comparison template operator '<')"<<endl; }
	else { cout<<"\tThe array 'v1' is not 'strictly less than' the array 'v0' (see the comparison template operator '<')"<<endl; }
	if( Mangrove_DataComparator<uint>()(v1,v0) ) { cout<<"\tThe array 'v1' is 'strictly less than' the array 'v0' (see the 'Mangrove_DataComparator' template class)"<<endl<<endl; }
	else { cout<<"\tThe array 'v1' is not 'strictly less than' the array 'v0' (see the 'Mangrove_DataComparator' template class)"<<endl<<endl; }
	cout<<"\tThe hashing value of the array 'v0': "<<boost::hash_value(v0)<<endl;
	cout<<"\tThe hashing value of the array 'v1': "<<boost::hash_value(v1)<<endl<<endl;
	if( Mangrove_DataComparatorWithHashing<uint>()(v1,v0) ) { cout<<"\tThe array 'v1' is 'strictly less than' the array 'v0' (see the 'Mangrove_DataComparatorWithHashing' template class)"<<endl; }
	else { cout<<"\tThe array 'v1' is not 'strictly less than' the array 'v0' (see the 'Mangrove_DataComparatorWithHashing' template class)"<<endl; }
	if( Mangrove_DataComparatorWithHashing<uint>()(v0,v1) ) { cout<<"\tThe array 'v0' is 'strictly less than' the array 'v1' (see the 'Mangrove_DataComparatorWithHashing' template class)"<<endl<<endl; }
	else { cout<<"\tThe array 'v0' is not 'strictly less than' the array 'v1' (see the 'Mangrove_DataComparatorWithHashing' template class)"<<endl<<endl; }
	cout.flush();
	Mangrove_pause();
	
	/* Validating the 'Mangrove_isPermutation()' template function for the arrays of several template values. */
	if(Mangrove_isPermutation(v0,v1)==true) cout<<"\tThe 'uint' values in the array 'v0' are a permutation of the 'uint' values in the array 'v1'"<<endl;
	else cout<<"\tThe 'uint' values in the array 'v0' are not a permutation of the 'uint' values in the array 'v1'"<<endl;
	cout<<endl;
	cout.flush();
	
	/* Validating the 'Mangrove_includes()' template function for the arrays of several template values. */
	if(Mangrove_includes(v0,v1)==true) cout<<"\tThe array 'v0' contains all 'uint' values of the array 'v1'"<<endl;
	else cout<<"\tThe array 'v0' does not contain all 'uint' values of the array 'v1'"<<endl;
	if(Mangrove_includes(v1,v0)==true) cout<<"\tThe array 'v1' contains all 'uint' values of the array 'v0'"<<endl;
	else cout<<"\tThe array 'v1' does not contain all 'uint' values of the array 'v0'"<<endl;
	cout<<endl;
	cout.flush();
	
	/* Validating the 'Mangrove_intersection()' template function for the arrays of several template values. */
	cout<<"\tIntersecting the arrays 'v0' and 'v1' (without sorting the template values in the arrays of interest) ... ";
	Mangrove_intersection(v0,v1,v01);
	cout<<"ok"<<endl;
	cout<<"\tThe wrong content for the intersection of interest (obtained without sorting the template values in the arrays 'v0' and 'v1') is the following: ";
	Mangrove_exportHybrid(v01);
	cout<<endl;
	cout.flush();
	cout<<"\tIntersecting the arrays 'v0' and 'v1' (by also sorting the template values in the arrays of interest) ... ";
	Mangrove_intersection(v0,v1,v01,true);
	cout<<"ok"<<endl;
	cout<<"\tThe sorted template values in the updated array 'v0': ";
	Mangrove_exportHybrid(v0);
	cout<<"\tThe sorted template values in the updated array 'v1': ";
	Mangrove_exportHybrid(v1);
	cout<<"\tThe correct content for the intersection of interest (obtained by also sorting the template values in the arrays 'v0' and 'v1') is the following: ";
	Mangrove_exportHybrid(v01);
	cout<<endl;
	
	/* Validating the 'Mangrove_isPermutation()' template function for the (sorted) arrays of several template values. */
	if(Mangrove_isPermutation(v0,v1)==true) cout<<"\tThe (sorted) 'uint' values in the array 'v0' are a permutation of the (sorted) 'uint' values in the array 'v1'"<<endl;
	else cout<<"\tThe (sorted) 'uint' values in the array 'v0' are not a permutation of the (sorted) 'uint' values in the array 'v1'"<<endl;
	cout<<endl;
	cout.flush();
	
	/* Validating the 'Mangrove_includes()' template function for the arrays of several template values. */
	if(Mangrove_includes(v0,v1)==true) cout<<"\tThe (sorted) array 'v0' contains all 'uint' values of the (sorted) array 'v1'"<<endl;
	else cout<<"\tThe (sorted) array 'v0' does not contain all 'uint' values of the (sorted) array 'v1'"<<endl;
	if(Mangrove_includes(v1,v0)==true) cout<<"\tThe (sorted) array 'v1' contains all 'uint' values of the (sorted) array 'v0'"<<endl;
	else cout<<"\tThe (sorted) array 'v1' does not contain all 'uint' values of the (sorted) array 'v0'"<<endl;
	cout<<endl;
	cout.flush();
	cout<<"\tDeallocating all arrays of interest ... ";
	v0.clear();
	v1.clear();
	v01.clear();
	cout<<"ok"<<endl<<endl;
	cout.flush();
}
