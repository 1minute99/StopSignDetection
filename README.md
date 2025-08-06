# Stop Sign Detection on Embedded Device

This is an **end-to-end Stop Sign Detection** project using an **embedded device (Arduino Nano 33 BLE)**.  
When the user makes a hand gesture resembling a stop sign, the device captures an image, runs a deep learning model for classification, and lights up an LED:

- **Blue LED**: Capturing image  
- **Green LED**: Stop sign detected  
- **Red LED**: Stop sign not detected

---
## 🎥 Demo

![Demo GIF](demo.gif)
___


## 📂 Project Structure

StopSignDetection/
- dataset/                     # Full dataset (not uploaded for privacy)
- inference_StopSignDetection/
  - model_data.cpp           # Converted TFLite model for inference
  - main_functions.cpp       # Inference loop (modified from TF Person Detection)
- main.ipynb                   # Data preprocessing, model building, training, TFLite conversion
- recording_to_image.ipynb     # Extract frames from videos to images
- requirements.txt
- README.md
- .gitignore
