/*************************************************************************************************************************************************************************
 * This source code provides the 'Tutorial Example-018' for the Mangrove Topological Data Structure Library (Mangrove TDS Library 3.0)
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
 * Mangrove_tutorial018.cpp - the 'Tutorial Example-018' for the 'Mangrove TDS Library 3.0'.
 *************************************************************************************************************************************************************************/
 
#include "Mangrove_Miscellanea.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
using namespace mangrove_tds;

/// The <i>main function</i> for the <i>Mangrove_tutorial018</i> program.
/**
 * \file Mangrove_tutorial018.cpp
 * \author <A href="http://davidcanino.github.io">David Canino</A> (e-mail: <A href="mailto:canino.david@gmail.com">David Canino</A>)
 */

/// The <i>main function</i> for the <i>Mangrove_tutorial018</i> program.
/**
 * \return <ul><li>the built-in <i>EXIT_SUCCESS</i> constant value (provided by the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), if all is ok</li><li>the built-in <i>EXIT_FAILURE</i> constant value (provided by 
 * the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), otherwise</li></ul>
 * \see mangrove_tds::Mangrove_exportCopyrightDisclaimer()
 */
int main(void)
{
	list< list<uint> > l,l1;
	list< set<uint> > ls;
	ofstream out;
	ifstream in;
	
	/* Now, we validate several functions in the 'Mangrove_Miscellanea.h' file, focused for manipulating the nested lists, containing several lists of 'uint' values. */
	Mangrove_exportCopyrightDisclaimer("Mangrove_tutorial018");
	cout<<"\tCreating the nested list 'l', containing several lists of 'uint' values, ... ";
	l.push_back( list<uint>() );
	l.push_back( list<uint>() );
	l.back().push_back(4);
	l.back().push_back(2);
	l.back().push_back(5);
	cout<<"ok"<<endl<<endl;
	cout<<"\tThe total number of the 'uint' values in the nested list 'l': "<<Mangrove_valuesNumber(l)<<endl;
	cout.flush();
	Mangrove_debug(l);
	cout<<"\tExporting the 'compact' representation of the nested list 'l' on the 'nested_list_compact.txt' file ... ";
	out.open("nested_list_compact.txt");
	out<<l;
	out.close();
	cout<<"ok"<<endl;
	cout<<"\tReconstructing the content of the nested list 'l' by parsing its 'compact' representation from the 'nested_list_compact.txt' file ... ";
	in.open("nested_list_compact.txt");
	in>>l1;
	in.close();
	cout<<"ok"<<endl<<endl;
	cout<<"\tThe total number of the 'uint' values in the reconstructed nested list 'l': "<<Mangrove_valuesNumber(l1)<<endl;
	Mangrove_debug(l1);
	if(Mangrove_theSame(l,l1)) cout<<"\tThe content of the reconstructed nested list coincides with the content of the original nested list 'l'"<<endl<<endl;
	else cout<<"\tThe content of the reconstructed nested list does not coincide with the content of the original nested list 'l'"<<endl<<endl;
	cout<<"\tRemoving the 'nested_list_compact.txt' file ... ";
	Mangrove_removeFile(string("nested_list_compact.txt"));
	cout<<"ok"<<endl<<endl;
	Mangrove_destroy(l1);
	Mangrove_pause();
	
	/* Now, we validate the functions for manipulating the nested lists, containing several sets of 'uint' values. */
	cout<<"\tConverting the nested list 'l' into the nested list 'ls', containing several sets of 'uint' values, ... ";
	Mangrove_convert(l,ls);
	cout<<"ok"<<endl<<endl;
	cout<<"\tThe total number of the 'uint' values in the new nested list 'ls': "<<Mangrove_valuesNumber(ls)<<endl;
	cout.flush();
	Mangrove_debug(ls);
	cout<<"\tConverting the nested list 'ls' into the corresponding nesting list, containing several lists, ... ";
	Mangrove_convert(ls,l1);
	cout<<"ok"<<endl<<endl;
	cout<<"\tThe total number of the 'uint' values in the new nested list: "<<Mangrove_valuesNumber(l1)<<endl;
	Mangrove_debug(l1);
	cout<<"\tDeallocating all nested lists of this tutorial ... ";
	Mangrove_destroy(l);
	Mangrove_destroy(l1);
	Mangrove_destroy(ls);
	cout<<"ok"<<endl<<endl;
	cout.flush();
	return EXIT_SUCCESS;
}
