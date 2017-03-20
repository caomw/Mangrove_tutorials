/*************************************************************************************************************************************************************************
 * This source code provides the 'Tutorial Example-020' for the Mangrove Topological Data Structure Library (Mangrove TDS Library 3.0)
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
 * Mangrove_tutorial020.cpp - the 'Tutorial Example-020' for the 'Mangrove TDS Library 3.0'.
 *************************************************************************************************************************************************************************/

#include "Mangrove_Miscellanea.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
using namespace mangrove_tds;

/// The <i>main function</i> for the <i>'Mangrove_tutorial020'</i> program.
/**
 * \file Mangrove_tutorial020.cpp
 * \author <A href="http://davidcanino.github.io">David Canino</A> (e-mail: <A href="mailto:canino.david@gmail.com">David Canino</A>)
 */

/// The <i>main function</i> for the <i>'Mangrove_tutorial020'</i> program.
/**
 * \return <ul><li>the built-in <i>EXIT_SUCCESS</i> constant value (provided by the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), if all is ok</li><li>the built-in <i>EXIT_FAILURE</i> constant value (provided by 
 * the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), otherwise</li></ul>
 * \see mangrove_tds::Mangrove_exportCopyrightDisclaimer(), mangrove_tds::Mangrove_pause(), mangrove_tds::Mangrove_removeFile(), mangrove_tds::Mangrove_DataComparatorWithHashing
 */
int main(void)
{
	deque< deque<int> > d,d1;
	deque< set<int, Mangrove_DataComparatorWithHashing<int> > > ds;
	ofstream out;
	ifstream in;

	/* This is the 'Mangrove_tutorial020' tutorial, where the nested deques of several 'integer (int)' C++ built-in values are validated. Here, the 'integer (int)' C++ built-in values are sorted with respect to their hashing values (see the 
	 * 'Mangrove_DataComparatorWithHashing' template class). */
	Mangrove_exportCopyrightDisclaimer ("The 'Mangrove_tutorial020' Tutorial");
	cout<<"\tIMPORTANT:\tthe 'integer (int)' C++ built-in values in the sets of interest are sorted with respect to the order relation of their hashing values (see the 'Mangrove_DataComparatorWithHashing' template class)."<<endl<<endl;
	cout.flush();
	
	/* TASK #1 - creating a new nested deque, containing several deques of 'integer (int)' C++ built-in values. Then, converting this new deque to the corresponding nested deque of several sets. */
	cout<<"\tCreating the nested deque 'd', containing several deques of 'integer (int)' C++ built-in values, ... ";
	d.push_back( deque<int>() );
	d.back().push_back(3);
	d.push_back( deque<int>() );
	for(int k=10;k>6;k--) d.back().push_back(2*k);
	d.back().push_back(-1);
	d.back().push_back(-4);
	cout<<"ok"<<endl;
	Mangrove_debug(d);
	cout<<"\tThe total number of the 'integer (int)' C++ built-in values in the nested deque 'd' is "<<Mangrove_valuesNumber(d)<<"."<<endl<<endl;
	cout.flush();
	cout<<"\tConverting the nested deque 'd' into the nested deque 'ds', containing several sets of 'integer (int)' C++ built-in values, ... ";
	Mangrove_convert(d,ds);
	cout<<"ok"<<endl;
	Mangrove_debug(ds);
	cout<<"\tThe total number of the 'integer (int)' C++ built-in values in the new nested deque 'ds' is "<<Mangrove_valuesNumber(ds)<<"."<<endl<<endl;
	cout<<"\tConverting the nested deque 'ds' back to the corresponding nesting deque, containing several deques, ... ";
	Mangrove_convert(ds,d1);
	cout<<"ok"<<endl;
	if(Mangrove_theSame(d,d1)) cout<<"\tThe content of the new nested deque coincides with the content of the original nested deque 'd'."<<endl<<endl;
	else cout<<"\tThe content of the new nested deque does not coincide with the content of the original nested deque 'd'."<<endl<<endl;
	cout.flush();
	
	/* TASK #2 - deallocating all nested deques in this tutorial. */
	cout<<"\tDeallocating all nested deques of this tutorial ... ";
	Mangrove_destroy(d);
	Mangrove_destroy(d1);
	Mangrove_destroy(ds);
	cout<<"ok"<<endl<<endl;
	cout.flush();
	return EXIT_SUCCESS;
}
