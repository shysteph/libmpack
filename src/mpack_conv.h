#ifndef MPACK_CONV_H
#define MPACK_CONV_H

#include "mpack_core.h"

#ifndef bool
# define bool unsigned
#endif

mpack_token_t mpack_pack_nil(void) FPURE;
mpack_token_t mpack_pack_boolean(unsigned v) FPURE;
mpack_token_t mpack_pack_uint(mpack_uintmax_t v) FPURE;
mpack_token_t mpack_pack_sint(mpack_sintmax_t v) FPURE;
mpack_token_t mpack_pack_float_compat(double v) FPURE;
mpack_token_t mpack_pack_float_fast(double v) FPURE;
mpack_token_t mpack_pack_chunk(const char *p, mpack_uint32_t l) FPURE FNONULL;
mpack_token_t mpack_pack_str(mpack_uint32_t l) FPURE;
mpack_token_t mpack_pack_bin(mpack_uint32_t l) FPURE;
mpack_token_t mpack_pack_ext(int type, mpack_uint32_t l) FPURE;
mpack_token_t mpack_pack_array(mpack_uint32_t l) FPURE;
mpack_token_t mpack_pack_map(mpack_uint32_t l) FPURE;
bool mpack_unpack_boolean(const mpack_token_t *t) FPURE FNONULL;
mpack_uintmax_t mpack_unpack_uint(const mpack_token_t *t) FPURE FNONULL;
mpack_sintmax_t mpack_unpack_sint(const mpack_token_t *t) FPURE FNONULL;
double mpack_unpack_float_fast(const mpack_token_t *t) FPURE FNONULL;
double mpack_unpack_float_compat(const mpack_token_t *t) FPURE FNONULL;

/* The mpack_{pack,unpack}_float_fast functions should work in 99% of the
 * platforms. When compiling for a platform where floats don't use ieee754 as
 * the internal format, pass
 * -Dmpack_{pack,unpack}_float=mpack_{pack,unpack}_float_compat to the
 *  compiler.*/
#ifndef mpack_pack_float
# define mpack_pack_float mpack_pack_float_fast
#endif
#ifndef mpack_unpack_float
# define mpack_unpack_float mpack_unpack_float_fast
#endif

#endif  /* MPACK_CONV_H */
