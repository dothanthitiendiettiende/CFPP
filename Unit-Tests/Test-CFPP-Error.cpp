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
 * @file        CFPP-Error.cpp
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    Unit tests for CF::Error
 */

#include <CF++.h>
#include <GoogleMock/GoogleMock.h>

using namespace testing;

TEST( CFPP_Error, CTOR )
{}

TEST( CFPP_Error, CTOR_CFType )
{}

TEST( CFPP_Error, CTOR_CFError )
{}

TEST( CFPP_Error, CTOR_StringDomain_NumberCode )
{}

TEST( CFPP_Error, CTOR_StringDomain_NumberCode_DictionaryInfo )
{}

TEST( CFPP_Error, CTOR_CFDomain_CFCode )
{}

TEST( CFPP_Error, CTOR_CFDomain_CFCode_CFInfo )
{}

TEST( CFPP_Error, CTOR_STDStringDomain_CFCode )
{}

TEST( CFPP_Error, CTOR_STDStringDomain_CFCode_DictionaryInfo )
{}

TEST( CFPP_Error, CTOR_CCharDomain_CFCode )
{}

TEST( CFPP_Error, CTOR_CCharDomain_CFCode_DictionaryInfo )
{}

TEST( CFPP_Error, CCTOR )
{
    CF::Error e1( "com.xs-labs", 42 );
    CF::Error e2( e1 );
    
    ASSERT_TRUE( e2.IsValid() );
    ASSERT_EQ( e2.GetDomain(), "com.xs-labs" );
    ASSERT_EQ( e2.GetCode(), 42 );
}

TEST( CFPP_Error, MCTOR )
{
    CF::Error e1( "com.xs-labs", 42 );
    CF::Error e2( std::move( e1 ) );
    
    ASSERT_FALSE( e1.IsValid() );
    ASSERT_TRUE(  e2.IsValid() );
    ASSERT_EQ( e2.GetDomain(), "com.xs-labs" );
    ASSERT_EQ( e2.GetCode(), 42 );
}

TEST( CFPP_Error, OperatorEqualError )
{
    CF::Error e1( "com.xs-labs", 42 );
    CF::Error e2( "org.xs-labs", 0 );
    
    e2 = e1;
    
    ASSERT_TRUE(  e2.IsValid() );
    ASSERT_EQ( e2.GetDomain(), "com.xs-labs" );
    ASSERT_EQ( e2.GetCode(), 42 );
}

TEST( CFPP_Error, OperatorEqualCFType )
{
    CF::Error e1( "com.xs-labs", 42 );
    CF::Error e2( "org.xs-labs", 0 );
    
    e2 = static_cast< CFTypeRef >( e1.GetCFObject() );
    
    ASSERT_TRUE(  e2.IsValid() );
    ASSERT_EQ( e2.GetDomain(), "com.xs-labs" );
    ASSERT_EQ( e2.GetCode(), 42 );
    
    e2 = static_cast< CFTypeRef >( NULL );
    
    ASSERT_FALSE( e2.IsValid() );
}

TEST( CFPP_Error, OperatorEqualCFError )
{
    CF::Error e1( "com.xs-labs", 42 );
    CF::Error e2( "org.xs-labs", 0 );
    
    e2 = static_cast< CFErrorRef >( const_cast< void * >( e1.GetCFObject() ) );
    
    ASSERT_TRUE(  e2.IsValid() );
    ASSERT_EQ( e2.GetDomain(), "com.xs-labs" );
    ASSERT_EQ( e2.GetCode(), 42 );
    
    e2 = static_cast< CFErrorRef >( NULL );
    
    ASSERT_FALSE( e2.IsValid() );
}

TEST( CFPP_Error, GetTypeID )
{
    CF::Error e;
    
    ASSERT_EQ( e.GetTypeID(), CFErrorGetTypeID() );
}

TEST( CFPP_Error, GetCFObject )
{
    CF::Error e1( "com.xs-labs", 42 );
    CF::Error e2;
    
    ASSERT_TRUE( e1.GetCFObject() != NULL );
    ASSERT_TRUE( e2.GetCFObject() == NULL );
    ASSERT_EQ( CFGetTypeID( e1.GetCFObject() ), CFErrorGetTypeID() );
}

TEST( CFPP_Error, GetDomain )
{
    CF::Error e1( "com.xs-labs", 42 );
    CF::Error e2;
    
    ASSERT_EQ( e1.GetDomain(), "com.xs-labs" );
    ASSERT_EQ( e2.GetDomain(), "" );
}

TEST( CFPP_Error, GetCode )
{
    CF::Error e1( "com.xs-labs", 42 );
    CF::Error e2;
    
    ASSERT_EQ( e1.GetCode(), 42 );
    ASSERT_EQ( e2.GetCode(), 0 );
}

TEST( CFPP_Error, GetUserInfo )
{
    CF::Dictionary info;
    
    info << CF::Pair( CF::String( "hello" ), CF::String( "hello, world" ) );
    
    {
        CF::Dictionary i;
        CF::Error      e( "com.xs-labs", 42, info );
        
        ASSERT_GT( e.GetUserInfo().GetCount(), 0 );
        ASSERT_EQ( CF::String( e.GetUserInfo()[ "hello" ] ), "hello, world" );
        
        e = static_cast< CFErrorRef >( NULL );
        
        ASSERT_FALSE( e.IsValid() );
        ASSERT_EQ( e.GetUserInfo().GetCount(), 0 );
    }
}

TEST( CFPP_Error, GetDescription )
{
    CF::Dictionary info;
    
    info << CF::Pair( CF::String( kCFErrorLocalizedDescriptionKey ), CF::String( "hello, world" ) );
    
    {
        CF::Error e( "com.xs-labs", 42, info );
        
        ASSERT_EQ( e.GetDescription(), "hello, world" );
        
        e = static_cast< CFErrorRef >( NULL );
        
        ASSERT_FALSE( e.IsValid() );
        ASSERT_EQ( e.GetDescription(), "" );
    }
}

TEST( CFPP_Error, GetFailureReason )
{
    CF::Dictionary info;
    
    info << CF::Pair( CF::String( kCFErrorLocalizedFailureReasonKey ), CF::String( "hello, world" ) );
    
    {
        CF::Error e( "com.xs-labs", 42, info );
        
        ASSERT_EQ( e.GetFailureReason(), "hello, world" );
        
        e = static_cast< CFErrorRef >( NULL );
        
        ASSERT_FALSE( e.IsValid() );
        ASSERT_EQ( e.GetFailureReason(), "" );
    }
}

TEST( CFPP_Error, GetRecoverySuggestion )
{
    CF::Dictionary info;
    
    info << CF::Pair( CF::String( kCFErrorLocalizedRecoverySuggestionKey ), CF::String( "hello, world" ) );
    
    {
        CF::Error e( "com.xs-labs", 42, info );
        
        ASSERT_EQ( e.GetRecoverySuggestion(), "hello, world" );
        
        e = static_cast< CFErrorRef >( NULL );
        
        ASSERT_FALSE( e.IsValid() );
        ASSERT_EQ( e.GetRecoverySuggestion(), "" );
    }
}

TEST( CFPP_Error, Swap )
{
    CF::Error e1( "com.xs-labs", 42 );
    CF::Error e2;
    
    swap( e1, e2 );
    
    ASSERT_FALSE( e1.IsValid() );
    ASSERT_TRUE(  e2.IsValid() );
    ASSERT_EQ( e2.GetDomain(), "com.xs-labs" );
    ASSERT_EQ( e2.GetCode(), 42 );
}
