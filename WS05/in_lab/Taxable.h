#ifndef SICT_TAXABLE_H
#define SICT_TAXABLE_H

namespace sict {
	class Taxable {
	private:
		float rate = 0.0f;
	public:
		inline Taxable() {};
		inline Taxable(const float r) {
			rate = r;
		}

		inline float operator()(float price) {
			return price * (1 + rate);
		}


	};

	
}

#endif
