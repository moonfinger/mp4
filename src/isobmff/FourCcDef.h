/*
 * FourCcDef.h
 *
 *  Created on: Mar 9, 2017
 *      Author: moonfinger
 */

#ifndef ISOBMFF_FOURCCDEF_H_
#define ISOBMFF_FOURCCDEF_H_

enum {
	// level 1
	box_ftyp = 0x66747970,
	box_pdin = 0x7064696e,
	box_moov = 0x6d6f6f76,
	box_moof = 0x6d6f6f66,
	box_mfra = 0x6d667261,
	box_mdat = 0x6d646174,
	box_free = 0x66726565,
	box_skip = 0x736b6970,
	box_meta = 0x6d657461,
	// level 2
	box_uuid = 0x75756964,
	box_mvhd = 0x6d766864,
	box_trak = 0x7472616b,
	box_mvex = 0x6d766578,
	box_ipmc = 0x69706d63,
	// level 3
	box_tkhd = 0x746b6864,
	box_tref = 0x74726566,
	box_edts = 0x65647473,
	box_mdia = 0x6d646961,
	box_mhed = 0x6d686564,
	box_trex = 0x74726578,
	box_minf = 0x6d696e66,
	// level 4
	box_elst = 0x656c7374,
	box_mdhd = 0x6d646864,
	box_hdlr = 0x68646c72,
	box_vmhd = 0x766d6864,
	box_smhd = 0x736d6864,
	box_hmhd = 0x686d6864,
	box_nmhd = 0x6e6d6864,
	box_dinf = 0x0a64696e,
	box_stbl = 0x7374626c,

	// level 5
	box_dref = 0x64726566,
	box_url  = 0x75726c,
	box_urn  = 0x75726e
};




#endif /* ISOBMFF_FOURCCDEF_H_ */
