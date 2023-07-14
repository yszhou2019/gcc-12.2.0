// { dg-options "-std=gnu++2a" }
// { dg-do compile { target c++2a } }
// { dg-require-gthreads "" }

// Copyright (C) 2020-2022 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

#include <thread>

template<typename Expected, typename T>
  struct check_type
  : std::false_type
  { };

template<typename Expected>
  struct check_type<Expected, Expected>
  : std::true_type
  { };

void test01()
{
  // thread::id operators
  std::thread::id id1;
  std::thread::id id2;

  static_assert( check_type<bool, decltype(id1 == id2)>{} );
  static_assert( check_type<bool, decltype(id1 != id2)>{} );
  static_assert( check_type<bool, decltype(id1 < id2)>{} );
  static_assert( check_type<bool, decltype(id1 > id2)>{} );
  static_assert( check_type<bool, decltype(id1 >= id2)>{} );
  static_assert( check_type<bool, decltype(id1 <= id2)>{} );

  static_assert( check_type<std::strong_ordering, decltype(id1 <=> id2)>{} );
}
