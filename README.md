# Making thermoelectric current visible: Arduino data acquisition with Blynk mobile visualisation in physics classroom
<br>
<b>Prapawan Thongsri, Kornchawal Chaipah and Niwat Srisawasdi*</b><br>
*Corresponding author:<a href= "mailto: niwsri@kku.ac.th"> niwsri@kku.ac.th </a><br>
<br>
This repository holds all Arduino resources for "Thermoelectric Real-time Measurement System (TRMS)"<br>
<br>
<header>
  <h1>Abstract</h1>
  <p>Thermoelectric generators offer an authentic context for teaching energy conversion because electrical output depends on thermal conditions and circuit loading and changes dynamically during heating and cooling. This paper proposes a classroom-ready approach that makes thermoelectric current visible in real time using an Arduino-compatible Wi-Fi microcontroller and Blynk mobile visualisation. The system streams current measurements (with optional voltage, derived power, and temperature difference) wirelessly to a smartphone dashboard for live indicators and time-series plots. The key implication is pedagogical, real-time traces support prediction–observe–explain cycles while thermal conditions evolve, helping students connect temperature difference, thermal contact and cooling strategies to circuit response, rather than treating measurements as isolated numbers. The approach also enables low-cost inquiry into load effects, internal resistance, and power optimisation, while keeping the measurement chain transparent through indirect current determination via a known resistor. Two model investigations are outlined to illustrate how teachers can structure guided inquiry or student-designed projects, and how mobile logging can support later analysis of power and energy.</p>
</header>
<br>
<header>
  <h1>Quick Key to Access the Arduino Source Code and the TRMS Supplemental Documentations</h1>
  <p>Note: The final data set used in analysis is available for public use. Additionally, deidentified raw survey data is available here. Due to IRB Restrictions all data files used in analysis that contain institutional information (Name, ID, etc.) prior to the final merged, and deidientified data are available upon direct request. Following approval, all deidentified data including institutional info will be shared directly.</p>
</header><br>
<br>
<table>
  <tr>
    <th>File Name</th>
    <th>Brief Description</th>
    <th>Link</th>
  </tr>
  <tr>
    <td>1. Arduino Source Code (Experiment 1)</td>
    <td>Full Arduino source code for the NodeMCU V2 and WeMos D1 mini implementations. They are complete source code for temperature-gradient monitoring (Experiment 1)</td>
    <td><a href="https://github.com/niwsri/TRMS/blob/631465fc71955c43160f195c5a1c85f93db8e453/Arduino%20Source%20Code%20(Experiment_1).ino">Link</a></td>
  </tr>
  <tr>
    <td>2. Arduino Source Code (Experiment 2)</td>
    <td>Full Arduino source code for the NodeMCU V2 and WeMos D1 mini implementations. They are complete source code for electrical characterization with extended logging (Experiment 2)</td>
    <td><a href="https://github.com/niwsri/TRMS/blob/2777da73a702730dfa264b05eb7b33876f2ebbad/Arduino%20Source%20Code%20(Experiment_2).ino">Link</a></td>
  </tr>
  <tr>
    <td>3. Arduino Firmware for TRMS</td>
    <td>A documentation of Arduino firmware used in the TRMS for experiment 1 and 2</td>
    <td><a href="https://github.com/niwsri/TRMS/blob/7a6ae352d57586530403b479b04419bf0efa8d8b/TRMS%20Arduino%20Firmware%20Used%20(Listing%201%20and%202).pdf">Link</a></td>
  </tr>
  <tr>
    <td>4. Pin-by-pin Circuit Information for TRMS</td>
    <td>A documentation of pin-by-pin circuit information of the TRMS for experiment 1 and 2.</td>
    <td><a href="https://github.com/niwsri/TRMS/blob/137bd7d465c4d1137f9773456300684d298f4c08/Pin-by-pin%20Circuit%20Information%20of%20the%20TRMS.pdf">Link</a></td>
  </tr>
  <tr>
    <td>5. TRMS Classroom Implementation</td>
    <td>A documentation of TRMS classroom implementation for experiment 1 and 2, and an evaluation of the TRMS approach</td>
    <td><a href="https://github.com/niwsri/TRMS/blob/a495706e9949244ad6da8781d52d03d6f3ba091d/TRMS%20Classroom%20Implementation.pdf">Link</a></td>
  </tr>
</table>
<br>
