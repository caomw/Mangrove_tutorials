/*************************************************************************************************************************************************************************
 * This source code provides the 'Tutorial Example-015' for the Mangrove Topological Data Structure Library (Mangrove TDS Library 3.0)
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
 * Mangrove_tutorial015.cpp - the 'Tutorial Example-015' for the 'Mangrove TDS Library 3.0'.
 *************************************************************************************************************************************************************************/

#include "Mangrove_Miscellanea.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
using namespace mangrove_tds;

/// The <i>main function</i> for the <i>'Mangrove_tutorial015'</i> program.
/**
 * \file Mangrove_tutorial015.cpp
 * \author <A href="http://davidcanino.github.io">David Canino</A> (e-mail: <A href="mailto:canino.david@gmail.com">David Canino</A>)
 */

/// The <i>main function</i> for the <i>'Mangrove_tutorial015'</i> program.
/**
 * \return <ul><li>the built-in <i>EXIT_SUCCESS</i> constant value (provided by the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), if all is ok</li><li>the built-in <i>EXIT_FAILURE</i> constant value (provided by 
 * the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), otherwise</li></ul>
 * \see mangrove_tds::Mangrove_exportCopyrightDisclaimer(), mangrove_tds::Mangrove_pause(), mangrove_tds::Mangrove_removeFile(), mangrove_tds::Mangrove_DataComparator, mangrove_tds::Mangrove_DataComparatorWithHashing
 */
