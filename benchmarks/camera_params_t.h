#pragma once

// Shared struct for passing OpenCV camera model params.
struct camera_params_t {
  double fx;
  double fy;
  double cx;
  double cy;
  double k1;
  double k2;
  double k3;
  double p1;
  double p2;
};
