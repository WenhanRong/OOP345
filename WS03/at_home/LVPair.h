/*************************************************************************
// OOP345SFF Workshop 3 at home
// File: LVPair.h
// Version: 1
// Date: 2019-02-13
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
	protected:
		L l;
		V v;

	public:
		LVPair();
		LVPair(const L & l, const V & v);
		virtual void display(std::ostream & os) const;


	};

	template <typename L, typename V>
	std::ostream& operator<<(std::ostream & os, const LVPair<L, V>& pair)
	{
		pair.display(os);
		
		return os;
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
	inline void LVPair<L, V>::display(std::ostream & os) const
	{
		os << this->l << " : " << this->v << std::endl;

	}

	template <typename L, typename V >
	class SummableLVPair : public LVPair<L,V>{
	private:
		static size_t f_width;
		static const V initial;
	public:
		virtual void display(std::ostream & os) const override;
		SummableLVPair();
		SummableLVPair(const L & label, const V & v);
		static const V & getInitialValue();
		V sum(const L & label, const V & sum) const;
	};

	template <typename T, typename V>
	size_t SummableLVPair<T, V>::f_width = 0;

	template<>
	const int SummableLVPair<std::string, int>::initial = 0;


	template<>
	const std::string SummableLVPair<std::string, std::string>::initial = "";

	template<>
	std::string SummableLVPair<std::string, std::string>::sum(const std::string &label, const std::string &sum) const
	{

		if (label == this->l) {
			return sum + " " + v;
		}

		return sum;

	}


	template<typename L, typename V>
	inline void SummableLVPair<L, V>::display(std::ostream & os) const
	{
		os << std::left << std::setw(f_width) << LVPair<L, V>::l << " : " << LVPair<L, V>::v << std::endl;
	}

	
	template<typename L, typename V>
	inline SummableLVPair<L, V>::SummableLVPair()
	{	

	}

	template<typename L, typename V>
	inline SummableLVPair<L, V>::SummableLVPair(const L & label, const V & value) : LVPair<L, V>(label, value)
	{

		if (label.size() > f_width) {
			f_width = label.size();
		}
		
	}

	template<typename L, typename V>
	inline const V & SummableLVPair<L, V>::getInitialValue()
	{

		return initial;
		
	}

	template<typename L, typename V>
	inline V SummableLVPair<L, V>::sum(const L & label, const V & sum) const
	{

		if (label == this->l) {
			return LVPair<L, V>::v + sum;
		}

		return sum;
	
	}

}

#endif