/*************************************************************************************************************************************************************************
 * This source code provides the 'Tutorial Example 02' for the Mangrove Topological Data Structure Library (Mangrove TDS Library 3.0)
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
 * Mangrove_tutorial02.cpp - the 'Tutorial Example 02' for the 'Mangrove TDS Library 3.0'.
 *************************************************************************************************************************************************************************/
 
#include "Mangrove_hashing.h"
#include "Mangrove_Miscellanea.h"
#include <cstdlib>
#include <iostream>
#include <map>
#include "QTime"
using namespace std;
using namespace mangrove_tds;

/// The <i>main function</i> for the <i>Mangrove_tutorial02</i> program.
/**
 * \file Mangrove_tutorial02.cpp
 * \author <A href="http://davidcanino.github.io">David Canino</A> (e-mail: <A href="mailto:canino.david@gmail.com">David Canino</A>)
 */

/// The maximum number of numbers/elements to be analyzed in this unit test.
/**
 * This constant value indicates the maximum number of the tests over the pairs <i>"numbers/elements"</i>, that we we must perform in this unit test. Specifically, this is number of the associations, that we create in this unit test for evaluating the efficiency of 
 * several implementations of the hashing maps. These latter are provided by the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i> and by the <i><A href="http://code.google.com/p/sparsehash/">SparseHash Library</A>
 * </i>.
 * \see mangrove_tds::Mangrove_DataComparatorWithHashing
 */
#define ASSOCIATIONS_NUMBER 1000000

/// The <i>main function</i> for the <i>Mangrove_tutorial02</i> program.
/**
 * \return <ul><li>the built-in <i>EXIT_SUCCESS</i> constant value (provided by the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), if all is ok</li><li>the built-in <i>EXIT_FAILURE</i> constant value (provided by 
 * the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), otherwise</li></ul>
 * \see mangrove_tds::Mangrove_exportCopyrightDisclaimer()
 */
