/*************************************************************************************************************************************************************************
 * This source code provides the 'Tutorial Example-023' for the Mangrove Topological Data Structure Library (Mangrove TDS Library 3.0)
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
 * Mangrove_tutorial023.cpp - the 'Tutorial Example-023' for the 'Mangrove TDS Library 3.0'.
 *************************************************************************************************************************************************************************/

#include "Mangrove_Miscellanea.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
using namespace mangrove_tds;

/// The <i>main function</i> for the <i>'Mangrove_tutorial023'</i> program.
/**
 * \file Mangrove_tutorial023.cpp
 * \author <A href="http://davidcanino.github.io">David Canino</A> (e-mail: <A href="mailto:canino.david@gmail.com">David Canino</A>)
 */
 
/// This function compares two <i>'unsigned int (uint)'</i> C++ built-in values.
/**
 * This function compares two <i>'unsigned int (uint)'</i> C++ built-in values by exploiting their lexicographic order. Broadly speaking, this (custom) function is an helper (custom) function for the operator \f$<\f$, which compares two <i>'unsigned int (uint)'</i> 
 * C++ built-in values \f$a\f$ and \f$b\f$. In other words, this custom function computes \f$a<b\f$.<p>\attention In other words, this (custom) function checks whether the <i>'unsigned int (uint)'</i> C++ built-in value \f$a\f$ is <i>"strictly less than"</i> the 
 * <i>'unsigned int (uint)'</i> C++ built-in value \f$b\f$.
 * \param a the first <i>'unsigned int (uint)'</i> C++ built-in value \f$a\f$ to be compared
 * \param b the second <i>'unsigned int (uint)'</i> C++ built-in value \f$b\f$ to be compared
 * \return <ul><li>the boolean flag <i>"true"</i>, if the <i>'unsigned int (uint)'</i> C++ built-in value \f$a\f$ is <i>"strictly less than"</i> the <i>'unsigned int (uint)'</i> C++ built-in value \f$b\f$</li><li>the boolean flag <i>"false"</i>, otherwise</li></ul>
 * \see mangrove_tds::Mangrove_DataComparator, mangrove_tds::Mangrove_DataComparatorWithHashing, Mangrove_sameUintValues()
 */
inline bool Mangrove_compareUintValues(const uint& a,const uint& b) { return (a<b); }

/// This function compares two <i>'unsigned int (uint)'</i> C++ built-in values.
/**
 * This function compares two <i>'unsigned int (uint)'</i> C++ built-in values by exploiting their lexicographic order. Broadly speaking, this (custom) function is an helper (custom) function for the operator \f$==\f$, which compares two <i>'unsigned int (uint)'</i> 
 * C++ built-in values \f$a\f$ and \f$b\f$. In other words, this custom function computes \f$a==b\f$.<p>\attention In other words, this (custom) function checks whether the <i>'unsigned int (uint)'</i> C++ built-in value \f$a\f$ is <i>"the same as"</i> the 
 * <i>'unsigned int (uint)'</i> C++ built-in value \f$b\f$.
 * \param a the first <i>'unsigned int (uint)'</i> C++ built-in value \f$a\f$ to be compared
 * \param b the second <i>'unsigned int (uint)'</i> C++ built-in value \f$b\f$ to be compared
 * \return <ul><li>the boolean flag <i>"true"</i>, if the <i>'unsigned int (uint)'</i> C++ built-in value \f$a\f$ is <i>"the same as"</i> the <i>'unsigned int (uint)'</i> C++ built-in value \f$b\f$</li><li>the boolean flag <i>"false"</i>, otherwise</li></ul>
 * \see mangrove_tds::Mangrove_DataComparator, mangrove_tds::Mangrove_DataComparatorWithHashing, Mangrove_compareUintValues()
 */
inline bool Mangrove_sameUintValues(const uint& a,const uint& b) { return (a==b); }

