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

/// The <i>main function</i> for the <i>Mangrove_tutorial023</i> program.
/**
 * \file Mangrove_tutorial23.cpp
 * \author <A href="http://davidcanino.github.io">David Canino</A> (e-mail: <A href="mailto:canino.david@gmail.com">David Canino</A>)
 */
 
/// This function compares two <i>'unsigned int (uint)'</i> C++ built-in values.
/**
 * This function compares two <i>'unsigned int (uint)'</i> C++ built-in values by exploiting their lexicographic order. Broadly speaking, this (custom) function is an helper (custom) function for the operator \f$<\f$, which compares two <i>'unsigned int (uint)'</i> 
 * C++ built-in values \f$a\f$ and \f$b\f$. Thus, this custom function computes \f$a<b\f$.<p>\attention In other words, this (custom) function checks whether the <i>'unsigned int (uint)'</i> C++ built-in value \f$a\f$ is <i>"strictly less than"</i> the <i>'unsigned 
 * int (uint)'</i> C++ built-in value \f$b\f$.
 * \param a the first <i>'unsigned int (uint)'</i> C++ built-in value \f$a\f$ to be compared
 * \param b the second <i>'unsigned int (uint)'</i> C++ built-in value \f$b\f$ to be compared
 * \return <ul><li>the boolean flag <i>"true"</i>, if the <i>'unsigned int (uint)'</i> C++ built-in value \f$a\f$ is <i>"strictly less than"</i> the <i>'unsigned int (uint)'</i> C++ built-in value \f$b\f$</li><li>the boolean flag <i>"false"</i>, otherwise</li></ul>
 * \see mangrove_tds::Mangrove_DataComparator, mangrove_tds::Mangrove_DataComparatorWithHashing, Mangrove_sameUintValues()
 */
inline bool Mangrove_compareUintValues(const uint& a,const uint& b) { return (a<b); }

/// This function compares two <i>'unsigned int (uint)'</i> C++ built-in values.
/**
 * This function compares two <i>'unsigned int (uint)'</i> C++ built-in values by exploiting their lexicographic order. Broadly speaking, this (custom) function is an helper (custom) function for the operator \f$==\f$, which compares two <i>'unsigned int (uint)'</i> 
 * C++ built-in values \f$a\f$ and \f$b\f$. Thus, this custom function computes \f$a==b\f$.<p>\attention In other words, this (custom) function checks whether the <i>'unsigned int (uint)'</i> C++ built-in value \f$a\f$ is <i>"the same as"</i> the <i>'unsigned int 
 * (uint)'</i> C++ built-in value \f$b\f$.
 * \param a the first <i>'unsigned int (uint)'</i> C++ built-in value \f$a\f$ to be compared
 * \param b the second <i>'unsigned int (uint)'</i> C++ built-in value \f$b\f$ to be compared
 * \return <ul><li>the boolean flag <i>"true"</i>, if the <i>'unsigned int (uint)'</i> C++ built-in value \f$a\f$ is <i>"the same as"</i> the <i>'unsigned int (uint)'</i> C++ built-in value \f$b\f$</li><li>the boolean flag <i>"false"</i>, otherwise</li></ul>
 * \see mangrove_tds::Mangrove_DataComparator, mangrove_tds::Mangrove_DataComparatorWithHashing, Mangrove_compareUintValues()
 */
inline bool Mangrove_sameUintValues(const uint& a,const uint& b) { return (a==b); }

/// The <i>main function</i> for the <i>Mangrove_tutorial23</i> program.
/**
 * \return <ul><li>the built-in <i>EXIT_SUCCESS</i> constant value (provided by the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), if all is ok</li><li>the built-in <i>EXIT_FAILURE</i> constant value (provided by 
 * the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), otherwise</li></ul>
 * \see mangrove_tds::Mangrove_exportCopyrightDisclaimer(), mangrove_tds::Mangrove_DataComparator, mangrove_tds::Mangrove_DataComparatorWithHashing, Mangrove_compareUintValues()
 */
