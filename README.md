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
├── dataset/                       # Full dataset (not uploaded for privacy)
│   └── samples/                   # Sample images for reference
│
├── inference_StopSignDetection/    # Inference code (modified from TF Person Detection)
│   ├── model_data.cpp             # Converted TFLite model for inference
│   └── main_functions.cpp         # Inference loop (LED control, model invoke)
│
├── main.ipynb                     # Data preprocessing, model building, training, TFLite conversion
├── recording_to_image.ipynb       # Extract frames from videos to images
├── requirements.txt
├── README.md
└── .gitignore

## 📸 Data Collection

1. **Video Recording**  
   - Recorded hand gestures for **Positive (Stop Sign)** and **Negative (Other)** samples  
2. **Frame Extraction**  
   - `recording_to_image.ipynb` converts videos into image datasets at **5 FPS**  
3. **Dataset**  
   - Input: **96×96 grayscale images**  
   - Only sample data uploaded (full dataset is private for privacy reasons)

---

## 🧠 Model

- **Lightweight CNN** using Depthwise Convolutions
- **Architecture:**  
  Input (96x96x1) → DepthwiseConv2D → Conv2D → MaxPooling2D → DepthwiseConv2D → Conv2D → MaxPooling2D → Conv2D → Flatten → Dense(2)

---

## 🚀 Deployment

1. Train model → Convert to **TFLite** → Convert to **C++ array (.cc)**  
2. Include `model_data.cpp` in `inference_StopSignDetection`  
3. The inference code is based on **TensorFlow Lite Micro Person Detection** example  
   - Apache 2.0 license maintained

---

## ⚡ Hardware & Environment

- **Arduino Nano 33 BLE + TinyML Shield**  
- **Python 3.9**, TensorFlow 2.16, TFLite Micro  
- MacOS + Arduino IDE 2.x

---

## 📊 Performance

- **Test Accuracy:** 97.5%  
- **Inference Speed:** 3.3 FPS  
- **LED feedback** indicates detection results in real-time

---

## 📜 License

- Base code from **TensorFlow Lite Micro (Apache 2.0 License)**
- Modifications: Custom dataset, preprocessing, model architecture, etc
- Custom dataset & model © 2025 Wonmin Kim
