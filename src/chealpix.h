/* -----------------------------------------------------------------------------
 *
 *  Copyright (C) 1997-2016 Krzysztof M. Gorski, Eric Hivon, Martin Reinecke,
 *                          Benjamin D. Wandelt, Anthony J. Banday,
 *                          Matthias Bartelmann,
 *                          Reza Ansari & Kenneth M. Ganga
 *
 *
 *  This file is part of HEALPix.
 *
 *  HEALPix is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  HEALPix is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with HEALPix; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *  For more information about HEALPix see http://healpix.sourceforge.net
 *
 *----------------------------------------------------------------------------*/
/*
 * chealpix.h
 */

#ifndef CHEALPIX_H
#define CHEALPIX_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*! \defgroup chealpix HEALPix C interface
    All angles are in radian, all \a theta values are colatitudes, i.e. counted
    downwards from the North Pole. \a Nside can be any positive number for
    pixelisations in RING scheme; in NEST scheme, they must be powers of 2.
    The maximum \a Nside for the traditional interface is 8192; for the
    64bit interface it is 2^29.
 */
/*! \{ */

/* -------------------- */
/* Constant Definitions */
/* -------------------- */

#ifndef HEALPIX_NULLVAL
#define HEALPIX_NULLVAL (-1.6375e30)
#endif /* HEALPIX_NULLVAL */

/* pixel operations */
/* ---------------- */
/*! Sets \a *ipix to the pixel number in NEST scheme at resolution \a nside,
    which contains the position \a theta, \a phi. */
void ang2pix_nest(long nside, double theta, double phi, long *ipix);
/*! Sets \a *ipix to the pixel number in RING scheme at resolution \a nside,
    which contains the position \a theta, \a phi. */
void ang2pix_ring(long nside, double theta, double phi, long *ipix);

/*! Sets \a theta and \a phi to the angular position of the center of pixel
    \a ipix in NEST scheme at resolution \a nside. */
void pix2ang_nest(long nside, long ipix, double *theta, double *phi);
/*! Sets \a theta and \a phi to the angular position of the center of pixel
    \a ipix in NEST scheme at resolution \a nside. */
void pix2ang_ring(long nside, long ipix, double *theta, double *phi);

/*! Computes the RING pixel index of pixel \a ipnest at resolution \a nside
    and returns it in \a *ipring. On error, \a *ipring is set to -1. */
void nest2ring(long nside, long ipnest, long *ipring);
/*! Computes the NEST pixel index of pixel \a ipring at resolution \a nside
    and returns it in \a *ipring. On error, \a *ipnest is set to -1. */
void ring2nest(long nside, long ipring, long *ipnest);

/*! Returns \a 12*nside*nside. */
long nside2npix(long nside);
/*! Returns \a sqrt(npix/12) if this is an integer number, otherwise \a -1. */
long npix2nside(long npix);

/*! Computes a normalized Cartesian vector pointing in the same direction as
    \a theta, \a phi, and stores it in \a vec. \a vec must point to storage
    sufficient for at least three doubles. */
void ang2vec(double theta, double phi, double *vec);
/*! Computes the angles \a *theta and \a *phi describing the same directions
    as the Cartesian vector \a vec. \a vec need not be normalized. */
void vec2ang(const double *vec, double *theta, double *phi);

/*! Sets \a *ipix to the pixel number in NEST scheme at resolution \a nside,
    which contains the direction described the Cartesian vector \a vec. */
void vec2pix_nest(long nside, const double *vec, long *ipix);
/*! Sets \a *ipix to the pixel number in RING scheme at resolution \a nside,
    which contains the direction described the Cartesian vector \a vec. */
void vec2pix_ring(long nside, const double *vec, long *ipix);

/*! Sets \a vec to the Cartesian vector pointing in the direction of the center
    of pixel \a ipix in NEST scheme at resolution \a nside. */
