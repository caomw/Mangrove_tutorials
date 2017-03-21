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
 
/// This function compares two <i>'integer (int)'</i> C++ built-in values.
/**
 * This function compares two <i>'integer (int)'</i> C++ built-in values by exploiting their lexicographic order. Broadly speaking, this (custom) function is an helper (custom) function for the operator \f$<\f$, which compares two <i>'integer (int)'</i> C++ built-in 
 * values \f$a\f$ and \f$b\f$. In other words, this custom function computes \f$a<b\f$.<p>\attention In other words, this (custom) function checks whether the <i>'integer (int)'</i> C++ built-in value \f$a\f$ is <i>"strictly less than"</i> the <i>'integer (int)'</i> 
 * C++ built-in value \f$b\f$.
 * \param a the first <i>'integer (int)'</i> C++ built-in value \f$a\f$ to be compared
 * \param b the second <i>'integer (int)'</i> C++ built-in value \f$b\f$ to be compared
 * \return <ul><li>the boolean flag <i>"true"</i>, if the <i>'integer (int)'</i> C++ built-in value \f$a\f$ is <i>"strictly less than"</i> the <i>'integer (int)'</i> C++ built-in value \f$b\f$</li><li>the boolean flag <i>"false"</i>, otherwise</li></ul>
 * \see mangrove_tds::Mangrove_DataComparator, mangrove_tds::Mangrove_DataComparatorWithHashing, Mangrove_sameIntValues(), Mangrove_compareIntValuesHashing(), Mangrove_sameIntValuesHashing()
 */
inline bool Mangrove_compareIntValues(const int& a,const int& b) { return (a<b); }

/// This function compares two <i>'integer (int)'</i> C++ built-in values.
/**
 * This function compares two <i>'integer (int)'</i> C++ built-in values by exploiting their lexicographic order. Broadly speaking, this (custom) function is an helper (custom) function for the operator \f$==\f$, which compares two <i>'integer (int)'</i> 
 * C++ built-in values \f$a\f$ and \f$b\f$. In other words, this custom function computes \f$a==b\f$.<p>\attention In other words, this (custom) function checks whether the <i>'integer (int)'</i> C++ built-in value \f$a\f$ is <i>"the same as"</i> the 
 * <i>'integer (int)'</i> C++ built-in value \f$b\f$.
 * \param a the first <i>'integer (int)'</i> C++ built-in value \f$a\f$ to be compared
 * \param b the second <i>'integer (int)'</i> C++ built-in value \f$b\f$ to be compared
 * \return <ul><li>the boolean flag <i>"true"</i>, if the <i>'integer (int)'</i> C++ built-in value \f$a\f$ is <i>"the same as"</i> the <i>'integer (int)'</i> C++ built-in value \f$b\f$</li><li>the boolean flag <i>"false"</i>, otherwise</li></ul>
 * \see mangrove_tds::Mangrove_DataComparator, mangrove_tds::Mangrove_DataComparatorWithHashing, Mangrove_compareIntValues(), Mangrove_compareIntValuesHashing(), Mangrove_sameIntValuesHashing()
 */
inline bool Mangrove_sameIntValues(const int& a,const int& b) { return (a==b); }

/// This function compares two <i>'integer (int)'</i> C++ built-in values.
/**
 * This function compares two <i>'integer (int)'</i> C++ built-in values by exploiting the order relation of their hashing values. Broadly speaking, this (custom) function is an helper (custom) function for the operator \f$<\f$, which compares the hashing values
 * \f$h_a\f$ and \f$h_b\f$ of two <i>'integer (int)'</i> C++ built-in values \f$a\f$ and \f$b\f$, respectively. In other words, this custom function computes \f$h_a<h_b\f$.<p>\attention In other words, this (custom) function checks whether the <i>'integer (int)'</i> 
 * C++ built-in value \f$a\f$ is <i>"strictly less than"</i> the <i>'integer (int)'</i> C++ built-in value \f$b\f$, thus if \f$h_a<h_b\f$.
 * \param a the first <i>'integer (int)'</i> C++ built-in value \f$a\f$ to be compared
 * \param b the second <i>'integer (int)'</i> C++ built-in value \f$b\f$ to be compared
 * \return <ul><li>the boolean flag <i>"true"</i>, if the <i>'integer (int)'</i> C++ built-in value \f$a\f$ is <i>"strictly less than"</i> the <i>'integer (int)'</i> C++ built-in value \f$b\f$</li><li>the boolean flag <i>"false"</i>, otherwise</li></ul>
 * \see mangrove_tds::Mangrove_DataComparator, mangrove_tds::Mangrove_DataComparatorWithHashing, Mangrove_compareIntValues(), Mangrove_sameIntValues(), Mangrove_sameIntValuesHashing()
 */
