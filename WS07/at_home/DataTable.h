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

		T median() const {
			std::vector<point>newdata = data;
			sort(newdata.begin(), newdata.end(), [](const point &a, const point &b) {return a.second < b.second; });
			size_t n = newdata.size();
			return n ? newdata[n / 2].second : 0;
		}

		void regression(T& slope, T& y_intercept) const {
			T xy = 0;
			T x = 0;
			T y = 0;
			T x2 = 0;

			std::for_each(data.begin(), data.end(), [&](const point &p) {
				xy += p.first * p.second;
				x += p.first;
				y += p.second;
				x2 += std::pow(p.first, 2);
			});

			size_t n = data.size();
			if (n != 0) {
				slope = (n * xy - (x*y)) / (n*x2 - (x*x));
				y_intercept = (y - (slope * x)) / n;
			}

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

			T a, b;
			regression(a, b);

			os << "Statistics" << std::endl;
			os << "----------" << std::endl;
			os << std::left << std::setw(FW) << std::fixed << std::setprecision(ND) << "  y mean" << "    = " << std::setw(FW) << std::right << mean() << std::endl;
			os << std::left << std::setw(FW) << std::fixed << std::setprecision(ND) << "  y sigma" << "   = " << std::setw(FW) << std::right << sigma() << std::endl;
			os << std::left << std::setw(FW) << std::fixed << std::setprecision(ND) << "  y median" << "  = " << std::setw(FW) << std::right << median() << std::endl;
			os << std::left << std::setw(FW) << std::fixed << std::setprecision(ND) << "  slope" << "    = " << std::setw(FW) << std::right << a << std::endl;
			if (b) {
				os << std::left << std::setw(FW) << std::fixed << std::setprecision(ND) << "  intercept" << " = " << std::setw(FW) << std::right << b << std::endl;

			}
		}
		
	};

}


#endif 
