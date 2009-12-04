/****************************************************************************
*
*   Copyright (c) 2009 Dave Hylands     <dhylands@gmail.com>
*
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License version 2 as
*   published by the Free Software Foundation.
*
*   Alternatively, this software may be distributed under the terms of BSD
*   license.
*
*   See README and COPYING for more details.
*
****************************************************************************/
/**
*
*   @file   BioloidCommandLine.h
*
*   @brief  Implements a simulated bioloid bus which is useful for some
*           types of debugging.
*
*   The simulated bus prints out all of the packets that would be
*   sent over the bus.
*
****************************************************************************/

#if !defined( BIOLOIDCOMMANDLINE_H )
#define BIOLOIDCOMMANDLINE_H       /**< Include Guard                             */

// ---- Include Files -------------------------------------------------------

#include "bioloid-reg.h"
#include "BioloidBus.h"
#include "BioloidDevice.h"
#include "StrToken.h"

class BioloidCommandLine
{
public:

    //------------------------------------------------------------------------
    // Default constructor

    BioloidCommandLine();

    //------------------------------------------------------------------------
    // Destructor

    ~BioloidCommandLine();

    //------------------------------------------------------------------------
    // Processes one line of data

    bool ProcessLine( char *line );

    //------------------------------------------------------------------------
    // Registers a device type which has registers

    void RegisterDevices( BLD_DevType_t *devType );

    //------------------------------------------------------------------------
    // Sets the bus used to send commands.

    void SetBus( BioloidBus *bus )
    {
        m_bus = bus;
    }

private:

    //------------------------------------------------------------------------
    // Prints out register information

    void DumpRegInfo( BLD_DevType_t *devType );

    //------------------------------------------------------------------------
    // Parses an offset and some data

    bool ParseOffsetAndData( StrTokenizer &line, uint8_t *offset, uint8_t *numBytes, uint8_t *data, size_t maxLen );

    //------------------------------------------------------------------------
    // Parses a register name

    bool ParseRegisterName( StrTokenizer &line, BLD_DevType_t *devType, BLD_Reg_t **outReg );

    BioloidBus     *m_bus;
    BioloidDevice   m_device;
};

#endif  // BIOLOIDCOMMANDLINE_H