/// The <i>main function</i> for the <i>'Mangrove_tutorial023'</i> program.
/**
 * \return <ul><li>the built-in <i>EXIT_SUCCESS</i> constant value (provided by the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), if all is ok</li><li>the built-in <i>EXIT_FAILURE</i> constant value (provided by 
 * the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), otherwise</li></ul>
 * \see mangrove_tds::Mangrove_exportCopyrightDisclaimer(), mangrove_tds::Mangrove_pause(), mangrove_tds::Mangrove_removeFile(), mangrove_tds::Mangrove_DataComparator, mangrove_tds::Mangrove_DataComparatorWithHashing, Mangrove_compareUintValues(), 
 * Mangrove_sameUintValues()
 */
int main(void)
{
	set<uint, Mangrove_DataComparatorWithHashing<uint> > s01;

	/* This is the 'Mangrove_tutorial023' tutorial, where the sets of several 'uint' C++ built-in values are validated. Here, the 'uint' C++ built-in values are sorted with respect to their hashing values (see the 'Mangrove_DataComparatorWithHashing' template 
	 * class). */
	Mangrove_exportCopyrightDisclaimer ("The 'Mangrove_tutorial023' Tutorial");
	cout.flush();
	
	/* TASK #1 - creating a new set of several 'uint' C++ built-in values. */
	cout<<"\tCreating the new set 's0' of several 'uint' C++ built-in values ... ";
	set<uint, Mangrove_DataComparatorWithHashing<uint> > s0={3,0,46,55,11,5,0};
	cout<<"ok"<<endl;
	Mangrove_debug(s0);
	cout<<"\tIMPORTANT:\tthe 'uint' C++ built-in values in the sets of interest are sorted with respect to the order relation of their hashing values (see the 'Mangrove_DataComparatorWithHashing' template class)."<<endl<<"\t\t\tHere, the hashing value of an ";
	cout<<"'uint' C++ built-in value coincides with its hashing value (by construction)."<<endl<<endl;
	cout.flush();
	
	/* TASK #2 - validating the 'Mangrove_contains()' template function by using the 'Mangrove_compareUintValues()' and the 'Mangrove_sameUintValues()' custom function. */
	if(Mangrove_compareUintValues(0,5)==true) cout<<"\tThe 'uint' C++ built-in value 0 is 'strictly less than' the 'uint' C++ built-in value 5 (with respect to the 'Mangrove_compareUintValues()' custom function)."<<endl;
	else cout<<"\tThe 'uint' C++ built-in value 0 is not 'strictly less than' the 'uint' C++ built-in value 5 (with respect to the 'Mangrove_compareUintValues()' custom function)."<<endl;
	if(Mangrove_compareUintValues(2,1)==true) cout<<"\tThe 'uint' C++ built-in value 2 is 'strictly less than' the 'uint' C++ built-in value 1 (with respect to the 'Mangrove_compareUintValues()' custom function)."<<endl;
	else cout<<"\tThe 'uint' C++ built-in value 2 is not 'strictly less than' the 'uint' C++ built-in value 1 (with respect to the 'Mangrove_compareUintValues()' custom function)."<<endl;
	if(Mangrove_sameUintValues(5,5)==true) cout<<"\tThe 'uint' C++ built-in value 5 is 'the same as' the 'uint' C++ built-in value 5 (with respect to the 'Mangrove_sameUintValues()' custom function)."<<endl;
	else cout<<"\tThe 'uint' C++ built-in value 5 is not 'the same as' the 'uint' C++ built-in value 5 (with respect to the 'Mangrove_sameUintValues()' custom function)."<<endl;
	if(Mangrove_sameUintValues(3,7)==true) cout<<"\tThe 'uint' C++ built-in value 3 is 'the same as' the 'uint' C++ built-in value 7 (with respect to the 'Mangrove_sameUintValues()' custom function)."<<endl;
	else cout<<"\tThe 'uint' C++ built-in value 3 is not 'the same as' the 'uint' C++ built-in value 7 (with respect to the 'Mangrove_sameUintValues()' custom function)."<<endl;
	if(Mangrove_contains(s0,(uint)5,Mangrove_compareUintValues)==true) cout<<"\tThe set 's0' contains the 'uint' C++ built-in value 5 (see the 'Mangrove_contains()' template function and the 'Mangrove_compareUintValues()' custom function)."<<endl;
	else cout<<"\tThe set 's0' does not contain the 'uint' C++ built-in value 5 (see the 'Mangrove_contains()' template function and the 'Mangrove_compareUintValues()' custom function)."<<endl;
	if(Mangrove_contains(s0,(uint)12,Mangrove_compareUintValues)==true) cout<<"\tThe set 's0' contains the 'uint' C++ built-in value 12 (see the 'Mangrove_contains()' template function and the 'Mangrove_compareUintValues()' custom function)."<<endl;
	else cout<<"\tThe set 's0' does not contain the 'uint' C++ built-in value 12 (see the 'Mangrove_contains()' template function and the 'Mangrove_compareUintValues()' custom function)."<<endl;
	cout<<endl;
	cout.flush();
	Mangrove_pause();
	
	/* TASK #3 - creating another set 's1', containing several 'uint' C++ built-in values to be manipulated and compared with the set 's0'. */
	cout<<"\tCreating another new set 's1' of several 'uint' C++ built-in values ... ";
	set<uint, Mangrove_DataComparatorWithHashing<uint> > s1={54,3,55,0,44,2};
	cout<<"ok"<<endl;
	Mangrove_debug(s1);
	cout<<"\tRetrieving the intersection between the sets 's0' and 's1' (see the 'Mangrove_intersection()' template function and the 'Mangrove_compareUintValues()' custom function) ... ";
	Mangrove_intersection(s0,s1,s01,Mangrove_compareUintValues);
	cout<<"ok"<<endl;
	cout<<"\tThe common 'uint' C++ built-in values in the intersection of interest are the following: ";
	Mangrove_exportHybrid(s01);
	if(Mangrove_sameValues(s0,s1,Mangrove_sameUintValues)==true) 
		cout<<"\tThe sets 's0' and 's1' contain the same 'uint' C++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameUintValues()' custom function)."<<endl<<endl;
	else cout<<"\tThe sets 's0' and 's1' do not contain the same 'uint' C++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameUintValues()' custom function)."<<endl<<endl;
	cout<<"\tSetting the content of the set 's1' as a copy of the set 's0' ... ";
	s1.clear();
	s01.clear();
	s1=set<uint, Mangrove_DataComparatorWithHashing<uint> >(s0.begin(),s0.end());
	cout<<"ok"<<endl;
	cout.flush();
	Mangrove_debug(s1);
	if(Mangrove_sameValues(s0,s1,Mangrove_sameUintValues)==true) 
		cout<<"\tThe sets 's0' and 's1' contain the same 'uint' C++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameUintValues()' custom function)."<<endl<<endl;
	else cout<<"\tThe sets 's0' and 's1' do not contain the same 'uint' C++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameUintValues()' custom function)."<<endl<<endl;
	s1.clear();
	Mangrove_pause();
	
	/* TASK #4 - creating a deque of several 'uint' C++ built-in values to be manipulated and compared with the set 's0'. */
	cout<<"\tCreating a new deque 'd' of several 'uint' C++ built-in values ... ";
	deque<uint> d={5,2,54,13};
	cout<<"ok"<<endl;
	cout<<"\tThe 'uint' C++ built-in values in the deque 'd' are: ";
	Mangrove_exportHybrid(d);
	cout<<"\tFiltering the 'uint' C++ built-in values in the deque 'd' with respect to the set 's0' (see the 'Mangrove_filterValues()' template function and the 'Mangrove_compareUintValues()' custom function) ... ";
	Mangrove_filterValues(d,s0,Mangrove_compareUintValues);
	cout<<"ok"<<endl;
	cout<<"\tThe 'uint' C++ built-in values in the filtered deque 'd' are: ";
	Mangrove_exportHybrid(d);
	if(Mangrove_sameValues(s0,d,Mangrove_sameUintValues)) 
		cout<<"\tThe deque 'd' and the set 's0' contain the same 'uint' C++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameUintValues()' custom function)."<<endl;
	else cout<<"\tThe deque 'd' and the set 's0' do not contain the same 'uint' c++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameUintValues()' custom function)."<<endl;
	cout<<"\tSetting the content of the deque 'd' as a copy of the set 's0' ... ";
	d.clear();
	d=deque<uint>(s0.begin(),s0.end());
	cout<<"ok"<<endl;
	if(Mangrove_sameValues(s0,d,Mangrove_sameUintValues)) 
		cout<<"\tThe deque 'd' and the set 's0' contain the same 'uint' C++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameUintValues()' custom function)."<<endl<<endl;
	else cout<<"\tThe deque 'd' and the set 's0' do not contain the same 'uint' c++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameUintValues()' custom function)."<<endl<<endl;
	
	/* TASK #5 - creating a list of several 'uint' C++ built-in values to be manipulated and compared with the set 's0'. */
	cout<<"\tCreating a new list 'l' of several 'uint' C++ built-in values ... ";
	list<uint> l={57,32,54,13};
	cout<<"ok"<<endl;
	cout<<"\tThe 'uint' C++ built-in values in the list 'l' are: ";
	Mangrove_exportHybrid(l);
	cout<<"\tFiltering the 'uint' C++ built-in values in the list 'l' with respect to the set 's0' (see the 'Mangrove_filterValues()' template function and the 'Mangrove_compareUintValues()' custom function) ... ";
	Mangrove_filterValues(l,s0,Mangrove_compareUintValues);
	cout<<"ok"<<endl;
	cout<<"\tThe 'uint' C++ built-in values in the filtered list 'l' are: ";
	Mangrove_exportHybrid(l);
	if(Mangrove_sameValues(s0,l,Mangrove_sameUintValues)) 
		cout<<"\tThe list 'l' and the set 's0' contain the same 'uint' C++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameUintValues()' custom function)."<<endl;
	else cout<<"\tThe list 'l' and the set 's0' do not contain the same 'uint' c++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameUintValues()' custom function)."<<endl;
	cout<<"\tSetting the content of the list 'l' as a copy of the set 's0' ... ";
	l.clear();
	l=list<uint>(s0.begin(),s0.end());
	cout<<"ok"<<endl;
	if(Mangrove_sameValues(s0,l,Mangrove_sameUintValues)) 
		cout<<"\tThe list 'l' and the set 's0' contain the same 'uint' C++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameUintValues()' custom function)."<<endl<<endl;
	else cout<<"\tThe list 'l' and the set 's0' do not contain the same 'uint' c++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameUintValues()' custom function)."<<endl<<endl;
	cout.flush();
	
	/* TASK #6 - creating an array of several 'uint' C++ built-in values to be manipulated and compared with the set 's0'. */
	cout<<"\tCreating a new array 'v' of several 'uint' C++ built-in values ... ";
	vector<uint> v=vector<uint>(s0.crbegin(),s0.crend());
	cout<<"ok"<<endl;
	cout<<"\tThe 'uint' C++ built-in values in the array 'v' are: ";
	Mangrove_exportHybrid(v);
	cout<<"\tFiltering the 'uint' C++ built-in values in the array 'v' with respect to the set 's0' (see the 'Mangrove_filterValues()' template function and the 'Mangrove_compareUintValues()' custom function) ... ";
	Mangrove_filterValues(v,s0,Mangrove_compareUintValues);
	cout<<"ok"<<endl;
	cout<<"\tThe 'uint' C++ built-in values in the filtered array 'v' are: ";
	Mangrove_exportHybrid(v);
	if(Mangrove_sameValues(s0,v,Mangrove_sameUintValues)) 
		cout<<"\tThe array 'v' and the set 's0' contain the same 'uint' C++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameUintValues()' custom function)."<<endl;
	else cout<<"\tThe array 'v' and the set 's0' do not contain the same 'uint' c++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameUintValues()' custom function)."<<endl;
	cout<<"\tSorting the 'uint' C++ built-in values (with respect to the 'Mangrove_compareUintValues()' custom function) ... ";
	sort(v.begin(),v.end(),Mangrove_compareUintValues);
	cout<<"ok"<<endl;
	if(Mangrove_sameValues(s0,v,Mangrove_sameUintValues)) 
		cout<<"\tThe array 'v' and the set 's0' contain the same 'uint' C++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameUintValues()' custom function)."<<endl;
	else cout<<"\tThe array 'v' and the set 's0' do not contain the same 'uint' c++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameUintValues()' custom function)."<<endl;
	cout<<endl;
	Mangrove_pause();
	
	/* TASK #7 - deallocating all auxiliary data structures in this tutorial. */
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
