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
using namespace std;
using namespace mangrove_tds;

/// The <i>main function</i> for the <i>'Mangrove_tutorial026'</i> program.
/**
 * \file Mangrove_tutorial025.cpp
 * \author <A href="http://davidcanino.github.io">David Canino</A> (e-mail: <A href="mailto:canino.david@gmail.com">David Canino</A>)
 */

/// The <i>main function</i> for the <i>'Mangrove_tutorial025'</i> program.
/**
 * \return <ul><li>the built-in <i>EXIT_SUCCESS</i> constant value (provided by the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), if all is ok</li><li>the built-in <i>EXIT_FAILURE</i> constant value (provided by 
 * the <i><A href="http://en.wikipedia.org/wiki/C%2B%2B_Standard_Library">Standard C++ Library</A></i>), otherwise</li></ul>
 * \see mangrove_tds::MANGROVE_ENTITY_ID, mangrove_tds::MANGROVE_ENTITY_DIM, mangrove_tds::Mangrove_exportCopyrightDisclaimer(), mangrove_tds::Mangrove_compare_faces(), mangrove_tds::Mangrove_compare_faces_with_hashing(), mangrove_tds::Mangrove_same_faces(), 
 * mangrove_tds::Mangrove_same_faces_with_hashing(), mangrove_tds::RawFace, mangrove_tds::Mangrove_AuxiliaryExtendedRawFace, mangrove_tds::Mangrove_ExtendedRawFace, mangrove_tds::Mangrove_VirtualInheritance4Single, mangrove_tds::Mangrove_VirtualInheritance4Multiple, 
 * mangrove_tds::Mangrove_SerializableObject, mangrove_tds::Mangrove_AuxiliaryRawFace::getCIndex(), mangrove_tds::Mangrove_AuxiliaryRawFace::CReverseIndex(), mangrove_tds::Mangrove_AuxiliaryRawFace::getCVertices(), mangrove_tds::Mangrove_AuxiliaryRawFace::getIndex(), 
 * mangrove_tds::Mangrove_AuxiliaryRawFace::getReverseIndex(), mangrove_tds::Mangrove_AuxiliaryRawFace::getVertices(), mangrove_tds::Mangrove_AuxiliaryRawFace::getHashingValue(), mangrove_tds::Mangrove_AuxiliaryRawFace::updateHashingValue(), checkPointerValidity()
 */
