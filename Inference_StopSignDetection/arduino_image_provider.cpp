/* Copyright 2019 The TensorFlow Authors. All Rights Reserved.
  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at
  http://www.apache.org/licenses/LICENSE-2.0
  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
  ==============================================================================*/

#include "image_provider.h"

#ifndef ARDUINO_EXCLUDE_CODE

#include "Arduino.h"
#include <TinyMLShield.h>

// Get an image from the camera module
TfLiteStatus GetImage(tflite::ErrorReporter* error_reporter, int image_width,
                      int image_height, int channels, int8_t* image_data) {

  byte data[176 * 144]; // Receiving QCIF grayscale from camera = 176 * 144 * 1

  static bool g_is_camera_initialized = false;
  static bool serial_is_initialized = false;

  // Initialize camera if necessary
  if (!g_is_camera_initialized) {
    if (!Camera.begin(QCIF, GRAYSCALE, 5, OV7675)) {
      TF_LITE_REPORT_ERROR(error_reporter, "Failed to initialize camera!");
      return kTfLiteError;
    }
    g_is_camera_initialized = true;
  }

  // Read camera data
  Camera.readFrame(data);

  int min_x = (176 - 96) / 2;
  int min_y = (144 - 96) / 2;
  int index = 0;

  float scaleX = 176.0 / 96.0;
  float scaleY = 144.0 / 96.0;

  for (int y = 0; y < 96; y++) {
    int srcY = (int)(y * scaleY);
    for (int x = 0; x < 96; x++) {
      int srcX = (int)(x * scaleX);
      uint8_t pixel = data[srcY * 176 + srcX];
      image_data[index++] = static_cast<int8_t>(pixel - 128);
    }
  }

  return kTfLiteOk;
}

#endif  // ARDUINO_EXCLUDE_CODE