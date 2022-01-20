#include "GPRegressor.h"

void test() {
    R__LOAD_LIBRARY(libgproot);
    std::vector<double> pars = {1., 1.};
    RationalQuadraticKernel kern = RationalQuadraticKernel(pars);
    GPRegressor reg = GPRegressor(kern);
    std::vector<GPPoint> x = {{0},{1},{2},{3}};
    std::vector<GPPoint> x_new = {{0.5},{1.5},{2.5},{3.5}};
    TVectorD y(0,3,0.,1.,2.,3.,"END");
    reg.Fit(x, y);
    reg.Predict(x_new);
    TVectorD yhat = reg.PosteriorMean();
    TVectorD ystd = reg.PosteriorStd();
    yhat.Print();
    ystd.Print();
}

