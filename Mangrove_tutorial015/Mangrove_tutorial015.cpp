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

/// The <i>main function</i> for the <i>Mangrove_tutorial015</i> program.
/**
 * \file Mangrove_tutorial015.cpp
 * \author <A href="http://davidcanino.github.io">David Canino</A> (e-mail: <A href="mailto:canino.david@gmail.com">David Canino</A>)
 */

/// The <i>main function</i> for the <i>Mangrove_tutorial015</i> program.
/**
 * \return <ul><li>the built-in <i>EXIT_SUCCESS</i> constant value (provided by the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), if all is ok</li><li>the built-in <i>EXIT_FAILURE</i> constant value (provided by 
 * the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), otherwise</li></ul>
 * \see mangrove_tds::Mangrove_exportCopyrightDisclaimer()
 */
int main(void)
{
	set<uint> s0,s1,s01;
	uint p;
	ofstream out;
	ifstream in;
	list<uint> l;
	deque<uint> d;
	vector<uint> a;
	
	/* Now, we validate several functions in the 'Mangrove_Miscellanea.h' file, focused for manipulating the set of several template values (here, specialized for the 'uint' values). */
	Mangrove_exportCopyrightDisclaimer("Mangrove_tutorial015");
	cout<<"\tCreating the new set 's0', formed by several 'uint' values, ... ";
	s0.insert(3);
	s0.insert(0);
	s0.insert(54);
	s0.insert(11);
	s0.insert(5);
	s0.insert(0);
	cout<<"ok"<<endl;
	cout<<"\tThe 'debug' representation for the content of the set 's0' is:"<<endl;
	Mangrove_debug(s0);
	cout<<endl;
	cout.flush();
	
	/* Validating the 'Mangrove_exportHybrid()' and the 'Mangrove_reconstructFromHybrid()' template functions for the sets of several template values. */
	cout<<"\tThe 'hybrid' representation for the content of the set 's0' is: ";
	Mangrove_exportHybrid(s0);
	cout<<endl<<"\tExporting the 'hybrid' representation for the content of the set 's0' on the 'hybrid_set.txt' file ... ";
	out.open("hybrid_set.txt");
	Mangrove_exportHybrid(s0,out);
	out.close();
	cout<<"ok"<<endl;
	for(uint k=0;k<5;k++) s1.insert(k);
	cout<<"\tReconstructing the content of the set 's0' from the 'hybrid_set.txt' file ... ";
	in.open("hybrid_set.txt");
	Mangrove_reconstructFromHybrid(s1,in);
	in.close();
	cout<<"ok"<<endl;
	cout<<"\tThe 'hybrid' representation for the resulting set is: ";
	Mangrove_exportHybrid(s1);
	
	/* Validating the 'Mangrove_sameValues()' template function for the sets of several template values. */
	if(Mangrove_sameValues(s0,s1)) cout<<"\tThe reconstructed set is 'the same as' the initial set 's0'"<<endl<<endl;
	else cout<<"\tThe reconstructed set is not 'the same as' the initial set 's0'"<<endl<<endl;
	cout<<"\tRemoving the 'hybrid_set.txt' file ... ";
	Mangrove_removeFile("hybrid_set.txt");
	cout<<"ok"<<endl<<endl;
	cout.flush();
	s1.clear();
	
	/* Validating the '<<' and the '>>' template operators for the sets of several template values. */
	cout<<"\tThe 'compact' representation for the content of the set 's0' is: "<<s0;
	cout.flush();
	cout<<endl<<"\tExporting the 'compact' representation for the content of the set 's0' on the 'compact_set.txt' file ... ";
	out.open("compact_set.txt");
	out<<s0;
	out.close();
	cout<<"ok"<<endl;
	cout<<"\tReconstructing the content of the set 's0' from the 'compact_set.txt' file ... ";
	in.open("compact_set.txt");
	in>>s1;
	in.close();
	cout<<"ok"<<endl;
	cout<<"\tThe 'compact' representation for the resulting set is: "<<s1;
	
	/* Validating the 'Mangrove_sameValues()' template function for the sets of several template values. */
	if(Mangrove_sameValues(s0,s1)) cout<<"\tThe reconstructed set is 'the same as' the initial set 's0'"<<endl<<endl;
	else cout<<"\tThe reconstructed set is not 'the same as' the initial set 's0'"<<endl<<endl;
	cout<<"\tRemoving the 'compact_set.txt' file ... ";
	Mangrove_removeFile("compact_set.txt");
	cout<<"ok"<<endl<<endl;
	cout.flush();
	s1.clear();
	
	/* Validating the 'Mangrove_contains()' and the 'Mangrove_select()' template functions for the sets of several template values. */
	if(Mangrove_contains(s0,(uint)54)==true) cout<<"\tThe set 's0' contains the 'uint' value '54'"<<endl;
	else cout<<"\tThe set 's0' does not contain the 'uint' value '54'"<<endl;
	if(Mangrove_contains(s0,(uint)99)==true) cout<<"\tThe set 's0' contains the 'uint' value '99'"<<endl;
	else cout<<"\tThe set 's0' does not contain the 'uint' value '99'"<<endl;
	cout<<"\tThe set 's0' contains the 'uint' value '";
	Mangrove_select(s0,2,p);
	cout<<p<<"' in position 2"<<endl<<endl;
	cout.flush();
	Mangrove_pause();
	
	/* Validating the 'Mangrove_findProjection()' and the 'Mangrove_filterValues()' template function for the sets of several template values. Here, the results are saved on the lists. */
	cout<<"\tThe 'hybrid' representation for the content of the set 's0' is: ";
	Mangrove_exportHybrid(s0);
	cout<<"\tRetrieving the canonical projection of the set 's0' with respect to the position 0 (and saved on the list 'l')  ... ";
	Mangrove_findProjection(0,s0,l);
	cout<<"ok"<<endl;
	cout<<"\tThe resulting canonical projection of interest is saved in the list 'l': ";
	Mangrove_exportHybrid(l);
	cout.flush();
	cout<<endl<<"\tUpdating the content of the list 'l' ... ";
	l.clear();
	l.push_back(11);
	l.push_back(3);
	l.push_back(45);
	l.push_back(52);
	cout<<"ok"<<endl;
	cout<<"\tThe new 'uint' values in the list 'l': ";
	Mangrove_exportHybrid(l);
	cout<<"\tFiltering the 'uint' values in the new list 'l' with respect to the set 's0' ... ";
	Mangrove_filterValues(l,s0);
	cout<<"ok"<<endl;
	cout<<"\tThe filtered 'uint' values in the new list 'l': ";
	if(l.size()==0) cout<<"no 'uint' value"<<endl;
	else Mangrove_exportHybrid(l);
	cout<<endl;
	if(Mangrove_sameValues(s0,l)==false) cout<<"\tThe set 's0' and the list 'l' do not contain the same 'uint' values (position by position)"<<endl;
	else cout<<"\tThe set 's0' and the list 'l' contain the same 'uint' values (position by position)"<<endl;
	cout<<"\tSetting the list 'l' as a copy of the set 's0' ... ";
	l.clear();
	l=list<uint>(s0.begin(),s0.end());
	cout<<"ok"<<endl;
	if(Mangrove_sameValues(s0,l)==false) cout<<"\tThe set 's0' and the new list 'l' do not contain the same 'uint' values (position by position)"<<endl<<endl;
	else cout<<"\tThe set 's0' and the new list 'l' contain the same 'uint' values (position by position)"<<endl<<endl;
	l.clear();
	Mangrove_pause();
	
	/* Validating the 'Mangrove_findProjection()' and the 'Mangrove_filterValues()' template function for the sets of several template values. Here, the results are saved on the deques. */
	cout<<"\tThe 'hybrid' representation for the content of the set 's0' is: ";
	Mangrove_exportHybrid(s0);
	cout<<"\tRetrieving the canonical projection of the set 's0' with respect to the position 2 (and saved on the deque 'd')  ... ";
	Mangrove_findProjection(2,s0,d);
	cout<<"ok"<<endl;
	cout<<"\tThe resulting canonical projection of interest is saved in the deque 'd': ";
	Mangrove_exportHybrid(d);
	cout.flush();
	cout<<endl<<"\tUpdating the content of the deque 'd' ... ";
	d.clear();
	d.push_back(10);
	d.push_back(2);
	d.push_back(45);
	d.push_back(22);
	cout<<"ok"<<endl;
	cout<<"\tThe new 'uint' values in the deque 'd': ";
	Mangrove_exportHybrid(d);
	cout<<"\tFiltering the 'uint' values in the new deque 'd' with respect to the set 's0' ... ";
	Mangrove_filterValues(d,s0);
	cout<<"ok"<<endl;
	cout<<"\tThe filtered 'uint' values in the new deque 'd': ";
	if(d.size()==0) cout<<"no 'uint' value"<<endl;
	else Mangrove_exportHybrid(d);
	cout<<endl;
	if(Mangrove_sameValues(s0,d)==false) cout<<"\tThe set 's0' and the deque 'd' do not contain the same 'uint' values (position by position)"<<endl;
	else cout<<"\tThe set 's0' and the deque 'd' contain the same 'uint' values (position by position)"<<endl;
	cout<<"\tSetting the deque 'd' as a copy of the set 's0' ... ";
	d.clear();
	d=deque<uint>(s0.begin(),s0.end());
	cout<<"ok"<<endl;
	if(Mangrove_sameValues(s0,d)==false) cout<<"\tThe set 's0' and the new deque 'd' do not contain the same 'uint' values (position by position)"<<endl<<endl;
	else cout<<"\tThe set 's0' and the new deque 'd' contain the same 'uint' values (position by position)"<<endl<<endl;
	d.clear();
	Mangrove_pause();
	
	/* Validating the 'Mangrove_findProjection()' and the 'Mangrove_filterValues()' template function for the sets of several template values. Here, the results are saved on the arrays. */
	cout<<"\tThe 'hybrid' representation for the content of the set 's0' is: ";
	Mangrove_exportHybrid(s0);
	cout<<"\tRetrieving the canonical projection of the set 's0' with respect to the position 4 (and saved on the array 'a')  ... ";
	Mangrove_findProjection(4,s0,a);
	cout<<"ok"<<endl;
	cout<<"\tThe resulting canonical projection of interest is saved in the array 'a': ";
	Mangrove_exportHybrid(a);
	cout.flush();
	cout<<endl<<"\tUpdating the content of the array 'a' ... ";
	a.push_back(60);
	a.push_back(11);
	a.push_back(66);
	cout<<"ok"<<endl;
	cout<<"\tThe new 'uint' values in the array 'a': ";
	Mangrove_exportHybrid(a);
	cout<<"\tFiltering the 'uint' values in the new array 'a' with respect to the set 's0' ... ";
	Mangrove_filterValues(a,s0);
	cout<<"ok"<<endl;
	cout<<"\tThe filtered 'uint' values in the new array 'a': ";
	if(a.size()==0) cout<<"no 'uint' value"<<endl;
	else Mangrove_exportHybrid(a);
	cout<<endl;
	if(Mangrove_sameValues(s0,a)==false) cout<<"\tThe set 's0' and the array 'a' do not contain the same 'uint' values (position by position)"<<endl;
	else cout<<"\tThe set 's0' and the array 'a' contain the same 'uint' values (position by position)"<<endl;
	cout<<"\tSetting the array 'a' as a copy of the set 's0' ... ";
	a.clear();
	a=vector<uint>(s0.begin(),s0.end());
	cout<<"ok"<<endl;
	if(Mangrove_sameValues(s0,a)==false) cout<<"\tThe set 's0' and the new array 'a' do not contain the same 'uint' values (position by position)"<<endl<<endl;
	else cout<<"\tThe set 's0' and the new array 'a' contain the same 'uint' values (position by position)"<<endl<<endl;
	a.clear();
	Mangrove_pause();

	/* Validating the 'Mangrove_intersection()' template function for the sets of several template values. */
	cout<<"\tThe 'hybrid' representation for the content of the set 's0' is: ";
	Mangrove_exportHybrid(s0);
	cout<<endl<<"\tCreating a new set 's1', formed by several 'uint' values, ... ";
	s1.insert(44);
	s1.insert(0);
	s1.insert(4);
	s1.insert(11);
	s1.insert(4);
	s1.insert(54);
	cout<<"ok"<<endl;
	cout<<"\tThe 'hybrid' representation for the content of the set 's1' is: ";
	Mangrove_exportHybrid(s1);
	cout<<"\tRetrieving the intersection between the sets 's0' and 's1' ... ";
	Mangrove_intersection(s0,s1,s01);
	cout<<"ok"<<endl;
	cout<<"\tThe 'hybrid' representation for the intersection of interest is: ";
	Mangrove_exportHybrid(s01);
	cout<<endl<<"\tDeallocating all auxiliary data structures of this tutorial ... ";
	s0.clear();
	s1.clear();
	s01.clear();
	l.clear();
	d.clear();
	a.clear();
	cout<<"ok"<<endl<<endl;
	cout.flush();
	return EXIT_SUCCESS;
}
