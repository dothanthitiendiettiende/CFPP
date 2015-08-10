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
 * @file        Test-CFPP-Bundle.cpp
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    Unit tests for CF::Bundle
 */

#include <CF++.hpp>
#include <GoogleMock/GoogleMock.h>

using namespace testing;

TEST( CFPP_Bundle, GetAllBundles )
{
    CF::Array           a;
    CF::Array::Iterator i;
    CF::Bundle          b;
    
    a = CF::Bundle::GetAllBundles();
    
    ASSERT_TRUE( a.GetCount() > 0 );
    
    for( i = a.begin(); i != a.end(); ++i )
    {
        ASSERT_TRUE( CF::Bundle( *( i ) ).IsValid() );
    }
}

TEST( CFPP_Bundle, GetBundlesFromDirectory )
{}

TEST( CFPP_Bundle, GetBundleWithIdentifier )
{
    CF::Bundle b1;
    CF::Bundle b2;
    
    b1 = CF::Bundle::GetBundleWithIdentifier( "com.apple.CoreFoundation" );
    b2 = CF::Bundle::GetBundleWithIdentifier( "foo.bar" );
    
    ASSERT_TRUE(  b1.IsValid() );
    ASSERT_FALSE( b2.IsValid() );
}

TEST( CFPP_Bundle, GetMainBundle )
{
    CF::Bundle b;
    
    b = CF::Bundle::GetMainBundle();
    
    ASSERT_TRUE( b.IsValid() );
}

TEST( CFPP_Bundle, GetResourceURLInDirectory )
{}

TEST( CFPP_Bundle, GetResourceURLsOfTypeInDirectory )
{}

TEST( CFPP_Bundle, GetInfoDictionaryInDirectory )
{}

TEST( CFPP_Bundle, GetInfoDictionaryForURL )
{}

TEST( CFPP_Bundle, GetPackageInfoInDirectory )
{}

TEST( CFPP_Bundle, GetExecutableArchitecturesForURL )
{}

TEST( CFPP_Bundle, GetLocalizationsForPreferences )
{}

TEST( CFPP_Bundle, GetLocalizationsForURL )
{}

TEST( CFPP_Bundle, GetPreferredLocalizationsFromArray )
{}

TEST( CFPP_Bundle, CTOR )
{
    CF::Bundle b;
    
    ASSERT_FALSE( b.IsValid() );
}

TEST( CFPP_Bundle, CTOR_AutoPointer )
{}

TEST( CFPP_Bundle, CTOR_CFType )
{}

TEST( CFPP_Bundle, CTOR_CFBundle )
{}

TEST( CFPP_Bundle, CTOR_String )
{}

TEST( CFPP_Bundle, CTOR_URL )
{}

TEST( CFPP_Bundle, CCTOR )
{}

#ifdef CFPP_HAS_CPP11
TEST( CFPP_Bundle, MCTOR )
{}
#endif

TEST( CFPP_Bundle, OperatorAssignBundle )
{}

TEST( CFPP_Bundle, OperatorAssignAutoPointer )
{}

TEST( CFPP_Bundle, OperatorAssignCFType )
{}

TEST( CFPP_Bundle, OperatorAssignCFBundle )
{}

TEST( CFPP_Bundle, OperatorAssignString )
{}

TEST( CFPP_Bundle, OperatorAssignURL )
{}

TEST( CFPP_Bundle, GetTypeID )
{
    CF::Bundle b;
    
    ASSERT_EQ( b.GetTypeID(), CFBundleGetTypeID() );
}

TEST( CFPP_Bundle, GetCFObject )
{
    CF::Bundle b1;
    CF::Bundle b2;
    
    b2 = CF::Bundle::GetMainBundle();
    
    ASSERT_TRUE( b1.GetCFObject() == NULL );
    ASSERT_TRUE( b2.GetCFObject() != NULL );
    ASSERT_EQ( CFGetTypeID( b2.GetCFObject() ), CFBundleGetTypeID() );
}

TEST( CFPP_Bundle, IsExecutableLoaded )
{}

TEST( CFPP_Bundle, PreflightExecutable )
{}

TEST( CFPP_Bundle, LoadExecutable )
{}

TEST( CFPP_Bundle, UnloadExecutable )
{}

TEST( CFPP_Bundle, GetAuxiliaryExecutableURL )
{}

TEST( CFPP_Bundle, GetBuiltInPlugInsURL )
{}

TEST( CFPP_Bundle, GetExecutableURL )
{}

TEST( CFPP_Bundle, GetPrivateFrameworksURL )
{}

TEST( CFPP_Bundle, GetResourcesDirectoryURL )
{}

TEST( CFPP_Bundle, GetSharedFrameworksURL )
{}

TEST( CFPP_Bundle, GetSharedSupportURL )
{}

TEST( CFPP_Bundle, GetSupportFilesDirectoryURL )
{}

TEST( CFPP_Bundle, CloseBundleResourceMap )
{}

TEST( CFPP_Bundle, GetResourceURL )
{}

TEST( CFPP_Bundle, GetResourceURLsOfType )
{}

TEST( CFPP_Bundle, GetResourceURLForLocalization )
{}

TEST( CFPP_Bundle, GetResourceURLsOfTypeForLocalization )
{}

TEST( CFPP_Bundle, OpenBundleResourceFiles )
{}

TEST( CFPP_Bundle, OpenBundleResourceMap )
{}

TEST( CFPP_Bundle, GetBundleLocalizations )
{}

TEST( CFPP_Bundle, GetLocalizedString )
{}

TEST( CFPP_Bundle, GetDataPointerForName )
{}

TEST( CFPP_Bundle, GetDataPointersForNames )
{}

TEST( CFPP_Bundle, GetFunctionPointerForName )
{}

TEST( CFPP_Bundle, GetFunctionPointersForNames )
{}

TEST( CFPP_Bundle, GetPlugIn )
{}

TEST( CFPP_Bundle, GetBundleURL )
{}

TEST( CFPP_Bundle, GetDevelopmentRegion )
{}

TEST( CFPP_Bundle, GetIdentifier )
{}

TEST( CFPP_Bundle, GetInfoDictionary )
{}

TEST( CFPP_Bundle, GetLocalInfoDictionary )
{}

TEST( CFPP_Bundle, GetValueForInfoDictionaryKey )
{}

TEST( CFPP_Bundle, GetPackageInfo )
{}

TEST( CFPP_Bundle, GetExecutableArchitectures )
{}

TEST( CFPP_Bundle, GetVersionNumber )
{}

TEST( CFPP_Bundle, Swap )
{}
