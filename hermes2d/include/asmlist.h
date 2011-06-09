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

#ifndef __H2D_ASMLIST_H
#define __H2D_ASMLIST_H

#include "hermes2d_common_defs.h"


/// AsmList is a simple container for the element assembly arrays idx, dof and coef.
/// These arrays are filled by Space::get_element_assembly_list() and used by the
/// assembling procedure and the Solution class. The arrays are allocated and deallocated
/// automatically by the class. The class provides a list of triples (idx, dof, coef).
/// The triples are flattened to separate arrays of length 'cnt'.
///
template<typename Scalar>
class HERMES_API AsmList
{
public:

  int* idx;      ///< array of shape function indices
  int* dof;      ///< array of basis function numbers (DOFs)
  Scalar* coef;  ///< array of coefficients
  unsigned int cnt;       ///< the number of items in the arrays idx, dof and coef
  unsigned int cap;       ///< internal

  AsmList(const AsmList & other)
  {
    this->cnt = other.cnt;
    this->cap = other.cap;
    this->idx = (int*) malloc(sizeof(int) * cap);
    this->dof = (int*) malloc(sizeof(int) * cap);
    this->coef = (Scalar*) malloc(sizeof(Scalar) * cap);
    for(unsigned int i = 0; i < cnt; i++) {
      coef[i] = other.coef[i];
      dof[i] = other.dof[i];
      idx[i] = other.idx[i];
    }
  }

  AsmList()
  {
    idx = dof = NULL;
    coef = NULL;
    cnt = cap = 0;
  }

  ~AsmList()
  {
    free(idx);
    free(dof);
    free(coef);
  }

  void clear() { cnt = 0; }

  inline void add_triplet(int i, int d, Scalar c)
  {
    if (cnt >= cap) enlarge();
    idx[cnt] = i;
    dof[cnt] = d;
    coef[cnt++] = c;
  }

protected:
  void enlarge();
};

#endif
