# Making thermoelectric current visible: Arduino data acquisition with Blynk mobile visualisation in physics classroom
<br>
<b>Prapawan Thongsri, Niwat Srisawasdi*</b><br>
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
    <td>A Documentation of Arduino Firmware Used in the TRMS for experiment 1 and 2</td>
    <td><a href="https://github.com/niwsri/CERP-Data-TPACK-CCCs-/blob/main/TPACK%20Lesson%20Plan%20Design%20Scores.xls](https://apps.apple.com/us/app/appsheet/id732548900?platform=iphone">Link</a></td>
  </tr>
  <tr>
    <td>4. Appsheet hosting app for Andriod</td>
    <td>The AppSheet Hosting app is required to run the Plastic Detective app on Android devices. The Plastic Detective app operates via this hosting app, ensuring smooth functionality. This link directs users to download the hosting app from the Google Play Store.</td>
    <td><a href="https://apps.apple.com/nl/app/the-ocean-cleanup-survey-app/id1533071965](https://play.google.com/store/apps/details?id=x1Trackmaster.x1Trackmaster&hl=en&pli=1">AppSheet (Andriod)</a></td>
  </tr>
</table>
<br>
