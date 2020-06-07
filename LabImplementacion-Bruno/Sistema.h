#include "./colecciones/ColMozos.cpp"


class Sistema {
	private:
		static Sistema * instance;
		Sistema();
		ColMozos * mozos;
	public:
		static Sistema * getInstance();
		ColMozos * getMozos();
};
