//Function to get Mode-S data from RTL-SDR

//    Get Mode-S data from RTL-SDR
//    Copyright (C) 2015 James 'Trip' Humphries
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License along
//    with this program; if not, write to the Free Software Foundation, Inc.,
//    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.


#include <errno.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//RTL-SDR
#include "rtl-sdr.h"


#define SAMPLE_RATE     2000000         //2MHz Sample Rate
#define FREQ            1090000000      //1090MHz Center Frequency

int main () {

    printf("Testing compiler\n");

    }
