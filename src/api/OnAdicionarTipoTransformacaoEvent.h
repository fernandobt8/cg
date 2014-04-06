/*
 * OnAdicionarTipoTransformacaoEvent.h
 *
 *  Created on: 06/04/2014
 *      Author: fernandobt8
 */

#ifndef ONADICIONARTIPOTRANSFORMACAOEVENT_H_
#define ONADICIONARTIPOTRANSFORMACAOEVENT_H_
#include "../dto/transformacao/Transformacao.h"

class OnAdicionarTipoTransformacaoEvent {
public:
	virtual void onAdicionarTipoTransformacaoClick(Transformacao* transformacao) = 0;
};

#endif /* ONADICIONARTIPOTRANSFORMACAOEVENT_H_ */


