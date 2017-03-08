/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_key_apple.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 19:16:14 by wescande          #+#    #+#             */
/*   Updated: 2016/12/26 19:18:09 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_KEY_APPLE_H
# define MY_KEY_APPLE_H
# define K_ESC				0x35

/*
** line 1
*/
# define K_TILDE			0x32
# define K_1				0x12
# define K_2				0x13
# define K_3				0x14
# define K_4				0x15
# define K_5				0x17
# define K_6				0x16
# define K_7				0x1A
# define K_8				0x1C
# define K_9				0x19
# define K_0				0x1D
# define K_SUB				0x1B
# define K_ADD				0x18
# define K_DELETE			0x33

/*
** line 2
*/
# define K_TAB				0x30
# define K_Q				0xC
# define K_W				0xD
# define K_E				0xE
# define K_R				0xF
# define K_T				0x11
# define K_Y				0x10
# define K_U				0x20
# define K_I				0x22
# define K_O				0x1F
# define K_P				0x23
# define K_BRACKET_OPEN		0x21
# define K_BRACKET_CLOSE	0x1E
# define K_PIPE				0x2A

/*
** line 3
*/
# define K_A				0x0
# define K_S				0x1
# define K_D				0x2
# define K_F				0x3
# define K_G				0x5
# define K_H				0x4
# define K_J				0x26
# define K_K				0x28
# define K_L				0x25
# define K_DOUBLE_DOTS		0x29
# define K_QUOTE			0x27
# define K_RETURN			0x24

/*
** line 4
*/
# define K_SHIFT_LEFT		0x101
# define K_Z				0x6
# define K_X				0x7
# define K_C				0x8
# define K_V				0x9
# define K_B				0xB
# define K_N				0x2D
# define K_M				0x2E
# define K_INFERIOR			0x2B
# define K_SUPERIOR			0x2F
# define K_QUESTION_MARK	0x2C
# define K_SHIFT_RIGHT		0x102

/*
** line 5
*/
# define K_CTRL_LEFT		0x100
# define K_ALT_LEFT			0x105
# define K_CMD_LEFT			0x103
# define K_SPACE			0x31
# define K_CMD_RIGHT		0x104
# define K_ALT_RIGHT		0x106
# define K_CTRL_RIGHT		0x10D

/*
** line 1 | col 2 && line 2 | col 2
*/
# define K_FN				0x117
# define K_HOME				0x73
# define K_PAGE_UP			0x74
# define K_SUPPR			0x75
# define K_END				0x77
# define K_PAGE_DOWN		0x79

/*
** direction pad
*/
# define K_UP				0x7E
# define K_LEFT				0x7B
# define K_DOWN				0x7D
# define K_RIGHT			0x7C

/*
** numpad
*/
# define K_CLEAR			0x47
# define K_PAD_EQUAL		0x51
# define K_PAD_DIV			0x4B
# define K_PAD_MUL			0x43
# define K_PAD_7			0x59
# define K_PAD_8			0x5B
# define K_PAD_9			0x5C
# define K_PAD_SUB			0x4E
# define K_PAD_4			0x56
# define K_PAD_5			0x57
# define K_PAD_6			0x58
# define K_PAD_ADD			0x45
# define K_PAD_1			0x53
# define K_PAD_2			0x54
# define K_PAD_3			0x55
# define K_PAD_0			0x52
# define K_PAD_DOT			0x41
# define K_PAD_ENTER		0x4C

# define M_BUTTON_LEFT		1
# define M_BUTTON_RIGHT		2
# define M_BUTTON_MIDDLE	3
# define M_SCROLL_UP		4
# define M_SCROLL_DOWN		5

#endif
