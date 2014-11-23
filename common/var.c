/**
 *  naken_asm assembler.
 *  Author: Michael Kohn
 *   Email: mike@mikekohn.net
 *     Web: http://www.mikekohn.net/
 * License: GPL
 *
 * Copyright 2010-2014 by Michael Kohn
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#include "var.h"

#define VAR_RETURN_VALUE(var,ret_type) \
  if (var->type == VAR_INT) \
  { \
    return (ret_type)var->value_int; \
  } \
    else \
  if (var->type == VAR_FLOAT) \
  { \
    return (ret_type)var->value_float; \
  }

void var_set_int(struct _var *var, uint64_t value)
{
  var->value_int = value;
  var->type = VAR_INT;
}

void var_set_float(struct _var *var, double value)
{
  var->value_float = value;
  var->type = VAR_FLOAT;
}

uint32_t var_get_int32(struct _var *var)
{
  VAR_RETURN_VALUE(var,uint32_t);

  assert(0);

  return 0;
}

uint64_t var_get_int64(struct _var *var)
{
  VAR_RETURN_VALUE(var,uint64_t);

  assert(0);

  return 0;
}

float var_get_float(struct _var *var)
{
  VAR_RETURN_VALUE(var,float);

  assert(0);

  return 0;
}

double var_get_double(struct _var *var)
{
  VAR_RETURN_VALUE(var,double);

  assert(0);

  return 0;
}

int var_add(struct _var *var_d, struct _var *var_s)
{
  if (var_d->type == VAR_INT && var_d->type == VAR_INT)
  {
    var_d->value_int = var_d->value_int + var_s->value_int;
  }
    else
  {
    var_d->value_float = var_get_double(var_d) + var_get_double(var_s);
    var_d->type = VAR_FLOAT;
  }

  return 0;
}

int var_sub(struct _var *var_d, struct _var *var_s)
{
  if (var_d->type == VAR_INT && var_d->type == VAR_INT)
  {
    var_d->value_int = var_d->value_int - var_s->value_int;
  }
    else
  {
    var_d->value_float = var_get_double(var_d) - var_get_double(var_s);
    var_d->type = VAR_FLOAT;
  }

  return 0;
}

int var_mul(struct _var *var_d, struct _var *var_s)
{
  if (var_d->type == VAR_INT && var_d->type == VAR_INT)
  {
    var_d->value_int = var_d->value_int * var_s->value_int;
  }
    else
  {
    var_d->value_float = var_get_double(var_d) * var_get_double(var_s);
    var_d->type = VAR_FLOAT;
  }

  return 0;
}

int var_div(struct _var *var_d, struct _var *var_s)
{
  if (var_d->type == VAR_INT && var_d->type == VAR_INT)
  {
    var_d->value_int = var_d->value_int / var_s->value_int;
  }
    else
  {
    var_d->value_float = var_get_double(var_d) / var_get_double(var_s);
    var_d->type = VAR_FLOAT;
  }

  return 0;
}

