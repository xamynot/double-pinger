declare filename "untitled.dsp";
declare name "untitled";
import("stdfaust.lib");
declare name "WingBinger";

Q         = hslider("Q",               15,  1, 50,   0.01);
cf    = hslider("Cutoff(0~1)",     1, 0.5, 20, 0.01):si.smoo;
thresh    = hslider("Threshold",       0.0, -1.0, 1.0, 0.01);
step_mod     = hslider("Step modulation", 0,   0.0, 1,  0.01):si.smoo;

crossmod = hslider("Cross Modulation", 0,   0, 10,  0.01):si.smoo;

toggle = button("Fast/Slow") : ba.toggle;
shiftAmount =  4, 8: select2(toggle);



QB         = hslider("QB",               15,  1, 50,   0.01);
cfB    = hslider("CutoffB(0~1)",     1, 0.5, 20, 0.01):si.smoo;
threshB    = hslider("ThresholdB",       0.0, -1.0, 1.0, 0.01);
step_modB     = hslider("Step modulationB", 0,   0.0, 1,  0.01):si.smoo;

crossmodB = hslider("Cross Modulation B", 0,   0, 10,  0.01):si.smoo;

toggleB = button("Fast/Slow B") : ba.toggle;
shiftAmountB =  4, 8: select2(toggleB);

scale(n) = 	146.83, 164.81, 184.99, 220.00, 246.94:ba.selectn(5,n-1); // C D E G A

one_peak(cff_, Q) = fi.resonlp(cff_,Q,0.1):fi.resonlp(cff_,Q,0.1);

one_peakB(cff_, Q) = fi.resonlp(cff_,Q,0.1):fi.resonlp(cff_,Q,0.1);

sof_   = (no.noise*0.0001)
         : one_peak(cf*1000, Q);

sof_B   = (no.noise*0.0001)
         : one_peakB(cfB*1000, QB);


pulsess = sof_ > 0;
edge = pulsess * (1 - (pulsess : mem));

pulsessB = sof_B > 0;
edgeB = pulsessB * (1 - (pulsessB : mem));


count =  ba.counter(edge);
bit1 = (count >> shiftAmount) & 1; // /4
edge2 = bit1 * (1 - (bit1 : mem));


countB =  ba.counter(edgeB);
bit1B = (countB >> shiftAmountB) & 1; // /4
edge2B = bit1B * (1 - (bit1B : mem));


indexNoise = (no.pink_noise : abs ) *10000 % 5:ba.latch(edge2); 
randNote   =  scale(indexNoise);  

indexNoiseB = (no.pink_noise : abs ) *10000 % 5:ba.latch(edge2B); 
randNoteB   =  scale(indexNoiseB);  

sof_2  = (no.noise*0.0001 + no.noise*0.0001+edge2*10)
         : one_peak(randNote*cf+randNote*cf*crossmod*sof_B,Q);
         

         sof_2B  = (no.noise*0.0001 + no.noise*0.0001+edge2B*10)
         : one_peakB(randNote*cfB+randNote*cfB*crossmodB*sof_,QB);


pulsess2 = sof_2 > 0;
edge3 = pulsess2 * (1 - (pulsess2 : mem));

pulsess2B = sof_2B > 0;
edge3B = pulsess2B * (1 - (pulsess2B : mem));



count2 =  ba.counter(edge3);
bit2 = (count >> shiftAmount) & 1; // /4
edge4 = bit2 * (1 - (bit2 : mem));


count2B =  ba.counter(edge3B);
bit2B = (countB >> shiftAmountB) & 1; // /4
edge4B = bit2B * (1 - (bit2B : mem));



indexNoise2 = (no.pink_noise : abs ) *10000 % 5:ba.latch(edge4); 
randNote2   =  scale(indexNoise2);  

indexNoise2B = (no.pink_noise : abs ) *10000 % 5:ba.latch(edge4B); 
randNote2B   =  scale(indexNoise2B);  

freq_ = ((randNote2-randNote2*step_mod)+1)*cf;
sof_3  = (no.noise*0.01 + no.noise*0.01+edge4*100)
         : one_peak(freq_*(1+crossmod*sof_2B),Q);

freq_B = ((randNote2B-randNote2B*step_modB)+1)*cfB;

         sof_3B  = (no.noise*0.01 + no.noise*0.01+edge4B*100)
         : one_peakB(freq_B*(1+crossmodB*sof_2),QB);



process = sof_3,sof_3B<: _, _;

