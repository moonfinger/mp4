/*
 * SampleTableBox.h
 *
 *  Created on: Mar 10, 2017
 *      Author: moonfinger
 */

#ifndef ISOBMFF_SAMPLETABLEBOX_H_
#define ISOBMFF_SAMPLETABLEBOX_H_

#include <iostream>
#include <stdint.h>

#include "Box.h"
#include "SampleDescriptionBox.h"
#include "MediaInformationBox.h"

class SampleTableBox : public Box {
public:
	SampleTableBox();
	virtual ~SampleTableBox();

public:
	void Read(uint8_t *buf, int32_t len);

private:
	SampleDescriptionBox* m_stsd;

private:
	MediaInformationBox* m_parent;
};

#endif /* ISOBMFF_SAMPLETABLEBOX_H_ */
