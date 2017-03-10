/*
 * HandlerBox.h
 *
 *  Created on: Mar 9, 2017
 *      Author: moonfinger
 */

#ifndef ISOBMFF_HANDLERBOX_H_
#define ISOBMFF_HANDLERBOX_H_

#include <iostream>
#include <stdint.h>

#include "FullBox.h"

using namespace std;

class HandlerBox : public FullBox {
public:
	HandlerBox();
	virtual ~HandlerBox();

public:
	void Read(uint8_t *buf, int32_t len);

public:
	uint32_t  GetPreDefined();
	uint32_t  GetHandlerType();
	uint32_t* GetReserved0();
	string    GetName();

private:
	uint32_t m_pre_defined;
	uint32_t m_handler_type;
	uint32_t m_reserved_0[3];
	string   m_name;
};

#endif /* ISOBMFF_HANDLERBOX_H_ */
