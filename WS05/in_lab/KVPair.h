

#ifndef SICT_KVPAIR_H
#define SICT_FVPAIR_H

#include<ostream>
#include<iomanip>
#include <algorithm>

extern int fieldWidth;
namespace sict {
	

	template<typename K, typename V> // K = KEY, V = VAL
	class KVPair {
	private:
		K m_key;
		V m_value;
		bool m_val = false;
		
	public:
		KVPair() {}
		KVPair(const K & key, const V & val) : m_key(key), m_value(val) { m_val = true; }
		template<typename FUNC>
		void display(std::ostream & os, FUNC f) const {

			if (m_val == false) {
				return;
			}

			os << std::left << std::setw(11) << std::setfill(' ') << this->m_key << ": " << std::right << 
				std::setw(fieldWidth) << this->m_value << std::setw(fieldWidth) << f(m_value) << std::endl; 
		}


	};

	
}

#endif
