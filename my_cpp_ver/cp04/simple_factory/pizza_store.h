#ifndef _PIZZA_STORE_H_
#define _PIZZA_STORE_H_
#include "pizza.h"
#include "simple_pizza_factory.h"
namespace pizza{
	class pizza_store
	{
	public:
		pizza_store(simple_pizza_factory *spf){
			this->simplepf = spf;
		}
		~pizza_store(){}
		pizza *order_pizza(string type){
			pizza *pi = simplepf->create_pizza(type);
			if(pi == NULL){
				return NULL;
			}
			pi->prepare();
			pi->bake();
			pi->cut();
			pi->box();

			return pi;
		}
	private:
		simple_pizza_factory *simplepf;
	};
}
#endif
