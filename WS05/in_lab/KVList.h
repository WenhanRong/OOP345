#ifndef SICT_LIST_H
#define SICT_LIST_H

namespace sict {
	template <typename T>
	class KVList {
	private:
		T * m_list;
		size_t m_size = 0;
		size_t m_used = 0;
	public:
		KVList() {
			m_list = nullptr;
			m_size = 0;
		}
		KVList(int n) : KVList() {
			
			if (n < 0) {

				throw std::string("Negative Number");
			}
			
			m_list = new(std::nothrow) T[n];

			if (m_list == nullptr) {
				return;
			}

			m_size = n;

			
		}

		KVList(KVList&& list) : KVList() {
			
			std::swap(m_list, list.m_list);
			std::swap(m_size, list.m_size);
			std::swap(m_used, list.m_used);
	}
		~KVList() {
			delete[] m_list;
		}

		const T & operator[](size_t i)const {
			
			if (i < m_used) {
				throw std::string("[] not available");
			}
			return m_list[i];
		}

		template<typename F>
		void display(std::ostream & os, F f) const {

			if (this->m_list == nullptr) {
				return;
			}
			for (size_t i = 0; i < m_used; i++) {
				m_list[i].display(os, f);
			}
			
		}

		void push_back(const T & t) {
			if (m_list == nullptr) {
				return;
			}

			if (m_used == m_size) {
				return;
			}

			m_list[m_used] = t;
			
			m_used++;

	}


	};
}

#endif

