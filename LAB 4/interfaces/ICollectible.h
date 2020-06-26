#include<stdio.h>
#include<iostream>

#ifndef _ICOLLECTIBLE_H
#define	_ICOLLECTIBLE_H



class ICollectible{
	protected:
	    /*
	     * No se permite instanciar ICollectible directamente
	     */
	    ICollectible();
	public:
	    virtual ~ICollectible();
};
 
#endif
