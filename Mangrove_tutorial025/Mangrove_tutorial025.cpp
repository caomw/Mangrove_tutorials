/*************************************************************************************************************************************************************************
 * This source code provides the 'Tutorial Example-025' for the Mangrove Topological Data Structure Library (Mangrove TDS Library 3.0)
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
 * Mangrove_tutorial025.cpp - the 'Tutorial Example-025' for the 'Mangrove TDS Library 3.0'.
 *************************************************************************************************************************************************************************/
 
#include "Mangrove_Miscellanea.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
using namespace mangrove_tds;

/// The <i>main function</i> for the <i>Mangrove_tutorial025</i> program.
/**
 * \file Mangrove_tutorial025.cpp
 * \author <A href="http://davidcanino.github.io">David Canino</A> (e-mail: <A href="mailto:canino.david@gmail.com">David Canino</A>)
 */

/// The <i>main function</i> for the <i>Mangrove_tutorial025</i> program.
/**
 * \return <ul><li>the built-in <i>EXIT_SUCCESS</i> constant value (provided by the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), if all is ok</li><li>the built-in <i>EXIT_FAILURE</i> constant value (provided by 
 * the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), otherwise</li></ul>
 * \see mangrove_tds::MANGROVE_ENTITY_ID, mangrove_tds::MANGROVE_ENTITY_DIM, checkPointerValidity(), mangrove_tds::Mangrove_exportCopyrightDisclaimer(), mangrove_tds::Mangrove_pause(), mangrove_tds::Mangrove_compare_faces(), mangrove_tds::Mangrove_same_faces(), 
 * mangrove_tds::Mangrove_compare_faces_with_hashing(), mangrove_tds::Mangrove_same_faces_with_hashing(), mangrove_tds::Mangrove_AuxiliaryRawFace
 */
