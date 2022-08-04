/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*===========================================================================*\
|
|  File:        strrec.h
|
|  Description: 
|       SDF string parsing class
|       
|-----------------------------------------------------------------------------
|
|  Copyright (C) 1995 Microsoft Corporation.  All Rights Reserved.
|
|  Written by Moss Bay Engineering, Inc. under contract to Microsoft Corporation
|
\*===========================================================================*/

#ifndef STRREC_H
#define STRREC_H

#define MAX_FIELDS 256

class CStringRecord
{
public:
    CStringRecord(char* pString, char* pDelims);
    virtual ~CStringRecord();

    char* operator[](int field);

    int GetNumFields()
    {
        return mNumFields;
    }

private:
    char** mpFields;
    int mNumFields;
};


#endif // STRREC_H
