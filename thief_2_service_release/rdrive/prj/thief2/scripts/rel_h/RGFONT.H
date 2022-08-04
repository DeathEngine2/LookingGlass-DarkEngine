/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/*=========================================================

  Created:  12/2/99 3:58:30 PM

  File:  rgFont.h

  Description:  Hardware font rendering interface


=========================================================*/

// $Header: x:/prj/tech/libsrc/rg/RCS/rgfont.h 1.1 1970/01/01 00:00:00 Zarko Exp $

#pragma once 

#ifndef _RGFONT_H
#define _RGFONT_H


//_____INCLUDES_AND_DEFINITIONS___________________________

#ifdef __cplusplus
extern "C" {
#endif

   //______________DESCRIPTION_______________________________

   //     Hardware Fonts System
   //
   //    Fonts are created individually with "CreateFont" method.
   // Fonts can be destroyed only collectively, with "DestroyAllFonts".
   // Creation, "CreateFont", assigns an unique "handle" of the  type
   // HFont.  This handle is valid until the call to "DestroyAllFonts".
   //
   //    In addition to the HFont handle, the client can set a 
   // C-string indentification for the font, using "SetFontDescription"
   // (and "GetFontDescription").
   //
   // A font can be in the "loaded state" that would typically imply
   // that the required textures are loaded with the texture manager.
   // There is a single font that is "current" at any given time
   // between CreateFont and DestroyAllFonts calls.
   //
   // A font is "loaded" when is "set"( i.e., chosen for the "current"
   // font) for the first time. 
   //
   // To set a font use "SetFont( HFont )" or, if using the font description, 
   // "SetFontThatIs( const char*, HFont*)"

   //       Font states
   // The following states are stored and controlled by the font system:
   //    ARGB color
   //    "Z"-coordinate and Depth buffer toggle
   //
   
   //       Text output
   // The system handles C-strings and individual characters. (Characters are 
   // internally "promoted" into C-strings).
   //    A string can be outputed immediately with a "WriteZTString" call, or
   // they can be compiled into a "font display list" with a "CompileZTString"
   // call.  "CompileZTString" returns HFontDL value which is the "handle"
   // for the created FDL (font display list).  Using this handle the client
   // can access the FDL with "DisplayFontDL", "GetFontDLExtent" and
   // "ReleaseFontDL" calls.  After the list is compiled, color, Z-value and 
   // the position can not be updated




   
   //_______TYPEDEFS_________________________________________
   
   
   // font indentification
   typedef unsigned int          HFont;   // font handle
   typedef unsigned int          HFontDL; // font display list  
   
#define INVALID_RGFONT_HANDLE       0x7FFFFFFF 
#define INVALID_RGF_FDLIST_HANDLE   0x7FFFFFFF 
  
#define USE_DEFAULT_FONT_Z       -1.0f

   
   // FDList updates

   // UpdateFontDL(...) flags
#define RG_FDL_UPDATE_COLOR      1
#define RG_FDL_UPDATE_Z          2
#define RG_FDL_UPDATE_POSITION   4

   typedef struct sFDListUpdate{
      DWORD    dwColor;
      float    fZ;
      float    fX;
      float    fY;
   }sFDListUpdate;


   ///_________IRGFontSys_______________________

   F_DECLARE_INTERFACE(IRGFontSys);
   
#undef INTERFACE
#define INTERFACE IRGFontSys;
   
   DECLARE_INTERFACE_(IRGFontSys, IUnknown)
   {
      DECLARE_UNKNOWN_PURE();
      

      // font creation

      // create font from a font resource
      // and retrun a handle to it
      STDMETHOD (CreateFont) (
         THIS_
         /*[in]*/ void* pvFontRes,   // type checking is done during the processing
         /*[out]*/HFont* phHandleAddress     // FAILS IF NULL! 
         )
         PURE;
   
      // destroys **ALL** fonts created up to now
      // NOTE: an individual font can not deleted,use  
      //       "UnloadFont" to unload its video memory
      STDMETHOD (DestroyAllFonts) (THIS) PURE;

      // hint to remove the font data from the memory,
      // The handle is still valid and SetFont will reload
      // the font
      STDMETHOD (UnloadFont)(
         THIS_
         /*[in]*/ HFont hFont   // handle to the font
         )
         PURE;
       
      // call "UnloadFont" on all fonts
      STDMETHOD_(void,UnloadAllFonts) (THIS) PURE;

      

      // set a text description to a font
      // fails if hFont does not point to loaded font 
      STDMETHOD (SetFontDescription) (
         THIS_
         /*[in]*/ HFont hFont,   // handle to the font
         /*[in]*/ const char* szDescription  //31 characters max!
         )
         PURE;
      
      STDMETHOD_(const char*,GetFontDescription) (
         THIS_
         /*[in]*/ HFont hFont   // handle to the font
         )
         PURE;

      
      // font selection

      // sets the font as the current font
      STDMETHOD (SetFont)(
         THIS_
         /*[in]*/ HFont hFont   // handle to the font
         )
         PURE;

      // sets the font with this descriptions
      STDMETHOD (SetFontThatIs)(
         THIS_
         /*[in]*/ const char* szDescription, //31 characters max!
         /*[out]*/HFont* phHandleAddress     // ignored if NULL    
         )
         PURE;


      // font color

      // set the font color and return the previous one
      STDMETHOD_(DWORD,SetFontARGBColor) (
         THIS_
         /*[in]*/ DWORD dwNewColor  // color to be set
         )
         PURE;

      //get the color
      STDMETHOD_(DWORD,GetFontARGBColor) (THIS) PURE;


      // depth: the"z" coordinate

      // use default(no depth sorting)
      STDMETHOD_(void,UseDefaultDepth)(THIS) PURE;

      // set the z-depth
      // returns the previous z or USE_DEFAULT_FONT_Z (== -1.0), 
      // if the default is in the use
      STDMETHOD_(float,SetDepth) (
         THIS_
         /*[in]*/ float fZ // in the open interval (0,1)
         )
         PURE;


      // text output
   
      // the simplest text output, writes a zero-termainated string
      STDMETHOD_(void,WriteZTString) (
         THIS_
         /*[in]*/ const char* szString,   // string to output
         /*[in]*/ float fScreenX,         // where to place the leftmost column
         /*[in]*/ float fScreenY          // where to place the topmost row
         )
         PURE;

      //NOTE: it is implemented in terms of WriteZTString
      STDMETHOD_(void,WriteCharacter) (
         THIS_
         /*[in]*/ char  chCharacter,   // character to output
         /*[in]*/ float fScreenX,      // where to place the leftmost column
         /*[in]*/ float fScreenY       // where to place the topmost row
         )
         PURE;

      // ... using font display lists

      // create and cache an output display lists
      // return FALSE if creation failed
      STDMETHOD_(BOOL,CompileZTString) (
         THIS_
         /*[in]*/ BOOL bDrawIt,           // whether to write it immediately
         /*[in]*/ const char* szString,   // string to output
         /*[in]*/ float fScreenX,         // where to place the leftmost column
         /*[in]*/ float fScreenY,          // where to place the topmost row
         /*[in]*/ HFontDL* phFDList  //ADDRESS where to place  the display list handle 
         )
         PURE;
      
      // display the font display list
      STDMETHOD_(void,DisplayFontDL) (
         THIS_
         /*[in]*/ HFontDL hFDList // a handle got from "CompileZTString"
         )
         PURE;

      STDMETHOD_(BOOL,GetFontDLExtent) (
         THIS_
         /*[in]*/ HFontDL hFDList,        // a handle got from "CompileZTString"
         /*[in]*/ sClipRect* pRectAddress // where to copy the data
         )
         PURE;

      STDMETHOD_(void,ReleaseFontDL) (
         THIS_
         /*[in]*/ HFontDL hFDList // a handle got from "CompileZTString"
         )
         PURE; 


      STDMETHOD (UpdateFontDL) (
         THIS_
         /*[in]*/ HFontDL hFDList,           // a handle got from "CompileZTString"
         /*[in]*/ DWORD dwUpdateFlags,       // flags that specify what states need to be updated
         /*[in]*/ sFDListUpdate* psNewData   // pointer to data, dwUpdateFlags specifies what's relevant
         )
         PURE;


      // compute string's data without compailing or
      // loading the font.  
      
      // Get the size: It fails if font not created
      // or all of DWORD*'s are NULL
      STDMETHOD_(BOOL,ComputeStringsSize) (
         THIS_
         /*[in]*/ HFont hFont,            // handle to the font
         /*[in]*/ const char* szString,   // string to measure
         /*[in]*/ DWORD* pdwWidth,        // address, ignored if NULL
         /*[in]*/ DWORD* pdwHeight,       // address, ignored if NULL
         /*[in]*/ DWORD* pdwNumRows       // address, ignored if NULL
         )
         PURE;

 

      // de-buggin' stuff
#ifdef DEBUG 
      // outputs how many
      STDMETHOD_(DWORD,dbDisplayTexturePages)(THIS) PURE;
#endif

   };
  


   
   
#ifdef __cplusplus
}
#endif
      

#endif //_RGFONT_H