inline bool Mangrove_compareIntValuesHashing(const int& a,const int& b) { return (hash_value(a)<hash_value(b)); }

/// This function compares two <i>'integer (int)'</i> C++ built-in values.
/**
 * This function compares two <i>'integer (int)'</i> C++ built-in values by exploiting the order relation of their hashing values. Broadly speaking, this (custom) function is an helper (custom) function for the operator \f$==\f$, which compares the hashing values
 * \f$h_a\f$ and \f$h_b\f$ of two <i>'integer (int)'</i> C++ built-in values \f$a\f$ and \f$b\f$, respectively. In other words, this custom function computes \f$h_a==h_b\f$.<p>\attention In other words, this (custom) function checks whether the <i>'integer (int)'</i> 
 * C++ built-in value \f$a\f$ is <i>"the same as"</i> the <i>'integer (int)'</i> C++ built-in value \f$b\f$, thus if \f$h_a=h_b\f$.
 * \param a the first <i>'integer (int)'</i> C++ built-in value \f$a\f$ to be compared
 * \param b the second <i>'integer (int)'</i> C++ built-in value \f$b\f$ to be compared
 * \return <ul><li>the boolean flag <i>"true"</i>, if the <i>'integer (int)'</i> C++ built-in value \f$a\f$ is <i>"the same as"</i> the <i>'integer (int)'</i> C++ built-in value \f$b\f$</li><li>the boolean flag <i>"false"</i>, otherwise</li></ul>
 * \see mangrove_tds::Mangrove_DataComparator, mangrove_tds::Mangrove_DataComparatorWithHashing, Mangrove_compareIntValues(), Mangrove_sameIntValues(), Mangrove_compareIntValuesHashing()
 */
inline bool Mangrove_sameIntValuesHashing(const int& a,const int& b) { return (hash_value(a)==hash_value(b)); }

/// The <i>main function</i> for the <i>'Mangrove_tutorial023'</i> program.
/**
 * \return <ul><li>the built-in <i>EXIT_SUCCESS</i> constant value (provided by the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), if all is ok</li><li>the built-in <i>EXIT_FAILURE</i> constant value (provided by 
 * the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), otherwise</li></ul>
 * \see mangrove_tds::Mangrove_exportCopyrightDisclaimer(), mangrove_tds::Mangrove_pause(), mangrove_tds::Mangrove_removeFile(), mangrove_tds::Mangrove_DataComparator, mangrove_tds::Mangrove_DataComparatorWithHashing, Mangrove_compareIntValues(), 
 * Mangrove_sameIntValues()
 */