int main(void)
{
	set<uint, Mangrove_DataComparatorWithHashing<uint> > s0,s1,s01;
	deque<uint> d;
	list<uint> l;
	vector<uint> v;
	
	/* Now, we validate several functions in the 'Mangrove_Miscellanea.h' file, focused for comparing sets and other containers of several template values (here, specialized for the 'uint' values) by using the custom functions for sorting their 'uint' values. */
	Mangrove_exportCopyrightDisclaimer("Mangrove_tutorial023");
	cout<<"\tCreating the new set 's0', formed by several 'uint' values (sorted with respect to the order relation of their hashing values, see the 'Mangrove_DataComparatorWithHashing' template class), ... ";
	s0.insert(3);
	s0.insert(0);
	s0.insert(46);
	s0.insert(55);
	s0.insert(11);
	s0.insert(5);
	s0.insert(0);
	cout<<"ok"<<endl<<endl;
	cout<<"\tNOTE: in this implementation, the hashing value of a given 'uint' value 'x' corresponds with 'x' itself."<<endl<<endl;
	cout<<"\tThe 'debug' representation for the content of the set 's0' is:"<<endl;
	Mangrove_debug(s0);
	cout<<endl;
	cout.flush();
	
	/* Now, we validate the 'Mangrove_contains()' template function by using a custom set and the 'Mangrove_compareUintValues()' custom function. */
	if(Mangrove_compareUintValues(0,5)==true) cout<<"\tThe 'uint' value 0 is 'strictly less than' the 'uint' value 5"<<endl;
	else cout<<"\tThe 'uint' value 0 is not 'strictly less than' the 'uint' value 5"<<endl;
	if(Mangrove_compareUintValues(2,1)==true) cout<<"\tThe 'uint' value 2 is 'strictly less than' the 'uint' value 1"<<endl<<endl;
	else cout<<"\tThe 'uint' value 2 is not 'strictly less than' the 'uint' value 1"<<endl<<endl;
	if(Mangrove_sameUintValues(5,5)==true) cout<<"\tThe 'uint' value 5 is 'the same as' the 'uint' value 5"<<endl;
	else cout<<"\tThe 'uint' value 5 is not 'the same as' the 'uint' value 5"<<endl;
	if(Mangrove_sameUintValues(3,7)==true) cout<<"\tThe 'uint' value 3 is 'the same as' the 'uint' value 7"<<endl<<endl;
	else cout<<"\tThe 'uint' value 3 is not 'the same as' the 'uint' value 7"<<endl<<endl;
	if(Mangrove_contains(s0,(uint)5,Mangrove_compareUintValues)==true) cout<<"\tThe set 's0' contains the 'uint' value 5 (see the 'Mangrove_contains()' template function and the 'Mangrove_compareUintValues()' custom function)"<<endl;
	else cout<<"\tThe set 's0' does not contain the 'uint' value 5 (see the 'Mangrove_contains()' template function and the 'Mangrove_compareUintValues()' custom function)"<<endl;
	if(Mangrove_contains(s0,(uint)12,Mangrove_compareUintValues)==true) cout<<"\tThe set 's0' contains the 'uint' value 12 (see the 'Mangrove_contains()' template function and the 'Mangrove_compareUintValues()' custom function)"<<endl;
	else cout<<"\tThe set 's0' does not contain the 'uint' value 12 (see the 'Mangrove_contains()' template function and the 'Mangrove_compareUintValues()' custom function)"<<endl;
	cout<<endl;
	cout.flush();
	Mangrove_pause();
	
	/* Now, we create another set 's1', containing several 'uint' values. */
	cout<<"\tCreating another new set 's1', formed by several 'uint' values (sorted with respect to the order relation of their hashing values, see the 'Mangrove_DataComparatorWithHashing' template class), ... ";
	s1.insert(54);
	s1.insert(3);
	s1.insert(55);
	s1.insert(0);
	s1.insert(44);
	s1.insert(2);
	cout<<"ok"<<endl;
	cout<<"\tThe 'debug' representation for the content of the set 's1' is:"<<endl;
	Mangrove_debug(s1);
	cout<<endl;
	cout.flush();
	cout<<"\tRetrieving the intersection between the sets 's0' and 's1' (see the 'Mangrove_intersection()' template function and the 'Mangrove_compareUintValues()' custom function) ... ";
	Mangrove_intersection(s0,s1,s01,Mangrove_compareUintValues);
	cout<<"ok"<<endl;
	cout<<"\tThe 'uint' values in the intersection of interest are: ";
	Mangrove_exportHybrid(s01);
	cout<<endl;
	if(Mangrove_sameValues(s0,s1,Mangrove_sameUintValues)==true) cout<<"\tThe sets 's0' and 's1' contain the same 'uint' values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameUintValues()' custom function)";
	else cout<<"\tThe sets 's0' and 's1' do not contain the same 'uint' values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameUintValues()' custom function)";
	cout<<endl;
	cout<<"\tSetting the content of the set 's1' as a copy of the set 's0' ... ";
	s1.clear();
	s01.clear();
	s1=set<uint, Mangrove_DataComparatorWithHashing<uint> >(s0.begin(),s0.end());
	cout<<"ok"<<endl;
	cout.flush();
	if(Mangrove_sameValues(s0,s1,Mangrove_sameUintValues)==true) cout<<"\tThe sets 's0' and 's1' contain the same 'uint' values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameUintValues()' custom function)";
	else cout<<"\tThe sets 's0' and 's1' do not contain the same 'uint' values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameUintValues()' custom function)";
	s1.clear();
	cout<<endl<<endl;
	Mangrove_pause();
	
	/* Now, we create a deque of several 'uint' values to be compared with the set 's0'. */
	cout<<"\tThe 'uint' values in the set 's0' are: ";
	Mangrove_exportHybrid(s0);
	cout<<endl<<"\tCreating a new deque 'd' of 'uint' values ... ";
	d.push_back(5);
	d.push_back(2);
	d.push_back(54);
	d.push_back(13);
	cout<<"ok"<<endl;
	cout<<"\tThe 'uint' values in the deque 'd' are: ";
	Mangrove_exportHybrid(d);
	cout<<"\tFiltering the 'uint' values in the deque 'd' with respect to the set 's0' (see the 'Mangrove_filterValues()' template function and the 'Mangrove_compareUintValues()' custom function) ... ";
	Mangrove_filterValues(d,s0,Mangrove_compareUintValues);
	cout<<"ok"<<endl;
	cout<<"\tThe 'uint' values in the filtered deque 'd' are: ";
	Mangrove_exportHybrid(d);
	if(Mangrove_sameValues(s0,d,Mangrove_sameUintValues)) cout<<"\tThe deque 'd' and the set 's0' contain the same 'uint' values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameUintValues()' custom function)"<<endl;
	else cout<<"\tThe deque 'd' and the set 's0' do not contain the same 'uint' values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameUintValues()' custom function)"<<endl;
	cout<<"\tSetting the content of the deque 'd' as a copy of the set 's0' ... ";
	d.clear();
	d=deque<uint>(s0.begin(),s0.end());
	cout<<"ok"<<endl;
	if(Mangrove_sameValues(s0,d,Mangrove_sameUintValues)) cout<<"\tThe deque 'd' and the set 's0' contain the same 'uint' values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameUintValues()' custom function)"<<endl;
	else cout<<"\tThe deque 'd' and the set 's0' do not contain the same 'uint' values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameUintValues()' custom function)"<<endl;
	cout<<endl;
	cout.flush();
	
	/* Now, we create a list of several 'uint' values to be compared with the set 's0'. */
	cout<<"\tCreating a new list 'l' of 'uint' values ... ";
	l.push_back(57);
	l.push_back(32);
	l.push_back(54);
	l.push_back(13);
	cout<<"ok"<<endl;
	cout<<"\tThe 'uint' values in the list 'l' are: ";
	Mangrove_exportHybrid(l);
	cout<<"\tFiltering the 'uint' values in the list 'l' with respect to the set 's0' (see the 'Mangrove_filterValues()' template function and the 'Mangrove_compareUintValues()' custom function) ... ";
	Mangrove_filterValues(l,s0,Mangrove_compareUintValues);
	cout<<"ok"<<endl;
	cout<<"\tThe 'uint' values in the filtered list 'l' are: ";
	Mangrove_exportHybrid(l);
	if(Mangrove_sameValues(s0,l,Mangrove_sameUintValues)) cout<<"\tThe list 'l' and the set 's0' contain the same 'uint' values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameUintValues()' custom function)"<<endl;
	else cout<<"\tThe list 'l' and the set 's0' do not contain the same 'uint' values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameUintValues()' custom function)"<<endl;
	cout<<"\tSetting the content of the list 'l' as a copy of the set 's0' ... ";
	l.clear();
	l=list<uint>(s0.begin(),s0.end());
	cout<<"ok"<<endl;
	if(Mangrove_sameValues(s0,l,Mangrove_sameUintValues)) cout<<"\tThe list 'l' and the set 's0' contain the same 'uint' values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameUintValues()' custom function)"<<endl;
	else cout<<"\tThe list 'l' and the set 's0' do not contain the same 'uint' values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameUintValues()' custom function)"<<endl;
	cout<<endl;
	cout.flush();
	
	/* Now, we create an array of several 'uint' values to be compared with the set 's0'. */
	cout<<"\tCreating a new array 'v' of 'uint' values ... ";
	v.clear();
	v=vector<uint>(s0.begin(),s0.end());
	cout<<"ok"<<endl;
	cout<<"\tThe 'uint' values in the array 'v' are: ";
	Mangrove_exportHybrid(v);
	cout<<"\tFiltering the 'uint' values in the array 'v' with respect to the set 's0' (see the 'Mangrove_filterValues()' template function and the 'Mangrove_compareUintValues()' custom function) ... ";
	Mangrove_filterValues(v,s0,Mangrove_compareUintValues);
	cout<<"ok"<<endl;
	cout<<"\tThe 'uint' values in the filtered array 'v' are: ";
	Mangrove_exportHybrid(v);
	if(Mangrove_sameValues(s0,l,Mangrove_sameUintValues)) cout<<"\tThe array 'v' and the set 's0' contain the same 'uint' values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameUintValues()' custom function)"<<endl;
	else cout<<"\tThe array 'v' and the set 's0' do not contain the same 'uint' values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameUintValues()' custom function)"<<endl;
	cout<<endl;
	cout.flush();
	
	/* We deallocate everything! */
	cout<<"\tDeallocating all auxiliary data structures of this tutorial ... ";
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
