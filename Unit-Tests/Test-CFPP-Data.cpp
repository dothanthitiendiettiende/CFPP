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
 * @file        Test-CFPP-Data.cpp
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    Unit tests for CF::Data
 */

#include <CF++.hpp>
#include <GoogleMock/GoogleMock.h>

using namespace testing;

static CF::Data::Byte __bytes[] = { 0xDE, 0xAD, 0xBE, 0xEF };

TEST( CFPP_Data, CTOR )
{
    CF::Data d;
    
    ASSERT_TRUE( d.IsValid() );
    ASSERT_EQ( d.GetLength(), 0 );
}

TEST( CFPP_Data, CTOR_AutoPointer )
{
    CF::Data d1( CF::AutoPointer( CFDataCreateMutable( NULL, 10 ) ) );
    CF::Data d2( CF::AutoPointer( CFUUIDCreate( NULL ) ) );
    CF::Data d3( CF::AutoPointer( NULL ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    ASSERT_FALSE( d3.IsValid() );
}

TEST( CFPP_Data, CTOR_CFType )
{
    CF::Data d1( static_cast< CFTypeRef >( CF::Data().GetCFObject() ) );
    CF::Data d2( static_cast< CFTypeRef >( NULL ) );
    CF::Data d3( static_cast< CFTypeRef >( CF::Boolean().GetCFObject() ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    ASSERT_FALSE( d3.IsValid() );
}

TEST( CFPP_Data, CTOR_CFData )
{
    CF::Data d1( static_cast< CFDataRef >( CF::Data().GetCFObject() ) );
    CF::Data d2( static_cast< CFDataRef >( NULL ) );
    CF::Data d3( static_cast< CFDataRef >( CF::Boolean().GetCFObject() ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    ASSERT_FALSE( d3.IsValid() );
}

TEST( CFPP_Data, CTOR_CFString )
{
    CF::Data d1( static_cast< CFStringRef >( CFSTR( "hello, world" ) ) );
    CF::Data d2( static_cast< CFStringRef >( NULL ) );
    CF::Data d3( static_cast< CFStringRef >( CF::Boolean().GetCFObject() ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    ASSERT_FALSE( d3.IsValid() );
}

TEST( CFPP_Data, CTOR_STDString )
{
    CF::Data d1( std::string( "hello, world" ) );
    CF::Data d2( std::string( "" ) );
    
    ASSERT_TRUE( d1.IsValid() );
    ASSERT_TRUE( d2.IsValid() );
}

TEST( CFPP_Data, CTOR_BytePtr )
{
    CF::Data d1( __bytes, sizeof( __bytes ) );
    CF::Data d2( NULL,    sizeof( __bytes ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
}

TEST( CFPP_Data, CCTOR )
{
    CF::Data d1;
    CF::Data d2( static_cast< CFDataRef >( NULL ) );
    CF::Data d3( d1 );
    CF::Data d4( d2 );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    ASSERT_TRUE(  d3.IsValid() );
    ASSERT_FALSE( d4.IsValid() );
}

#ifdef CFPP_HAS_CPP11
TEST( CFPP_Data, MCTOR )
{
    CF::Data d1;
    CF::Data d2( static_cast< CFDataRef >( NULL ) );
    CF::Data d3( std::move( d1 ) );
    CF::Data d4( std::move( d2 ) );
    
    ASSERT_FALSE( d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    ASSERT_TRUE(  d3.IsValid() );
    ASSERT_FALSE( d4.IsValid() );
}
#endif

TEST( CFPP_Data, OperatorAssignData )
{
    CF::Data d1( __bytes, sizeof( __bytes ) );
    CF::Data d2( static_cast< CFDataRef >( NULL ) );
    CF::Data d3;
    CF::Data d4;
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    ASSERT_TRUE(  d3.IsValid() );
    ASSERT_TRUE(  d4.IsValid() );
    
    ASSERT_TRUE( d1.GetLength() == sizeof( __bytes ) );
    
    d3 = d1;
    d4 = d2;
    
    ASSERT_TRUE(  d3.IsValid() );
    ASSERT_FALSE( d4.IsValid() );
    
    ASSERT_TRUE( d3.GetLength() == sizeof( __bytes ) );
}

TEST( CFPP_Data, OperatorAssignAutoPointer )
{
    CF::Data d1( static_cast< CFTypeRef >( NULL ) );
    CF::Data d2;
    CF::Data d3;
    
    ASSERT_FALSE( d1.IsValid() );
    ASSERT_TRUE(  d2.IsValid() );
    ASSERT_TRUE(  d3.IsValid() );
    
    d1 = CF::AutoPointer( CFDataCreateMutable( NULL, 10 ) );
    d2 = CF::AutoPointer( CFUUIDCreate( NULL ) );
    d3 = CF::AutoPointer( NULL );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    ASSERT_FALSE( d3.IsValid() );
}

TEST( CFPP_Data, OperatorAssignCFType )
{}

TEST( CFPP_Data, OperatorAssignCFData )
{}

TEST( CFPP_Data, OperatorAssignCFString )
{}

TEST( CFPP_Data, OperatorAssignSTDString )
{}

TEST( CFPP_Data, CastToBytePtr )
{}

TEST( CFPP_Data, CastToSTDString )
{}

TEST( CFPP_Data, OperatorSubscript )
{}

TEST( CFPP_Data, OperatorPlusEqualByte )
{}

TEST( CFPP_Data, OperatorPlusEqualCFString )
{}

TEST( CFPP_Data, OperatorPlusEqualCFData )
{}

TEST( CFPP_Data, OperatorPlusEqualSTDString )
{}

TEST( CFPP_Data, GetTypeID )
{
    CF::Data d;
    
    ASSERT_EQ( d.GetTypeID(), CFDataGetTypeID() );
}

TEST( CFPP_Data, GetCFObject )
{
    CF::Data d1;
    CF::Data d2( static_cast< CFStringRef >( NULL ) );
    
    ASSERT_TRUE( d1.GetCFObject() != NULL );
    ASSERT_TRUE( d2.GetCFObject() == NULL );
    
    ASSERT_EQ( CFGetTypeID( d1.GetCFObject() ), CFDataGetTypeID() );
}

TEST( CFPP_Data, GetLength )
{}

TEST( CFPP_Data, SetLength )
{}

TEST( CFPP_Data, IncreaseLength )
{}

TEST( CFPP_Data, GetBytePtr )
{}

TEST( CFPP_Data, GetMutableBytePtr )
{}

TEST( CFPP_Data, GetBytes )
{}

TEST( CFPP_Data, AppendBytes )
{}

TEST( CFPP_Data, ReplaceBytes )
{}

TEST( CFPP_Data, DeleteBytes )
{}

TEST( CFPP_Data, Swap )
{
    CF::Data d1;
    CF::Data d2( static_cast< CFDataRef >( NULL ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    
    swap( d1, d2 );
    
    ASSERT_FALSE( d1.IsValid() );
    ASSERT_TRUE(  d2.IsValid() );
}
