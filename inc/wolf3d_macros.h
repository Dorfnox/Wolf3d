/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_macros.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 11:55:35 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/03 14:44:52 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_MACROS_H
# define WOLF3D_MACROS_H

/*
** Keys
*/

# define A__ 0
# define B__ 11
# define C__ 8
# define D__ 2
# define E__ 14
# define F__ 3
# define G__ 5
# define H__ 4
# define I__ 34
# define J__ 38
# define K__ 40
# define L__ 37
# define M__ 46
# define N__ 45
# define O__ 31
# define P__ 35
# define Q__ 12
# define R__ 15
# define S__ 1
# define T__ 17
# define U__ 32
# define V__ 9
# define W__ 13
# define X__ 7
# define Y__ 16
# define Z__ 6
# define UP__ 126
# define DOWN__ 125
# define RIGHT__ 124
# define LEFT__ 123
# define MOUSE1__ 1
# define MOUSE2__ 2
# define MOUSESCROLLUP__ 4
# define MOUSESCROLLDOWN__ 5
# define SPACE__ 49
# define PLUS__ 69
# define MINUS__ 78
# define DIVIDE__ 75
# define MULTIPLY__ 67
# define ADD__ 24
# define SUBTRACT__ 27
# define LESSTHAN__ 43
# define GREATERTHAN__ 47
# define ESC__ 53

/*
** Ease of understanding macros
*/

# define WOLF w->p
# define TRIG w->t
# define MAP w->map
# define SCREEN w->screen
# define PIXEL w->screen->pix[x + (y * W)]

# define NS_WALL 1
# define SN_WALL 2
# define EW_WALL 3
# define WE_WALL 4
# define EX_WALL 5

# define AB(x) (((x) < 0) ? ((x) * -1) : (x))

# define NXT_X MAP->map[(int)WOLF->pos.y][(int)(WOLF->pos.x + WOLF->dir.x)]
# define NXT_Y MAP->map[(int)(WOLF->pos.y + WOLF->dir.y)][(int)WOLF->pos.x]
# define PRV_X MAP->map[(int)WOLF->pos.y][(int)(WOLF->pos.x - WOLF->dir.x)]
# define PRV_Y MAP->map[(int)(WOLF->pos.y - WOLF->dir.y)][(int)WOLF->pos.x]

# define RT_X MAP->map[(int)WOLF->pos.y][(int)(WOLF->pos.x + WOLF->plane.x)]
# define RT_Y MAP->map[(int)(WOLF->pos.y + WOLF->plane.y)][(int)WOLF->pos.x]
# define LT_X MAP->map[(int)WOLF->pos.y][(int)(WOLF->pos.x - WOLF->plane.x)]
# define LT_Y MAP->map[(int)(WOLF->pos.y - WOLF->plane.y)][(int)WOLF->pos.x]
/*
** Function Macros
*/

# define MIN(a, b) ((a < b) ? (a) : (b))
# define MAX(a, b) ((a > b) ? (a) : (b))
# define CLAMP(a, min, max) (MIN(MAX(a, min), max))
# define VXP(x0, y0, x1, y1) ((x0 * y1) - (x1 * y0))

# define OV1(a0, a1, b0, b1) (MIN(a0, a1) <= MAX(b0, b1))
# define OV2(a0, a1, b0, b1) (MIN(b0, b1) <= MAX(a0, a1))
# define OVERLAP(a0, a1, b0, b1) (OV1(a0, a1, b0, b1) && OV2(a0, a1, b0, b1))

# define IB1(x0, x1, x2, x3) (OVERLAP(x0, x1, x2, x3))
# define IB2(y0, y1, y2, y3) (OVERLAP(y0, y1, y2, y3))
# define INTRSCTBOX(a, e, b, f, c, g, d, h) (IB1(a, b, c, d) && IB2(e, f, g, h))

# define PO1 (x1 - x0)
# define PO2 (y1 - y0)
# define PO3 (px - x0)
# define PO4 (py - y0)
# define POINTSIDE(px, py, x0, y0, x1, y1) (VXP(PO1, PO2, PO3, PO4))

# define IN1 VXP(x0, y0, x1, y1)
# define IN2 ((x0) - (x1))
# define IN3 VXP(x2, y2, x3, y3)
# define IN4 ((x2) - (x3))
# define IN5 ((y0) - (y1))
# define IN6 ((y2) - (y3))
# define IN7 VXP((x0 - x1), (y0 - y1), (x2 - x3), (y2 - y3))
# define XNTRSCT(x0, y0, x1, y1, x2, y2, x3, y3) (VXP(IN1, IN2, IN3, IN4) / IN7)
# define YNTRSCT(x0, y0, x1, y1, x2, y2, x3, y3) (VXP(IN1, IN5, IN3, IN6) / IN7)

#endif
