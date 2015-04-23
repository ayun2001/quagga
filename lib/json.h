/* json support for quagga
 * Copyright (C) 2015 Donald Sharp, CumulusNetworks.com

This file is part of GNU Zebra.

GNU Zebra is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 2, or (at your option) any
later version.

GNU Zebra is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU Zebra; see the file COPYING.  If not, write to the Free
Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
02111-1307, USA.  */

#if !defined(__BGP_JSON_H__)
#define __BGP_JSON_H__

#if defined(HAVE_JSON)
#include <json/json.h>

#define JSON_STR      " {json}"
#define JSON_HELP_STR "JavaScript Object Notation\n"
#define JSON_VALUE(X) ((X) != NULL)

#else

/*
 * If the platform does not have json libraries installed
 * Just have the cli not show up and have the code
 * silently do nothing.  It should not be called though.
 * These functions are used to just compile properly
 */
#define JSON_STR      ""
#define JSON_HELP_STR ""
#define JSON_VALUE(X) 0

typedef void json_object;

inline json_object *json_object_new_object (void)
{
  return NULL;
}

inline json_object *json_object_new_array (void)
{
  return NULL;
}

inline json_object *json_object_new_int (int value)
{
  return NULL;
}

inline json_object *json_object_new_string (const char *str)
{
  return NULL;
}

inline void json_object_object_add (json_object *a, const char *str, json_object *b)
{
  return;
}

inline void json_object_pug (json_object *obj)
{
  return;
}

inline char * json_object_to_json_string (json_object *obj)
{
  return NULL;
}

inline void json_object_array_add (json_object *obj1, json_object *obj2)
{
  return;
}
#endif

#endif
