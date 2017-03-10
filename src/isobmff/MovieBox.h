/*
 * MovieBox.h
 *
 *  Created on: Mar 9, 2017
 *      Author: moonfinger
 */

#ifndef ISOBMFF_MOVIEBOX_H_
#define ISOBMFF_MOVIEBOX_H_

#include <iostream>
#include <vector>
#include <stdint.h>

#include "Box.h"
#include "MovieHeaderBox.h"
#include "TrackBox.h"

using namespace std;

class MovieBox : public Box {
public:
	MovieBox();
	virtual ~MovieBox();

public:
	void Read(uint8_t *buf, int32_t len);

public:
	MovieHeaderBox* GetMoviewHeaderBox();
	void SetMovieHeaderBox(MovieHeaderBox* mvhd);
	vector<TrackBox *> GetTrackBoxList();
	void AddTrackBox(TrackBox* trak);

private:
	MovieHeaderBox*    m_mvhd;			// mandatory, exactly one
	vector<TrackBox *> m_trak_list;		// mandatory, one or more
};

#endif /* ISOBMFF_MOVIEBOX_H_ */
