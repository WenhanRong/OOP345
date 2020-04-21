/*************************************************************************
// OOP345SFF Workshop 3 in lab
// File: LVPair.h
// Version: 1
// Date: 2019-02-07
// Author: Alisa Tam
// Description: Header file for LVPair
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/


#ifndef SICT_LVPAIR_H
#define SICT_LVPAIR_H

namespace sict {
	template <typename L, typename V >
	class LVPair {
	private:
		L l;
		V v;

	public:
		LVPair();
		LVPair(const L & l, const V & v);
		std::ostream& display(std::ostream & os) const;


	};

	template <typename L, typename V>
	std::ostream& operator<<(std::ostream & os, const LVPair<L, V>& pair)
	{
		return pair.display(os);

	}

	template <typename L, typename V >
	inline LVPair<L, V>::LVPair()
	{

	}

	template <typename L, typename V >
	inline LVPair<L, V>::LVPair(const L & l, const V & v)
	{
		this->l = l;
		this->v = v;
	}

	template<typename L, typename V>
	inline std::ostream& LVPair<L, V>::display(std::ostream & os) const
	{
		return os << this->l << " : " << this->v << std::endl;

	}

}

#endif