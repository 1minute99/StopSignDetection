# 🛑 Stop Sign Detection (Embedded TinyML Project)

An **end-to-end embedded AI project** for **real-time Stop Sign Detection** using **Arduino Nano 33 BLE + TinyML Shield**.  
The device captures hand gesture images, runs **on-device deep learning inference**, and provides **LED feedback**:

- 🔵 **Blue**: Capturing image  
- 🟢 **Green**: Stop sign detected  
- 🔴 **Red**: No stop sign detected  

This project demonstrates **TinyML deployment**, from **custom data collection → model training → TFLite conversion → microcontroller inference**.

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
     Input (96×96×1)
   → DepthwiseConv2D
   → Conv2D(8) + ReLU
   → MaxPooling2D
   → DepthwiseConv2D
   → Conv2D(16) + ReLU
   → MaxPooling2D
   → Conv2D(4) + ReLU
   → Flatten
   → Dense(2, Softmax)
- **Parameters:** 4,928 (~19 KB)  
- **Test Accuracy:** 97.5%  
- **Inference Speed:** ~3.3 FPS on Arduino Nano 33 BLE

---

## 🚀 Deployment Pipeline

1. **Model Training & Quantization** (`main.ipynb`)  
2. **Convert Keras → TFLite → C++ array (`model_data.cpp`)**  
3. **Deploy to Arduino** via `inference_StopSignDetection`  
   - Based on **TensorFlow Lite Micro Person Detection** example  
   - Inference loop modified for **custom Stop Sign detection & LED feedback**

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
