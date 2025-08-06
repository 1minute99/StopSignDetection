# 🛑 Stop Sign Detection (Embedded TinyML Project)

An **end-to-end embedded AI project** for **real-time Stop Sign Detection** running entirely on an **Arduino Nano 33 BLE + TinyML Shield**.  
The system captures hand gesture images, performs **on-device deep learning inference**, and provides **LED feedback**:

- 🔵 **Blue**: Capturing image  
- 🟢 **Green**: Stop sign detected  
- 🔴 **Red**: No stop sign detected  

This project demonstrates a **full TinyML pipeline**:  
**Custom Data Collection → Model Training & Optimization → TFLite Conversion → Embedded Deployment & Inference**

---

## 📌 Project Summary

| Metric                        | Value                               |
|-------------------------------|-------------------------------------|
| **Input Size**                | 96 × 96 grayscale (1 channel)        |
| **Model Size (int8 TFLite)**   | ~20 KB                              |
| **Test Accuracy**              | **97.5%**                           |
| **Inference Speed**            | ~3.3 FPS (≈ 300 ms per frame)        |
| **Hardware**                   | Arduino Nano 33 BLE + TinyML Shield |
| **Training Data**              | ~2,000 images (Positive/Negative)    |
| **Dataset FPS**                | Extracted at 5 FPS from videos       |

---

## 🎥 Demo

![Demo GIF](demo.gif)

🔗 [Watch Full Demo on YouTube](https://youtu.be/lrnlHX9MhXQ)

---

## 📸 Data Collection & Preprocessing

1. **Hand Gesture Recording**  
   - Collected **positive (Stop Sign)** and **negative (Other)** hand gesture videos  
2. **Frame Extraction**  
   - `recording_to_image.ipynb` converts videos to **96×96 grayscale images** at **5 FPS**  
3. **Dataset**  
   - Sample dataset uploaded for reference  
   - Full dataset is private for **privacy reasons (face/hands visible)**

---

## 🧠 Model Overview

- **Custom Lightweight CNN** optimized for embedded devices  
- Designed using **Depthwise Separable Convolutions** (MobileNet-style)  
- **Architecture**:
   Input (96x96x1)
   ↓
   DepthwiseConv2D (3x3) + Conv2D(1x1, 8ch)
   ↓
   MaxPooling2D (2x2)
   ↓
   DepthwiseConv2D (3x3) + Conv2D(1x1, 16ch)
   ↓
   MaxPooling2D (2x2)
   ↓
   Conv2D(1x1, 4ch)
   ↓
   Flatten → Dense(2, softmax)
- **Parameters:** 4,928 (~19 KB)  
- **Test Accuracy:** 96.5%  
- **Inference Speed:** ~3.3 FPS on Arduino Nano 33 BLE

---

## 🚀 Deployment Pipeline

1. **Model Training & Quantization** (`main.ipynb`)  
2. **Convert Keras → TFLite → C++ array (`model_data.cpp`)**  
3. **Deploy to Arduino** via `inference_StopSignDetection`  
   - Based on **TensorFlow Lite Micro Person Detection** example  
   - Inference loop and other functions are modified for **custom Stop Sign detection & LED feedback**

---

## 📂 Project Structure

```plaintext
StopSignDetection/
├── dataset/                        # Full dataset (not uploaded)
│   └── samples/                    # Sample images for reference
│
├── inference_StopSignDetection/     # Embedded inference code
│   ├── model_data.cpp              # TFLite model as C++ array
│   └── main_functions.cpp          # Inference loop (LED control, model invoke)
│
├── main.ipynb                      # Data preprocessing, model building, training, TFLite conversion
├── recording_to_image.ipynb        # Extract frames from videos to images
├── requirements.txt
├── README.md
└── .gitignore
```

⚡ Hardware & Software
- Embedded Device: Arduino Nano 33 BLE + TinyML Shield
- Software: Python 3.9, TensorFlow 2.16, TFLite Micro, Arduino IDE 2.x
- OS: macOS

  📜 License & Credits
- Base Code: TensorFlow Lite Micro (Apache 2.0 License)
- This Project:
- Custom dataset & model (© 2025 Wonmin Kim)
- Modified from Person Detection example with significant changes:
   - Custom data pipeline
   - Lightweight CNN architecture
   - Input image preprocessing

