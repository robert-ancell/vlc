/*****************************************************************************
 * dsp.c : OSS /dev/dsp module for vlc
 *****************************************************************************
 * Copyright (C) 2000-2001 VideoLAN
 * $Id: dsp.c,v 1.13 2002/02/24 20:51:09 gbazin Exp $
 *
 * Authors: Michel Kaempf <maxx@via.ecp.fr>
 *          Samuel Hocevar <sam@zoy.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111, USA.
 *****************************************************************************/

/*****************************************************************************
 * Preamble
 *****************************************************************************/
#include <stdlib.h>                                      /* malloc(), free() */
#include <string.h>                                              /* strdup() */

#include <videolan/vlc.h>

/*****************************************************************************
 * Capabilities defined in the other files.
 *****************************************************************************/
void _M( aout_getfunctions )( function_list_t * p_function_list );

/*****************************************************************************
 * Build configuration tree.
 *****************************************************************************/
#define DSP_DEV_VAR                    "dsp_dev"

MODULE_CONFIG_START
ADD_CATEGORY_HINT( "Misc Options", NULL )
ADD_FILE  ( DSP_DEV_VAR, "/dev/dsp", NULL,"OSS dsp device",NULL )
MODULE_CONFIG_STOP

MODULE_INIT_START
    SET_DESCRIPTION( "Linux OSS /dev/dsp module" )
    ADD_CAPABILITY( AOUT, 100 )
    ADD_SHORTCUT( "dsp" )
MODULE_INIT_STOP

MODULE_ACTIVATE_START
    _M( aout_getfunctions )( &p_module->p_functions->aout );
MODULE_ACTIVATE_STOP

MODULE_DEACTIVATE_START
MODULE_DEACTIVATE_STOP