int main(void)
{
	set<int, Mangrove_DataComparatorWithHashing<int> > s01;

	/* This is the 'Mangrove_tutorial023' tutorial, where the sets of several 'integer (int)' C++ built-in values are validated. Here, the 'integer (int)' C++ built-in values are sorted with respect to their hashing values (see the 
	 * 'Mangrove_DataComparatorWithHashing' template class). */
	Mangrove_exportCopyrightDisclaimer ("The 'Mangrove_tutorial023' Tutorial");
	cout<<"\tIMPORTANT:\tthe 'integer (int)' C++ built-in values in the sets of interest are sorted with respect to the order relation of their hashing values (see the 'Mangrove_DataComparatorWithHashing' template class)."<<endl<<endl;
	cout.flush();
	
	/* TASK #1 - creating a new set of several 'integer (int)' C++ built-in values. */
	cout<<"\tCreating the new set 's0' of several 'integer (int)' C++ built-in values ... ";
	set<int, Mangrove_DataComparatorWithHashing<int> > s0={3,0,46,55,11,-5,0,-4};
	cout<<"ok"<<endl;
	Mangrove_debug(s0);
	
	/* TASK #2 - validating the 'Mangrove_contains()' template function by using the 'Mangrove_compareIntValues()' and the 'Mangrove_sameIntValues()' custom functions. */
	if(Mangrove_compareIntValues(0,5)==true) cout<<"\tThe 'integer (int)' C++ built-in value 0 is 'strictly less than' the 'integer (int)' C++ built-in value 5 (with respect to the 'Mangrove_compareIntValues()' custom function)."<<endl;
	else cout<<"\tThe 'integer (int)' C++ built-in value 0 is not 'strictly less than' the 'integer (int)' C++ built-in value 5 (with respect to the 'Mangrove_compareIntValues()' custom function)."<<endl;
	if(Mangrove_compareIntValues(2,-1)==true) cout<<"\tThe 'integer (int)' C++ built-in value 2 is 'strictly less than' the 'integer (int)' C++ built-in value -1 (with respect to the 'Mangrove_compareIntValues()' custom function)."<<endl;
	else cout<<"\tThe 'integer (int)' C++ built-in value 2 is not 'strictly less than' the 'integer (int)' C++ built-in value -1 (with respect to the 'Mangrove_compareIntValues()' custom function)."<<endl;
	if(Mangrove_sameIntValues(5,5)==true) cout<<"\tThe 'integer (int)' C++ built-in value 5 is 'the same as' the 'integer (int)' C++ built-in value 5 (with respect to the 'Mangrove_sameIntValues()' custom function)."<<endl;
	else cout<<"\tThe 'integer (int)' C++ built-in value 5 is not 'the same as' the 'integer (int)' C++ built-in value 5 (with respect to the 'Mangrove_sameIntValues()' custom function)."<<endl;
	if(Mangrove_sameIntValues(3,7)==true) cout<<"\tThe 'integer (int)' C++ built-in value 3 is 'the same as' the 'integer (int)' C++ built-in value 7 (with respect to the 'Mangrove_sameIntValues()' custom function)."<<endl;
	else cout<<"\tThe 'integer (int)' C++ built-in value 3 is not 'the same as' the 'integer (int)' C++ built-in value 7 (with respect to the 'Mangrove_sameIntValues()' custom function)."<<endl;
	if(Mangrove_contains(s0,-5,Mangrove_compareIntValues)==true) cout<<"\tThe set 's0' contains the 'integer (int)' C++ built-in value -5 (see the 'Mangrove_contains()' template function and the 'Mangrove_compareIntValues()' custom function)."<<endl;
	else cout<<"\tThe set 's0' does not contain the 'integer (int)' C++ built-in value -5 (see the 'Mangrove_contains()' template function and the 'Mangrove_compareIntValues()' custom function)."<<endl;
	if(Mangrove_contains(s0,12,Mangrove_compareIntValues)==true) cout<<"\tThe set 's0' contains the 'integer (int)' C++ built-in value 12 (see the 'Mangrove_contains()' template function and the 'Mangrove_compareIntValues()' custom function)."<<endl;
	else cout<<"\tThe set 's0' does not contain the 'integer (int)' C++ built-in value 12 (see the 'Mangrove_contains()' template function and the 'Mangrove_compareIntValues()' custom function)."<<endl;
	cout<<endl;
	cout<<"\tIMPORTANT:\tthe wrong results of the operations (just performed) depends on the different sorting policies among the hashing values (see the 'Mangrove_DataComparatorWithHashing' template class), and the actual "<<endl;
	cout<<"\t\t\t'integer (int)' C++ built-in values (see the 'Mangrove_compareValues()' and the 'Mangrove_sameValues()' template functions)."<<endl<<endl;
	cout.flush();
	
	/* TASK #3 - validating the 'Mangrove_contains()' template function by using the 'Mangrove_compareIntValuesHashing()' and the 'Mangrove_sameIntValuesHashing()' custom functions. */
	cout<<"\tRepeating these operations by considering the order relation of the hashing values for the 'integer (int)' C++ built-in values."<<endl<<endl;
	if(Mangrove_compareIntValuesHashing(0,5)==true) cout<<"\tThe 'integer (int)' C++ built-in value 0 is 'strictly less than' the 'integer (int)' C++ built-in value 5 (with respect to the 'Mangrove_compareIntValuesHashing()' custom function)."<<endl;
	else cout<<"\tThe 'integer (int)' C++ built-in value 0 is not 'strictly less than' the 'integer (int)' C++ built-in value 5 (with respect to the 'Mangrove_compareIntValuesHashing()' custom function)."<<endl;
	if(Mangrove_compareIntValuesHashing(2,-1)==true) cout<<"\tThe 'integer (int)' C++ built-in value 2 is 'strictly less than' the 'integer (int)' C++ built-in value -1 (with respect to the 'Mangrove_compareIntValuesHashing()' custom function)."<<endl;
	else cout<<"\tThe 'integer (int)' C++ built-in value 2 is not 'strictly less than' the 'integer (int)' C++ built-in value -1 (with respect to the 'Mangrove_compareIntValuesHashing()' custom function)."<<endl;
	if(Mangrove_sameIntValuesHashing(5,5)==true) cout<<"\tThe 'integer (int)' C++ built-in value 5 is 'the same as' the 'integer (int)' C++ built-in value 5 (with respect to the 'Mangrove_sameIntValuesHashing()' custom function)."<<endl;
	else cout<<"\tThe 'integer (int)' C++ built-in value 5 is not 'the same as' the 'integer (int)' C++ built-in value 5 (with respect to the 'Mangrove_sameIntValuesHashing()' custom function)."<<endl;
	if(Mangrove_sameIntValuesHashing(3,7)==true) cout<<"\tThe 'integer (int)' C++ built-in value 3 is 'the same as' the 'integer (int)' C++ built-in value 7 (with respect to the 'Mangrove_sameIntValuesHashing()' custom function)."<<endl;
	else cout<<"\tThe 'integer (int)' C++ built-in value 3 is not 'the same as' the 'integer (int)' C++ built-in value 7 (with respect to the 'Mangrove_sameIntValuesHashing()' custom function)."<<endl;
	if(Mangrove_contains(s0,-5,Mangrove_compareIntValuesHashing)==true) cout<<"\tThe set 's0' contains the 'integer (int)' C++ built-in value -5 (see the 'Mangrove_contains()' template function and the 'Mangrove_compareIntValuesHashing()' custom function)."<<endl;
	else cout<<"\tThe set 's0' does not contain the 'integer (int)' C++ built-in value -5 (see the 'Mangrove_contains()' template function and the 'Mangrove_compareIntValuesHashing()' custom function)."<<endl;
	if(Mangrove_contains(s0,12,Mangrove_compareIntValuesHashing)==true) cout<<"\tThe set 's0' contains the 'integer (int)' C++ built-in value 12 (see the 'Mangrove_contains()' template function and the 'Mangrove_compareIntValuesHashing()' custom function)."<<endl;
	else cout<<"\tThe set 's0' does not contain the 'integer (int)' C++ built-in value 12 (see the 'Mangrove_contains()' template function and the 'Mangrove_compareIntValuesHashing()' custom function)."<<endl;
	cout<<endl;
	Mangrove_pause();
	
	/* TASK #4 - creating another set 's1', containing several 'integer (int)' C++ built-in values to be manipulated and compared with the set 's0'. */
	cout<<"\tCreating another new set 's1' of several 'integer (int)' C++ built-in values ... ";
	set<int, Mangrove_DataComparatorWithHashing<int> > s1={54,3,55,0,-4,2,-5};
	cout<<"ok"<<endl;
	Mangrove_debug(s1);
	if(Mangrove_sameValues(s0,s1,Mangrove_sameIntValues)==true) 
		cout<<"\tThe sets 's0' and 's1' contain the same 'integer (int)' C++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameIntValues()' custom function)."<<endl;
	else cout<<"\tThe sets 's0' and 's1' do not contain the same 'integer (int)' C++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameIntValues()' custom function)."<<endl;
	if(Mangrove_sameValues(s0,s1,Mangrove_sameIntValuesHashing)==true) 
		cout<<"\tThe sets 's0' and 's1' contain the same 'integer (int)' C++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameIntValuesHashing()' custom function)."<<endl<<endl;
	else cout<<"\tThe sets 's0' and 's1' do not contain the same 'integer (int)' C++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameIntValuesHashing()' custom function)."<<endl<<endl;
	s01.clear();
	cout<<"\tRetrieving the intersection between the sets 's0' and 's1' (see the 'Mangrove_intersection()' template function and the 'Mangrove_compareIntValues()' custom function) ... ";
	Mangrove_intersection(s0,s1,s01,Mangrove_compareIntValues);
	cout<<"ok"<<endl;
	cout<<"\tThe common 'integer (int)' C++ built-in values in the intersection of interest are the following: ";
	Mangrove_exportHybrid(s01);
	s01.clear();
	cout<<"\tRetrieving the intersection between the sets 's0' and 's1' (see the 'Mangrove_intersection()' template function and the 'Mangrove_compareIntValuesHashing()' custom function) ... ";
	Mangrove_intersection(s0,s1,s01,Mangrove_compareIntValuesHashing);
	cout<<"ok"<<endl;
	cout<<"\tThe common 'integer (int)' C++ built-in values in the intersection of interest are the following: ";
	Mangrove_exportHybrid(s01);
	cout<<endl<<"\tSetting the content of the set 's1' as a copy of the set 's0' ... ";
	s1.clear();
	s01.clear();
	s1=set<int, Mangrove_DataComparatorWithHashing<int> >(s0.cbegin(),s0.cend());
	cout<<"ok"<<endl;
	cout.flush();
	Mangrove_debug(s1);
	if(Mangrove_sameValues(s0,s1,Mangrove_sameIntValues)==true) 
		cout<<"\tThe sets 's0' and 's1' contain the same 'integer (int)' C++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameIntValues()' custom function)."<<endl;
	else cout<<"\tThe sets 's0' and 's1' do not contain the same 'integer (int)' C++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameIntValues()' custom function)."<<endl;
	if(Mangrove_sameValues(s0,s1,Mangrove_sameIntValuesHashing)==true) 
		cout<<"\tThe sets 's0' and 's1' contain the same 'integer (int)' C++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameIntValuesHashing()' custom function)."<<endl<<endl;
	else cout<<"\tThe sets 's0' and 's1' do not contain the same 'integer (int)' C++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameIntValuesHashing()' custom function)."<<endl<<endl;
	s1.clear();
	cout.flush();
	Mangrove_pause();
	
	/* TASK #5 - creating a deque of several 'integer (int)' C++ built-in values to be manipulated and compared with the set 's0'. */
	cout<<"\tThe 'integer (int)' C++ built-in values in the set 's0' are: ";
	Mangrove_exportHybrid(s0);
	cout<<"\tCreating a new deque 'd' of several 'integer (int)' C++ built-in values ... ";
	deque<int> d={-5,-2,54,-4,13,11};
	cout<<"ok"<<endl;
	cout<<"\tThe 'integer (int)' C++ built-in values in the deque 'd' are: ";
	Mangrove_exportHybrid(d);
	cout<<endl<<"\tFiltering the 'integer (int)' C++ built-in values in the deque 'd' with respect to the set 's0' (see the 'Mangrove_filterValues()' template function and the 'Mangrove_compareIntValues()' custom function) ... ";
	Mangrove_filterValues(d,s0,Mangrove_compareIntValues);
	cout<<"ok"<<endl;
	cout<<"\tThe 'integer (int)' C++ built-in values in the filtered deque 'd' are: ";
	if(d.empty()==false) Mangrove_exportHybrid(d);
	else cout<<"none."<<endl;
	if(Mangrove_sameValues(s0,d,Mangrove_sameIntValues)) 
		cout<<"\tThe deque 'd' and the set 's0' contain the same 'integer (int)' C++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameIntValues()' custom function)."<<endl;
	else cout<<"\tThe deque 'd' and the set 's0' do not contain the same 'integer (int)' c++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameIntValues()' custom function)."<<endl;
	cout<<"\tSetting the content of the deque 'd' as a copy of the set 's0' ... ";
	d.clear();
	d=deque<int>(s0.cbegin(),s0.cend());
	cout<<"ok"<<endl;
	if(Mangrove_sameValues(s0,d,Mangrove_sameIntValues)) 
		cout<<"\tThe deque 'd' and the set 's0' contain the same 'integer (int)' C++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameIntValues()' custom function)."<<endl<<endl;
	else cout<<"\tThe deque 'd' and the set 's0' do not contain the same 'integer (int)' c++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameIntValues()' custom function)."<<endl<<endl;
	cout<<"\tIMPORTANT:\tthe wrong results of the operations (just performed) depends on the different sorting policies among the hashing values (see the 'Mangrove_DataComparatorWithHashing' template class), and the actual "<<endl;
	cout<<"\t\t\t'integer (int)' C++ built-in values (see the 'Mangrove_compareValues()' and the 'Mangrove_sameValues()' template functions)."<<endl<<endl;
	cout.flush();
	cout<<"\tRepeating these operations by considering the order relation of the hashing values for the 'integer (int)' C++ built-in values."<<endl<<endl;
	cout<<"\tResetting the initial deque 'd' of several 'integer (int)' C++ built-in values ... ";
	d={-5,-2,54,-4,13,11};
	cout<<"ok"<<endl;
	cout<<"\tThe 'integer (int)' C++ built-in values in the deque 'd' are: ";
	Mangrove_exportHybrid(d);
	cout<<endl<<"\tFiltering the 'integer (int)' C++ built-in values in the deque 'd' with respect to the set 's0' (see the 'Mangrove_filterValues()' template function and the 'Mangrove_compareIntValuesHashing()' custom function) ... ";
	Mangrove_filterValues(d,s0,Mangrove_compareIntValuesHashing);
	cout<<"ok"<<endl;
	cout<<"\tThe 'integer (int)' C++ built-in values in the filtered deque 'd' are: ";
	if(d.empty()==false) Mangrove_exportHybrid(d);
	else cout<<"none."<<endl;
	if(Mangrove_sameValues(s0,d,Mangrove_sameIntValuesHashing)) 
		cout<<"\tThe deque 'd' and the set 's0' contain the same 'integer (int)' C++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameIntValuesHashing()' custom function)."<<endl;
	else cout<<"\tThe deque 'd' and the set 's0' do not contain the same 'integer (int)' c++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameIntValuesHashing()' custom function)."<<endl;
	cout<<"\tSetting the content of the deque 'd' as a copy of the set 's0' ... ";
	d.clear();
	d=deque<int>(s0.cbegin(),s0.cend());
	cout<<"ok"<<endl;
	if(Mangrove_sameValues(s0,d,Mangrove_sameIntValuesHashing)) 
		cout<<"\tThe deque 'd' and the set 's0' contain the same 'integer (int)' C++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameIntValuesHashing()' custom function)."<<endl<<endl;
	else cout<<"\tThe deque 'd' and the set 's0' do not contain the same 'integer (int)' c++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameIntValuesHashing()' custom function)."<<endl<<endl;
	Mangrove_pause();	
	
	/* TASK #6 - creating a list of several 'integer (int)' C++ built-in values to be manipulated and compared with the set 's0'. */
	cout<<"\tThe 'integer (int)' C++ built-in values in the set 's0' are: ";
	Mangrove_exportHybrid(s0);
	cout<<"\tCreating a new list 'l' of several 'integer (int)' C++ built-in values ... ";
	list<int> l(s0.crbegin(),s0.crend());
	cout<<"ok"<<endl;
	cout<<"\tThe 'integer (int)' C++ built-in values in the list 'l' are: ";
	Mangrove_exportHybrid(l);
	cout<<endl<<"\tFiltering the 'integer (int)' C++ built-in values in the list 'l' with respect to the set 's0' (see the 'Mangrove_filterValues()' template function and the 'Mangrove_compareIntValues()' custom function) ... ";
	Mangrove_filterValues(l,s0,Mangrove_compareIntValues);
	cout<<"ok"<<endl;
	cout<<"\tThe 'integer (int)' C++ built-in values in the filtered list 'l' are: ";
	if(l.empty()==false) Mangrove_exportHybrid(l);
	else cout<<"none."<<endl;
	if(Mangrove_sameValues(s0,l,Mangrove_sameIntValues)) 
		cout<<"\tThe list 'l' and the set 's0' contain the same 'integer (int)' C++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameIntValues()' custom function)."<<endl;
	else cout<<"\tThe list 'l' and the set 's0' do not contain the same 'integer (int)' c++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameIntValues()' custom function)."<<endl;
	cout<<"\tSetting the content of the list 'l' as a copy of the set 's0' ... ";
	l.clear();
	l=list<int>(s0.cbegin(),s0.cend());
	cout<<"ok"<<endl;
	if(Mangrove_sameValues(s0,l,Mangrove_sameIntValues)) 
		cout<<"\tThe list 'l' and the set 's0' contain the same 'integer (int)' C++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameIntValues()' custom function)."<<endl<<endl;
	else cout<<"\tThe list 'l' and the set 's0' do not contain the same 'integer (int)' c++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameIntValues()' custom function)."<<endl<<endl;
	cout<<"\tIMPORTANT:\tthe wrong results of the operations (just performed) depends on the different sorting policies among the hashing values (see the 'Mangrove_DataComparatorWithHashing' template class), and the actual "<<endl;
	cout<<"\t\t\t'integer (int)' C++ built-in values (see the 'Mangrove_compareValues()' and the 'Mangrove_sameValues()' template functions)."<<endl<<endl;
	cout.flush();
	cout<<"\tRepeating these operations by considering the order relation of the hashing values for the 'integer (int)' C++ built-in values."<<endl<<endl;
	cout<<"\tResetting the initial list 'l' of several 'integer (int)' C++ built-in values ... ";
	l=list<int>(s0.crbegin(),s0.crend());
	cout<<"ok"<<endl;
	cout<<"\tThe 'integer (int)' C++ built-in values in the list 'l' are: ";
	Mangrove_exportHybrid(l);
	cout<<endl<<"\tFiltering the 'integer (int)' C++ built-in values in the list 'l' with respect to the set 's0' (see the 'Mangrove_filterValues()' template function and the 'Mangrove_compareIntValuesHashing()' custom function) ... ";
	Mangrove_filterValues(l,s0,Mangrove_compareIntValuesHashing);
	cout<<"ok"<<endl;
	cout<<"\tThe 'integer (int)' C++ built-in values in the filtered list 'l' are: ";
	if(l.empty()==false) Mangrove_exportHybrid(l);
	else cout<<"none."<<endl;
	if(Mangrove_sameValues(s0,l,Mangrove_sameIntValuesHashing)) 
		cout<<"\tThe list 'l' and the set 's0' contain the same 'integer (int)' C++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameIntValuesHashing()' custom function)."<<endl;
	else cout<<"\tThe list 'l' and the set 's0' do not contain the same 'integer (int)' c++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameIntValuesHashing()' custom function)."<<endl;
	cout<<"\tSetting the content of the list 'l' as a copy of the set 's0' ... ";
	l.clear();
	l=list<int>(s0.cbegin(),s0.cend());
	cout<<"ok"<<endl;
	if(Mangrove_sameValues(s0,l,Mangrove_sameIntValues)) 
		cout<<"\tThe list 'l' and the set 's0' contain the same 'integer (int)' C++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameIntValues()' custom function)."<<endl<<endl;
	else cout<<"\tThe list 'l' and the set 's0' do not contain the same 'integer (int)' c++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameIntValues()' custom function)."<<endl<<endl;
	Mangrove_pause();
	
	/* TASK #7 - creating an array of several 'integer (int)' C++ built-in values to be manipulated and compared with the set 's0'. */
	cout<<"\tThe 'integer (int)' C++ built-in values in the set 's0' are: ";
	Mangrove_exportHybrid(s0);
	cout<<"\tCreating a new array 'v' of several 'integer (int)' C++ built-in values ... ";
	vector<int> v={57,-8,-11,-12,-5};
	cout<<"ok"<<endl;
	cout<<"\tThe 'integer (int)' C++ built-in values in the array 'v' are: ";
	Mangrove_exportHybrid(v);
	cout<<endl<<"\tFiltering the 'integer (int)' C++ built-in values in the array 'v' with respect to the set 's0' (see the 'Mangrove_filterValues()' template function and the 'Mangrove_compareIntValues()' custom function) ... ";
	Mangrove_filterValues(v,s0,Mangrove_compareIntValues);
	cout<<"ok"<<endl;
	cout<<"\tThe 'integer (int)' C++ built-in values in the filtered array 'v' are: ";
	if(v.empty()==false) Mangrove_exportHybrid(v);
	else cout<<"none."<<endl;
	if(Mangrove_sameValues(s0,v,Mangrove_sameIntValues)) 
		cout<<"\tThe array 'v' and the set 's0' contain the same 'integer (int)' C++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameIntValues()' custom function)."<<endl;
	else cout<<"\tThe array 'v' and the set 's0' do not contain the same 'integer (int)' c++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameIntValues()' custom function)."<<endl;
	cout<<"\tSetting the content of the array 'v' as a copy of the set 's0' ... ";
	v.clear();
	v=vector<int>(s0.cbegin(),s0.cend());
	cout<<"ok"<<endl;
	if(Mangrove_sameValues(s0,v,Mangrove_sameIntValues)) 
		cout<<"\tThe array 'v' and the set 's0' contain the same 'integer (int)' C++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameIntValues()' custom function)."<<endl<<endl;
	else cout<<"\tThe array 'v' and the set 's0' do not contain the same 'integer (int)' c++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameIntValues()' custom function)."<<endl<<endl;
	cout<<"\tIMPORTANT:\tthe wrong results of the operations (just performed) depends on the different sorting policies among the hashing values (see the 'Mangrove_DataComparatorWithHashing' template class), and the actual "<<endl;
	cout<<"\t\t\t'integer (int)' C++ built-in values (see the 'Mangrove_compareValues()' and the 'Mangrove_sameValues()' template functions)."<<endl<<endl;
	cout.flush();
	cout<<"\tRepeating these operations by considering the order relation of the hashing values for the 'integer (int)' C++ built-in values."<<endl<<endl;
	cout<<"\tResetting the initial array 'v' of several 'integer (int)' C++ built-in values ... ";
	v={57,-8,-11,-12,-5};
	cout<<"ok"<<endl;
	cout<<"\tThe 'integer (int)' C++ built-in values in the array 'v' are: ";
	Mangrove_exportHybrid(v);
	cout<<endl<<"\tFiltering the 'integer (int)' C++ built-in values in the array 'v' with respect to the set 's0' (see the 'Mangrove_filterValues()' template function and the 'Mangrove_compareIntValuesHashing()' custom function) ... ";
	Mangrove_filterValues(v,s0,Mangrove_compareIntValuesHashing);
	cout<<"ok"<<endl;
	cout<<"\tThe 'integer (int)' C++ built-in values in the filtered array 'v' are: ";
	if(v.empty()==false) Mangrove_exportHybrid(v);
	else cout<<"none."<<endl;
	if(Mangrove_sameValues(s0,v,Mangrove_sameIntValuesHashing)) 
		cout<<"\tThe array 'v' and the set 's0' contain the same 'integer (int)' C++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameIntValuesHashing()' custom function)."<<endl;
	else cout<<"\tThe array 'v' and the set 's0' do not contain the same 'integer (int)' c++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameIntValuesHashing()' custom function)."<<endl;
	cout<<"\tSetting the content of the array 'v' as a copy of the set 's0' ... ";
	v.clear();
	v=vector<int>(s0.cbegin(),s0.cend());
	cout<<"ok"<<endl;
	if(Mangrove_sameValues(s0,v,Mangrove_sameIntValues)) 
		cout<<"\tThe array 'v' and the set 's0' contain the same 'integer (int)' C++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameIntValues()' custom function)."<<endl<<endl;
	else cout<<"\tThe array 'v' and the set 's0' do not contain the same 'integer (int)' c++ built-in values position by position (see the 'Mangrove_sameValues()' template function and the 'Mangrove_sameIntValues()' custom function)."<<endl<<endl;
	Mangrove_pause();

	/* TASK #8 - deallocating all auxiliary data structures in this tutorial. */
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
