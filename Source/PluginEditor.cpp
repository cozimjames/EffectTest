/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.3.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
EffectTestAudioProcessorEditor::EffectTestAudioProcessorEditor (EffectTestAudioProcessor& p)
    : AudioProcessorEditor(p), processor(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (gainLevel = new Slider ("new slider"));
    gainLevel->setRange (0, 100, 0);
    gainLevel->setSliderStyle (Slider::Rotary);
    gainLevel->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    gainLevel->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    startTimer(200);//starts timer with interval of 200mS
    //[/Constructor]
}

EffectTestAudioProcessorEditor::~EffectTestAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    gainLevel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void EffectTestAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void EffectTestAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    gainLevel->setBounds (24, 24, 71, 80);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void EffectTestAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == gainLevel)
    {
        //[UserSliderCode_gainLevel] -- add your slider handling code here..
        processor.gainLevel = gainLevelPosition->getValue();
        //[/UserSliderCode_gainLevel]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void EffectTestAudioProcessorEditor::timerCallback()
{
    //exchange any data you want between UI elements and the Plugin "ourProcessor"
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="EffectTestAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="EffectTestAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor(p), processor(p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <SLIDER name="new slider" id="30c79e76befdbc90" memberName="gainLevel"
          virtualName="" explicitFocusOrder="0" pos="24 24 71 80" min="0"
          max="100" int="0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
