#include <ap_int.h>
#include <iostream>


void comparator(
		bool a0,
		bool a1,
		bool a2,
		bool a3,

		bool b0,
		bool b1,
		bool b2,
		bool b3,

		bool &M,
		bool &N,
		bool &P
		);

void comparator_sw( ap_uint<4> a, ap_uint<4> b, bool &m_sw, bool &n_sw, bool &p_sw) {
	if (a == b) {
		m_sw = 1;
		n_sw = 0;
		p_sw = 0;
	}

	if (a > b) {
		m_sw = 0;
		n_sw = 1;
		p_sw = 0;
	}


	if (a < b) {
		m_sw = 0;
		n_sw = 0;
		p_sw = 1;
	}

}
int main() {

	int status = 0;

	ap_uint<4> a;
	ap_uint<4> b;

	bool a0, a1, a2, a3;
	bool b0, b1, b2, b3;

	bool m_hw, n_hw, p_hw;
	bool m_sw, n_sw, p_sw;

	for (int i = 0; (i < 16) && (status == 0) ; i++) {
		for (int j = 0; (j < 16) && (status == 0); j++) {

			a0 = a[0];
			a1 = a[1];
			a2 = a[2];
			a3 = a[3];

			b0 = b[0];
			b1 = b[1];
			b2 = b[2];
			b3 = b[3];

			comparator( a0, a1, a2, a3, b0, b1, b2, b3, m_hw, n_hw, p_hw);
			comparator_sw( a, b, m_sw, n_sw, p_sw);

			if ( (m_hw != m_sw) || (n_hw != n_sw) || (p_hw != p_sw) ){
				status = -1;
				std::cout << " Error at "
						  << " a = " << a
						  << " b = " << b
						  << " m_hw = " << m_hw << "m_sw = " << m_sw
						  << " n_hw = " << n_hw << "n_sw = " << n_sw
						  << " p_hw = " << p_hw << "p_sw = " << p_sw
						  << std::endl;
			}

		}
	}


	if (status == 0 ) {
		std::cout << "OK " << std::endl;
	} else {
		std::cout << "Error " << std::endl;
	}

	return status;
}
