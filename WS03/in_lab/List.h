
/*************************************************************************
// OOP345SFF Workshop 3 in lab
// File: List.h
// Version: 1
// Date: 2019-02-07
// Author: Alisa Tam
// Description: Header file for List
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019-01-15      created empty file for workshop
*************************************************************************/
#ifndef SICT_LIST_H
#define SICT_LIST_H



namespace sict {

	template<class T, size_t N>
	class List {
	private:
		size_t m_cnt;
		T array[N];

	public:
		List();
		size_t size() const;
		const T & operator[](size_t i) const;
		void operator+=(const T & t);
	};

	template<class T, size_t N>
	inline List<T, N>::List()
	{
		m_cnt = 0;

	}

	template<class T, size_t N>
	inline size_t List<T, N>::size() const
	{
		return m_cnt;
	}

	template<class T, size_t N>
	inline const T & List<T, N>::operator[](size_t i) const
	{

		return array[i];
	}

	template<class T, size_t N>
	inline void List<T, N>::operator+=(const T & t)
	{
		if (m_cnt >= N) {
			return;
		}

		array[m_cnt++] = t;
	}

}


#endif