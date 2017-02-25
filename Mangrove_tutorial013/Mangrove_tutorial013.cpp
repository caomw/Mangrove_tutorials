/*************************************************************************************************************************************************************************
 * This source code provides the 'Tutorial Example-013' for the Mangrove Topological Data Structure Library (Mangrove TDS Library 3.0)
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
 * Mangrove_tutorial013.cpp - the 'Tutorial Example-013' for the 'Mangrove TDS Library 3.0'.
 *************************************************************************************************************************************************************************/
 
#include "Mangrove_Miscellanea.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;
using namespace mangrove_tds;

/// The <i>main function</i> for the <i>Mangrove_tutorial013</i> program.
/**
 * \file Mangrove_tutorial013.cpp
 * \author <A href="http://davidcanino.github.io">David Canino</A> (e-mail: <A href="mailto:canino.david@gmail.com">David Canino</A>)
 */
 
/// The <i>main function</i> for the <i>Mangrove_tutorial013</i> program.
/**
 * \return <ul><li>the built-in <i>EXIT_SUCCESS</i> constant value (provided by the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), if all is ok</li><li>the built-in <i>EXIT_FAILURE</i> constant value (provided by 
 * the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), otherwise</li></ul>
 * \see mangrove_tds::Mangrove_exportCopyrightDisclaimer()
 */
