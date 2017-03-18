/*************************************************************************************************************************************************************************
 * This source code provides the 'Tutorial Example-014' for the Mangrove Topological Data Structure Library (Mangrove TDS Library 3.0)
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
 * Mangrove_tutorial014.cpp - the 'Tutorial Example-014' for the 'Mangrove TDS Library 3.0'.
 *************************************************************************************************************************************************************************/

#include "Mangrove_Miscellanea.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
using namespace mangrove_tds;

/// The <i>main function</i> for the <i>'Mangrove_tutorial014'</i> program.
/**
 * \file Mangrove_tutorial014.cpp
 * \author <A href="http://davidcanino.github.io">David Canino</A> (e-mail: <A href="mailto:canino.david@gmail.com">David Canino</A>)
 */

/// The <i>main function</i> for the <i>'Mangrove_tutorial014'</i> program.
/**
 * \return <ul><li>the built-in <i>EXIT_SUCCESS</i> constant value (provided by the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), if all is ok</li><li>the built-in <i>EXIT_FAILURE</i> constant value (provided by 
 * the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), otherwise</li></ul>
 * \see mangrove_tds::Mangrove_exportCopyrightDisclaimer(), mangrove_tds::Mangrove_pause()
 */
int main(void)
{
	pair< bool, deque<uint> > pd0;
	pair< bool, list<uint> > pl0;
	pair< bool, vector<uint> > pa0;
	ofstream out;
	ifstream in;

	/* This is the 'Mangrove_tutorial014' tutorial, where the pairs, involving a boolean flag and arrays/deques/lists of several template values (here, specialized for the 'uint' C++ built-in values), are validated. */
	Mangrove_exportCopyrightDisclaimer ("The 'Mangrove_tutorial014' Tutorial");
	cout.flush();
	
	/* TASK #1 - validating the pairs, involving a boolean flag and a deque of 'uint' C++ built-in values. */
	cout<<"\tConstructing a new pair 'p=(b,d)', involving a boolean flag 'b' and a deque 'd' of several 'uint' C++ built-in values ... ";
	pd0.first=true;
	pd0.second=deque<uint>();
	for(uint k=0;k<5;k++) pd0.second.push_back(k);
	cout<<"ok"<<endl;
	Mangrove_debug(pd0);
	cout<<"\tExporting the 'compact' representation of the pair 'p' on the 'pair_deque.txt' file ... ";
	out.open(string("pair_deque.txt"));
	out<<pd0;
	out.close();
	cout<<"ok"<<endl;
	cout<<"\tClearing the state of the pair 'p' ... ";
	pd0.first=false;
	pd0.second.clear();
	cout<<"ok"<<endl;
	Mangrove_debug(pd0);
	cout<<"\tReconstructing the pair 'p' from its 'compact' representation in the 'pair_deque.txt' file ... ";
	in.open(string("pair_deque.txt"));
	in>>pd0;
	in.close();
	cout<<"ok"<<endl;
	Mangrove_debug(pd0);
	cout<<"\tRemoving the 'pair_deque.txt' file ... ";
	Mangrove_removeFile(string("pair_deque.txt"));
	cout<<"ok"<<endl<<endl;
	pd0.first=false;
	pd0.second.clear();
	Mangrove_pause();
	
	/* TASK #2 - validating the pairs, involving a boolean flag and a list of 'uint' C++ built-in values. */
	cout<<"\tConstructing a new pair 'p=(b,l)', involving a boolean flag 'b' and a list 'l' of several 'uint' C++ built-in values ... ";
	pl0.first=false;
	pl0.second=list<uint>();
	for(uint k=0;k<5;k++) pl0.second.push_back(3*k);
	cout<<"ok"<<endl;
	Mangrove_debug(pl0);
	cout<<"\tExporting the 'compact' representation of the pair 'p' on the 'pair_list.txt' file ... ";
	out.open(string("pair_list.txt"));
	out<<pl0;
	out.close();
	cout<<"ok"<<endl;
	cout<<"\tClearing the state of the pair 'p' ... ";
	pl0.first=true;
	pl0.second.clear();
	cout<<"ok"<<endl;
	Mangrove_debug(pl0);
	cout<<"\tReconstructing the pair 'p' from its 'compact' representation in the 'pair_list.txt' file ... ";
	in.open(string("pair_list.txt"));
	in>>pl0;
	in.close();
	cout<<"ok"<<endl;
	Mangrove_debug(pl0);
	cout<<"\tRemoving the 'pair_list.txt' file ... ";
	Mangrove_removeFile(string("pair_list.txt"));
	cout<<"ok"<<endl<<endl;
	pl0.first=false;
	pl0.second.clear();
	Mangrove_pause();

	/* TASK #3 - validating the pairs, involving a boolean flag and an array of 'uint' C++ built-in values. */
	cout<<"\tConstructing a new pair 'p=(b,a)', involving a boolean flag 'b' and an array 'a' of several 'uint' C++ built-in values ... ";
	pa0.first=false;
	pa0.second=vector<uint>();
	pa0.second.push_back(8);
	cout<<"ok"<<endl;
	Mangrove_debug(pa0);
	cout<<"\tExporting the 'compact' representation of the pair 'p' on the 'pair_array.txt' file ... ";
	out.open(string("pair_array.txt"));
	out<<pa0;
	out.close();
	cout<<"ok"<<endl;
	cout<<"\tClearing the state of the pair 'p' ... ";
	pa0.first=true;
	pa0.second.clear();
	cout<<"ok"<<endl;
	Mangrove_debug(pa0);
	cout<<"\tReconstructing the pair 'p' from its 'compact' representation in the 'pair_array.txt' file ... ";
	in.open(string("pair_array.txt"));
	in>>pa0;
	in.close();
	cout<<"ok"<<endl;
	Mangrove_debug(pa0);
	cout<<"\tRemoving the 'pair_array.txt' file ... ";
	Mangrove_removeFile(string("pair_array.txt"));
	cout<<"ok"<<endl<<endl;
	pa0.first=false;
	pa0.second.clear();

	/* TASK #4 - deallocating all pairs of in this tutorial. */
	cout<<"\tDeallocating the content of all pairs in this tutorial ... ";
	pd0.second.clear();
	pl0.second.clear();
	pa0.second.clear();
	cout<<"ok"<<endl<<endl;
	cout.flush();
	return EXIT_SUCCESS;
}