int main(void)
{
	ofstream out;
	ifstream in;
	int p;

	/* This is the 'Mangrove_tutorial015' tutorial, where the sets, containing several 'int' C++ built-in values, are validated. */
	Mangrove_exportCopyrightDisclaimer ("The 'Mangrove_tutorial015' Tutorial");
	cout.flush();
	cout<<"\tIMPORTANT:\tthe 'int' C++ built-in values in the sets of interest are sorted with respect to the '<' and the '==' comparison operators."<<endl<<endl;

	/* TASK #1 - creating a new set 's0' of several 'int' C++ built-in values, and validating functions for exporting its 'debug', 'hybrid', and compact representations. */
	cout<<"\tCreating the new set 's0' of several 'int' C++ built-in values ... ";
	set<int> s0={ 3,0,54,11, 0, -5, -2 },s1,s01;
	cout<<"ok"<<endl;
	
	Mangrove_debug(s0);
	cout<<"\tThe 'hybrid' representation for the content of the set 's0' is: ";
	Mangrove_exportHybrid(s0);
	cout<<endl<<"\tExporting the 'hybrid' representation for the content of the set 's0' on the 'hybrid_set.txt' file ... ";
	out.open("hybrid_set.txt");
	Mangrove_exportHybrid(s0,out);
	out.close();
	cout<<"ok"<<endl;
	for(int k=0;k<s0.size();k++) s1.insert(k);
	cout<<"\tReconstructing the content of the set 's0' from the 'hybrid_set.txt' file ... ";
	in.open("hybrid_set.txt");
	Mangrove_reconstructFromHybrid(s1,in);
	in.close();
	cout<<"ok"<<endl;
	Mangrove_debug(s1);
	if(Mangrove_sameValues(s0,s1)) cout<<"\tThe 'int' C++ built-in values in the reconstructed set coincide position by position with the 'int' C++ built-in values in the set 's0'."<<endl<<endl;
	else cout<<"\tThe 'int' C++ built-in values in the reconstructed set do not coincide position by position with the 'int' C++ built-in values in the set 's0'."<<endl<<endl;
	cout<<"\tRemoving the 'hybrid_set.txt' file ... ";
	Mangrove_removeFile("hybrid_set.txt");
	cout<<"ok"<<endl<<endl;
	cout.flush();
	s1.clear();
	cout<<"\tExporting the 'compact' representation for the content of the set 's0' on the 'compact_set.txt' file ... ";
	out.open("compact_set.txt");
	out<<s0;
	out.close();
	cout<<"ok"<<endl;
	cout<<"\tReconstructing the content of the set 's0' from the 'compact_set.txt' file ... ";
	in.open("compact_set.txt");
	in>>s1;
	in.close();
	cout<<"ok"<<endl;
	Mangrove_debug(s1);
	if(Mangrove_sameValues(s0,s1)) cout<<"\tThe 'int' C++ built-in values in the reconstructed set coincide position by position with the 'int' C++ built-in values in the set 's0'."<<endl<<endl;
	else cout<<"\tThe 'int' C++ built-in values in the reconstructed set do not coincide position by position with the 'int' C++ built-in values in the set 's0'."<<endl<<endl;
	cout<<"\tRemoving the 'compact_set.txt' file ... ";
	Mangrove_removeFile("compact_set.txt");
	cout<<"ok"<<endl<<endl;
	cout.flush();
	s1.clear();
	Mangrove_pause();
	
	/* TASK #2 - validating the 'Mangrove_contains()' and the 'Mangrove_select()' template functions, as well as the 'Mangrove_intersection()' template function. */
	if(Mangrove_contains(s0,54)==true) cout<<"\tThe set 's0' contains the 'int' C++ built-in value '54'."<<endl;
	else cout<<"\tThe set 's0' does not contain the 'int' C++ built-in value '54'."<<endl;
	if(Mangrove_contains(s0,99)==true) cout<<"\tThe set 's0' contains the 'int' C++ built-in value '99'."<<endl;
	else cout<<"\tThe set 's0' does not contain the 'int' C++ built-in value '99'."<<endl;
	cout<<"\tThe set 's0' contains the 'int' C++ built-in value ";
	Mangrove_select(s0,4,p);
	cout<<p<<" in position 4."<<endl<<endl;
	cout.flush();
	cout<<"\tCreating the new set 's1' of several 'int' C++ built-in values ... ";
	s1={ 5,0,54,11, 22, -1, -3 };
	cout<<"ok"<<endl;
	Mangrove_debug(s1);
	cout<<"\tRetrieving the 'int' C++ built-in values in the common intersection between the existing set 's0' and the new set 's1' ... ";
	Mangrove_intersection(s0,s1,s01);
	cout<<"ok"<<endl;
	Mangrove_debug(s01);
	Mangrove_pause();
	
	/* TASK #3 - validating the 'Mangrove_findProjection()' and the 'Mangrove_filterValues()' template functions. Here, the results are saved on a generic deque of several 'int' C++ built-in values. */
	deque<int> d;
	cout<<"\tThe set 's0' contains the following 'int' C++ built-in values: ";
	Mangrove_exportHybrid(s0);
	cout<<endl<<"\tRetrieving the canonical projection of the set 's0' with respect to the position 2 (saved in the deque 'd')... ";
	Mangrove_findProjection(2,s0,d);
	cout<<"ok"<<endl;
	cout<<"\tThe resulting canonical projection of interest (saved in the deque 'd') is: ";
	Mangrove_exportHybrid(d);
	cout.flush();
	cout<<endl<<"\tUpdating the 'int' C++ built-in values in the deque 'd' ... ";
	d.clear();
	d={ 5,0,54,11, 22, -1, -3 };
	cout<<"ok"<<endl;
	cout<<"\tThe new deque 'd' contains the following 'int' C++ built-in values: ";
	Mangrove_exportHybrid(d);
	cout.flush();
	cout<<"\tFiltering the deque 'd' with respect to the set 's0' ... ";
	Mangrove_filterValues(d,s0);
	cout<<"ok"<<endl;
	cout<<"\tThe filtered deque 'd' contains the following 'int' C++ built-in values: ";
	Mangrove_exportHybrid(d);
	cout.flush();
	if(Mangrove_sameValues(s0,d)) cout<<"\tThe 'int' C++ built-in values in the set 's0' coincide position by position with the 'int' C++ built-in values in the deque 'd'."<<endl;
	else cout<<"\tThe 'int' C++ built-in values in the set 's0' do not coincide position by position with the 'int' C++ built-in values in the deque 'd'."<<endl;
	cout<<endl<<"\tSetting the deque 'd' as the copy of the set 's0' ... ";
	d.clear();
	d=deque<int>(s0.begin(),s0.end());
	cout<<"ok"<<endl;
	if(Mangrove_sameValues(s0,d)) cout<<"\tThe 'int' C++ built-in values in the set 's0' coincide position by position with the 'int' C++ built-in values in the deque 'd'."<<endl<<endl;
	else cout<<"\tThe 'int' C++ built-in values in the set 's0' do not coincide position by position with the 'int' C++ built-in values in the deque 'd'."<<endl<<endl;
	cout.flush();
	Mangrove_pause();
	
	/* TASK #4 - validating the 'Mangrove_findProjection()' and the 'Mangrove_filterValues()' template functions. Here, the results are saved on a generic list of several 'int' C++ built-in values. */
	list<int> l;
	cout<<"\tThe set 's0' contains the following 'int' C++ built-in values: ";
	Mangrove_exportHybrid(s0);
	cout<<endl<<"\tRetrieving the canonical projection of the set 's0' with respect to the position 1 (saved in the list 'l')... ";
	Mangrove_findProjection(1,s0,l);
	cout<<"ok"<<endl;
	cout<<"\tThe resulting canonical projection of interest (saved in the list 'l') is: ";
	Mangrove_exportHybrid(l);
	cout.flush();
	cout<<endl<<"\tUpdating the 'int' C++ built-in values in the list 'l' ... ";
	l.clear();
	l={ -5,0,44,11, 22, 1, -43 };
	cout<<"ok"<<endl;
	cout<<"\tThe new list 'l' contains the following 'int' C++ built-in values: ";
	Mangrove_exportHybrid(l);
	cout.flush();
	cout<<"\tFiltering the list 'l' with respect to the set 's0' ... ";
	Mangrove_filterValues(l,s0);
	cout<<"ok"<<endl;
	cout<<"\tThe filtered list 'l' contains the following 'int' C++ built-in values: ";
	Mangrove_exportHybrid(l);
	cout.flush();
	if(Mangrove_sameValues(s0,l)) cout<<"\tThe 'int' C++ built-in values in the set 's0' coincide position by position with the 'int' C++ built-in values in the list 'l'."<<endl;
	else cout<<"\tThe 'int' C++ built-in values in the set 's0' do not coincide position by position with the 'int' C++ built-in values in the list 'l'."<<endl;
	cout<<endl<<"\tSetting the list 'l' as the copy of the set 's0' ... ";
	l.clear();
	l=list<int>(s0.begin(),s0.end());
	cout<<"ok"<<endl;
	if(Mangrove_sameValues(s0,l)) cout<<"\tThe 'int' C++ built-in values in the set 's0' coincide position by position with the 'int' C++ built-in values in the list 'l'."<<endl<<endl;
	else cout<<"\tThe 'int' C++ built-in values in the set 's0' do not coincide position by position with the 'int' C++ built-in values in the list 'l'."<<endl<<endl;
	cout.flush();
	Mangrove_pause();
	
	/* TASK #5 - validating the 'Mangrove_findProjection()' and the 'Mangrove_filterValues()' template functions. Here, the results are saved on a generic array of several 'int' C++ built-in values. */
	vector<int> v;
	cout<<"\tThe set 's0' contains the following 'int' C++ built-in values: ";
	Mangrove_exportHybrid(s0);
	cout<<endl<<"\tRetrieving the canonical projection of the set 's0' with respect to the position 0 (saved in the array 'v')... ";
	Mangrove_findProjection(0,s0,v);
	cout<<"ok"<<endl;
	cout<<"\tThe resulting canonical projection of interest (saved in the array 'v') is: ";
	Mangrove_exportHybrid(v);
	cout.flush();
	cout<<endl<<"\tUpdating the 'int' C++ built-in values in the array 'v' ... ";
	v.clear();
	v={ 6,7,8,-23,-6 };
	cout<<"ok"<<endl;
	cout<<"\tThe new array 'v' contains the following 'int' C++ built-in values: ";
	Mangrove_exportHybrid(v);
	cout.flush();
	cout<<"\tFiltering the array 'v' with respect to the set 's0' ... ";
	Mangrove_filterValues(v,s0);
	cout<<"ok"<<endl;
	cout<<"\tThe filtered array 'v' contains the following 'int' C++ built-in values: ";
	if(v.empty()==true) cout<<"none."<<endl; 
	else Mangrove_exportHybrid(v);
	cout.flush();
	if(Mangrove_sameValues(s0,v)) cout<<"\tThe 'int' C++ built-in values in the set 's0' coincide position by position with the 'int' C++ built-in values in the array 'v'."<<endl;
	else cout<<"\tThe 'int' C++ built-in values in the set 's0' do not coincide position by position with the 'int' C++ built-in values in the array 'v'."<<endl;
	cout<<endl<<"\tSetting the array 'v' as the copy of the set 's0' ... ";
	v.clear();
	v=vector<int>(s0.begin(),s0.end());
	cout<<"ok"<<endl;
	if(Mangrove_sameValues(s0,v)) cout<<"\tThe 'int' C++ built-in values in the set 's0' coincide position by position with the 'int' C++ built-in values in the array 'v'."<<endl<<endl;
	else cout<<"\tThe 'int' C++ built-in values in the set 's0' do not coincide position by position with the 'int' C++ built-in values in the array 'v'."<<endl<<endl;
	cout.flush();
	Mangrove_pause();
	
	/* TASK #6 - deallocating all auxiliary data structures in this tutorial. */
	cout<<"\tDeallocating all auxiliary data structures in this tutorial ... ";
	s0.clear();
	s1.clear();
	s01.clear();
	d.clear();
	l.clear();
	v.clear();
	cout<<"ok"<<endl<<endl;
	cout.flush();
	return EXIT_SUCCESS;
}
