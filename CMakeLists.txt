################################################################################
#
# medInria
#
# Copyright (c) INRIA 2018. All rights reserved.
# See LICENSE.txt for details.
# 
#  This software is distributed WITHOUT ANY WARRANTY; without even
#  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
#  PURPOSE.
#
################################################################################

cmake_minimum_required(VERSION 3.2)

if(NOT DEFINED ${MEDINRIA_SUPERBUILD_VERSION})
    set(MEDINRIA_SUPERBUILD_VERSION 3.0.1)
endif()

SET(CMAKE_CXX_STANDARD 11)

project(MEDINRIA_SUPERBUILD VERSION ${MEDINRIA_SUPERBUILD_VERSION})

add_subdirectory(superbuild)
