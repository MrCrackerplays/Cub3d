/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tan.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 17:08:55 by rdrazsky      #+#    #+#                 */
/*   Updated: 2022/02/17 17:16:50 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double	ml_tan(double degree)
{
	return (tan(degree * M_PI / 180));
}
