// This file is part of Hermes2D.
//
// Hermes2D is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Hermes2D is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Hermes2D.  If not, see <http://www.gnu.org/licenses/>.

#ifndef __HERMES_COMMON_TUPLE_H
#define __HERMES_COMMON_TUPLE_H

#include <vector>

/// A vector of values.
/** This class is used to pass a variable number of parameters in a type-safe fashion.
 *  \par Suggested Use
 *  Let us assume a function foo(const Tuple<Solution*>&) and instances sln1-sln3 of a class Solution. Then,
 *  - 1 parameter: foo(&sln1);
 *  - 2 up to 10 parameters: foo(Tuple<double>(&sln1, &sln2, &sln3));
 *  - more than 10 parameters: Fill the instance similar to STL vector (std::vector). */
template<typename T>
class HERMES_API Tuple: public std::vector<T> {
public:
  /// A default constructor. Creates an empty vector.
  explicit Tuple() {};
  /// 1 parameter constructor.
  Tuple(const T& a) { push_back(a); };
  /// 2 parameters constructor.
  Tuple(const T& a, const T& b) { std::vector<T>::reserve(2); push_back(a); push_back(b); };
  /// 3 parameters constructor.
  Tuple(const T& a, const T& b, const T& c) { std::vector<T>::reserve(3); push_back(a); push_back(b); push_back(c); };
  /// 4 parameters constructor.
  Tuple(const T& a, const T& b, const T& c, const T& d) { std::vector<T>::reserve(4); push_back(a); push_back(b); push_back(c); push_back(d); };
  /// 5 parameters constructor.
  Tuple(const T& a, const T& b, const T& c, const T& d, const T& e) { std::vector<T>::reserve(5); push_back(a); push_back(b); push_back(c); push_back(d); push_back(e); };
  /// 6 parameters constructor.
  Tuple(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f) { std::vector<T>::reserve(6); push_back(a); push_back(b); push_back(c); push_back(d); push_back(e); push_back(f); };
  /// 7 parameters constructor.
  Tuple(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g) { std::vector<T>::reserve(7); push_back(a); push_back(b); push_back(c); push_back(d); push_back(e); push_back(f); push_back(g); };
  /// 8 parameters constructor.
  Tuple(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h) { std::vector<T>::reserve(8); push_back(a); push_back(b); push_back(c); push_back(d); push_back(e); push_back(f); push_back(g); push_back(h); };
  /// 9 parameters constructor.
  Tuple(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h, const T& i) { std::vector<T>::reserve(9); push_back(a); push_back(b); push_back(c); push_back(d); push_back(e); push_back(f); push_back(g); push_back(h); push_back(i); };
  /// 10 parameters constructor.
  Tuple(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h, const T& i, const T& j) { std::vector<T>::reserve(10); push_back(a); push_back(b); push_back(c); push_back(d); push_back(e); push_back(f); push_back(g); push_back(h); push_back(i); push_back(j); };
};

#endif
