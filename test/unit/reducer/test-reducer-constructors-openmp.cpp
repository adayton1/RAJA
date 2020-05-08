//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// Copyright (c) 2016-20, Lawrence Livermore National Security, LLC
// and RAJA project contributors. See the RAJA/COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

///
/// Source file containing tests for RAJA reducer constructors and initialization.
///

#include "tests/test-reducer-constructors.hpp"

#include "test-reducer-utils.hpp"

#if defined(RAJA_ENABLE_OPENMP)
using OpenMPBasicReducerConstructorTypes = Test< camp::cartesian_product<
                                                        OpenMPReducerPolicyList,
                                                        DataTypeList,
                                                        HostResourceList
                                                      >
                             >::Types;

using OpenMPInitReducerConstructorTypes = Test< camp::cartesian_product<
                                                        OpenMPReducerPolicyList,
                                                        DataTypeList,
                                                        HostResourceList,
                                                        SequentialForoneList
                                                     >
                            >::Types;

INSTANTIATE_TYPED_TEST_CASE_P(OpenMPBasicTest,
                              ReducerBasicConstructorUnitTest,
                              OpenMPBasicReducerConstructorTypes);

INSTANTIATE_TYPED_TEST_CASE_P(OpenMPInitTest,
                              ReducerInitConstructorUnitTest,
                              OpenMPInitReducerConstructorTypes);
#endif

