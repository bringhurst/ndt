/*
 *      $Id: hex.c 191 2007-03-30 23:26:38Z boote $
 */
/************************************************************************
*									*
*			     Copyright (C)  2003			*
*				Internet2				*
*			     All Rights Reserved			*
*									*
************************************************************************/
/*
 *	File:		hex.c
 *
 *	Author:		Jeff W. Boote
 *			Internet2
 *
 *	Date:		Tue Dec 16 15:45:00 MST 2003
 *
 *	Description:	
 */
#include <I2util/utilP.h>
#include <ctype.h>

/*
 * buff must be at least (nbytes*2) +1 long or memory will be over-run.
 */
void
I2HexEncode(
	char            *buff,
	const uint8_t   *bytes,
	size_t          nbytes
	)
{
    char    hex[]="0123456789abcdef";
    size_t  i;

    for(i=0;i<nbytes;i++){
        *buff++ = hex[*bytes >> 4];
        *buff++ = hex[*bytes++ & 0x0f];
    }
    *buff = '\0';
}

/*
 * Function:	I2HexDecode
 *
 * Description:	
 * 	Decode hex chars into bytes. Return True on success, False on error.
 *
 * 	It is valid to pass the same memory in for buff and bytes. On
 * 	input buff should hold the hex encoded string, on output the
 * 	memory will hold the bytes. (It will take half the memory...)
 *
 * In Args:	
 *
 * Out Args:	
 *
 * Scope:	
 * Returns:	
 * Side Effect:	
 */
I2Boolean
I2HexDecode(
        const char  *buff,
        uint8_t     *bytes,
        size_t	    nbytes
        )
{
    char            hex[]="0123456789abcdef";
    unsigned int    i,j,offset;
    char            a;
    uint8_t         byte;

    for(i=0;i<nbytes;i++,bytes++){
        byte = 0;
        for(j=0;(*buff != '\0')&&(j<2);j++,buff++){
            a = tolower(*buff);
            for(offset=0;offset<sizeof(hex);offset++){
                if(a == hex[offset]){
                    byte |= offset;
                    if(!j)
                        byte <<= 4;
                    goto byteset;
                }
            }
            return False;
byteset:
            ;
        }
        *bytes = byte;
    }

    return True;
}