void pix2vec_nest(long nside, long ipix, double *vec);
/*! Sets \a vec to the Cartesian vector pointing in the direction of the center
    of pixel \a ipix in RING scheme at resolution \a nside. */
void pix2vec_ring(long nside, long ipix, double *vec);

/* operations on Nside values up to 2^29 */

/*! Sets \a *ipix to the pixel number in NEST scheme at resolution \a nside,
    which contains the position \a theta, \a phi. */
void ang2pix_nest64(int64_t nside, double theta, double phi, int64_t *ipix);
/*! Sets \a *ipix to the pixel number in RING scheme at resolution \a nside,
    which contains the position \a theta, \a phi. */
void ang2pix_ring64(int64_t nside, double theta, double phi, int64_t *ipix);

/*! Sets \a theta and \a phi to the angular position of the center of pixel
    \a ipix in NEST scheme at resolution \a nside. */
void pix2ang_nest64(int64_t nside, int64_t ipix, double *theta, double *phi);
/*! Sets \a theta and \a phi to the angular position of the center of pixel
    \a ipix in RING scheme at resolution \a nside. */
void pix2ang_ring64(int64_t nside, int64_t ipix, double *theta, double *phi);

/*! Computes the RING pixel index of pixel \a ipnest at resolution \a nside
    and returns it in \a *ipring. On error, \a *ipring is set to -1. */
void nest2ring64(int64_t nside, int64_t ipnest, int64_t *ipring);
/*! Computes the NEST pixel index of pixel \a ipring at resolution \a nside
    and returns it in \a *ipring. On error, \a *ipnest is set to -1. */
void ring2nest64(int64_t nside, int64_t ipring, int64_t *ipnest);

/*! Returns \a 12*nside*nside. */
int64_t nside2npix64(int64_t nside);
/*! Returns \a sqrt(npix/12) if this is an integer number, otherwise \a -1. */
long npix2nside64(int64_t npix);

/*! Sets \a *ipix to the pixel number in NEST scheme at resolution \a nside,
    which contains the direction described the Cartesian vector \a vec. */
void vec2pix_nest64(int64_t nside, const double *vec, int64_t *ipix);
/*! Sets \a *ipix to the pixel number in RING scheme at resolution \a nside,
    which contains the direction described the Cartesian vector \a vec. */
void vec2pix_ring64(int64_t nside, const double *vec, int64_t *ipix);

/*! Sets \a vec to the Cartesian vector pointing in the direction of the center
    of pixel \a ipix in NEST scheme at resolution \a nside. */
void pix2vec_nest64(int64_t nside, int64_t ipix, double *vec);
/*! Sets \a vec to the Cartesian vector pointing in the direction of the center
    of pixel \a ipix in RING scheme at resolution \a nside. */
void pix2vec_ring64(int64_t nside, int64_t ipix, double *vec);
/*! Return neighbors of pix in NEST scheme. neighbors pointer must be an array
    of 8 long minimum. Negative number in neighbors, means it is inexistent.
    There can be 7 to 8 valid neighbors. */
void neighbours_nest64(int64_t nside, int64_t pix, int64_t *neighbours);
/*! Returns the distance angle between two vectors in radiant. Vectors do not
    have to be normalized. TODO tests*/
double angdist(double *vector_A, double *vector_B);
void vect_prod(double*vector_A, double *vector_B, double*vector_C);
/*! Return the distance in radiant of two pixels in the nest scheme with the
    Provided nside. Note that distances between pixels are variable. This does
    only provide an insight of how large are the pixels. TODO tests.
 */
/*
 * Euclidean distance between two vectors
 */
double euclidean_distance(double *va, double *vb);
/* FITS operations */
/* --------------- */

float *read_healpix_map (const char *infile, long *nside, char *coordsys,
  char *ordering);

void write_healpix_map (const float *signal, long nside, const char *filename,
  char nest, const char *coordsys);

long get_fits_size(const char *filename, long *nside, char *ordering);

/*! \} */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CHEALPIX_H */
