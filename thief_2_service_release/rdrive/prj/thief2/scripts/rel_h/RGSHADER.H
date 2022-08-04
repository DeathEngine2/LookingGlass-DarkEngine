/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*=========================================================

  Created:  8/24/99 9:28:29 AM

  File:  rgShader.h

  Description: Shader definition and manipulation interface 


=========================================================*/

// $Header: x:/prj/tech/libsrc/rg/RCS/rgshader.h 1.3 1970/01/01 00:00:00 Zarko Exp $

#pragma once 

#ifndef _RGSHADER_H
#define _RGSHADER_H



//_____INCLUDES_AND_DEFINITIONS___________________________

F_DECLARE_INTERFACE(IRGShader); 


// errors
#define RG_SHADER_METHOD_ERROR   0xFFFFFFFFL
#define RG_VOID_SHADER           0xFFFFFFFFL

struct IRenderG;

//_______TYPEDEFS_________________________________________


///RenderG shader interface

// a shader 

// data corresponding to a shader's rendering method
// in all its uses this structure is always created
// and destroyed by the client.  Library always copies
// its internal data into it
typedef struct sRGShaderData {
   DWORD    dwHandle;         // returned by attaching call in IRenderG  
   DWORD    dwSelectedMethod; // RG_SHADER_METHOD_ERROR if shader not valid
   DWORD    dwNoPasses;       // for the selected method...
   DWORD    dwNoLevels;       // for the selected method...
} sRGShaderData;
 


#undef INTERFACE
#define INTERFACE IRGShader

DECLARE_INTERFACE_(IRGShader, IUnknown)
{
   // IUnknown
   DECLARE_UNKNOWN_PURE();
   
   
   // verification and configuration
   // Requriements:
   // this is shader's only chance to verify all of its 
   // methods.  The call has to fail if none of
   // its methods is successfully validated.
   // One of the validated method is internaly selected.
   // NOTE: to find out the selected method use "GetConfiguration"
   STDMETHOD_(BOOL,ConfigureYourself) (
      THIS_
      /*[in]*/ IRenderG* pIRG    //MUST BE cRenderG*
      ) 
      PURE;
   

   // sets the shader's handle. 
   // Requirements: This method is called by the shader 
   // attachment call.  The handle is the only mean of accessing the
   // shader.  This handle has to be equal to sRGShaderData::dwHandle
   // of the structure that is returned by the "GetConfiguration" call.
   STDMETHOD_(void,SetHandle) (
      THIS_
      /*[in]*/ DWORD dwHandle //there is no validity checking
      )
      PURE;
   
   // RESELECTING the method 
   
   // try to configure rendering for the 
   // requested method
   // error codes: E_RG_UNINITIALIZED if the shader was not configured
   //                 with a ConfigureYourself call
   //              E_RG_FEATURE_UNSUPPORTED if the method is not valid
   STDMETHOD (SelectMethod) (
      THIS_
      /*[in]*/ DWORD dwMethodNo,    // the method 
      /*[out]*/sRGShaderData* pData // address of client created object
                                    // that will contain copy of the 
                                    // shader's data after the call
      )
      PURE;
   
   
   // INFO:
   
   // gets the data on the selected
   // rendering method
   // error codes: E_RG_UNINITIALIZED if the shader was not configured
   //                 with a ConfigureYourself call
   STDMETHOD (GetConfiguration) (
      THIS_
      /*[out]*/sRGShaderData* pData // address of client created object
                                    // that will contain copy of the 
                                    // shader's data after the call
      )
      PURE;
   
   // a shader becomes valid only AFTER succesful configuration
   STDMETHOD_(BOOL,IsValid) (THIS) PURE;  // is there any method that is valid
   
   // returns the validity of the requested method
   STDMETHOD_(BOOL,IsMethodValid) (
      THIS_
      /*[in]*/ DWORD dwMethodNo  //number into shader's internal method ordering
      )
      PURE;
   

   // ACTIONS:

   // configure rendering pipeline for the
   // specified step and for the method that
   // was selecte before
   // NOTE: it is client's responsability to call this method at the  
   // appropriate times with correct pass numbers
   STDMETHOD_(void,DoExecutePass) (
      THIS_
      /*[in]*/ DWORD dwPassNo   //shader specific ordering
      )
      PURE;
   
   // do shader specific clean-up 
   STDMETHOD_(void,Disengage) (THIS) PURE; 

   // receive a notification
   // a shader can use this channel to set an observer and get notified.
   // (For example, if the current texture uses alpha, modulate shader 
   // needs to know that, so it can set an observer
   // using cCtrAlphaSw::SetTexAlphaAlarm.)
   STDMETHOD_(void,Notify) (
      THIS_
      /*[in]*/ DWORD dwEventNo,  //implementation specific (DIFFERENT from 0)
      /*[in]*/ DWORD dwValue     //implementation specific
      )
      PURE;
};



#endif //_RGSHADER_H