int main(void)
{
	std::map<uint,uint> map_std;
	dense_hash_map<uint,uint> map_google;
	sparse_hash_map<uint,uint> map_google_sparse;
	std::map< vector<uint>, uint > map_arr_std;
	dense_hash_map< vector<uint>, uint, boost::hash< vector<uint> > > map_arr_google;
	sparse_hash_map< vector<uint>, uint, boost::hash< vector<uint> > > map_arr_google_sparse;
	uint num;
	QTime t;

	/* Now, we validate several functions in the 'Mangrove_hashing.h', plus the 'Mangrove_exportCopyrightDisclaimer()' function in the 'Mangrove_Miscellanea.h' file. */
	Mangrove_exportCopyrightDisclaimer ("Mangrove_tutorial02");
	cout<<"\tCreating a new hashing map of the 'std::map' type (involving several 'uint' values as the keys) with "<<ASSOCIATIONS_NUMBER<<" associations ... ";
	cout.flush();
	t.start();
	for(unsigned int k=0;k<ASSOCIATIONS_NUMBER;k++) { map_std[k]=k; }
	cout<<"ok [ in "<<t.elapsed()<<" ms ]"<<endl;
	cout.flush();
	cout<<"\tNavigating all associations, involving one 'uint' value (as the key), in the hashing map of the 'std::map' type (provided by the Standard Template Library) ... ";
	cout.flush();
	num=0;
	for(unsigned int k=0;k<ASSOCIATIONS_NUMBER;k++)
	{
		t.restart();
		map_std[k];
		num=num+t.elapsed();
	}
	
	/* Now, we export the mean times for the hashing map of the 'std::map' type (see the 'Mangrove_computeMean()' function). */
	cout<<"ok"<<endl<<"\tThe total time for this traversal: "<<num<<" ms"<<endl<<"\tThe mean time for accessing an association: "<<Mangrove_computeMean(num,ASSOCIATIONS_NUMBER)<<endl<<endl;
	cout.flush();
	map_std.clear();
	
	/* Now, we validate the efficiency of the hashing table, provided by the Google SparseHash Library. First, we analyze the hashing map of the 'google::dense_hash_map' type. */
	cout<<"\tCreating a new hashing map of the 'google::dense_hash_map' type (involving several 'uint' values as the keys) with "<<ASSOCIATIONS_NUMBER<<" associations ... ";
	cout.flush();
	map_google.set_empty_key(std::numeric_limits<uint>::max());
	t.restart();
	for(unsigned int k=0;k<ASSOCIATIONS_NUMBER;k++) { map_google[k]=k; }
	cout<<"ok [ in "<<t.elapsed()<<" ms ]"<<endl;
	cout.flush();
	cout<<"\tNavigating all associations, involving one 'uint' value (as the key), in the hashing map of the 'google::dense_hash_map' type (provided by the Google SparseHash Library) ... ";
	cout.flush();
	num=0;
	for(unsigned int k=0;k<ASSOCIATIONS_NUMBER;k++)
	{
		t.restart();
		map_google[k];
		num=num+t.elapsed();
	}
	
	/* Now, we export the mean times for the hashing map of the 'google::dense_hash_map' type (provided by the Google SparseHash Library). */
	cout<<"ok"<<endl<<"\tThe total time for this traversal: "<<num<<" ms"<<endl<<"\tThe mean time for accessing an association: "<<Mangrove_computeMean(num,ASSOCIATIONS_NUMBER)<<endl<<endl;
	cout.flush();
	map_google.clear();
	
	/* Now, we validate the efficiency of the hashing table, provided by the Google SparseHash Library. Now, we analyze the hashing map of the 'google::sparse_hash_map' type */
	cout<<"\tCreating a new hashing map of the 'google::sparse_hash_map' type (involving several 'uint' values as the keys) with "<<ASSOCIATIONS_NUMBER<<" associations ... ";
	cout.flush();
	t.restart();
	for(unsigned int k=0;k<ASSOCIATIONS_NUMBER;k++) { map_google_sparse[k]=k; }
	cout<<"ok [ in "<<t.elapsed()<<" ms ]"<<endl;
	cout.flush();
	cout<<"\tNavigating all associations, involving one 'uint' value (as the key), in the hashing map of the 'google::sparse_hash_map' type (provided by the Google SparseHash Library) ... ";
	cout.flush();
	num=0;
	for(unsigned int k=0;k<ASSOCIATIONS_NUMBER;k++)
	{
		t.restart();
		map_google_sparse[k];
		num=num+t.elapsed();
	}
	
	/* Now, we export the mean times for the hashing map of the 'google::sparse_hash_map' type (provided by the Google SparseHash Library). */
	cout<<"ok"<<endl<<"\tThe total time for this traversal: "<<num<<" ms"<<endl<<"\tThe mean time for accessing an association: "<<Mangrove_computeMean(num,ASSOCIATIONS_NUMBER)<<endl<<endl;
	cout.flush();
	map_google_sparse.clear();
	
	/* Now, we validate the efficiency of the hashing table, provided by the Standard Template Library (STL). Here, the key is a generic array, formed by 4 'uint' values. */
	cout<<"\tCreating a new hashing map of the 'std::map' type (involving several arrays, formed by 4 'uint' values, as the keys) with "<<ASSOCIATIONS_NUMBER<<" associations ... ";
	cout.flush();
	num=0;
	for(unsigned int k=0;k<ASSOCIATIONS_NUMBER;k++)
	{
		vector<uint> aux;
		
		/* Now, we create the new array 'aux' to be saved in the hashing map of the 'std::map' type. */
		aux.push_back(0);
		aux.push_back(1);
		aux.push_back(2);
		aux.push_back(k);
		t.restart();
		map_arr_std[aux]=k;
		num=num+t.elapsed();
	}
	
	/* Now, we export the result, then we study performance for the hashing map of the 'std::map' type (see the 'Mangrove_computeMean()' function). */
	cout<<"ok [ in "<<num<<" ms ]"<<endl;
	cout.flush();
	cout<<"\tNavigating all associations, involving one array of 4 'uint' values (as the key), in the hashing map of the 'std::map' type (provided by the Standard Template Library) ... ";
	cout.flush();
	num=0;
	for(unsigned int k=0;k<ASSOCIATIONS_NUMBER;k++)
	{
		vector<uint> aux;
		
		/* Now, we create the new array 'aux' to be exploited as the key in the hashing map of the 'std::map' type. */
		aux.push_back(0);
		aux.push_back(1);
		aux.push_back(2);
		aux.push_back(k);
		t.restart();
		map_arr_std[aux];
		num=num+t.elapsed();
	}
	
	/* Now, we export the mean times for the hashing map of the 'std::map' type. */
	cout<<"ok"<<endl<<"\tThe total time for this traversal: "<<num<<" ms"<<endl<<"\tThe mean time for accessing an association: "<<Mangrove_computeMean(num,ASSOCIATIONS_NUMBER)<<endl<<endl;
	cout.flush();
	map_arr_std.clear();
	
	/* Now, we validate the efficiency of the hashing table of the 'google_dense_hash_map' type, provided by the Google SparseHash Library. Here, the key is a generic array, formed by 4 'uint' values. */
	cout<<"\tCreating a new hashing map of the 'google::dense_hash_map' type (involving several arrays, formed by 4 'uint' values, as the keys) with "<<ASSOCIATIONS_NUMBER<<" associations ... ";
	cout.flush();
	num=0;
	map_arr_google.set_empty_key( vector<uint>() );
	for(unsigned int k=0;k<ASSOCIATIONS_NUMBER;k++)
	{
		vector<uint> aux;
		
		/* Now, we create the new array 'aux' to be saved in the hashing map of the 'map_arr_google' type. */
		aux.push_back(0);
		aux.push_back(1);
		aux.push_back(2);
		aux.push_back(k);
		t.restart();
		map_arr_google[aux]=k;
		num=num+t.elapsed();
	}
	
	/* Now, we export the result, then we study performance for the hashing map of the 'google::dense_hash_map' type (see the 'Mangrove_computeMean()' function). */
	cout<<"ok [ in "<<num<<" ms ]"<<endl;
	cout.flush();
	cout<<"\tNavigating all associations, involving one array of 4 'uint' values (as the key), from the hashing map of the 'google::dense_hash_map' type (provided by the Google SparseHash Library) ... ";
	cout.flush();
	num=0;
	for(unsigned int k=0;k<ASSOCIATIONS_NUMBER;k++)
	{
		vector<uint> aux;
		
		/* Now, we create the new array 'aux' to be exploited as the key in the hashing map of the 'map_arr_google' type. */
		aux.push_back(0);
		aux.push_back(1);
		aux.push_back(2);
		aux.push_back(k);
		t.restart();
		map_arr_google[aux];
		num=num+t.elapsed();
	}
	
	/* Now, we export the mean times for the hashing map of the 'google::dense_hash_map' type. */
	cout<<"ok"<<endl<<"\tThe total time for this traversal: "<<num<<" ms"<<endl<<"\tThe mean time for accessing an association: "<<Mangrove_computeMean(num,ASSOCIATIONS_NUMBER)<<endl<<endl;
	cout.flush();
	map_arr_google.clear();
	
	/* Now, we validate the efficiency of the hashing table of the 'google_sparse_hash_map' type, provided by the Google SparseHash Library. Here, the key is a generic array, formed by 4 'uint' values. */
	cout<<"\tCreating a new hashing map of the 'google::sparse_hash_map' type (involving several arrays, formed by 4 'uint' values, as the keys) with "<<ASSOCIATIONS_NUMBER<<" associations ... ";
	cout.flush();
	num=0;
	for(unsigned int k=0;k<ASSOCIATIONS_NUMBER;k++)
	{
		vector<uint> aux;
		
		/* Now, we create the new array 'aux' to be saved in the hashing map of the 'map_arr_google_sparse' type. */
		aux.push_back(0);
		aux.push_back(1);
		aux.push_back(2);
		aux.push_back(k);
		t.restart();
		map_arr_google_sparse[aux]=k;
		num=num+t.elapsed();
	}
	
	/* Now, we export the result, then we study performance for the hashing map of the 'google::sparse_hash_map' type. */
	cout<<"ok [ in "<<num<<" ms ]"<<endl;
	cout.flush();
	cout<<"\tNavigating all associations, involving one array of 4 'uint' values (as the key), in the hashing map of the 'google::sparse_hash_map' type (provided by the Google SparseHash Library) ... ";
	cout.flush();
	num=0;
	for(unsigned int k=0;k<ASSOCIATIONS_NUMBER;k++)
	{
		vector<uint> aux;
		
		/* Now, we create the new array 'aux' to be exploited as the key in the hashing map of the 'map_arr_google_sparse' type. */
		aux.push_back(0);
		aux.push_back(1);
		aux.push_back(2);
		aux.push_back(k);
		t.restart();
		map_arr_google_sparse[aux];
		num=num+t.elapsed();
	}
	
	/* Now, we export the mean times for the hashing map of the 'google::dense_hash_map' type. */
	cout<<"ok"<<endl<<"\tThe total time for this traversal: "<<num<<" ms"<<endl<<"\tThe mean time for accessing an association: "<<Mangrove_computeMean(num,ASSOCIATIONS_NUMBER)<<endl<<endl;
	cout.flush();
	
	/* Now, we can remove everything! */
	map_std.clear();
	map_google.clear();
	map_google_sparse.clear();
	map_arr_std.clear();
	map_arr_google.clear();
	map_arr_google_sparse.clear();
	return EXIT_SUCCESS;
}
