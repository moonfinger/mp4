/*
 * TrackBox.h
 *
 *  Created on: Mar 9, 2017
 *      Author: moonfinger
 */

#ifndef ISOBMFF_TRACKBOX_H_
#define ISOBMFF_TRACKBOX_H_

#include <iostream>
#include <stdint.h>

#include "Box.h"
//#include "MovieBox.h"

#include "TrackHeaderBox.h"
#include "MediaInformationBox.h"

using namespace std;

class TrackBox : public Box {
public:
	TrackBox();
	virtual ~TrackBox();

public:
	void Read(uint8_t *buf, int32_t len);

public:
	TrackHeaderBox* GetTrackHeaderBox();
    void SetTrackHeaderBox(TrackHeaderBox* tkhd);
//    MediaInformationBox* GetMediaInformationBox();
//    void SetMediaInformationBox(MediaInformationBox* mdia);

private:
	TrackHeaderBox* m_tkhd;
//	MediaInformationBox* m_mdia;

private:
//	MovieBox* m_parent;
};

#endif /* ISOBMFF_TRACKBOX_H_ */
