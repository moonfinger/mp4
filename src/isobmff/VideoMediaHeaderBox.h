/*
 * VideoMediaHeaderBox.h
 *
 *  Created on: Mar 9, 2017
 *      Author: moonfinger
 */

#ifndef ISOBMFF_VIDEOMEDIAHEADERBOX_H_
#define ISOBMFF_VIDEOMEDIAHEADERBOX_H_

#include <iostream>
#include <stdint.h>

#include "FullBox.h"

using namespace std;

class VideoMediaHeaderBox : public FullBox {
public:
	VideoMediaHeaderBox();
	virtual ~VideoMediaHeaderBox();

public:
	void Read(uint8_t *buf, int32_t len);

public:
	uint16_t  GetGraphicmode();
	uint16_t* GetOpcolor();

private:
	uint16_t m_graphicmode;
	uint16_t m_opcolor[3];
};

#endif /* ISOBMFF_VIDEOMEDIAHEADERBOX_H_ */
