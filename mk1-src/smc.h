/* sd2snes - SD card based universal cartridge for the SNES
   Copyright (C) 2009-2010 Maximilian Rehkopf <otakon@gmx.net>
   AVR firmware portion

   Inspired by and based on code from sd2iec, written by Ingo Korb et al.
   See sdcard.c|h, config.h.

   FAT file system access based on code by ChaN, Jim Brain, Ingo Korb,
   see ff.c|h.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License only.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

   smc.h: SMC file structures
*/

#ifndef SMC_H
#define SMC_H

typedef struct _snes_header {
	uint8_t maker[2];		// 0xB0
	uint8_t gamecode[4];	// 0xB2
	uint8_t fixed_00[7];	// 0xB6
	uint8_t expramsize;		// 0xBD
	uint8_t specver;		// 0xBE
	uint8_t carttype2; 		// 0xBF
	uint8_t name[21];		// 0xC0
	uint8_t map;			// 0xD5
	uint8_t carttype;		// 0xD6
	uint8_t romsize;		// 0xD7
	uint8_t ramsize;		// 0xD8
	uint8_t destcode;		// 0xD9
	uint8_t fixed_33;		// 0xDA
	uint8_t ver;			// 0xDB
	uint16_t cchk;			// 0xDC
	uint16_t chk;			// 0xDE
} snes_header_t;

typedef struct _snes_romprops {
	uint16_t offset;			// start of actual ROM image
	uint8_t mapper_id;			// FPGA mapper
	uint8_t pad1;				// for alignment
	uint32_t expramsize_bytes;	// ExpRAM size in bytes
	uint32_t ramsize_bytes;		// CartRAM size in bytes
	uint32_t romsize_bytes;		// ROM size in bytes (rounded up)
	snes_header_t header;		// original header from ROM image
} snes_romprops_t;

void smc_id(snes_romprops_t*);
uint8_t smc_headerscore(snes_header_t*);

#endif
