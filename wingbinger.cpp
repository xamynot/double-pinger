/* ------------------------------------------------------------
name: "untitled", "WingBinger"
Code generated with Faust 2.79.4 (https://faust.grame.fr)
Compilation options: -lang cpp -ct 1 -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

static float mydsp_faustpower2_f(float value) {
	return value * value;
}

class mydsp : public dsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec0[2];
	float fConst3;
	FAUSTFLOAT fHslider1;
	int iRec3[2];
	float fRec2[3];
	float fRec1[3];
	FAUSTFLOAT fHslider2;
	float fRec4[2];
	FAUSTFLOAT fButton0;
	float fVec0[2];
	int iRec6[2];
	int iVec1[2];
	int iVec2[2];
	int iRec7[2];
	int iVec3[2];
	int iVec4[2];
	float fRec8[4];
	float fRec5[2];
	FAUSTFLOAT fHslider3;
	float fRec9[2];
	float fConst4;
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fButton1;
	float fVec5[2];
	int iRec12[2];
	float fRec15[3];
	float fRec14[3];
	int iVec6[2];
	int iVec7[2];
	int iRec13[2];
	int iVec8[2];
	int iVec9[2];
	float fRec11[3];
	float fRec10[3];
	FAUSTFLOAT fHslider5;
	float fRec16[2];
	FAUSTFLOAT fHslider6;
	float fRec17[2];
	float fRec19[3];
	float fRec18[3];
	float fRec21[3];
	float fRec20[3];
	FAUSTFLOAT fHslider7;
	float fRec22[2];
	float fRec23[2];
	float fRec25[3];
	float fRec24[3];
	
 public:
	mydsp() {
	}
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/counter:author", "Stephane Letz");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/toggle:author", "Vince");
		m->declare("basics.lib/version", "1.21.0");
		m->declare("compile_options", "-lang cpp -ct 1 -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("filename", "untitled.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/resonlp:author", "Julius O. Smith III");
		m->declare("filters.lib/resonlp:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/resonlp:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "1.7.1");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.1");
		m->declare("name", "untitled");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "1.4.1");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "1.6.0");
	}

	virtual int getNumInputs() {
		return 0;
	}
	virtual int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = 44.1f / fConst0;
		fConst2 = 1.0f - fConst1;
		fConst3 = 3141.5928f / fConst0;
		fConst4 = 3.1415927f / fConst0;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(15.0f);
		fHslider2 = FAUSTFLOAT(0.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(1.0f);
		fHslider4 = FAUSTFLOAT(15.0f);
		fButton1 = FAUSTFLOAT(0.0f);
		fHslider5 = FAUSTFLOAT(0.0f);
		fHslider6 = FAUSTFLOAT(0.0f);
		fHslider7 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			iRec3[l1] = 0;
		}
		for (int l2 = 0; l2 < 3; l2 = l2 + 1) {
			fRec2[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 3; l3 = l3 + 1) {
			fRec1[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fRec4[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			fVec0[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			iRec6[l6] = 0;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			iVec1[l7] = 0;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			iVec2[l8] = 0;
		}
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			iRec7[l9] = 0;
		}
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			iVec3[l10] = 0;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			iVec4[l11] = 0;
		}
		for (int l12 = 0; l12 < 4; l12 = l12 + 1) {
			fRec8[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = l13 + 1) {
			fRec5[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = l14 + 1) {
			fRec9[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = l15 + 1) {
			fVec5[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = l16 + 1) {
			iRec12[l16] = 0;
		}
		for (int l17 = 0; l17 < 3; l17 = l17 + 1) {
			fRec15[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 3; l18 = l18 + 1) {
			fRec14[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = l19 + 1) {
			iVec6[l19] = 0;
		}
		for (int l20 = 0; l20 < 2; l20 = l20 + 1) {
			iVec7[l20] = 0;
		}
		for (int l21 = 0; l21 < 2; l21 = l21 + 1) {
			iRec13[l21] = 0;
		}
		for (int l22 = 0; l22 < 2; l22 = l22 + 1) {
			iVec8[l22] = 0;
		}
		for (int l23 = 0; l23 < 2; l23 = l23 + 1) {
			iVec9[l23] = 0;
		}
		for (int l24 = 0; l24 < 3; l24 = l24 + 1) {
			fRec11[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 3; l25 = l25 + 1) {
			fRec10[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2; l26 = l26 + 1) {
			fRec16[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2; l27 = l27 + 1) {
			fRec17[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 3; l28 = l28 + 1) {
			fRec19[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 3; l29 = l29 + 1) {
			fRec18[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 3; l30 = l30 + 1) {
			fRec21[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 3; l31 = l31 + 1) {
			fRec20[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 2; l32 = l32 + 1) {
			fRec22[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 2; l33 = l33 + 1) {
			fRec23[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 3; l34 = l34 + 1) {
			fRec25[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 3; l35 = l35 + 1) {
			fRec24[l35] = 0.0f;
		}
	}
	
	virtual void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	
	virtual void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual mydsp* clone() {
		return new mydsp();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("untitled");
		ui_interface->addHorizontalSlider("Cross Modulation", &fHslider5, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("Cross Modulation B", &fHslider2, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("Cutoff(0~1)", &fHslider0, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.5f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("CutoffB(0~1)", &fHslider3, FAUSTFLOAT(1.0f), FAUSTFLOAT(0.5f), FAUSTFLOAT(2e+01f), FAUSTFLOAT(0.01f));
		ui_interface->addButton("Fast/Slow", &fButton0);
		ui_interface->addButton("Fast/Slow B", &fButton1);
		ui_interface->addHorizontalSlider("Q", &fHslider1, FAUSTFLOAT(15.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(5e+01f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("QB", &fHslider4, FAUSTFLOAT(15.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(5e+01f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("Step modulation", &fHslider6, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("Step modulationB", &fHslider7, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = fConst1 * float(fHslider0);
		float fSlow1 = 1.0f / float(fHslider1);
		float fSlow2 = fConst1 * float(fHslider2);
		float fSlow3 = float(fButton0);
		float fSlow4 = fConst1 * float(fHslider3);
		float fSlow5 = 1.0f / float(fHslider4);
		float fSlow6 = float(fButton1);
		float fSlow7 = fConst1 * float(fHslider5);
		float fSlow8 = fConst1 * float(fHslider6);
		float fSlow9 = fConst1 * float(fHslider7);
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			fRec0[0] = fSlow0 + fConst2 * fRec0[1];
			float fTemp0 = std::tan(fConst3 * fRec0[0]);
			float fTemp1 = 1.0f / fTemp0;
			float fTemp2 = (fSlow1 + fTemp1) / fTemp0 + 1.0f;
			float fTemp3 = 1.0f - 1.0f / mydsp_faustpower2_f(fTemp0);
			float fTemp4 = (fTemp1 - fSlow1) / fTemp0 + 1.0f;
			iRec3[0] = 1103515245 * iRec3[1] + 12345;
			float fTemp5 = float(iRec3[0]);
			float fTemp6 = 4.6566128e-14f * fTemp5;
			fRec2[0] = fTemp6 - (fRec2[2] * fTemp4 + 2.0f * fRec2[1] * fTemp3) / fTemp2;
			fRec1[0] = (0.1f * fRec2[0] + 0.2f * fRec2[1] + 0.1f * fRec2[2] - (fTemp4 * fRec1[2] + 2.0f * fTemp3 * fRec1[1])) / fTemp2;
			float fTemp7 = 0.1f * fRec1[0] + 0.2f * fRec1[1] + 0.1f * fRec1[2];
			fRec4[0] = fSlow2 + fConst2 * fRec4[1];
			fVec0[0] = fSlow3;
			iRec6[0] = iRec6[1] != ((fSlow3 - fVec0[1]) == 1.0f);
			int iTemp8 = (fTemp7 / fTemp2) > 0.0f;
			iVec1[0] = iTemp8;
			int iTemp9 = iTemp8 * (1 - iVec1[1]);
			iVec2[0] = iTemp9;
			iRec7[0] = iRec7[1] + (iTemp9 > iVec2[1]);
			int iTemp10 = (iRec7[0] >> ((iRec6[0]) ? 8 : 4)) & 1;
			iVec3[0] = iTemp10;
			int iTemp11 = iTemp10 * (1 - iVec3[1]);
			iVec4[0] = iTemp11;
			int iTemp12 = (iVec4[1] <= 0) & (iTemp11 > 0);
			fRec8[0] = 0.5221894f * fRec8[3] + 4.656613e-10f * fTemp5 + 2.494956f * fRec8[1] - 2.0172658f * fRec8[2];
			float fTemp13 = std::fmod(1e+04f * std::fabs(0.049922034f * fRec8[0] + 0.0506127f * fRec8[2] - (0.095993534f * fRec8[1] + 0.004408786f * fRec8[3])), 5.0f);
			fRec5[0] = fRec5[1] * float(1 - iTemp12) + fTemp13 * float(iTemp12);
			float fTemp14 = fRec5[0] + -1.0f;
			float fTemp15 = ((fTemp14 >= 3.0f) ? ((fTemp14 >= 4.0f) ? 246.94f : 2.2e+02f) : ((fTemp14 >= 2.0f) ? 184.99f : ((fTemp14 >= 1.0f) ? 164.81f : 146.83f)));
			fRec9[0] = fSlow4 + fConst2 * fRec9[1];
			float fTemp16 = std::tan(fConst4 * fRec9[0] * fTemp15 * (fRec4[0] * fTemp7 / fTemp2 + 1.0f));
			float fTemp17 = 1.0f / fTemp16;
			float fTemp18 = (fSlow5 + fTemp17) / fTemp16 + 1.0f;
			float fTemp19 = 1.0f - 1.0f / mydsp_faustpower2_f(fTemp16);
			float fTemp20 = (fTemp17 - fSlow5) / fTemp16 + 1.0f;
			fVec5[0] = fSlow6;
			iRec12[0] = iRec12[1] != ((fSlow6 - fVec5[1]) == 1.0f);
			float fTemp21 = std::tan(fConst3 * fRec9[0]);
			float fTemp22 = 1.0f / fTemp21;
			float fTemp23 = (fSlow5 + fTemp22) / fTemp21 + 1.0f;
			float fTemp24 = 1.0f - 1.0f / mydsp_faustpower2_f(fTemp21);
			float fTemp25 = (fTemp22 - fSlow5) / fTemp21 + 1.0f;
			fRec15[0] = fTemp6 - (fRec15[2] * fTemp25 + 2.0f * fRec15[1] * fTemp24) / fTemp23;
			fRec14[0] = (0.1f * fRec15[0] + 0.2f * fRec15[1] + 0.1f * fRec15[2] - (fTemp25 * fRec14[2] + 2.0f * fTemp24 * fRec14[1])) / fTemp23;
			float fTemp26 = 0.1f * fRec14[0] + 0.2f * fRec14[1] + 0.1f * fRec14[2];
			int iTemp27 = (fTemp26 / fTemp23) > 0.0f;
			iVec6[0] = iTemp27;
			int iTemp28 = iTemp27 * (1 - iVec6[1]);
			iVec7[0] = iTemp28;
			iRec13[0] = iRec13[1] + (iTemp28 > iVec7[1]);
			int iTemp29 = (iRec13[0] >> ((iRec12[0]) ? 8 : 4)) & 1;
			iVec8[0] = iTemp29;
			int iTemp30 = iTemp29 * (1 - iVec8[1]);
			iVec9[0] = iTemp30;
			float fTemp31 = 9.3132255e-14f * fTemp5;
			fRec11[0] = fTemp31 + float(10 * iTemp30) - (fRec11[2] * fTemp20 + 2.0f * fRec11[1] * fTemp19) / fTemp18;
			fRec10[0] = (0.1f * fRec11[0] + 0.2f * fRec11[1] + 0.1f * fRec11[2] - (fTemp20 * fRec10[2] + 2.0f * fTemp19 * fRec10[1])) / fTemp18;
			fRec16[0] = fSlow7 + fConst2 * fRec16[1];
			fRec17[0] = fSlow8 + fConst2 * fRec17[1];
			float fTemp32 = std::tan(fConst4 * fRec0[0] * (fTemp15 * (1.0f - fRec17[0]) + 1.0f) * (fRec16[0] * (0.1f * fRec10[0] + 0.2f * fRec10[1] + 0.1f * fRec10[2]) / fTemp18 + 1.0f));
			float fTemp33 = 1.0f / fTemp32;
			float fTemp34 = (fSlow1 + fTemp33) / fTemp32 + 1.0f;
			float fTemp35 = 1.0f - 1.0f / mydsp_faustpower2_f(fTemp32);
			float fTemp36 = (fTemp33 - fSlow1) / fTemp32 + 1.0f;
			float fTemp37 = 9.3132255e-12f * fTemp5;
			fRec19[0] = fTemp37 + float(100 * iTemp11) - (fRec19[2] * fTemp36 + 2.0f * fRec19[1] * fTemp35) / fTemp34;
			fRec18[0] = (0.1f * fRec19[0] + 0.2f * fRec19[1] + 0.1f * fRec19[2] - (fTemp36 * fRec18[2] + 2.0f * fTemp35 * fRec18[1])) / fTemp34;
			output0[i0] = FAUSTFLOAT((0.1f * fRec18[0] + 0.2f * fRec18[1] + 0.1f * fRec18[2]) / fTemp34);
			float fTemp38 = std::tan(fConst4 * fRec0[0] * fTemp15 * (fRec16[0] * fTemp26 / fTemp23 + 1.0f));
			float fTemp39 = 1.0f / fTemp38;
			float fTemp40 = (fSlow1 + fTemp39) / fTemp38 + 1.0f;
			float fTemp41 = 1.0f - 1.0f / mydsp_faustpower2_f(fTemp38);
			float fTemp42 = (fTemp39 - fSlow1) / fTemp38 + 1.0f;
			fRec21[0] = fTemp31 + float(10 * iTemp11) - (fRec21[2] * fTemp42 + 2.0f * fRec21[1] * fTemp41) / fTemp40;
			fRec20[0] = (0.1f * fRec21[0] + 0.2f * fRec21[1] + 0.1f * fRec21[2] - (fTemp42 * fRec20[2] + 2.0f * fTemp41 * fRec20[1])) / fTemp40;
			fRec22[0] = fSlow9 + fConst2 * fRec22[1];
			int iTemp43 = (iVec9[1] <= 0) & (iTemp30 > 0);
			fRec23[0] = fRec23[1] * float(1 - iTemp43) + fTemp13 * float(iTemp43);
			float fTemp44 = fRec23[0] + -1.0f;
			float fTemp45 = std::tan(fConst4 * fRec9[0] * (((fTemp44 >= 3.0f) ? ((fTemp44 >= 4.0f) ? 246.94f : 2.2e+02f) : ((fTemp44 >= 2.0f) ? 184.99f : ((fTemp44 >= 1.0f) ? 164.81f : 146.83f))) * (1.0f - fRec22[0]) + 1.0f) * (fRec4[0] * (0.1f * fRec20[0] + 0.2f * fRec20[1] + 0.1f * fRec20[2]) / fTemp40 + 1.0f));
			float fTemp46 = 1.0f / fTemp45;
			float fTemp47 = (fSlow5 + fTemp46) / fTemp45 + 1.0f;
			float fTemp48 = 1.0f - 1.0f / mydsp_faustpower2_f(fTemp45);
			float fTemp49 = (fTemp46 - fSlow5) / fTemp45 + 1.0f;
			fRec25[0] = fTemp37 + float(100 * iTemp30) - (fRec25[2] * fTemp49 + 2.0f * fRec25[1] * fTemp48) / fTemp47;
			fRec24[0] = (0.1f * fRec25[0] + 0.2f * fRec25[1] + 0.1f * fRec25[2] - (fTemp49 * fRec24[2] + 2.0f * fTemp48 * fRec24[1])) / fTemp47;
			output1[i0] = FAUSTFLOAT((0.1f * fRec24[0] + 0.2f * fRec24[1] + 0.1f * fRec24[2]) / fTemp47);
			fRec0[1] = fRec0[0];
			iRec3[1] = iRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec4[1] = fRec4[0];
			fVec0[1] = fVec0[0];
			iRec6[1] = iRec6[0];
			iVec1[1] = iVec1[0];
			iVec2[1] = iVec2[0];
			iRec7[1] = iRec7[0];
			iVec3[1] = iVec3[0];
			iVec4[1] = iVec4[0];
			for (int j0 = 3; j0 > 0; j0 = j0 - 1) {
				fRec8[j0] = fRec8[j0 - 1];
			}
			fRec5[1] = fRec5[0];
			fRec9[1] = fRec9[0];
			fVec5[1] = fVec5[0];
			iRec12[1] = iRec12[0];
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			iVec6[1] = iVec6[0];
			iVec7[1] = iVec7[0];
			iRec13[1] = iRec13[0];
			iVec8[1] = iVec8[0];
			iVec9[1] = iVec9[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec16[1] = fRec16[0];
			fRec17[1] = fRec17[0];
			fRec19[2] = fRec19[1];
			fRec19[1] = fRec19[0];
			fRec18[2] = fRec18[1];
			fRec18[1] = fRec18[0];
			fRec21[2] = fRec21[1];
			fRec21[1] = fRec21[0];
			fRec20[2] = fRec20[1];
			fRec20[1] = fRec20[0];
			fRec22[1] = fRec22[0];
			fRec23[1] = fRec23[0];
			fRec25[2] = fRec25[1];
			fRec25[1] = fRec25[0];
			fRec24[2] = fRec24[1];
			fRec24[1] = fRec24[0];
		}
	}

};

#endif
