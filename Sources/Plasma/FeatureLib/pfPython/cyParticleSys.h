/*==LICENSE==*

CyanWorlds.com Engine - MMOG client, server and tools
Copyright (C) 2011  Cyan Worlds, Inc.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

Additional permissions under GNU GPL version 3 section 7

If you modify this Program, or any covered work, by linking or
combining it with any of RAD Game Tools Bink SDK, Autodesk 3ds Max SDK,
NVIDIA PhysX SDK, Microsoft DirectX SDK, OpenSSL library, Independent
JPEG Group JPEG library, Microsoft Windows Media SDK, or Apple QuickTime SDK
(or a modified version of those libraries),
containing parts covered by the terms of the Bink SDK EULA, 3ds Max EULA,
PhysX SDK EULA, DirectX SDK EULA, OpenSSL and SSLeay licenses, IJG
JPEG Library README, Windows Media SDK EULA, or QuickTime SDK EULA, the
licensors of this Program grant you additional
permission to convey the resulting work. Corresponding Source for a
non-source form of such a combination shall include the source code for
the parts of OpenSSL and IJG JPEG Library used as well as that of the covered
work.

You can contact Cyan Worlds, Inc. by email legal@cyan.com
 or by snail mail at:
      Cyan Worlds, Inc.
      14617 N Newport Hwy
      Mead, WA   99021

*==LICENSE==*/
#ifndef cyParticleSys_h
#define cyParticleSys_h

/////////////////////////////////////////////////////////////////////////////
//
// NAME: cyParticleSys
//
// PURPOSE: Class wrapper to for Particle System
//
#include "hsTemplates.h"

#include "pnKeyedObject/plKey.h"
class pyKey;

#include <Python.h>
#include "pyGlueHelpers.h"

class cyParticleSys
{
protected:
    plKey           fSender;
    hsTArray<plKey> fRecvr;
    hsBool          fNetForce;

    virtual void    ISendParticleSysMsg(uint32_t param, float value);

    cyParticleSys(const plKey sender=nil,const plKey recvr=nil);

public:
    // required functions for PyObject interoperability
    PYTHON_CLASS_NEW_FRIEND(ptParticle);
    static PyObject *New(PyObject *sender = nil, PyObject *recvr = nil);
    PYTHON_CLASS_CHECK_DEFINITION; // returns true if the PyObject is a cyParticleSys object
    PYTHON_CLASS_CONVERT_FROM_DEFINITION(cyParticleSys); // converts a PyObject to a cyParticleSys (throws error if not correct type)

    static void AddPlasmaClasses(PyObject *m);

    // setters
    virtual void    SetSender(plKey &sender);
    virtual void    AddRecvr(plKey &recvr);
    virtual void SetNetForce(hsBool state);

    virtual void    SetParticlesPerSecond(float value);
    virtual void    SetInitPitchRange(float value);
    virtual void    SetInitYawRange(float value);
    virtual void    SetVelMin(float value);
    virtual void    SetVelMax(float value);
    virtual void    SetXSize(float value);
    virtual void    SetYSize(float value);
    virtual void    SetScaleMin(float value);
    virtual void    SetScaleMax(float value);
    virtual void    SetGenLife(float value);
    virtual void    SetPartLifeMin(float value);
    virtual void    SetPartLifeMax(float value);

};


#endif  // cyParticleSys_h
