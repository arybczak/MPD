/* the Music Player Daemon (MPD)
 * Copyright (C) 2003-2007 by Warren Dukes (warren.dukes@gmail.com)
 * This project's homepage is: http://www.musicpd.org
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef DECODE_H
#define DECODE_H

#include "song.h"

#include "audio.h"
#include "notify.h"

#define DECODE_TYPE_FILE	0
#define DECODE_TYPE_URL		1

enum decoder_state {
	DECODE_STATE_STOP = 0,
	DECODE_STATE_START,
	DECODE_STATE_DECODE
};

#define DECODE_ERROR_NOERROR	0
#define DECODE_ERROR_UNKTYPE	10
#define DECODE_ERROR_FILE	20

typedef struct _DecoderControl {
	Notify notify;

	volatile enum decoder_state state;
	volatile mpd_sint8 stop;
	volatile mpd_sint8 start;
	volatile mpd_uint16 error;
	volatile mpd_sint8 seek;
	volatile mpd_sint8 seekError;
	volatile mpd_sint8 seekable;
	volatile double seekWhere;
	AudioFormat audioFormat;
	Song *current_song;
	volatile float totalTime;
} DecoderControl;

void decode(void);

void decoder_wakeup_player(void);

void decoder_sleep(void);

void decoderInit(void);

#endif