int main(void)
{
	deque<bool> d0,d1,origd;
	vector<bool> v0,v1,origv;
	list<bool> l0,l1,origl;
	
	/* Now, we validate several functions in the 'Mangrove_Miscellanea.h' file, starting from the 'Mangrove_exportCopyrightDisclaimer()' function. First, we validate several functions for the deques of the 'bool' values. */
	Mangrove_exportCopyrightDisclaimer("Mangrove_tutorial013");
	cout<<"\tCreating the new deque 'd0', formed by several 'bool' values, ... ";
	cout.flush();
	d0.push_back(true);
	d0.push_back(true);
	d0.push_back(true);
	d0.push_back(false);
	d0.push_back(false);
	d0.push_back(true);
	d0.push_back(false);
	cout<<"ok"<<endl;
	origd=deque<bool>(d0);
	cout<<"\tThe deque 'd0' contains "<<d0.size()<<" 'bool' values"<<endl;
	cout<<"\tThe content of the deque 'd0' is: ";
	Mangrove_exportHybrid(d0);
	cout.flush();
	cout<<endl<<"\tToggling (negating) the 'bool' values in the deque 'd0' on itself ... ";
	Mangrove_toggle(d0);
	cout<<"ok"<<endl;
	cout<<"\tThe new deque 'd0' contains "<<d0.size()<<" 'bool' values"<<endl;
	cout<<"\tThe content of the new deque 'd0' is: ";
	Mangrove_exportHybrid(d0);
	cout.flush();
	cout<<endl<<"\tToggling (negating) and saving the 'bool' values in the deque 'd0' on the new deque 'd1' ... ";
	cout.flush();
	Mangrove_toggle(d0,d1);
	cout<<"ok"<<endl;
	cout<<"\tThe existing deque 'd0' contains "<<d0.size()<<" 'bool' values"<<endl;
	cout<<"\tThe content of the existing deque 'd0' is: ";
	Mangrove_exportHybrid(d0);
	cout.flush();
	cout<<"\tThe new deque 'd1' contains "<<d1.size()<<" 'bool' values"<<endl;
	cout<<"\tThe content of the new deque 'd1' is: ";
	Mangrove_exportHybrid(d1);
	cout.flush();
	if(Mangrove_theSame(d1,origd)==true) cout<<endl<<"\tThe new deque 'd1' coincides with the original version of the deque 'd0'"<<endl<<endl;
	else cout<<endl<<"\tThe new deque 'd1' does not coincide with the original version of the deque 'd0'"<<endl<<endl;
	cout.flush();
	Mangrove_pause();
	
	/* Then, we validate several functions for the arrays of the 'bool' values. */
	cout<<"\tCreating the new array 'v0', formed by several 'bool' values, ... ";
	cout.flush();
	v0.push_back(true);
	v0.push_back(true);
	v0.push_back(true);
	v0.push_back(false);
	cout<<"ok"<<endl;
	origv=vector<bool>(v0);
	cout<<"\tThe array 'v0' contains "<<v0.size()<<" 'bool' values"<<endl;
	cout<<"\tThe content of the array 'v0' is: ";
	Mangrove_exportHybrid(v0);
	cout.flush();
	cout<<endl<<"\tToggling (negating) the 'bool' values in the array 'v0' on itself ... ";
	Mangrove_toggle(v0);
	cout<<"ok"<<endl;
	cout<<"\tThe new array 'v0' contains "<<v0.size()<<" 'bool' values"<<endl;
	cout<<"\tThe content of the new array 'v0' is: ";
	Mangrove_exportHybrid(v0);
	cout.flush();
	cout<<endl<<"\tToggling (negating) and saving the 'bool' values in the array 'v0' on the new array 'v1' ... ";
	cout.flush();
	Mangrove_toggle(v0,v1);
	cout<<"ok"<<endl;
	cout<<"\tThe existing array 'v0' contains "<<v0.size()<<" 'bool' values"<<endl;
	cout<<"\tThe content of the existing array 'v0' is: ";
	Mangrove_exportHybrid(v0);
	cout.flush();
	cout<<"\tThe new array 'v1' contains "<<v1.size()<<" 'bool' values"<<endl;
	cout<<"\tThe content of the new array 'v1' is: ";
	Mangrove_exportHybrid(v1);
	cout.flush();
	if(Mangrove_theSame(v1,origv)==true) cout<<endl<<"\tThe new array 'v1' coincides with the original version of the array 'v0'"<<endl<<endl;
	else cout<<endl<<"\tThe new array 'v1' does not coincide with the original version of the array 'v0'"<<endl<<endl;
	cout.flush();
	Mangrove_pause();

	/* Finally, we validate several functions for the lists of the 'bool' values. */
	cout<<"\tCreating the new list 'l0', formed by several 'bool' values, ... ";
	cout.flush();
	l0.push_back(true);
	l0.push_back(false);
	l0.push_back(true);
	l0.push_back(false);
	cout<<"ok"<<endl;
	origl=list<bool>(l0);
	cout<<"\tThe list 'l0' contains "<<l0.size()<<" 'bool' values"<<endl;
	cout<<"\tThe content of the list 'l0' is: ";
	Mangrove_exportHybrid(l0);
	cout.flush();
	cout<<endl<<"\tToggling (negating) the 'bool' values in the list 'l0' on itself ... ";
	Mangrove_toggle(l0);
	cout<<"ok"<<endl;
	cout<<"\tThe new list 'l0' contains "<<l0.size()<<" 'bool' values"<<endl;
	cout<<"\tThe content of the new list 'l0' is: ";
	Mangrove_exportHybrid(l0);
	cout.flush();
	cout<<endl<<"\tToggling (negating) and saving the 'bool' values in the list 'l0' on the new list 'l1' ... ";
	cout.flush();
	Mangrove_toggle(l0,l1);
	cout<<"ok"<<endl;
	cout<<"\tThe existing list 'l0' contains "<<l0.size()<<" 'bool' values"<<endl;
	cout<<"\tThe content of the existing list 'l0' is: ";
	Mangrove_exportHybrid(l0);
	cout.flush();
	cout<<"\tThe new list 'l1' contains "<<l1.size()<<" 'bool' values"<<endl;
	cout<<"\tThe content of the new list 'l1' is: ";
	Mangrove_exportHybrid(l1);
	cout.flush();
	if(Mangrove_theSame(l1,origl)==true) cout<<endl<<"\tThe new list 'l1' coincides with the original version of the list 'l0'"<<endl<<endl;
	else cout<<endl<<"\tThe new list 'l1' does not coincide with the original version of the list 'l0'"<<endl<<endl;
	cout.flush();
	Mangrove_pause();

	/* If we arrive here, then all is ok. */
	cout<<"\tDeallocating all auxiliary data structures in this tutorial ... ";
	d0.clear();
	d1.clear();
	origd.clear();
	v0.clear();
	v1.clear();
	origv.clear();
	l0.clear();
	l1.clear();
	origl.clear();
	cout<<"ok"<<endl<<endl;
	cout.flush();
	return EXIT_SUCCESS;
}
