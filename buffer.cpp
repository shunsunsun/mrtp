/*
 *  Mrtp: A simple raytracing tool.
 *  Copyright (C) 2017  Mikolaj Feliks <mikolaj.feliks@gmail.com>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#include "buffer.hpp"


unsigned char font[] = {
0x00 ,  0x00 ,  0x00 ,  0x00 ,  0x00 ,  0x00 ,  0x00 ,  0x00 ,  0x18 ,  0x18 ,  0x18 ,  0x18 ,  0x08 ,  
0x00 ,  0x18 ,  0x00 ,  0x28 ,  0x28 ,  0x28 ,  0x00 ,  0x00 ,  0x00 ,  0x00 ,  0x00 ,  0x28 ,  0x7c ,  
0x28 ,  0x28 ,  0x28 ,  0x7c ,  0x28 ,  0x00 ,  0x10 ,  0x7e ,  0x40 ,  0x7e ,  0x86 ,  0xfe ,  0x10 ,  
0x00 ,  0xe2 ,  0xa4 ,  0xe8 ,  0x10 ,  0x2e ,  0x4a ,  0x8e ,  0x00 ,  0x38 ,  0x28 ,  0x7c ,  0x44 ,  
0xc4 ,  0xce ,  0xfc ,  0x00 ,  0x10 ,  0x10 ,  0x10 ,  0x00 ,  0x00 ,  0x00 ,  0x00 ,  0x00 ,  0x02 ,  
0x04 ,  0x0c ,  0x08 ,  0x0c ,  0x04 ,  0x02 ,  0x00 ,  0x80 ,  0x40 ,  0x60 ,  0x20 ,  0x60 ,  0x40 ,  
0x80 ,  0x00 ,  0x00 ,  0x54 ,  0x38 ,  0x6c ,  0x38 ,  0x54 ,  0x00 ,  0x00 ,  0x00 ,  0x10 ,  0x10 ,  
0x7c ,  0x10 ,  0x10 ,  0x00 ,  0x00 ,  0x00 ,  0x00 ,  0x00 ,  0x00 ,  0x00 ,  0x18 ,  0x08 ,  0x00 ,  
0x00 ,  0x00 ,  0x00 ,  0x38 ,  0x00 ,  0x00 ,  0x00 ,  0x00 ,  0x00 ,  0x00 ,  0x00 ,  0x00 ,  0x00 ,  
0x00 ,  0x18 ,  0x00 ,  0x04 ,  0x04 ,  0x08 ,  0x10 ,  0x20 ,  0x40 ,  0x40 ,  0x00 ,  0x7e ,  0x42 ,  
0x42 ,  0xc2 ,  0xc6 ,  0xc6 ,  0xfe ,  0x00 ,  0x38 ,  0x00 ,  0x08 ,  0x18 ,  0x18 ,  0x18 ,  0x18 ,  
0x00 ,  0x7c ,  0x04 ,  0x7c ,  0xc0 ,  0xc0 ,  0xc6 ,  0xfe ,  0x00 ,  0x7e ,  0x02 ,  0x1e ,  0x06 ,  
0x06 ,  0xc6 ,  0xfe ,  0x00 ,  0x26 ,  0x22 ,  0x3e ,  0x06 ,  0x06 ,  0x06 ,  0x06 ,  0x00 ,  0x7c ,  
0x40 ,  0x7c ,  0x06 ,  0x06 ,  0xc6 ,  0xfe ,  0x00 ,  0x78 ,  0x40 ,  0x7e ,  0x46 ,  0xc6 ,  0xc6 ,  
0xfe ,  0x00 ,  0xfe ,  0x86 ,  0x0c ,  0x0c ,  0x18 ,  0x18 ,  0x18 ,  0x00 ,  0x3c ,  0x24 ,  0x7e ,  
0x42 ,  0xc2 ,  0xc6 ,  0xfe ,  0x00 ,  0x7e ,  0x42 ,  0x7e ,  0x02 ,  0x06 ,  0xc6 ,  0xfe ,  0x00 ,  
0x00 ,  0x00 ,  0x18 ,  0x00 ,  0x18 ,  0x00 ,  0x00 ,  0x00 ,  0x00 ,  0x00 ,  0x18 ,  0x00 ,  0x18 ,  
0x08 ,  0x00 ,  0x00 ,  0x0c ,  0x18 ,  0x30 ,  0x60 ,  0x30 ,  0x18 ,  0x0c ,  0x00 ,  0x00 ,  0x00 ,  
0x7c ,  0x00 ,  0x7c ,  0x00 ,  0x00 ,  0x00 ,  0x60 ,  0x30 ,  0x18 ,  0x0c ,  0x18 ,  0x30 ,  0x60 ,  
0x00 ,  0x1c ,  0x36 ,  0x66 ,  0x0c ,  0x18 ,  0x00 ,  0x18 ,  0x00 ,  0x7c ,  0x42 ,  0x1a ,  0x2a ,  
0x2a ,  0x2a ,  0x1c ,  0x00 ,  0x3c ,  0x26 ,  0x7e ,  0x42 ,  0xc2 ,  0xc6 ,  0xc6 ,  0x00 ,  0x78 ,  
0x4c ,  0x78 ,  0xcc ,  0xc6 ,  0xc6 ,  0xfc ,  0x00 ,  0x7e ,  0x42 ,  0xc0 ,  0xc0 ,  0xc0 ,  0xc6 ,  
0xfe ,  0x00 ,  0x78 ,  0x4c ,  0x42 ,  0xc2 ,  0xc6 ,  0xce ,  0xfc ,  0x00 ,  0x7e ,  0x42 ,  0x40 ,  
0xf0 ,  0xc0 ,  0xc6 ,  0xfe ,  0x00 ,  0x7e ,  0x42 ,  0x40 ,  0xf0 ,  0xc0 ,  0xc0 ,  0xc0 ,  0x00 ,  
0x7e ,  0x46 ,  0x40 ,  0xc0 ,  0xce ,  0xc6 ,  0xfe ,  0x00 ,  0x42 ,  0x42 ,  0x7e ,  0xc2 ,  0xc2 ,  
0xc2 ,  0xc6 ,  0x00 ,  0x08 ,  0x08 ,  0x08 ,  0x18 ,  0x18 ,  0x18 ,  0x18 ,  0x00 ,  0x02 ,  0x06 ,  
0x06 ,  0x06 ,  0xc6 ,  0xc6 ,  0xfe ,  0x00 ,  0x48 ,  0x50 ,  0x70 ,  0xd8 ,  0xcc ,  0xc6 ,  0xc6 ,  
0x00 ,  0x40 ,  0x40 ,  0x40 ,  0xc0 ,  0xc0 ,  0xc6 ,  0xfe ,  0x00 ,  0x42 ,  0x66 ,  0x7e ,  0xda ,  
0xc2 ,  0xc2 ,  0xc6 ,  0x00 ,  0x62 ,  0x62 ,  0x52 ,  0xda ,  0xce ,  0xc6 ,  0xc6 ,  0x00 ,  0x7e ,  
0x42 ,  0x42 ,  0xc2 ,  0xc6 ,  0xc6 ,  0xfe ,  0x00 ,  0x7c ,  0x42 ,  0x42 ,  0xfc ,  0xc0 ,  0xc0 ,  
0xc0 ,  0x00 ,  0x7e ,  0x42 ,  0x42 ,  0xc2 ,  0xce ,  0xc6 ,  0xfe ,  0x00 ,  0x7c ,  0x46 ,  0x7c ,  
0xd8 ,  0xc8 ,  0xce ,  0xc6 ,  0x00 ,  0x7e ,  0x40 ,  0x7e ,  0x06 ,  0x06 ,  0xc6 ,  0xfe ,  0x00 ,  
0x7e ,  0x08 ,  0x08 ,  0x18 ,  0x18 ,  0x18 ,  0x18 ,  0x00 ,  0x46 ,  0x46 ,  0xc2 ,  0xc2 ,  0xc2 ,  
0xc2 ,  0xfe ,  0x00 ,  0x46 ,  0x46 ,  0x62 ,  0x32 ,  0x36 ,  0x1c ,  0x1c ,  0x00 ,  0x46 ,  0x46 ,  
0xc2 ,  0xd2 ,  0xfe ,  0xee ,  0xc6 ,  0x00 ,  0xc6 ,  0x6c ,  0x38 ,  0x10 ,  0x38 ,  0x6c ,  0xc6 ,  
0x00 ,  0x46 ,  0x46 ,  0x7c ,  0x38 ,  0x18 ,  0x18 ,  0x18 ,  0x00 ,  0x7e ,  0x06 ,  0x3c ,  0x30 ,  
0xe0 ,  0xe6 ,  0xfe ,  0x00 ,  0x38 ,  0x20 ,  0x20 ,  0x20 ,  0x20 ,  0x20 ,  0x38 ,  0x00 ,  0x40 ,  
0x40 ,  0x20 ,  0x10 ,  0x08 ,  0x04 ,  0x04 ,  0x00 ,  0x38 ,  0x08 ,  0x08 ,  0x08 ,  0x08 ,  0x08 ,  
0x38 ,  0x00 ,  0x10 ,  0x28 ,  0x28 ,  0x00 ,  0x00 ,  0x00 ,  0x00 ,  0x00 ,  0x00 ,  0x00 ,  0x00 ,  
0x00 ,  0x00 ,  0x00 ,  0xfe ,  0x00 ,  0xff ,  0xff ,  0xff ,  0xff ,  0xff ,  0xff ,  0xff ,  0xff , 
0x00 };


Buffer::Buffer (unsigned int w,
        unsigned int h) {
    size_t size = (size_t) (w * h);
    data   = new Color [size];
    width  = w;
    heigth = h;
}

Buffer::~Buffer () {
    delete[] data;
}

Color *Buffer::GetPointer () {
    return &data[0];
}

void Buffer::Clear () {
    unsigned int i;
    Color *bp;

    bp = &data[0];
    for (i = 0; i < width * heigth; i++) {
        bp->Set (0., 0., 0.);
        bp++;
    }
}

void Buffer::WriteToPNG (char *filename) {
    png::image< png::rgb_pixel > image (width, heigth);
    rgb_pixel *pixel;
    unsigned char r, g, b;
    unsigned int i, j;
    Color *bp;

    bp = &data[0];
    for (i = 0; i < heigth; i++) {
        pixel = &image[i][0];
        for (j = 0; j < width; j++) {
            bp->Convert (&r, &g, &b);
            bp++;
            pixel->red   = r;
            pixel->green = g;
            pixel->blue  = b;
            pixel++;
        }
    }
    image.write (filename);
}

void Buffer::Text (char *text, unsigned int x,
        unsigned int y, Color &color) {
    unsigned char *fp, letter, idx, byte;
    char *tp;
    Color *bp, *sav;
    int row, col;

    tp = &text[0];
    bp = &data[x + y * width];

    while (*tp != 0) {
        letter = *(tp++);
        idx  = (letter - ' ') & 63;
        fp   = &font[idx << 3];
        sav  = bp;

        for (row = 7; row >= 0; row--) {
            byte = *(fp++);
            for (col = 7; col >= 0; col--) {
                if ((byte >> col) & 1)
                    color.CopyTo (bp);
                bp++;
            }
            bp += (width - 8);
        }
        bp = sav + 8;
    }
}
