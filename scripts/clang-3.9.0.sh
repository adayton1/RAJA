#!/bin/bash

##
## Copyright (c) 2016, Lawrence Livermore National Security, LLC.
##
## Produced at the Lawrence Livermore National Laboratory.
##
## LLNL-CODE-689114
##
## All rights reserved.
##
## For additional details and restrictions, please see RAJA/LICENSE.txt
##

rm -rf build-clang-3.9.0 2>/dev/null
mkdir build-clang-3.9.0 && cd build-clang-3.9.0

RAJA_DIR=$(git rev-parse --show-toplevel)

cmake \
  -C ${RAJA_DIR}/host-configs/chaos/clang_3_9_0.cmake \
  -DCMAKE_INSTALL_PREFIX=../install-clang-3.9.0 \
  "$@" \
  ${RAJA_DIR}

#cmake \
#  -C ${RAJA_DIR}/host-configs/chaos/clang_3_9_0.cmake \
#  -DCMAKE_INSTALL_PREFIX=../install-clang-3.9.0 \
#  -DENABLE_PERFSUITE=On \
#  -DENABLE_APPLICATIONS=On \
#  "$@" \
#  ${RAJA_DIR}
