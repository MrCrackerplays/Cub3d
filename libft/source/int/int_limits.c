/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_limits.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 11:25:41 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/13 17:31:56 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_int_types.h>

const BYTE		g_sbyte_size = sizeof(SBYTE) * 8 - 1;
const SBYTE		g_sbyte_min = (SBYTE)((SBYTE)1 << g_sbyte_size);
const SBYTE		g_sbyte_max = ~(SBYTE)((SBYTE)1 << g_sbyte_size);
const BYTE		g_byte_size = sizeof(SBYTE) * 8;
const BYTE		g_byte_max = (BYTE)(-1);

const BYTE		g_short_size = sizeof(short) * 8 - 1;
const short		g_short_min = (short)((short)1 << g_short_size);
const short		g_short_max = ~(short)((short)1 << g_short_size);
const BYTE		g_ushort_size = sizeof(USHORT) * 8;
const USHORT	g_ushort_max = (USHORT)(-1);

const BYTE		g_int_size = sizeof(int) * 8 - 1;
const int		g_int_min = (int)((int)1 << g_int_size);
const int		g_int_max = ~(int)((int)1 << g_int_size);
const BYTE		g_uint_size = sizeof(UINT) * 8;
const UINT		g_uint_max = (UINT)(-1);

const BYTE		g_long_size = sizeof(long) * 8 - 1;
const long		g_long_min = (long)((long)1 << g_long_size);
const long		g_long_max = ~(long)((long)1 << g_long_size);
const BYTE		g_ulong_size = sizeof(ULONG) * 8;
const ULONG		g_ulong_max = (ULONG)(-1);

const BYTE		g_llong_size = sizeof(LLONG) * 8 - 1;
const LLONG		g_llong_min = (LLONG)((LLONG)1 << g_llong_size);
const LLONG		g_llong_max = ~(LLONG)((LLONG)1 << g_llong_size);
const BYTE		g_ullong_size = sizeof(ULLONG) * 8;
const ULLONG	g_ullong_max = (ULLONG)(-1);
