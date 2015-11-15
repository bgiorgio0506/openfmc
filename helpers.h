#ifndef	_OPENFMC_HELPERS_H_
#define	_OPENFMC_HELPERS_H_

#include "airac.h"

/* Minimum/Maximum allowable elevation AMSL of anything */
#define	MIN_ELEV	-1000.0
#define	MAX_ELEV	30000.0

/* Minimum/Maximum allowable altitude AMSL of anything */
#define	MIN_ALT		-1000.0
#define	MAX_ALT		100000.0

static inline int
is_valid_lat(double lat)
{
	return (lat <= 90.0 && lat >= -90.0);
}

static inline int
is_valid_lon(double lon)
{
	return (lon <= 180.0 && lon >= -180.0);
}

static inline int
is_valid_elev(double elev)
{
	return (elev >= MIN_ELEV && elev <= MAX_ELEV);
}

static inline int
is_valid_alt(double alt)
{
	return (alt >= MIN_ALT && alt <= MAX_ALT);
}

static inline int
is_valid_hdg(double hdg)
{
	return (hdg > 0.0 && hdg <= 360.0);
}

int is_valid_vor_freq(double freq_mhz);
int is_valid_loc_freq(double freq_mhz);

char **explode_line(char *line, char *delim, size_t *num_comps);
void strip_newline(char *line, size_t line_len);

int geo_pos_2d_from_str(const char *lat, const char *lon, geo_pos_2d_t *pos);
int geo_pos_3d_from_str(const char *lat, const char *lon, const char *elev,
    geo_pos_3d_t *pos);

#endif	/* _OPENFMC_HELPERS_H_ */
