# 🛑 Stop Sign Detection (Embedded TinyML Project)

End-to-end **Stop Sign Detection** project running on an **embedded device** (Arduino Nano 33 BLE + TinyML Shield).  
When a hand makes a stop sign gesture, the device captures an image, classifies it using a **TinyML model**, and notifies the user via LED colors:

- 🔵 **Blue**: Image capturing  
- 🟢 **Green**: Stop sign detected  
- 🔴 **Red**: No stop sign detected  

---
## 🎥 Demo

![Demo GIF](demo.gif)

[Youtube Demo Video](https://youtu.be/lrnlHX9MhXQ)
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
