/*******************************************************************************
 * Copyright (c) 2014, Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/

/*!
 * @header      CFPP-Bundle.h
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    CoreFoundation++ CFBundleRef wrapper
 */

#ifndef CFPP_BUNDLE_H
#define CFPP_BUNDLE_H

namespace CF
{
    class CFPP_EXPORT Bundle: public Type
    {
        public:
            
            static Array  GetAllBundles( void );
            static Array  GetBundlesFromDirectory( URL directoryURL, Array bundleTypes );
            static Bundle GetBundleWithIdentifier( String identifier );
            static Bundle GetMainBundle( void );
            
            static URL   GetResourceURLInDirectory( URL bundleURL, String resourceName, String resourceType, String subDirName );
            static Array GetResourceURLsOfTypeInDirectory( URL bundleURL, String resourceType, String subDirName );
            
            static Dictionary GetInfoDictionaryInDirectory( URL bundleURL );
            static Dictionary GetInfoDictionaryForURL( URL url );
            static bool       GetPackageInfoInDirectory( URL url, UInt32 * packageType, UInt32 * packageCreator );
            static Array      GetExecutableArchitecturesForURL( URL url );
            
            static Array GetLocalizationsForPreferences( Array locArray, Array prefArray );
            static Array GetLocalizationsForURL( URL url );
            static Array GetPreferredLocalizationsFromArray( Array locArray );
            
            Bundle( void );
            Bundle( const Bundle & value );
            Bundle( const AutoPointer & value );
            Bundle( CFTypeRef cfObject );
            Bundle( CFBundleRef cfObject );
            Bundle( String identifier );
            Bundle( URL url );
            
            #ifdef CFPP_HAS_CPP11
            Bundle( Bundle && value );
            #endif
            
            virtual ~Bundle( void );
            
            Bundle & operator = ( Bundle value );
            Bundle & operator = ( const AutoPointer & value );
            Bundle & operator = ( CFTypeRef value );
            Bundle & operator = ( CFBundleRef value );
            Bundle & operator = ( String identifier );
            Bundle & operator = ( URL url );
            
            virtual CFTypeID  GetTypeID( void ) const;
            virtual CFTypeRef GetCFObject( void ) const;
            
            bool IsExecutableLoaded( void );
            bool PreflightExecutable( Error * error = NULL );
            bool LoadExecutable( Error * error = NULL );
            void UnloadExecutable( void );
            
            URL GetAuxiliaryExecutableURL( String executableName );
            URL GetBuiltInPlugInsURL( void );
            URL GetExecutableURL( void );
            URL GetPrivateFrameworksURL( void );
            URL GetResourcesDirectoryURL( void );
            URL GetSharedFrameworksURL( void );
            URL GetSharedSupportURL( void );
            URL GetSupportFilesDirectoryURL( void );
            
            void            CloseBundleResourceMap( CFBundleRefNum refNum );
            URL             GetResourceURL( String resourceName, String resourceType, String subDirName );
            Array           GetResourceURLsOfType( String resourceType, String subDirName );
            URL             GetResourceURLForLocalization( String resourceName, String resourceType, String subDirName, String localizationName );
            Array           GetResourceURLsOfTypeForLocalization( String resourceType, String subDirName, String localizationName );
            SInt32          OpenBundleResourceFiles( CFBundleRefNum * refNum, CFBundleRefNum * localizedRefNum );
            CFBundleRefNum  OpenBundleResourceMap( void );
            
            Array   GetBundleLocalizations( void );
            String  GetLocalizedString( String key, String value, String tableName );
            
            void      * GetDataPointerForName( String symbolName );
            void        GetDataPointersForNames( Array symbolNames, void * stbl[] );
            void      * GetFunctionPointerForName( String functionName );
            void        GetFunctionPointersForNames( Array functionNames, void * ftbl[] );
            CFPlugInRef GetPlugIn( void );

            URL         GetBundleURL( void );
            String      GetDevelopmentRegion( void );
            String      GetIdentifier( void );
            Dictionary  GetInfoDictionary( void );
            Dictionary  GetLocalInfoDictionary( void );
            CFTypeRef   GetValueForInfoDictionaryKey( String key );
            void        GetPackageInfo( UInt32 * packageType, UInt32 * packageCreator );
            Array       GetExecutableArchitectures( void );
            UInt32      GetVersionNumber( void );
            
            friend void swap( Bundle & v1, Bundle & v2 );
            
        private:
            
            CFBundleRef _cfObject;
    };
}

#endif /* CFPP_BUNDLE_H */
