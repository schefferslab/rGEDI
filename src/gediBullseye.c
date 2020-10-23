#include <R.h>
#include <Rinternals.h>
#include <Rembedded.h>
#include "gedisimulator/gediIO.h"
#include "tools/tools.h"
#include "argParse.h"

#define main gediBullseye
#define control bullseye_control
#define readCommands readCommands_bullseye
    #include "gedisimulator/lvisBullseye.h"
    #include "gedisimulator/lvisBullseye.c"
#undef readCommands
#undef control
#undef main



SEXP C_gediBullseye(
    // Input and output
    SEXP output,
    SEXP als,
    SEXP gedi,
    SEXP listAls,
    SEXP listGedi,
    SEXP bounds,
    SEXP leaveEmpty,
    SEXP alsEPSG,
    SEXP gediEPSG,
    SEXP beamList,
    SEXP solveCofG,
    SEXP maxVshift,
    SEXP vStep,
    SEXP maxShift,
    SEXP step,
    SEXP simplex,
    SEXP anneal,
    SEXP fixFsig,
    SEXP geoError,
    SEXP quickGeo,
    SEXP optTol,
    SEXP maxIter,
    SEXP writeSimProg,
    SEXP writeWaves,
    SEXP nTriesAnneal,
    SEXP itersFixedT,
    SEXP kAnneal,
    SEXP tInitial,
    SEXP muAnneal,
    SEXP tMinAnneal,
    SEXP hOffset,
    SEXP offset,
    SEXP fSigma,
    SEXP pSigma,
    SEXP readPulse,
    SEXP minSense,
    SEXP maxZen,
    SEXP maxScanAng,
    SEXP minDense,
    SEXP decimate,
    SEXP noFilt,
    SEXP filtOut,
    SEXP smooth,
    SEXP noNorm,
    SEXP norm,
    SEXP allSimMeth,
    SEXP pulseBefore,
    SEXP noOctree,
    SEXP octLevels,
    SEXP nOctPix)
{
    int argc = 1;
    char *argv[136];
    const char* algName = "lvisBullseye";

    argv[0] = malloc((strlen(algName)+1) * sizeof(char));
    strcpy(argv[0], algName);

    PARSE_ARG(char, output);
    PARSE_ARG(char, als);
    PARSE_ARG(char, gedi);
    PARSE_ARG(char, listAls);
    PARSE_ARG(char, listGedi);
    PARSE_ARG(logical, leaveEmpty);
    PARSE_ARG(realArray, bounds);
    PARSE_ARG(int, alsEPSG);
    PARSE_ARG(int, gediEPSG);
    PARSE_ARG(char, beamList);
    PARSE_ARG(logical, solveCofG);
    PARSE_ARG(real, maxVshift);
    PARSE_ARG(real, vStep);
    PARSE_ARG(real, maxShift);
    PARSE_ARG(real, step);
    PARSE_ARG(logical, simplex);
    PARSE_ARG(logical, anneal);
    PARSE_ARG(logical, fixFsig);
    PARSE_ARG(realArray, geoError);
    PARSE_ARG(logical, quickGeo);
    PARSE_ARG(real, optTol);
    PARSE_ARG(int, maxIter);
    PARSE_ARG(logical, writeSimProg);
    PARSE_ARG(char, writeWaves);
    PARSE_ARG(int, nTriesAnneal);
    PARSE_ARG(int, itersFixedT);
    PARSE_ARG(real, kAnneal);
    PARSE_ARG(real, tInitial);
    PARSE_ARG(real, muAnneal);
    PARSE_ARG(real, tMinAnneal);
    PARSE_ARG(realArray, hOffset);
    PARSE_ARG(real, offset);
    PARSE_ARG(real, fSigma);
    PARSE_ARG(real, pSigma);
    PARSE_ARG(logical, readPulse);
    PARSE_ARG(real, minSense);
    PARSE_ARG(real, maxZen);
    PARSE_ARG(real, maxScanAng);
    PARSE_ARG(real, minDense);
    PARSE_ARG(real, decimate);
    PARSE_ARG(logical, noFilt);
    PARSE_ARG(logical, filtOut);
    PARSE_ARG(real, smooth);
    PARSE_ARG(logical, noNorm);
    PARSE_ARG(logical, norm);
    PARSE_ARG(logical, allSimMeth);
    PARSE_ARG(logical, pulseBefore);
    PARSE_ARG(logical, noOctree);
    PARSE_ARG(int, octLevels);
    PARSE_ARG(int, nOctPix);

    

#ifdef DEBUG   
    for (int i = 1; i < argc; i++) {
        Rprintf("%s ", argv[i]);
    }
#endif
    GetRNGstate();
    gediBullseye(argc, argv);
    GetRNGstate();

    for (int i = 0; i < argc; i++) {
        free(argv[i]);
    }

    
    return (ScalarInteger(0));
} 

#ifdef DEBUG
    #include "debug.c"

    int main() {
        initR();
        SEXP gridBound = PROTECT(allocVector(REALSXP, 4));
        double *pGridBound = REAL(gridBound);
        *(pGridBound++) = 278204;
        *(pGridBound++) = 278296;
        *(pGridBound++) = 602203;
        *(pGridBound++) = 602296;
        pGridBound = NULL;

        C_gediSimulator(
            mkString("E:/Documentos/sample.las"),
            mkString("E:/Documentos/sample.h5"),
            R_NilValue,
            R_NilValue,
            ScalarLogical(1),
            R_NilValue, 
            R_NilValue,

            R_NilValue, 
            R_NilValue,
            gridBound,
            ScalarReal(15.0),

            ScalarReal(-1.0),
            ScalarReal(15.0),
            R_NilValue,
            ScalarReal(5.5),
            R_NilValue,
            ScalarReal(0.15),
            R_NilValue,
            R_NilValue,
            R_NilValue,
            ScalarReal(0.0),

            R_NilValue,
            ScalarReal(1000000.0),
            ScalarReal(1.0),

            ScalarInteger(20000000),
            ScalarInteger(1024),
            R_NilValue,
            R_NilValue,
            ScalarLogical(1),
            R_NilValue,

            R_NilValue,
            ScalarInteger(0),
            ScalarInteger(40),

            R_NilValue,
            R_NilValue,
            R_NilValue,

            R_NilValue,
            R_NilValue,
            R_NilValue,
            R_NilValue,
            R_NilValue,
            ScalarInteger(200));

            UNPROTECT(1);
    }
#endif
