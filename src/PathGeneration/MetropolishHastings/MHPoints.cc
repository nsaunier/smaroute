/*
 * MHPoints.cc
 *
 *  Created on: Apr 20, 2012
 *      Author: jchen
 */


#include "MHPoints.h"
//#include "patException.h"
#include <iostream>
MHPoints::MHPoints(int A, int B, int C):
m_A(A),m_B(B),m_C(C){
//	if(m_A>m_B or m_B > m_C){
//		stringstream ss;
//		ss<<"wrong points combination"<<m_A<<","<<m_B<<","<<m_C;
//		throw RuntimeException(ss.str().c_str());
//	}

}MHPoints::MHPoints(){
    
}
int MHPoints::getA() const
{
	return m_A;
}

int MHPoints::getB() const
{
	return m_B;
}
int MHPoints::getC() const
{
	return m_C;
}

bool operator==(const MHPoints& lhs, const MHPoints& rhs)
{
	if (lhs.getA()==rhs.getA() && lhs.getB()==rhs.getB() && lhs.getC()==rhs.getC()){
		return true;
	}
	else{
		return false;
	}
}


ostream& operator<<(ostream& str, const MHPoints& x) {
	str << x.getA()<<","<<x.getB()<<","<<x.getC();
	return str;
}
