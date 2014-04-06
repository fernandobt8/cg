/*
 * OnOkTransformcaoEvent.h
 *
 *  Created on: 06/04/2014
 *      Author: fernandobt8
 */

#ifndef ONOKTRANSFORMCAOEVENT_H_
#define ONOKTRANSFORMCAOEVENT_H_
#include <list>
#include "../dto/transformacao/Transformacao.h"

using namespace std;

class OnOkTransformcaoEvent {
public:
	virtual void onOkTransformacaoClick(list<Transformacao* >* transformacoes) = 0;
};

#endif /* ONOKTRANSFORMCAOEVENT_H_ */

