// mult.cpp
#include "mex.h"
#include "triple.h"

// MEX gateway function
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    // Check number of input and output arguments
    if (nrhs != 1) {
        mexErrMsgIdAndTxt("mult:input", "One input required.");
    }
    if (nlhs > 1) {
        mexErrMsgIdAndTxt("mult:output", "Too many output arguments.");
    }
    
    // Check that  input is a scalar
    if (!mxIsDouble(prhs[0]) || mxIsComplex(prhs[0]) || mxGetNumberOfElements(prhs[0]) != 1) {
        mexErrMsgIdAndTxt("mult:input", "Input must be a non-complex scalar double.");
    }
    
    // Get the scalar double from the input
    double input = mxGetScalar(prhs[0]);
    
    // Call the C++ function
    double output = triple(input);
    
    // Create output argument
    plhs[0] = mxCreateDoubleScalar(output);
}