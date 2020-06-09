#include "./colecciones/ColMozos.h"


class Sistema {
	private:
		static Sistema* instancia;
		Sistema();
		ColMozos* mozos;
	public:
		static Sistema* getInstancia();
		ColMozos* getMozos();
		virtual ~Sistema();
};
