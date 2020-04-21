#ifndef SICT_DATA_TABLE_H
#define SICT_DATA_TABLE_H

#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>

extern int FW;
extern int ND;

namespace sict {

	template<class T>
	class DataTable {
	private:
		using point = std::pair<T, T>;
		std::vector<point>data;

	public:
		DataTable(std::ifstream &f) {
			
			while (!f.eof()) {
				T x, y;
				f >> x >> y;
				if (!f.fail()) {
					data.push_back(std::make_pair(x, y));
				}

			}

		}

		T mean() const {

			T result = std::accumulate(data.begin(), data.end(), (T)0, [](T &acc, const point &p) {return acc + p.second; });
			size_t n = data.size();
			return n ? result / (T)n : (T)0;
		}

		T sigma() const {
			T avg = mean();
			T stdev = std::accumulate(data.begin(), data.end(), (T)0, [avg](T &acc, const point &p) {return acc + std::pow(p.second - avg, 2); });
			size_t n = data.size();
			return n ? std::sqrt(stdev / ((T)n - 1)) : 0;
		}
		
		void displayData(std::ostream& os) const {

			os << "Data Values" << std::endl;
			os << "------------" << std::endl;
			os << std::right << std::setw(FW) << std::fixed << std::setprecision(ND) << "x" << std::setw(FW) << "y" << std::endl;
			for (auto i = data.begin(); i < data.end(); i++) {
				os << std::setw(FW) << i->first << std::setw(FW) << i->second << std::endl;
			}

			os << std::endl;

		}

		void displayStatistics(std::ostream& os) const {

			os << "Statistics" << std::endl;
			os << "----------" << std::endl;
			os << std::left << std::setw(FW) << std::fixed << std::setprecision(ND) << "  y mean" << "    = " << std::setw(FW) << std::right << mean() << std::endl;
			os << std::left << std::setw(FW) << std::fixed << std::setprecision(ND) << "  y sigma" << "   = " << std::setw(FW) << std::right << sigma() << std::endl;
		}
		
	};

}


#endif 
