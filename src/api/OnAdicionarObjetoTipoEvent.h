/*
 * ObjetoGeometrico.h
 *
 *  Created on: 24/03/2014
 *      Author: fernandobt8
 */

#ifndef ONADICIONAROBJETOTIPOEVENT_H_
#define ONADICIONAROBJETOTIPOEVENT_H_

class OnAdicionarObjetoTipoEvent {
public:
	virtual void OnAdicionarObjetoTipoClick(class ObjetoGeometrico *objeto) = 0;
};
#endif /* OBJETOGEOMETRICO_H_ */
