/*************************************************************************************************************************************************************************
 * This source code provides the 'Tutorial Example-019' for the Mangrove Topological Data Structure Library (Mangrove TDS Library 3.0)
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
 * Mangrove_tutorial019.cpp - the 'Tutorial Example-019' for the 'Mangrove TDS Library 3.0'.
 *************************************************************************************************************************************************************************/

#include "Mangrove_Miscellanea.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
using namespace mangrove_tds;

/// The <i>main function</i> for the <i>'Mangrove_tutorial019'</i> program.
/**
 * \file Mangrove_tutorial019.cpp
 * \author <A href="http://davidcanino.github.io">David Canino</A> (e-mail: <A href="mailto:canino.david@gmail.com">David Canino</A>)
 */

/// The <i>main function</i> for the <i>'Mangrove_tutorial019'</i> program.
/**
 * \return <ul><li>the built-in <i>EXIT_SUCCESS</i> constant value (provided by the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), if all is ok</li><li>the built-in <i>EXIT_FAILURE</i> constant value (provided by 
 * the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), otherwise</li></ul>
 * \see mangrove_tds::Mangrove_exportCopyrightDisclaimer(), mangrove_tds::Mangrove_pause()
 */
int main(void)
{
	vector< vector<uint> > a,a1;
	vector< set<uint> > as;
	ofstream out;
	ifstream in;

	/* This is the 'Mangrove_tutorial019' tutorial, where the nested arrays of several 'uint' C++ built-in values are validated. */
	Mangrove_exportCopyrightDisclaimer ("The 'Mangrove_tutorial019' Tutorial");
	cout.flush();
	
	/* TASK #1 - creating a new nested array, containing several arrays of 'uint' C++ built-in values. */
	cout<<"\tCreating the nested array 'a', containing several arrays of 'uint' C++ built-in values, ... ";
	a.push_back( vector<uint>() );
	a.back()={10,20,30,40};
	cout<<"ok"<<endl;
	Mangrove_debug(a);
	cout<<"\tThe total number of the 'uint' C++ built-in values in the nested array 'a' is "<<Mangrove_valuesNumber(a)<<"."<<endl;
	cout<<"\tExporting the 'compact' representation of the nested array 'a' on the 'nested_array_compact.txt' file ... ";
	out.open("nested_array_compact.txt");
	out<<a;
	out.close();
	cout<<"ok"<<endl;
	cout<<"\tReconstructing the content of the nested array 'a' by parsing its 'compact' representation from the 'nested_array_compact.txt' file ... ";
	in.open("nested_array_compact.txt");
	in>>a1;
	in.close();
	cout<<"ok"<<endl;
	Mangrove_debug(a1);
	cout<<"\tThe total number of the 'uint' C++ built-in values in the reconstructed nested array 'a' is "<<Mangrove_valuesNumber(a1)<<"."<<endl;
	if(Mangrove_theSame(a,a1)) cout<<"\tThe content of the reconstructed nested array coincides with the content of the original nested array 'a'."<<endl<<endl;
	else cout<<"\tThe content of the reconstructed nested array does not coincide with the content of the original nested array 'a'."<<endl<<endl;
	cout<<"\tRemoving the 'nested_array_compact.txt' file ... ";
	Mangrove_removeFile(string("nested_array_compact.txt"));
	cout<<"ok"<<endl<<endl;
	Mangrove_destroy(a1);
	Mangrove_pause();
	
	/* TASK #2 - converting the nested array 'a' to the corresponding nested array of several sets. */
	cout<<"\tConverting the nested array 'a' into the nested array 'as', containing several sets of 'uint' C++ built-in values, ... ";
	Mangrove_convert(a,as);
	cout<<"ok"<<endl<<endl;
	cout<<"\tIMPORTANT:\tthe 'uint' C++ built-in values in the sets of interest are sorted with respect to the '<' and the '==' comparison operators."<<endl<<endl;
	cout.flush();
	Mangrove_debug(as);
	cout<<"\tThe total number of the 'uint' C++ built-in values in the new nested array 'as' is "<<Mangrove_valuesNumber(as)<<"."<<endl<<endl;
	cout<<"\tConverting the nested array 'as' back to the corresponding nesting array, containing several arrays, ... ";
	Mangrove_convert(as,a1);
	cout<<"ok"<<endl;
	if(Mangrove_theSame(a,a1)) cout<<"\tThe content of the new nested array coincides with the content of the original nested array 'a'."<<endl<<endl;
	else cout<<"\tThe content of the new nested array does not coincide with the content of the original nested array 'a'."<<endl<<endl;
	cout.flush();
	
	/* TASK #3 - deallocating all nested arrays in this tutorial. */
	cout<<"\tDeallocating all nested arrays of this tutorial ... ";
	Mangrove_destroy(a);
	Mangrove_destroy(a1);
	Mangrove_destroy(as);
	cout<<"ok"<<endl<<endl;
	cout.flush();
	return EXIT_SUCCESS;
}
