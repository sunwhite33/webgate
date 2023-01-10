/*
 * Copyright (C) Chen Xi.
 *
 * Version definitions.
 * Written by Chen Xi <sunwhite@gmail.com> Jan 2023
 */

#ifndef _VER_H_
#define _VER_H_

#define WEBGATE_VER_MAJOR        0
#define WEBGATE_VER_MINOR        1
#define WEBGATE_VER_MICRO        0
#define WEBGATE_VER_QUALIFIER    "build-585448"

#define WEBGATE_VER              WEBGATE_VERSION_MAJOR##WEBGATE_VERSION_MINOR##WEBGATE_VERSION_MICRO
#define WEBGATE_VER_BUILD        WEBGATE_VER ## " (" ## WEBGATE_VER_QUALIFIER ## ")"

#define WEBGATE_VERSION          WEBGATE_VERSION_MAJOR##"."##WEBGATE_VERSION_MINOR##"."##WEBGATE_VERSION_MICRO##WEBGATE_VERSION_QUALIFIER
#define WEBGATE_VERSION_NAME     "webgate/" ## WEBGATE_VERSION

#endif /* _VER_H_ */
