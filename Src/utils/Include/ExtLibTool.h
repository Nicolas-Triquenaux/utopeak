/*
 * UtoPeak - Automatic Estimation of DVFS Potential
 * Copyright (C) 2013 Universite de Versailles
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef H_EXTLIBTOOL
#define H_EXTLIBTOOL

typedef double (*evalGet)(void *data);
typedef  void* (*evalInit)(void);
typedef int (*evalClose)(void *data);

/* tempral function pointers */
evalGet tmpEvaluationStart;

typedef struct ProbeLib
{
	char* pLibName;
   void* pLibHandle;
   void* pProbeHandle;
   
	evalGet evaluationStart;   
	evalGet evaluationStop;    
	evalInit evaluationInit;   
	evalClose evaluationClose;    
   double start;
   double stop;
   double elapsed;
}ProbeLib;

int loadProbeLib(const char* pLibFileName, ProbeLib* pProbeLib);
void closeProbeLib(ProbeLib* pProbeLib);
void startProbeMeasure(ProbeLib* pProbeLib);
double stopProbeMeasure(ProbeLib* pProbeLib);

#endif