int main(void)
{
	/* First, we export the header for the tutorial. Then, we validate the 'auxiliary raw faces'. */
	Mangrove_exportCopyrightDisclaimer("Mangrove_tutorial025");
	cout<<"\tCreating a not initialized 'auxiliary raw face' 'r1' ... ";
	Mangrove_AuxiliaryRawFace r1;
	cout<<"ok"<<endl;
	cout<<"\tRetrieving the unique identifier of the corresponding 'parent (top)' topological entity: "<<r1.getCIndex()<<endl;
	cout<<"\tRetrieving the corresponding reverse index of the corresponding 'child cell': "<<r1.getCReverseIndex()<<endl;
	cout<<"\tRetrieving the corresponding 'indexed representation': ";
	if(r1.getCVertices().empty()) cout<<"none"<<endl;
	else Mangrove_exportHybrid(r1.getCVertices());
	cout<<"\tRetrieving the current hashing value: "<<r1.getHashingValue()<<endl<<endl;
	cout.flush();
	cout<<"\tUpdating the content of the 'auxiliary raw face' 'r1' ... ";
	r1.getReverseIndex()=2;
	r1.getIndex()=3;
	r1.getVertices()={1,2,3};
	cout<<"ok"<<endl;
	cout<<"\tRetrieving the unique identifier of the corresponding 'parent (top)' topological entity: "<<r1.getIndex()<<endl;
	cout<<"\tRetrieving the corresponding reverse index of the corresponding 'child cell': "<<r1.getReverseIndex()<<endl;
	cout<<"\tRetrieving the corresponding 'indexed representation': ";
	if(r1.getVertices().empty()) cout<<"none"<<endl;
	else Mangrove_exportHybrid(r1.getVertices());
	cout<<"\tRetrieving the current hashing value: "<<r1.getHashingValue()<<endl;
	cout<<"\tUpdating the current hashing value ... ";
	r1.updateHashingValue();
	cout<<"ok"<<endl;
	cout<<"\tRetrieving the current hashing value: "<<r1.getHashingValue()<<endl<<endl;
	cout.flush();
	Mangrove_pause();
	
	/* Creating a copy 'r2' of the 'auxiliary raw face' 'r1'. */
	cout<<"\tCreating a copy 'r2' of the 'auxiliary raw face' 'r1' ... ";
	Mangrove_AuxiliaryRawFace *r2=nullptr;
	r2=new Mangrove_AuxiliaryRawFace(r1);
	cout<<"ok"<<endl;
	cout<<"\tRetrieving the unique identifier of the corresponding 'parent (top)' topological entity: "<<r2->getCIndex()<<endl;
	cout<<"\tRetrieving the corresponding reverse index of the corresponding 'child cell': "<<r2->getCReverseIndex()<<endl;
	cout<<"\tRetrieving the corresponding 'indexed representation': ";
	if(r2->getCVertices().empty()) cout<<"none"<<endl;
	else Mangrove_exportHybrid(r2->getCVertices());
	cout<<"\tRetrieving the current hashing value: "<<r2->getHashingValue()<<endl<<endl;
	if(Mangrove_same_faces(r1,*r2)) cout<<"\tThe 'auxiliary raw faces' 'r1' and 'r2' are 'the same', and their indexed representations coincide position by position."<<endl;
	else cout<<"\tThe 'auxiliary raw faces' 'r1' and 'r2' are not 'the same', and their indexed representations do not coincide position by position."<<endl;
	if(Mangrove_same_faces_with_hashing(r1,*r2)) cout<<"\tThe 'auxiliary raw faces' 'r1' and 'r2' are 'the same', and their hashing values coincide."<<endl<<endl;
	else cout<<"\tThe 'auxiliary raw faces' 'r1' and 'r2' are not 'the same', and their hashing values do not coincide."<<endl<<endl;
	cout.flush();
	Mangrove_pause();
	
	/* Creating a copy 'r3' of the 'auxiliary raw face' 'r2'. */
	cout<<"\tCreating a copy 'r3' of the 'auxiliary raw face' 'r2' ... ";
	Mangrove_AuxiliaryRawFace r3(r2);
	cout<<"ok"<<endl;
	cout<<"\tRetrieving the unique identifier of the corresponding 'parent (top)' topological entity: "<<r3.getCIndex()<<endl;
	cout<<"\tRetrieving the corresponding reverse index of the corresponding 'child cell': "<<r3.getCReverseIndex()<<endl;
	cout<<"\tRetrieving the corresponding 'indexed representation': ";
	if(r3.getCVertices().empty()) cout<<"none"<<endl;
	else Mangrove_exportHybrid(r3.getCVertices());
	cout<<"\tRetrieving the current hashing value: "<<r3.getHashingValue()<<endl<<endl;
	if(Mangrove_same_faces(*r2,r3)) cout<<"\tThe 'auxiliary raw faces' 'r2' and 'r3' are 'the same', and their indexed representations coincide position by position."<<endl;
	else cout<<"\tThe 'auxiliary raw faces' 'r2' and 'r3' are not 'the same', and their indexed representations do not coincide position by position."<<endl;
	if(Mangrove_same_faces_with_hashing(*r2,r3)) cout<<"\tThe 'auxiliary raw faces' 'r2' and 'r3' are 'the same', and their hashing values coincide."<<endl<<endl;
	else cout<<"\tThe 'auxiliary raw faces' 'r2' and 'r3' are not 'the same', and their hashing values do not coincide."<<endl<<endl;
	cout.flush();
	Mangrove_pause();
	
	/* Creating another 'auxiliary raw face' 'r4'. */
	cout<<"\tCreating another 'auxiliary raw face' 'r4' with the same indexed representation of the 'auxiliary raw face' 'r3' (but without updating the hashing value) ... ";
	Mangrove_AuxiliaryRawFace r4;
	for(auto it : r3.getCVertices() ) r4.getVertices().push_back(it);
	cout<<"ok"<<endl;
	cout<<"\tRetrieving the corresponding 'indexed representation': ";
	if(r4.getCVertices().empty()) cout<<"none"<<endl;
	else Mangrove_exportHybrid(r4.getCVertices());
	cout<<"\tRetrieving the current hashing value: "<<r4.getHashingValue()<<endl<<endl;
	if(Mangrove_same_faces(r4,r3)) cout<<"\tThe 'auxiliary raw faces' 'r3' and 'r4' are 'the same', and their indexed representations coincide position by position."<<endl;
	else cout<<"\tThe 'auxiliary raw faces' 'r3' and 'r4' are not 'the same', and their indexed representations do not coincide position by position."<<endl;
	if(Mangrove_same_faces_with_hashing(r4,r3)) cout<<"\tThe 'auxiliary raw faces' 'r3' and 'r4' are 'the same', and their hashing values coincide."<<endl;
	else cout<<"\tThe 'auxiliary raw faces' 'r3' and 'r4' are not 'the same', and their hashing values do not coincide."<<endl;
	if(Mangrove_compare_faces(r4,r3)) cout<<"\tThe 'auxiliary raw face' 'r4' is 'strictly less than' the 'auxiliary raw face' 'r3' (with respect to the lexicographic order of the indexed representations)."<<endl;
	else cout<<"\tThe 'auxiliary raw face' 'r4' is not 'strictly less than' the 'auxiliary raw face' 'r3' (with respect to the lexicographic order of the indexed representations)."<<endl;
	if(Mangrove_compare_faces_with_hashing(r4,r3)) cout<<"\tThe 'auxiliary raw face' 'r4' is 'strictly less than' the 'auxiliary raw face' 'r3' (with respect to the order relation of the hashing values)."<<endl<<endl;
	else cout<<"\tThe 'auxiliary raw face' 'r4' is not 'strictly less than' the 'auxiliary raw face' 'r3' (with respect to the order relation of the hashing values)."<<endl<<endl;
	cout.flush();
	Mangrove_pause();
	
	/* Modifying the 'auxiliary raw face' 'r4' in order to validate the comparison functions! */
	cout<<"\tUpdating the indexed representation of the 'auxiliary raw face' 'r4' and its hashing value ... ";
	r4.getVertices()={1,2,4};
	r4.updateHashingValue();
	cout<<"ok"<<endl;
	cout<<"\tRetrieving the corresponding 'indexed representation': ";
	if(r4.getCVertices().empty()) cout<<"none"<<endl;
	else Mangrove_exportHybrid(r4.getCVertices());
	cout<<"\tRetrieving the current hashing value: "<<r4.getHashingValue()<<endl<<endl;
	cout<<"\tRetrieving the 'indexed representation' of the 'auxiliary raw face' 'r3': ";
	if(r3.getCVertices().empty()) cout<<"none"<<endl;
	else Mangrove_exportHybrid(r3.getCVertices());
	cout<<"\tRetrieving the hashing value of the 'auxiliary raw face' 'r3': "<<r3.getHashingValue()<<endl<<endl;
	cout.flush();
	if(Mangrove_same_faces(r4,r3)) cout<<"\tThe 'auxiliary raw faces' 'r3' and 'r4' are 'the same', and their indexed representations coincide position by position."<<endl;
	else cout<<"\tThe 'auxiliary raw faces' 'r3' and 'r4' are not 'the same', and their indexed representations do not coincide position by position."<<endl;
	if(Mangrove_same_faces_with_hashing(r4,r3)) cout<<"\tThe 'auxiliary raw faces' 'r3' and 'r4' are 'the same', and their hashing values coincide."<<endl;
	else cout<<"\tThe 'auxiliary raw faces' 'r3' and 'r4' are not 'the same', and their hashing values do not coincide."<<endl;
	if(Mangrove_compare_faces(r4,r3)) cout<<"\tThe 'auxiliary raw face' 'r4' is 'strictly less than' the 'auxiliary raw face' 'r3' (with respect to the lexicographic order of the indexed representations)."<<endl;
	else cout<<"\tThe 'auxiliary raw face' 'r4' is not 'strictly less than' the 'auxiliary raw face' 'r3' (with respect to the lexicographic order of the indexed representations)."<<endl;
	if(Mangrove_compare_faces_with_hashing(r4,r3)) cout<<"\tThe 'auxiliary raw face' 'r4' is 'strictly less than' the 'auxiliary raw face' 'r3' (with respect to the order relation of the hashing values)."<<endl<<endl;
	else cout<<"\tThe 'auxiliary raw face' 'r4' is not 'strictly less than' the 'auxiliary raw face' 'r3' (with respect to the order relation of the hashing values)."<<endl<<endl;
	cout.flush();
	
	/* Deallocating all 'auxiliary raw faces'. */
	cout<<"\tDeallocating all 'auxiliary raw faces' in this test ... ";
	cout.flush();
	r1.clear();
	if(r2!=nullptr) delete r2;
	r2=nullptr;
	r3.clear();
	r4.clear();
	cout<<"ok"<<endl<<endl;
	cout.flush();
	return EXIT_SUCCESS;
}
