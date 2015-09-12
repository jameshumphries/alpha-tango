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
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//RTL-SDR
#include "rtl-sdr.h"


#define SAMPLE_RATE     2000000         //2MHz Sample Rate
#define FREQ            1090000000      //1090MHz Center Frequency

//Radio structure
struct {

    int freq;
    int samp_rate;
    int device_index;
    rtlsdr_dev_t *device;

} radio;

void radioConfig(void) {

    radio.freq = FREQ;
    radio.samp_rate = SAMPLE_RATE;
    radio.device_index = 0; //Select first device if more than one

}

//Initialize RTL-SDR
void initRTLSDR(void) {

    printf("\n");

    int rtlsdr_num_devices;
    int rtlsdr_status;
    char vendor[256], product[256], serial[256];
    //int gains[100];

    rtlsdr_num_devices = rtlsdr_get_device_count();
    

    if(!rtlsdr_num_devices) {
        //If no devices connected, print an error
        printf("Error: No Devices Found!\n");
        
    }

    else {
        //If devices connected, print how many and device information
        printf("Found %d devices!\n", rtlsdr_num_devices);

        //Print out device information
        int j;
        for (j=0; j < rtlsdr_num_devices; j++) {
        
        rtlsdr_get_device_usb_strings(j, vendor, product, serial);
        printf("Device #%d: %s %s, SN: %s\n\n", j, vendor, product, serial);

        }

    }

    //Open the RTLSDR Device
    rtlsdr_status = rtlsdr_open(&radio.device, radio.device_index);
    printf("RTLSDR STATUS: %d\n\n", rtlsdr_status);

    if(rtlsdr_status < 0) {
        fprintf(stderr, "RTL-SDR Could Not be Opened: %s\n", strerror(errno));
    }
    
    //Setup the RTLSDR Device

}

//Initialize USRP
void initUSRP(void) {
    }

int main () {

    //Setup structure for some variables
    

    radioConfig();
    
    initRTLSDR();

    //Close the hardware
    //rtlsdr_close();
    return 0;

    }
