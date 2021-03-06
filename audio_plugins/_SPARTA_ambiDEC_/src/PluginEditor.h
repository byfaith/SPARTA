/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.3

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --

#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "outputCoordsView.h"
#include "log2dSlider.h"

typedef enum _SPARTA_WARNINGS{
    k_warning_none,
    k_warning_frameSize,
    k_warning_supported_fs,
    k_warning_mismatch_fs,
    k_warning_NinputCH,
    k_warning_NoutputCH
}SPARTA_WARNINGS;

//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PluginEditor  : public AudioProcessorEditor,
                      public Timer,
                      private FilenameComponentListener,
                      public ComboBox::Listener,
                      public Slider::Listener,
                      public Button::Listener
{
public:
    //==============================================================================
    PluginEditor (PluginProcessor* ownerFilter);
    ~PluginEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    PluginProcessor* hVst;
    void timerCallback() override;

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    ScopedPointer<OpenGLGraphicsContextCustomShader> shader;
    OpenGLContext openGLContext;

    /* freq-dependent decoding order */
    ScopedPointer<log2dSlider> decOrder2dSlider;

    /* source coordinates viewport */
    ScopedPointer<Viewport> outputCoordsVP;
    outputCoordsView* outputCoordsView_handle;
    FilenameComponent fileChooser;

    /* sofa file loading */
    void filenameComponentChanged (FilenameComponent*) override  {
        String directory = fileChooser.getCurrentFile().getFullPathName();
        const char* new_cstring = (const char*)directory.toUTF8();
        ambi_dec_setSofaFilePath(hVst->hAmbi, new_cstring);
    }

    /* warnings */
    SPARTA_WARNINGS currentWarning;

    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<ComboBox> CBoutputDirsPreset;
    std::unique_ptr<Slider> SL_num_loudspeakers;
    std::unique_ptr<ToggleButton> TBuseDefaultHRIRs;
    std::unique_ptr<ComboBox> CBsourcePreset;
    std::unique_ptr<ComboBox> CBchFormat;
    std::unique_ptr<ComboBox> CBnormScheme;
    std::unique_ptr<Slider> SL_transitionFreq;
    std::unique_ptr<ComboBox> CBdec1method;
    std::unique_ptr<ComboBox> CBdec2method;
    std::unique_ptr<ToggleButton> TBdec1EnableMaxrE;
    std::unique_ptr<ToggleButton> TBdec2EnableMaxrE;
    std::unique_ptr<ComboBox> CBdec1normtype;
    std::unique_ptr<ToggleButton> TBBinauraliseLS;
    std::unique_ptr<ComboBox> CBdec2normtype;
    std::unique_ptr<Slider> s_decOrder;
    std::unique_ptr<TextButton> tb_loadJSON;
    std::unique_ptr<TextButton> tb_saveJSON;
    std::unique_ptr<ComboBox> CBmasterOrder;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

