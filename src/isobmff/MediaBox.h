/*
 * MediaBox.h
 *
 *  Created on: Mar 9, 2017
 *      Author: moonfinger
 */

#ifndef ISOBMFF_MEDIABOX_H_
#define ISOBMFF_MEDIABOX_H_

#include <iostream>
#include <stdint.h>

#include "Box.h"
#include "MediaHeaderBox.h"
#include "HandlerBox.h"
#include "MediaInformationBox.h"

using namespace std;

class MediaBox : public Box {
public:
	MediaBox();
	virtual ~MediaBox();

public:
	void Read(uint8_t *buf, int32_t len);

public:
    MediaHeaderBox* GetMediaHeaderBox();
	void SetMediaHeaderbox(MediaHeaderBox* mdhd);
	HandlerBox* GetHandlerBox();
	void SetHandlerBox(HandlerBox* hdlr);
    MediaInformationBox* GetMediaInformationBox();
    void SetMediaInformationBox(MediaInformationBox* minf);

private:
	MediaHeaderBox* m_mdhd;
	HandlerBox* m_hdlr;
	MediaInformationBox* m_minf;
};

#endif /* ISOBMFF_MEDIABOX_H_ */
