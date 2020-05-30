#include <cstdlib>
#include <iostream>
#include "setint.h"
using namespace std;

int main(int argc, char *argv[]){
	int nums[10] = {0,1,2,3,4,5,6,7,8,9};
	
	SetInt *si = new SetInt(nums, 10);
//	SetInt *si = new SetInt();
	
	si->mostrar();
	printf("\n");
	
	
	printf("\n");
	system("PAUSE");
	return 0;
}
