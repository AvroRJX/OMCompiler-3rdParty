/*
 * -----------------------------------------------------------------
 * $Revision: 4402 $
 * $Date: 2015-02-28 19:35:39 -0800 (Sat, 28 Feb 2015) $
 * -----------------------------------------------------------------
 * Programmer(s): Carol Woodward @ LLNL
 * -----------------------------------------------------------------
 * LLNS Copyright Start
 * Copyright (c) 2015, Lawrence Livermore National Security
 * This work was performed under the auspices of the U.S. Department 
 * of Energy by Lawrence Livermore National Laboratory in part under 
 * Contract W-7405-Eng-48 and in part under Contract DE-AC52-07NA27344.
 * Produced at the Lawrence Livermore National Laboratory.
 * All rights reserved.
 * For details, see the LICENSE file.
 * LLNS Copyright End
 * -----------------------------------------------------------------
 * This is the implementation file for the Fortran interface to
 * the IDAKLU solver. See fida.h for usage.
 * -----------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include "fida.h"
#include "ida_impl.h"
#include <ida/ida_klu.h>
 
/*
 * ----------------------------------------------------------------
 * Function : FIDA_KLU
 * ----------------------------------------------------------------
 */

void FIDA_KLU(int *neq, int *nnz, int *ordering, int *ier)
{
  *ier = IDAKLU(IDA_idamem, *neq, *nnz);
  IDAKLUSetOrdering(IDA_idamem, *ordering);
  IDA_ls = IDA_LS_KLU;
}

/*
 * ----------------------------------------------------------------
 * Function : FIDA_KLUReinit
 * ----------------------------------------------------------------
 */

void FIDA_KLUREINIT(int *neq, int *nnz, int *reinit_type, int *ier)
{
  *ier = IDAKLUReInit(IDA_idamem, *neq, *nnz, *reinit_type);
}