int main(void)
{
	/* This is the 'Mangrove_tutorial025' tutorial, where the 'auxiliary raw faces' (see the 'Mangrove_AuxiliaryRawFace' class) are validated. */
	Mangrove_exportCopyrightDisclaimer("The 'Mangrove_tutorial025' Tutorial");
	
	/* TASK #1 - creating and initializing a new 'auxiliary raw face'. */
	cout<<"\tCreating a not initialized 'auxiliary raw face' 'r1' ... ";
	Mangrove_AuxiliaryRawFace r1;
	cout<<"ok"<<endl<<endl;
	cout<<"\tThe unique identifier of the 'parent (top)' topological entity in the new 'auxiliary raw face' 'r1' is "<<r1.getCIndex()<<"."<<endl;
	cout<<"\tThe reverse index of the 'child cell' in the new 'auxiliary raw face' 'r1' is "<<r1.getCReverseIndex()<<"."<<endl;
	cout<<"\tThe indices to the vertices in the 'indexed representation' of the new 'auxiliary raw face' 'r1' are: ";
	if(r1.getCVertices().empty()) cout<<"none."<<endl;
	else Mangrove_exportHybrid(r1.getCVertices());
	cout<<"\tThe current hashing value of the new 'auxiliary raw face' 'r1' is "<<r1.getHashingValue()<<"."<<endl<<endl;
	cout<<"\tUpdating the content of the 'auxiliary raw face' 'r1' ... ";
	r1.getReverseIndex()=2;
	r1.getIndex()=3;
	r1.getVertices()={1,2,3};
	cout<<"ok"<<endl<<endl;
	cout<<"\tThe unique identifier of the 'parent (top)' topological entity in the new 'auxiliary raw face' 'r1' is "<<r1.getCIndex()<<"."<<endl;
	cout<<"\tThe reverse index of the 'child cell' in the new 'auxiliary raw face' 'r1' is "<<r1.getCReverseIndex()<<"."<<endl;
	cout<<"\tThe indices to the vertices in the 'indexed representation' of the new 'auxiliary raw face' 'r1' are: ";
	if(r1.getCVertices().empty()) cout<<"none."<<endl;
	else Mangrove_exportHybrid(r1.getCVertices());
	cout<<"\tThe current hashing value of the new 'auxiliary raw face' 'r1' is "<<r1.getHashingValue()<<"."<<endl<<endl;
	cout<<"\tUpdating the hashing value of the new 'auxiliary raw face' 'r1' ... ";
	r1.updateHashingValue();
	cout<<"ok"<<endl;
	cout<<"\tThe current hashing value of the new 'auxiliary raw face' 'r1' is "<<r1.getHashingValue()<<"."<<endl<<endl;
	Mangrove_pause();
	
	/* TASK #2 - creating a copy 'r2' of the 'auxiliary raw face' 'r1'. */
	cout<<"\tCreating a copy 'r2' of the 'auxiliary raw face' 'r1' ... ";
	Mangrove_AuxiliaryRawFace *r2=nullptr;
	r2=new Mangrove_AuxiliaryRawFace(r1);
	cout<<"ok"<<endl;
	cout<<"\tThe unique identifier of the 'parent (top)' topological entity in the new 'auxiliary raw face' 'r2' is "<<r2->getCIndex()<<"."<<endl;
	cout<<"\tThe reverse index of the 'child cell' in the new 'auxiliary raw face' 'r2' is "<<r2->getCReverseIndex()<<"."<<endl;
	cout<<"\tThe indices to the vertices in the 'indexed representation' of the new 'auxiliary raw face' 'r2' are: ";
	if(r2->getCVertices().empty()) cout<<"none."<<endl;
	else Mangrove_exportHybrid(r2->getCVertices());
	cout<<"\tThe current hashing value of the new 'auxiliary raw face' 'r2' is "<<r2->getHashingValue()<<"."<<endl<<endl;
	if(Mangrove_same_faces(r1,*r2)) 
		cout<<"\tThe 'auxiliary raw faces' 'r1' and 'r2' are 'the same', and the indices to the vertices in their indexed representations coincide position by position (with respect to the 'mangrove_tds::Mangrove_same_faces()' function)."<<endl;
	else cout<<"\tThe 'auxiliary raw faces' 'r1' and 'r2' are not 'the same', and the indices to the vertices in their indexed representations do not coincide position by position (with respect to the 'mangrove_tds::Mangrove_same_faces()' function)."<<endl;
	if(Mangrove_same_faces_with_hashing(r1,*r2)) cout<<"\tThe 'auxiliary raw faces' 'r1' and 'r2' are 'the same', and their hashing values coincide (with respect to the 'mangrove_tds::Mangrove_same_faces_with_hashing()' function)."<<endl<<endl;
	else cout<<"\tThe 'auxiliary raw faces' 'r1' and 'r2' are not 'the same', and their hashing values do not coincide (with respect to the 'mangrove_tds::Mangrove_same_faces_with_hashing()' function)."<<endl<<endl;
	cout.flush();
	Mangrove_pause();
	
	/* TASK #3 - creating a copy 'r3' of the 'auxiliary raw face' 'r2'. */
	cout<<"\tCreating a copy 'r3' of the 'auxiliary raw face' 'r2' ... ";
	Mangrove_AuxiliaryRawFace r3(r2);
	cout<<"ok"<<endl;
	cout<<"\tThe unique identifier of the 'parent (top)' topological entity in the new 'auxiliary raw face' 'r3' is "<<r3.getCIndex()<<"."<<endl;
	cout<<"\tThe reverse index of the 'child cell' in the new 'auxiliary raw face' 'r3' is "<<r3.getCReverseIndex()<<"."<<endl;
	cout<<"\tThe indices to the vertices in the 'indexed representation' of the new 'auxiliary raw face' 'r3' are: ";
	if(r3.getCVertices().empty()) cout<<"none."<<endl;
	else Mangrove_exportHybrid(r3.getCVertices());
	cout<<"\tThe current hashing value of the new 'auxiliary raw face' 'r3' is "<<r3.getHashingValue()<<"."<<endl<<endl;
	if(Mangrove_same_faces(*r2,r3)) 
		cout<<"\tThe 'auxiliary raw faces' 'r2' and 'r3' are 'the same', and the indices to the vertices in their indexed representations coincide position by position (with respect to the 'mangrove_tds::Mangrove_same_faces()' function)."<<endl;
	else cout<<"\tThe 'auxiliary raw faces' 'r2' and 'r3' are not 'the same', and the indices to the vertices in their indexed representations do not coincide position by position (with respect to the 'mangrove_tds::Mangrove_same_faces()' function)."<<endl;
	if(Mangrove_same_faces_with_hashing(*r2,r3)) cout<<"\tThe 'auxiliary raw faces' 'r2' and 'r3' are 'the same', and their hashing values coincide (with respect to the 'mangrove_tds::Mangrove_same_faces_with_hashing()' function)."<<endl<<endl;
	else cout<<"\tThe 'auxiliary raw faces' 'r2' and 'r3' are not 'the same', and their hashing values do not coincide (with respect to the 'mangrove_tds::Mangrove_same_faces_with_hashing()' function)."<<endl<<endl;
	cout.flush();
	Mangrove_pause();
	
	/* TASK #4 - Creating another 'auxiliary raw face' 'r4' to be compared with the existing 'auxiliary raw faces'. */
	cout<<"\tCreating another 'auxiliary raw face' 'r4' ... ";
	Mangrove_AuxiliaryRawFace r4;
	cout<<"ok"<<endl;
	cout<<"\tSaving the indices to the vertices in the indexed representation of the 'auxiliary raw face' 'r3' in the indexed representation of the 'auxiliary raw face' 'r4' ... ";
	for(auto it : r3.getCVertices() ) r4.getVertices().push_back(it);
	cout<<"ok"<<endl<<"\tThe indices to the vertices in the 'indexed representation' of the new 'auxiliary raw face' 'r3' are: ";
	if(r3.getCVertices().empty()) cout<<"none."<<endl;
	else Mangrove_exportHybrid(r3.getCVertices());
	cout<<"\tThe indices to the vertices in the 'indexed representation' of the new 'auxiliary raw face' 'r4' are: ";
	if(r4.getCVertices().empty()) cout<<"none."<<endl;
	else Mangrove_exportHybrid(r4.getCVertices());
	cout<<endl;
	if(Mangrove_same_faces(r3,r4)) 
		cout<<"\tThe 'auxiliary raw faces' 'r3' and 'r4' are 'the same', and the indices to the vertices in their indexed representations coincide position by position (with respect to the 'mangrove_tds::Mangrove_same_faces()' function)."<<endl;
	else cout<<"\tThe 'auxiliary raw faces' 'r3' and 'r4' are not 'the same', and the indices to the vertices in their indexed representations do not coincide position by position (with respect to the 'mangrove_tds::Mangrove_same_faces()' function)."<<endl;
	if(Mangrove_compare_faces(r3,r4)) cout<<"\tThe 'auxiliary raw face' 'r3' is 'strictly less than' the 'auxiliary raw face' 'r4' (with respect to the 'mangrove_tds::Mangrove_compare_faces()' function)."<<endl;
	else cout<<"\tThe 'auxiliary raw face' 'r3' is not 'strictly less than' the 'auxiliary raw face' 'r4' (with respect to the 'mangrove_tds::Mangrove_compare_faces()' function)."<<endl;
	if(Mangrove_compare_faces(r4,r3)) cout<<"\tThe 'auxiliary raw face' 'r4' is 'strictly less than' the 'auxiliary raw face' 'r3' (with respect to the 'mangrove_tds::Mangrove_compare_faces()' function)."<<endl;
	else cout<<"\tThe 'auxiliary raw face' 'r4' is not 'strictly less than' the 'auxiliary raw face' 'r3' (with respect to the 'mangrove_tds::Mangrove_compare_faces()' function)."<<endl;
	cout<<endl;
	cout<<"\tInstead, the hashing value of the 'auxiliary raw face' 'r4' is not initially updated."<<endl<<endl;
	cout<<"\tThe current hashing value of the new 'auxiliary raw face' 'r3' is "<<r3.getHashingValue()<<"."<<endl;
	cout<<"\tThe current hashing value of the new 'auxiliary raw face' 'r4' is "<<r4.getHashingValue()<<"."<<endl<<endl;
	if(Mangrove_same_faces_with_hashing(r3,r4)) cout<<"\tThe 'auxiliary raw faces' 'r3' and 'r4' are 'the same', and their hashing values coincide (with respect to the 'mangrove_tds::Mangrove_same_faces_with_hashing()' function)."<<endl;
	else cout<<"\tThe 'auxiliary raw faces' 'r3' and 'r4' are not 'the same', and their hashing values do not coincide (with respect to the 'mangrove_tds::Mangrove_same_faces_with_hashing()' function)."<<endl;
	if(Mangrove_compare_faces_with_hashing(r3,r4)) cout<<"\tThe 'auxiliary raw face' 'r3' is 'strictly less than' the 'auxiliary raw face' 'r4' (with respect to the 'mangrove_tds::Mangrove_compare_faces_with_hashing()' function)."<<endl;
	else cout<<"\tThe 'auxiliary raw face' 'r3' is not 'strictly less than' the 'auxiliary raw face' 'r4' (with respect to the 'mangrove_tds::Mangrove_compare_faces_with_hashing()' function)."<<endl;
	if(Mangrove_compare_faces_with_hashing(r4,r3)) cout<<"\tThe 'auxiliary raw face' 'r4' is 'strictly less than' the 'auxiliary raw face' 'r3' (with respect to the 'mangrove_tds::Mangrove_compare_faces_with_hashing()' function)."<<endl;
	else cout<<"\tThe 'auxiliary raw face' 'r4' is not 'strictly less than' the 'auxiliary raw face' 'r3' (with respect to the 'mangrove_tds::Mangrove_compare_faces_with_hashing()' function)."<<endl;
	cout<<endl;
	Mangrove_pause();
	
	/* TASK #5 - modifying the content of the 'auxiliary raw faces' 'r3' and 'r4' in order to be compared. */
	cout<<"\tModifying the internal states of the 'auxiliary raw faces' 'r3' and 'r4' ... ";
	r3.clear();
	r4.clear();
	r3.getVertices()={4,2,3};
	r4.getVertices()={4,2,2};  //{2,1,4};
	cout<<"ok"<<endl;
	cout<<"\tThe indices to the vertices in the 'indexed representation' of the new 'auxiliary raw face' 'r3' are: ";
	if(r3.getCVertices().empty()) cout<<"none."<<endl;
	else Mangrove_exportHybrid(r3.getCVertices());
	cout<<"\tThe indices to the vertices in the 'indexed representation' of the new 'auxiliary raw face' 'r4' are: ";
	if(r4.getCVertices().empty()) cout<<"none."<<endl;
	else Mangrove_exportHybrid(r4.getCVertices());
	cout<<endl;
	if(Mangrove_same_faces(r3,r4)) 
		cout<<"\tThe 'auxiliary raw faces' 'r3' and 'r4' are 'the same', and the indices to the vertices in their indexed representations coincide position by position (with respect to the 'mangrove_tds::Mangrove_same_faces()' function)."<<endl;
	else cout<<"\tThe 'auxiliary raw faces' 'r3' and 'r4' are not 'the same', and the indices to the vertices in their indexed representations do not coincide position by position (with respect to the 'mangrove_tds::Mangrove_same_faces()' function)."<<endl;
	if(Mangrove_compare_faces(r3,r4)) cout<<"\tThe 'auxiliary raw face' 'r3' is 'strictly less than' the 'auxiliary raw face' 'r4' (with respect to the 'mangrove_tds::Mangrove_compare_faces()' function)."<<endl;
	else cout<<"\tThe 'auxiliary raw face' 'r3' is not 'strictly less than' the 'auxiliary raw face' 'r4' (with respect to the 'mangrove_tds::Mangrove_compare_faces()' function)."<<endl;
	if(Mangrove_compare_faces(r4,r3)) cout<<"\tThe 'auxiliary raw face' 'r4' is 'strictly less than' the 'auxiliary raw face' 'r3' (with respect to the 'mangrove_tds::Mangrove_compare_faces()' function)."<<endl;
	else cout<<"\tThe 'auxiliary raw face' 'r4' is not 'strictly less than' the 'auxiliary raw face' 'r3' (with respect to the 'mangrove_tds::Mangrove_compare_faces()' function)."<<endl;
	cout<<endl;
	cout<<"\tHere, the hashing values of the 'auxiliary raw faces' 'r3' and 'r4' are not initialized."<<endl<<endl;
	cout<<"\tThe current hashing value of the new 'auxiliary raw face' 'r3' is "<<r3.getHashingValue()<<"."<<endl;
	cout<<"\tThe current hashing value of the new 'auxiliary raw face' 'r4' is "<<r4.getHashingValue()<<"."<<endl<<endl;
	if(Mangrove_same_faces_with_hashing(r3,r4)) cout<<"\tThe 'auxiliary raw faces' 'r3' and 'r4' are 'the same', and their hashing values coincide (with respect to the 'mangrove_tds::Mangrove_same_faces_with_hashing()' function)."<<endl;
	else cout<<"\tThe 'auxiliary raw faces' 'r3' and 'r4' are not 'the same', and their hashing values do not coincide (with respect to the 'mangrove_tds::Mangrove_same_faces_with_hashing()' function)."<<endl;
	if(Mangrove_compare_faces_with_hashing(r3,r4)) cout<<"\tThe 'auxiliary raw face' 'r3' is 'strictly less than' the 'auxiliary raw face' 'r4' (with respect to the 'mangrove_tds::Mangrove_compare_faces_with_hashing()' function)."<<endl;
	else cout<<"\tThe 'auxiliary raw face' 'r3' is not 'strictly less than' the 'auxiliary raw face' 'r4' (with respect to the 'mangrove_tds::Mangrove_compare_faces_with_hashing()' function)."<<endl;
	if(Mangrove_compare_faces_with_hashing(r4,r3)) cout<<"\tThe 'auxiliary raw face' 'r4' is 'strictly less than' the 'auxiliary raw face' 'r3' (with respect to the 'mangrove_tds::Mangrove_compare_faces_with_hashing()' function)."<<endl;
	else cout<<"\tThe 'auxiliary raw face' 'r4' is not 'strictly less than' the 'auxiliary raw face' 'r3' (with respect to the 'mangrove_tds::Mangrove_compare_faces_with_hashing()' function)."<<endl;
	cout<<endl;
	Mangrove_pause();
	
	/* TASK #6 - updating also the hashing values for the 'auxiliary raw faces' 'r3' and 'r4' in order to be compared. */
	cout<<"\tUpdating also the hashing values for the 'auxiliary raw faces' 'r3' and 'r4' ... ";
	r3.updateHashingValue();
	r4.updateHashingValue();
	cout<<"ok"<<endl;
	cout<<"\tThe current hashing value of the new 'auxiliary raw face' 'r3' is "<<r3.getHashingValue()<<"."<<endl;
	cout<<"\tThe current hashing value of the new 'auxiliary raw face' 'r4' is "<<r4.getHashingValue()<<"."<<endl<<endl;
	if(Mangrove_same_faces_with_hashing(r3,r4)) cout<<"\tThe 'auxiliary raw faces' 'r3' and 'r4' are 'the same', and their hashing values coincide (with respect to the 'mangrove_tds::Mangrove_same_faces_with_hashing()' function)."<<endl;
	else cout<<"\tThe 'auxiliary raw faces' 'r3' and 'r4' are not 'the same', and their hashing values do not coincide (with respect to the 'mangrove_tds::Mangrove_same_faces_with_hashing()' function)."<<endl;
	if(Mangrove_compare_faces_with_hashing(r3,r4)) cout<<"\tThe 'auxiliary raw face' 'r3' is 'strictly less than' the 'auxiliary raw face' 'r4' (with respect to the 'mangrove_tds::Mangrove_compare_faces_with_hashing()' function)."<<endl;
	else cout<<"\tThe 'auxiliary raw face' 'r3' is not 'strictly less than' the 'auxiliary raw face' 'r4' (with respect to the 'mangrove_tds::Mangrove_compare_faces_with_hashing()' function)."<<endl;
	if(Mangrove_compare_faces_with_hashing(r4,r3)) cout<<"\tThe 'auxiliary raw face' 'r4' is 'strictly less than' the 'auxiliary raw face' 'r3' (with respect to the 'mangrove_tds::Mangrove_compare_faces_with_hashing()' function)."<<endl;
	else cout<<"\tThe 'auxiliary raw face' 'r4' is not 'strictly less than' the 'auxiliary raw face' 'r3' (with respect to the 'mangrove_tds::Mangrove_compare_faces_with_hashing()' function)."<<endl;
	cout<<endl;
	Mangrove_pause();
	
	/* TASK #7 - deallocating all 'auxiliary raw faces'. */
	cout<<"\tDeallocating all 'auxiliary raw faces' in this tutorial ... ";
	cout.flush();
	r1.clear();
	if(checkPointerValidity(r2)) delete r2;
	r2=nullptr;
	r3.clear();
	r4.clear();
	cout<<"ok"<<endl<<endl;
	cout.flush();
	return EXIT_SUCCESS;
}
