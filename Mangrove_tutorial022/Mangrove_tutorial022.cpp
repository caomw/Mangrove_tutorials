/*************************************************************************************************************************************************************************
 * This source code provides the 'Tutorial Example-022' for the Mangrove Topological Data Structure Library (Mangrove TDS Library 3.0)
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
 * Mangrove_tutorial022.cpp - the 'Tutorial Example-022' for the 'Mangrove TDS Library 3.0'.
 *************************************************************************************************************************************************************************/
 
#include "Mangrove_Miscellanea.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
using namespace mangrove_tds;

/// The <i>main function</i> for the <i>Mangrove_tutorial022</i> program.
/**
 * \file Mangrove_tutorial022.cpp
 * \author <A href="http://davidcanino.github.io">David Canino</A> (e-mail: <A href="mailto:canino.david@gmail.com">David Canino</A>)
 */

/// The <i>main function</i> for the <i>Mangrove_tutorial022</i> program.
/**
 * \return <ul><li>the built-in <i>EXIT_SUCCESS</i> constant value (provided by the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), if all is ok</li><li>the built-in <i>EXIT_FAILURE</i> constant value (provided by 
 * the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), otherwise</li></ul>
 * \see mangrove_tds::Mangrove_exportCopyrightDisclaimer(), mangrove_tds::Mangrove_DataComparatorWithHashing
 */
int main(void)
{
	vector< vector<uint> > a,a1;
	vector< set<uint,Mangrove_DataComparatorWithHashing<uint>> > as;

	/* Now, we validate several functions in the 'Mangrove_Miscellanea.h' file, focused for manipulating the nested arrays, containing several arrays of 'uint' values. 
	 * Here, the 'uint' values are sorted in the set of interest by using their hashing values. Specifically, the hashing value of a given 'uint' value 'x' corresponds with 'x' itself. The actual comparison are performed by the 'Mangrove_DataComparatorWithHashing' 
	 * template class. */
	Mangrove_exportCopyrightDisclaimer("Mangrove_tutorial022");
	cout<<"\tCreating the nested array 'a', containing several arrays of 'uint' values, ... ";
	a.push_back( vector<uint>() );
	a.back().push_back(4);
	a.back().push_back(2);
	a.back().push_back(5);
	a.push_back( vector<uint>() );
	for(uint k=10;k>6;k--) a.back().push_back(k);
	cout<<"ok"<<endl<<endl;
	cout<<"\tThe total number of the 'uint' values in the nested array 'a': "<<Mangrove_valuesNumber(a)<<endl;
	cout.flush();
	Mangrove_debug(a);
	cout<<"\tConverting the nested array 'a' into the nested array 'as', containing several sets of 'uint' values (sorted with respect to the order relation of their hashing values, see the 'Mangrove_DataComparatorWithHashing' template class), ... ";
	Mangrove_convert(a,as);
	cout<<"ok"<<endl<<endl;
	cout<<"\tThe total number of the 'uint' values in the new nested array 'as': "<<Mangrove_valuesNumber(as)<<endl;
	cout.flush();
	Mangrove_debug(as);
	cout<<"\tConverting the nested array 'as' into the corresponding nesting array, containing several arrays, ... ";
	Mangrove_convert(as,a1);
	cout<<"ok"<<endl<<endl;
	cout<<"\tThe total number of the 'uint' values in the new nested array: "<<Mangrove_valuesNumber(a1)<<endl;
	Mangrove_debug(a1);
	cout<<"\tDeallocating all nested arrays of this tutorial ... ";
	Mangrove_destroy(a);
	Mangrove_destroy(a1);
	Mangrove_destroy(as);
	cout<<"ok"<<endl<<endl;
	cout.flush();
	return EXIT_SUCCESS;
}
